//
// Created by buryhugo on 02/06/23.
//

#include "protocole.h"
#include "string.h"

void protocole_code(message_t * message, uint8_t ** buffer, size_t * len)
{
    // Création d'un objet Message
    BatteryLevel batteryLevel = BATTERY_LEVEL__INIT; 

    // Assignation d'un message
    batteryLevel.id = message->id;
    batteryLevel.level = message->payload[0];

    // Sérialisation du message
    *len = battery_level__get_packed_size(&batteryLevel);

     *buffer = malloc(*len);
    if (*buffer == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    battery_level__pack(&batteryLevel, *buffer);
}

void protocole_free(uint8_t * buffer){
    free(buffer);
}