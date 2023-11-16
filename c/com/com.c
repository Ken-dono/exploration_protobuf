//
// Created by buryhugo on 02/06/23.
//

#include "com.h"
#include "../connexion/connexion.h"

#define MQ_WRITE_NAME "/mq_write"

static int socket_client;

// static pthread_t thread_read;
static pthread_t thread_write;

/**
 * Thread function used to regularly read the socket
 * @param arg
 * @return
 */
void *thread_read_fct();

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

    // // Launching reading thread
    // if (pthread_create(&thread_read, NULL, thread_read_fct, NULL) != 0) {
    //     fprintf(stderr, "COM | com_init : erreur pthread_create thread_read\n");
    //     exit(-1);
    // }

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

// void *thread_read_fct(){
//     while (running){
//         // Read message
//         uint8_t buffer[1];
//         uint8_t bytes_read = connexion_read(buffer, 1);
//         uint8_t dlc = buffer[0];
//         printf("COM | thread_read_fct : bytes_read : %d | dlc : %d\n", bytes_read, dlc);
//         uint8_t bytes_read = connexion_read(buffer, dlc);
//         printf("COM | thread_read_fct : bytes_read : %d \n", bytes_read);

//         // Decode message and send it to the handler
//         message_t *msg = malloc(sizeof(message_t));
//         if (msg == NULL) {
//             perror("COM | thread_read_fct : Erreur d'allocation de mémoire\n");
//             exit(EXIT_FAILURE);
//         }
//         protocole_decode(msg,buffer);
//     }
// }

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
            // Write message on client socket
            uint8_t buffer[MAX_MSG_SIZE];
            protocole_code(msg, buffer);

            for (int i = 0; i < MAX_MSG_SIZE; ++i) {
                printf("%02X ", buffer[i]);
            }
            printf("\n");

            // Désérialisation du message pour vérification
            BatteryLevel *battery_in;
            size_t len = battery_level__get_packed_size(battery_in);
            battery_in = battery_level__unpack(NULL, len, buffer);
            if (battery_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                //free(buffer);
                exit(EXIT_FAILURE);
            }

            printf("Received: ID :%d | PAYLOAD (level) : %d \n", battery_in->id, battery_in->level);

            // Libération du battery_level désérialisé
            battery_level__free_unpacked(battery_in, NULL);

            // Nettoyage
            //free(buffer);

            //connexion_write(buffer, MAX_MSG_SIZE);
        }
        free(msg);
        usleep(200);
    }
    return NULL;
}