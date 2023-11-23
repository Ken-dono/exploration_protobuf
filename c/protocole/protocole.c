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

void protocole_decode(message_t *message, uint8_t *buffer, size_t len){
    printf("PROTOCOLE | protocole_decode : size_received : %02lX | id_received : %02X\n", len, message->id);
    switch (message->id) {
        case 0x01: {
            printf("PROTOCOLE | protocole_decode | case -> 0x01 | size_received : %02lX | id_received : %02X\n", len, message->id);
            // Désérialisation du message
            ArretUrgence *arret_urgence_in = arret_urgence__unpack(NULL, len, buffer);
            if (arret_urgence_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            // Mise à jour du payload du message
            message->id = message->id;
            message->payload[0] = arret_urgence_in->state;
            printf("PROTOCOLE | protocole_decode | case -> 0x01 | deser_id : %02X | deser_state : %02X\n", message->id, message->payload[0]);
            // Libération du message désérialisé
            arret_urgence__free_unpacked(arret_urgence_in, NULL);
            break;
        }
        case 0x03: {
            StopMarco *stop_marco_in = stop_marco__unpack(NULL, len, buffer);
            if (stop_marco_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            message->payload[0] = stop_marco_in->state;
            stop_marco__free_unpacked(stop_marco_in, NULL);
            break;
        }
        case 0x05: {
            DeplacementManuel *deplacement_manuel_in = deplacement_manuel__unpack(NULL, len, buffer);
            if (deplacement_manuel_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            message->payload[0] = deplacement_manuel_in->direction;
            message->payload[1] = deplacement_manuel_in->speed;
            deplacement_manuel__free_unpacked(deplacement_manuel_in, NULL);
            break;
        }
        case 0x07: {
            SetExploAlgo *set_explo_algo_in = set_explo_algo__unpack(NULL, len, buffer);
            if (set_explo_algo_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            message->payload[0] = set_explo_algo_in->algo;
            set_explo_algo__free_unpacked(set_explo_algo_in, NULL);
            break;
        }
        case 0x09: {
            SetExploParam *set_explo_param_in = set_explo_param__unpack(NULL, len, buffer);
            if (set_explo_param_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du message reçu\n");
                exit(EXIT_FAILURE);
            }
            message->payload[0] = set_explo_param_in->type;
            message->payload[1] = set_explo_param_in->isenable;
            message->payload[2] = set_explo_param_in->value;
            set_explo_param__free_unpacked(set_explo_param_in, NULL);
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