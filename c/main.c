#include <stdio.h>
#include <stdlib.h>
#include "com.h"
#include "fichier.pb-c.h"

int main() {
    // Initialise la connexion (remplacer par le port réel utilisé par votre application)
    connexion_init(12345);

    // Attend une connexion entrante
    int socket_client = connexion_accept();
    if (socket_client == -1) {
        fprintf(stderr, "Erreur lors de l'acceptation de la connexion client.\n");
        return EXIT_FAILURE;
    }

    // Création d'un objet Message
    Message msg = MESSAGE__INIT; 
    uint8_t *buf; // Buffer pour stocker les données sérialisées
    unsigned len; // Longueur des données sérialisées

    // Assignation d'un message
    msg.text = "M_EMB : Ceci est un test de packetage et dépackettage.";

    // Sérialisation du message
    len = message__get_packed_size(&msg);
    buf = malloc(len);
    if (buf == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return EXIT_FAILURE;
    }
    message__pack(&msg, buf);

    fprintf(stderr, "Writing %d serialized bytes\n", len); // Debug: affichage de la taille du message sérialisé

    // Envoi du message sérialisé sur la socket
    if (connexion_write(buf, len) == -1) {
        perror("Erreur lors de l'envoi du message");
        free(buf);
        return EXIT_FAILURE;
    }

    printf("Message sent to server\n");

    // Désérialisation du message pour vérification ou autre usage
    // Message *msg_in;
    // msg_in = message__unpack(NULL, len, buf);
    // if (msg_in == NULL) {
    //     fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
    //     free(buf);
    //     return EXIT_FAILURE;
    // }

    // printf("Received: %s\n", msg_in->text);

    // Libération du message désérialisé
    // message__free_unpacked(msg_in, NULL);

    // Nettoyage
    // free(buf);
    return EXIT_SUCCESS;
}
