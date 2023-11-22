//
// Created by buryhugo on 02/06/23.
//

#include "protocole.h"
#include "string.h"

void protocole_code(message_t * message, uint8_t ** buffer, size_t * len)
{
    switch (message->id) {
        case 0x01: {
            // Création d'un objet Message
            ArretUrgence arret_urgence = ARRET_URGENCE__INIT; 

            // Assignation d'un message
            arret_urgence.state = message->payload[0];

            // Sérialisation du message
            *len = arret_urgence__get_packed_size(&arret_urgence);

            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
            arret_urgence__pack(&arret_urgence, *buffer);
            break;
        }
        case 0x03: {
            StopMarco stop_marco = STOP_MARCO__INIT; 
            stop_marco.state = message->payload[0];
            *len = stop_marco__get_packed_size(&stop_marco);
            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
            stop_marco__pack(&stop_marco, *buffer);
            break;
        }
        case 0x04: {
            BatteryLevel batteryLevel = BATTERY_LEVEL__INIT; 
            batteryLevel.level = message->payload[0];
            *len = battery_level__get_packed_size(&batteryLevel);
            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
            battery_level__pack(&batteryLevel, *buffer);
            break;
        }
        case 0x05: {
            DeplacementManuel deplacement_manuel = DEPLACEMENT_MANUEL__INIT; 
            deplacement_manuel.direction = message->payload[0];
            deplacement_manuel.speed = message->payload[1];
            *len = deplacement_manuel__get_packed_size(&deplacement_manuel);
            *buffer = malloc(*len);
            if (*buffer == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
                exit(EXIT_FAILURE);
            
            }
            deplacement_manuel__pack(&deplacement_manuel, *buffer);
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