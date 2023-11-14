#include <stdio.h>
#include <stdlib.h>
#include "fichier.pb-c.h"

int main() {
    // Création d'un objet Message
    Message msg = MESSAGE__INIT; 
    void *buf; // Buffer pour stocker les données sérialisées
    unsigned len; // Longueur des données sérialisées

    // Assignation d'un message
    msg.text = "M_EMB : Ceci est un test de packetage et dépackettage.";

    // Sérialisation du message
    len = message__get_packed_size(&msg);
    buf = malloc(len);
    message__pack(&msg, buf);

    fprintf(stderr, "Writing %d serialized bytes\n", len); // Debug: affichage de la taille du message sérialisé

    // Ici, buf pourrait être écrit dans un fichier ou envoyé sur un réseau...

    

    // Désérialisation du message
    Message *msg_in;
    msg_in = message__unpack(NULL, len, buf);
    if (msg_in == NULL) {
        fprintf(stderr, "error unpacking incoming message\n");
        exit(1);
    }

    // Utilisation du message désérialisé
    printf("Received: %s\n", msg_in->text);

    // Libération du message désérialisé
    message__free_unpacked(msg_in, NULL);

    // Nettoyage
    free(buf);
    return 0;
}
