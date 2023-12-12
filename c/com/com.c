#define MQ_WRITE_NAME "/mq_write"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>
#include "com.h"
#include "../connexion/connexion.h"

static int socket_client;

static pthread_t thread_write;
static pthread_t thread_read;

// Fonction du thread pour écrire les messages de la file dans la socket.
void *thread_write_fct();

// Fonction du thread pour lire les messages de la socket.
void *thread_read_fct();

static int running = 1;

mqd_t mq_write;

// Démarre le système de communication.
void com_start(){
    // Ouverture du serveur sur le port SERVEUR_PORT
    connexion_init(SERVER_PORT);

    // Attente d'une connexion client
    printf("COM | com_init : En attente de connexion\n");
    socket_client = connexion_accept();

    running = 1; 

    // Lancement du thread d'écriture
    if (pthread_create(&thread_write, NULL, thread_write_fct, NULL) != 0) {
        perror("COM | com_init : erreur pthread_create thread_write");
        exit(-1);
    }
    TRACE("COM | com_start : thread_write lancé\n");
    // Lancement du thread de lecture
    if (pthread_create(&thread_read, NULL, thread_read_fct, NULL) != 0) {
        perror("COM | com_init : erreur pthread_create thread_read");
        exit(-1);
    }
    TRACE("COM | com_start : thread_read lancé\n");
}

// Arrête le système de communication.
void com_stop(){
    running = 0;

    // Envoi d'un message d'arrêt
    message_t msg_stop;
    msg_stop.dlc = 0x02;
    msg_stop.id = 0XAA;
    msg_stop.payload[0] = 100;
    com_send_message(&msg_stop);
    
    // Fermeture de la connexion
    connexion_close();

    // Attente de la fin des threads
    if (pthread_join(thread_write, NULL) != 0) {
        perror("COM | com_stop : erreur pthread_join thread_write");
    }
    TRACE("COM | com_stop : thread_write stopped\n");
    if (pthread_join(thread_read, NULL) != 0) {
        perror("COM | com_stop : erreur pthread_join thread_read");
    }
    TRACE("COM | com_stop : thread_read stopped\n");
}

// Envoie un message à travers la file de messages.
void com_send_message(message_t * message){
    if (mq_send(mq_write, (const char *) message, sizeof(message_t), 0) == -1) {
        perror("COM | com_send_message : mq_send");
        exit(EXIT_FAILURE);
    }
}

// Initialise la file de messages pour l'écriture.
void com_init() {
    // Configuration et ouverture de la file de messages
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
    TRACE("COM | com_init : mq_write créée avec succès\n");
    com_start();
}

// Libère les ressources utilisées par le système de communication.
void com_free(){
    // Fermeture de la file de messages
    if (mq_close(mq_write) == -1) {
        perror("COM | thread_write_fct : Erreur fermeture mq_write");
        exit(EXIT_FAILURE);
    }
    TRACE("COM | com_free : Fermeture mq_write réussie\n");

    // Suppression de la file de messages
    if (mq_unlink(MQ_WRITE_NAME) == -1) {
        perror("COM | thread_write_fct : Erreur suppression mq_write");
        exit(EXIT_FAILURE);
    }
    TRACE("COM | com_free : Suppression mq_write réussie\n");
}

// Thread d'écriture : lit la file de messages et envoie les données sur la socket.
void *thread_write_fct() {
    while (running == 1){
        // Lire la file de messages
        message_t *msg = malloc(sizeof(message_t));
        if (msg == NULL) {
            perror("COM | thread_write_fct : Erreur d'allocation de mémoire\n");
            exit(EXIT_FAILURE);
        }
        ssize_t bytes_send = mq_receive(mq_write, ( char *) msg, sizeof(message_t), NULL);
        if (msg->id==0xAA)
        {
            TRACE("COM | thread_write_fct : message stop recu\n");
        } else {
            TRACE("COM | thread_write_fct : bytes_send : %ld\n", bytes_send);
            if (bytes_send == -1) {
                perror("COM | thread_write_fct : mq_receive");
                exit(EXIT_FAILURE);
            } else if (bytes_send > 0){
                // Sérialiser le message
                uint8_t *buffer;
                size_t len;
                protocole_code(msg, &buffer, &len);

                // Envoyer un premier paquet avec la longueur du paquet sérialisé
                uint8_t payload_descriptor_send[2];
                payload_descriptor_send[0] = (uint8_t)((len >> 8) & 0xFF); // Octet de poids fort
                payload_descriptor_send[1] = (uint8_t)(len & 0xFF);        // Octet de poids faible
                connexion_write(payload_descriptor_send, 2);
                TRACE("COM | thread_write_fct : size_send : %02X%02X\n", payload_descriptor_send[0], payload_descriptor_send[1]);

                // Envoyer le paquet sérialisé
                connexion_write(buffer, len);
                
                // DEBUG : Afficher le paquet envoyé
                TRACE("COM | thread_write_fct : message send : ");
                for (size_t i = 0; i < len; ++i) {
                    TRACE("%02X ", buffer[i]);
                }
                TRACE("\n");

                // Libérer le buffer
                protocole_free(buffer);
            }
        }
        free(msg);
        usleep(200);
    }
    return NULL;
}

// Thread de lecture : lit les données de la socket et les traite.
void *thread_read_fct() {
    while (running == 1) {
        // Lire la taille du message (2 octets)
        uint8_t payload_descriptor_received[2];
        connexion_read(payload_descriptor_received, 2);

        // DEBUG : Afficher le message reçu pour débogage
        TRACE("COM | thread_write_fct : size_received : %02X%02X\n", payload_descriptor_received[0], payload_descriptor_received[1]);

        // Lire le message basé sur la taille lue
        size_t len = ((size_t)payload_descriptor_received[0] << 8) | (size_t)payload_descriptor_received[1];
        TRACE("COM | thread_write_fct : len_to_read (combined) : %ld\n", len);
        message_t *msg = malloc(sizeof(message_t));
        uint8_t *buffer = malloc(len);
        connexion_read(buffer, len);

        // DEBUG : Afficher le message reçu pour débogage
        TRACE("COM | thread_read_fct : ID : %02X | PAYLOAD : ", msg->id);
        for (size_t i = 0; i < len; ++i) {
            TRACE("%02X ", buffer[i]);
        }
        TRACE("\n");

        protocole_decode(msg, buffer, len);

        // DEBUG : Afficher le message reçu pour débogage
        TRACE("COM | thread_read_fct : ID : %d | PAYLOAD 0 : %d\n", msg->id, msg->payload[0]);

        // // Libérer le buffer et msg
        free(buffer);
        free(msg);

        usleep(200);
    }
    return NULL;
}


