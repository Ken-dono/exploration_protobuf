#include "com.h"
#include "../connexion/connexion.h"

#define MQ_WRITE_NAME "/mq_write"

static int socket_client;

static pthread_t thread_write;

/**
 * Thread function used to regularly check the message queue and write messages on the socket
 * @param arg
 * @return
 */
void *thread_write_fct();

void test_message();

static int running = 1;

mqd_t mq_write;

void com_init() {
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

    // Opening server on port SERVEUR_PORT
    connexion_init(SERVER_PORT);

    // Wait for connection
    printf("COM | com_init : En attente de connexion\n");
    socket_client = connexion_accept();

    // Launch writing thread
    if (pthread_create(&thread_write, NULL, thread_write_fct, NULL) != 0) {
        fprintf(stderr, "COM | com_init : erreur pthread_create thread_read\n");
        exit(-1);
    }

}

void com_send_message(message_t * message){
    if (mq_send(mq_write, (const char *) message, sizeof(message_t), 0) == -1) {
        perror("COM | com_send_message : mq_send");
        exit(EXIT_FAILURE);
    }
}

void *thread_write_fct() {

    while (running){
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
            uint8_t buffer[MAX_MSG_SIZE];
            size_t len = protocole_code(msg, buffer);

            //Envoi de la DLC
            connexion_write(&msg->dlc, 1);
            printf("COM | thread_write_fct : dlc_send : %d\n", msg->dlc);

            //Envoi du message prototypé
            connexion_write(buffer, len);
            printf("COM | thread_write_fct : message send : ");
            for (size_t i = 0; i < len; ++i) {
                printf("%02X ", buffer[i]);
            }
            printf("\n");

            // Désérialisation du message pour vérification
            BatteryLevel *battery_in = battery_level__unpack(NULL, len, buffer);
            if (battery_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            // Traitement du message désérialisé
            printf("Send: ID :%d | PAYLOAD (level) : %d \n", battery_in->id, battery_in->level);
            // Libération du message désérialisé
            battery_level__free_unpacked(battery_in, NULL);
        }
        free(msg);
        usleep(200);
    }
    return NULL;
}