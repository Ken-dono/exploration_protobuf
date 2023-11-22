//
// Created by buryhugo on 02/06/23.
//

#include "protocole.h"
#include "string.h"

void protocole_code(message_t * message, uint8_t ** buffer, size_t * len)
{
    switch (message->id) {
        case 0x04: {
            // Création d'un objet Message
            BatteryLevel battery_level = BATTERY_LEVEL__INIT; 
            // Assignation d'un message
            battery_level.level = message->payload[0];
            // Sérialisation du message
            *len = battery_level__get_packed_size(&battery_level);
            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
            battery_level__pack(&battery_level, *buffer);
            break;
        }
        case 0x06: {
            StatusExplo status_explo = STATUS_EXPLO__INIT; 
            status_explo.status = message->payload[0];
            status_explo.pourcentage = message->payload[1];
            status_explo.temps = message->payload[2];
            *len = status_explo__get_packed_size(&status_explo);
            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            
            }
            status_explo__pack(&status_explo, *buffer);
            break;
        }
        case 0x08: {
            Position position = POSITION__INIT; 
            position.x = message->payload[0];
            position.y = message->payload[1];
            *len = position__get_packed_size(&position);
            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            
            }
            position__pack(&position, *buffer);
            break;
        }
        default : {
            fprintf(stderr, "ID non pris en charge\n");
            break;
        }
    }
}

void protocole_free(uint8_t * buffer){
    free(buffer);
}