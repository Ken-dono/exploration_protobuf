#include "com.h"
#include "../connexion/connexion.h"

#define MQ_WRITE_NAME "/mq_write"

static int socket_client;

static pthread_t thread_write;
static pthread_t thread_read;

/**
 * Thread function used to regularly check the message queue and write messages on the socket
 * @param arg
 * @return
 */
void *thread_write_fct();

/**
 * Thread function used read messages on the socket
 * @param arg
 * @return
 */
void *thread_read_fct();

static int running = 1;

mqd_t mq_write;

void com_init() {
    // Opening server on port SERVEUR_PORT
    connexion_init(SERVER_PORT);

    // Wait for connection
    printf("COM | com_init : En attente de connexion\n");
    socket_client = connexion_accept();

    // Launch writing thread
    if (pthread_create(&thread_write, NULL, thread_write_fct, NULL) != 0) {
        fprintf(stderr, "COM | com_init : erreur pthread_create thread_write\n");
        exit(-1);
    }
    printf("COM | com_init : thread_write lancé\n");
    // Launch reading thread
    if (pthread_create(&thread_read, NULL, thread_read_fct, NULL) != 0) {
        fprintf(stderr, "COM | com_init : erreur pthread_create thread_read\n");
        exit(-1);
    }
    printf("COM | com_init : thread_read lancé\n");
}

void com_send_message(message_t * message){
    if (mq_send(mq_write, (const char *) message, sizeof(message_t), 0) == -1) {
        perror("COM | com_send_message : mq_send");
        exit(EXIT_FAILURE);
    }
}

void *thread_write_fct() {
    // Open mq for socket writing
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(message_t);
    mq_write = mq_open(MQ_WRITE_NAME, O_CREAT | O_RDWR, 0644, &attr);
    if (mq_write == (mqd_t ) -1)
    {
        perror("COM | com_init : Erreur création mq\n");
        mq_unlink( MQ_WRITE_NAME );
        mq_write = mq_open( MQ_WRITE_NAME , O_RDWR  |O_CREAT, 0644, &attr);
    }

    // Main
    while (running == 1){
        // Read message queue
        message_t *msg = malloc(sizeof(message_t));
        if (msg == NULL) {
            perror("COM | thread_write_fct : Erreur d'allocation de mémoire\n");
            exit(EXIT_FAILURE);
        }
        ssize_t bytes_send = mq_receive(mq_write, ( char *) msg, sizeof(message_t), NULL);
        printf("COM | thread_write_fct : bytes_send : %ld\n", bytes_send);

        if (bytes_send == -1) {
            perror("COM | thread_write_fct : mq_receive");
            exit(EXIT_FAILURE);
        } else if (bytes_send > 0){
            // Serialize the message
            uint8_t *buffer;
            size_t len;
            protocole_code(msg, &buffer, &len);

            // Send a first packet with the lenght of the serialized packet
            uint8_t len_byte = (uint8_t)len;
            connexion_write(&len_byte, 1);
            printf("COM | thread_write_fct : size_send : %02X\n", len_byte);

            // Send the serialized packet
            connexion_write(buffer, len);
            printf("COM | thread_write_fct : message send : ");

            // DEBUG : Print the sended package
            for (size_t i = 0; i < len; ++i) {
                printf("%02X ", buffer[i]);
            }
            printf("\n");

            // DEBUG : Désérialisation du message pour vérification
            BatteryLevel *battery_in = battery_level__unpack(NULL, len, buffer);
            if (battery_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            // Traitement du message désérialisé
            printf("Send : ID : %d | PAYLOAD (level) : %d \n", battery_in->id, battery_in->level);
            // Libération du message désérialisé
            battery_level__free_unpacked(battery_in, NULL);

            // Free the buffer
            protocole_free(buffer);
        }
        free(msg);
        usleep(200);
    }
    // Fermeture de la file de messages avant de sortir de la fonction
    if (mq_close(mq_write) == -1) {
        perror("COM | thread_write_fct : Erreur fermeture mq_write");
        exit(EXIT_FAILURE);
    }

    // Suppression de la file de messages
    if (mq_unlink(MQ_WRITE_NAME) == -1) {
        perror("COM | thread_write_fct : Erreur suppression mq_write");
        exit(EXIT_FAILURE);
    }
    return NULL;
}

void *thread_read_fct() {
    while (running == 1) {
        // Lire la taille du message (2 octets)
        uint8_t size_buffer[2];
        connexion_read(size_buffer, sizeof(size_buffer));
        // Afficher le message reçu pour débogage
        printf("COM | thread_read_fct : size_buffer reçu : ");
        for (size_t i = 0; i < sizeof(size_buffer); ++i) {
            printf("%02X ", size_buffer[i]);
        }
        printf("\n");

        // uint16_t message_size = (size_buffer[0] << 8) | size_buffer[1];

        // // Lire le message basé sur la taille lue
        // uint8_t *message_buffer = malloc(message_size);
        // if (message_buffer == NULL) {
        //     perror("COM | thread_read_fct : Erreur d'allocation de mémoire pour message_buffer\n");
        //     exit(EXIT_FAILURE);
        // }

        // connexion_read(message_buffer, message_size);

        // // Afficher le message reçu pour débogage
        // printf("COM | thread_read_fct : Message reçu : ");
        // for (size_t i = 0; i < message_size; ++i) {
        //     printf("%02X ", message_buffer[i]);
        // }
        // printf("\n");

        // // Libérer le buffer de message
        // free(message_buffer);

        usleep(200);
    }
    return NULL;
}

void com_free(){
    // Signal aux threads de s'arrêter
    running = 0;

    

    // Joindre les threads pour s'assurer qu'ils ont terminé
    if (pthread_join(thread_write, NULL) != 0) {
        perror("COM | com_free : erreur pthread_join thread_write");
    }

    if (pthread_join(thread_read, NULL) != 0) {
        perror("COM | com_free : erreur pthread_join thread_read");
    }
}