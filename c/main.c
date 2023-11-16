#include <stdio.h>
#include <stdlib.h>
#include "connexion/connexion.h"
#include "com/com.h"
#include "proto/fichier.pb-c.h"
#include "protocole/protocole.h"


int main() {
    // Initialise la connexion (remplacer par le port réel utilisé par votre application)
    com_init();


    // Exemple d'envoi de message : message batterie 20%
    message_t msg_battery_lvl;
    msg_battery_lvl.id = 0X04;
    msg_battery_lvl.dlc = 0x02;
    msg_battery_lvl.payload[0] = 20;
    com_send_message(&msg_battery_lvl);
    // Boucle d'execution de l'exploration
    while (1){

    }


    //fprintf(stderr, "Writing %d serialized bytes\n", len); // Debug: affichage de la taille du message sérialisé

    // Envoi du message sérialisé sur la socket
    // if (connexion_write(buf, len) == -1) {
    //     perror("Erreur lors de l'envoi du message");
    //     free(buf);
    //     return EXIT_FAILURE;
    // }

    // printf("Message sent to server\n");

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
