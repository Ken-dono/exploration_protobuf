//
// Created by buryhugo on 02/06/23.
//

#include "protocole.h"
#include "string.h"

void protocole_code(message_t * message, uint8_t *buffer)
{
    // Création d'un objet Message
    BatteryLevel batteryLevel = BATTERY_LEVEL__INIT; 

    // Assignation d'un message
    batteryLevel.id = message->id;
    batteryLevel.level = message->payload[0];

    // Sérialisation du message
    size_t len = battery_level__get_packed_size(&batteryLevel);
    buffer = malloc(len);
    if (buffer == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return;
    }
    battery_level__pack(&batteryLevel, buffer);
}

// void protocole_decode(message_t * message, uint8_t *buf, size_t * len){

//     // Désérialisation du message pour vérification ou autre usage
//     Message *msg_in;
//     msg_in = message__unpack(NULL, len, buf);
//     if (msg_in == NULL) {
//         fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
//         free(buf);
//         return EXIT_FAILURE;
//     }

//     printf("Received: %s\n", msg_in->text);

//     // Libération du message désérialisé
//     message__free_unpacked(msg_in, NULL);

//     // Nettoyage
//     free(buf);
// }