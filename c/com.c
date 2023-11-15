//
// Created by buryhugo on 02/06/23.
//
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

#include "com.h"

/* Socket de connexion au serveur. */
static int socket_serveur;
static int socket_client;

void connexion_init(int server_port){

    struct sockaddr_in socket_serveur_config;

    /* Creation du socket : AF_INET = IP, SOCK_STREAM = TCP */
    socket_serveur = socket(AF_INET, SOCK_STREAM, 0);

    /* Cree le socket meme si des connexions TIME_WAIT sont encore actives suite e de precedentes connexions. */
    int yes = 1;
    setsockopt(socket_serveur, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    /* Configutation du socket (pour l'OS). */
    // Type d'adresse : AF_INET = IP.
    socket_serveur_config.sin_family = AF_INET;

    // Port TCP oe le service est accessible.
    socket_serveur_config.sin_port = htons(server_port);

    // Attachement e toutes les interfaces reseaux.
    socket_serveur_config.sin_addr.s_addr = htonl(INADDR_ANY);

    /* Attache le socket au port et aux interfaces configures. */
    // TODO : Gérer les messages derreurs de bind
    bind(socket_serveur, (struct sockaddr *)&socket_serveur_config, sizeof(struct sockaddr_in));

    /* Mise en ecoute du socket. */
    listen(socket_serveur, MAX_CONNEXIONS_EN_ATTENTE);
    printf("COM | connexion_init : socket ouverte sur le port : %d\n", server_port);
}

int connexion_accept(){
    socket_client = accept(socket_serveur, NULL, NULL);
    if (socket_client == 1) {
        perror("COM | connexion_accept : Erreur lors de l'acceptation de la connexion entrante\n\n");
    } else
        printf("COM | connexion_accept : Client connecté sur la socket : %d\n", socket_client);

    return socket_client;
}

ssize_t connexion_read(uint8_t *buffer, size_t length) {
    ssize_t bytes_read;

    bytes_read = read(socket_client, buffer, length);
    if (bytes_read < 0) {
        perror("COM | connexion_read : Erreur lors de la lecture depuis la socket\n");
        return -1;
    } else if (bytes_read == 0) {
        printf("COM | connexion_read : La connexion a été fermée par le client\n");
        connexion_accept();
    }

    return bytes_read;
}

ssize_t connexion_write(const uint8_t* data, size_t length) {
    ssize_t num_written = write(socket_client, data, length);
    if (num_written < 0) {
        perror("COM | connexion_write : Erreur lors de l'écriture vers la socket");
    }
    return num_written;
}



