//
// Created by buryhugo on 02/06/23.
//

#include "protocole.h"
#include "string.h"

void protocole_code(message_t * message, uint8_t ** buffer, size_t *len)
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
    MessageType message_type = MESSAGE_TYPE__INIT;
    message_type.id = message->id;
    message_type.payload.len = *len;
    message_type.payload.data = *buffer;
    *len = message_type__get_packed_size(&message_type);
    *buffer = malloc(*len);
    if (*buffer == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    
    }
    message_type__pack(&message_type, *buffer);
}


void protocole_decode(message_t *message, uint8_t *buffer, size_t len){
    TRACE("PROTOCOLE | protocole_decode : size_received : %02lX\n", len);

    // Désérialisation du MessageType
    MessageType *message_type_in = message_type__unpack(NULL, len, buffer);
    if (message_type_in == NULL) {
        fprintf(stderr, "Erreur lors de la désérialisation du MessageType\n");
        exit(EXIT_FAILURE);
    }
    switch (message_type_in->id) {
        case 0x01: {
            // Désérialisation du ArretUrgence
            ArretUrgence *arret_urgence_in = arret_urgence__unpack(NULL, message_type_in->payload.len, message_type_in->payload.data);
            if (arret_urgence_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du ArretUrgence reçu\n");
                exit(EXIT_FAILURE);
            }
            // Mise à jour du message
            message->id = message_type_in->id;
            message->payload[0] = arret_urgence_in->state;
            TRACE("PROTOCOLE | protocole_decode | case -> 0x01 | deser_id : %d | deser_state : %d\n", message->id, message->payload[0]);
            // Libération du ArretUrgence désérialisé
            arret_urgence__free_unpacked(arret_urgence_in, NULL);
            break;
        }
        case 0x03: {
            // Désérialisation du StopMarco
            StopMarco *stop_marco_in = stop_marco__unpack(NULL, message_type_in->payload.len, message_type_in->payload.data);
            if (stop_marco_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du StopMarco reçu\n");
                exit(EXIT_FAILURE);
            }
            // Mise à jour du message
            message->id = message_type_in->id;
            message->payload[0] = stop_marco_in->state;
            TRACE("PROTOCOLE | protocole_decode | case -> 0x03 | deser_id : %d | deser_state : %d\n", message->id, message->payload[0]);
            // Libération du StopMarco désérialisé
            stop_marco__free_unpacked(stop_marco_in, NULL);
            break;
        }
        case 0x05: {
            // Désérialisation du DeplacementManuel
            DeplacementManuel *deplacement_manuel_in = deplacement_manuel__unpack(NULL, message_type_in->payload.len, message_type_in->payload.data);
            if (deplacement_manuel_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du DeplacementManuel reçu\n");
                exit(EXIT_FAILURE);
            }
            // Mise à jour du message
            message->id = message_type_in->id;
            message->payload[0] = deplacement_manuel_in->direction;
            message->payload[1] = deplacement_manuel_in->speed;
            TRACE("PROTOCOLE | protocole_decode | case -> 0x05 | deser_id : %d | deser_direction : %d | deser_speed : %d\n", message->id, message->payload[0], message->payload[1]);
            // Libération du DeplacementManuel désérialisé
            deplacement_manuel__free_unpacked(deplacement_manuel_in, NULL);
            break;
        }
        case 0x07: {
            // Désérialisation du SetExploAlgo
            SetExploAlgo *set_explo_algo_in = set_explo_algo__unpack(NULL, message_type_in->payload.len, message_type_in->payload.data);
            if (set_explo_algo_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du SetExploAlgo reçu\n");
                exit(EXIT_FAILURE);
            }
            // Mise à jour du message
            message->id = message_type_in->id;
            message->payload[0] = set_explo_algo_in->algo;
            TRACE("PROTOCOLE | protocole_decode | case -> 0x07 | deser_id : %d | deser_algo : %d\n", message->id, message->payload[0]);
            // Libération du SetExploAlgo désérialisé
            set_explo_algo__free_unpacked(set_explo_algo_in, NULL);
            break;
        }
        case 0x09: {
            // Désérialisation du SetExploParam
            SetExploParam *set_explo_param_in = set_explo_param__unpack(NULL, message_type_in->payload.len, message_type_in->payload.data);
            if (set_explo_param_in == NULL) {
                fprintf(stderr, "Erreur lors de la désérialisation du SetExploParam reçu\n");
                exit(EXIT_FAILURE);
            }
            // Mise à jour du message
            message->id = message_type_in->id;
            message->payload[0] = set_explo_param_in->type;
            message->payload[1] = set_explo_param_in->isenable;
            message->payload[2] = set_explo_param_in->value;
            TRACE("PROTOCOLE | protocole_decode | case -> 0x09 | deser_id : %d | deser_type : %d | deser_isenable : %d | deser_value : %d\n", message->id, message->payload[0], message->payload[1], message->payload[2]);
            // Libération du SetExploParam désérialisé
            set_explo_param__free_unpacked(set_explo_param_in, NULL);
            break;
        }
        default : {
            fprintf(stderr, "ID non pris en charge\n");
            break;
        }
    }
    // Libération du MessageType désérialisé
    message_type__free_unpacked(message_type_in, NULL);
}

void protocole_free(uint8_t * buffer){
    free(buffer);
}