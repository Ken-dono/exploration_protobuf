#include <stdio.h>
#include <stdlib.h>
#include "com/com.h"

int main() {
    // Initialise la connexion
    com_init();

    sleep(2);

    printf("Entrez l'ID du message ou 'q' pour quitter:\n");
    printf("04 - Battery Level\n");
    printf("06 - Status Explo\n");
    printf("08 - Position\n");

    char input[10];
    while (1) {
        sleep(2);
        printf("ID du message > ");
        scanf("%s", input);

        if (input[0] == 'q') {
            break;
        }

        if (strcmp(input, "04") == 0) {
            // Exemple d'envoi de message : battery_level 70%
            message_t battery_level;
            battery_level.dlc = 0x02;
            battery_level.id = 0X04;
            battery_level.payload[0] = 70;
            com_send_message(&battery_level);
        } else if (strcmp(input, "06") == 0) {
            // Exemple d'envoi de message : status_explo 20% 450s
            message_t status_explo;
            status_explo.dlc = 0x02;
            status_explo.id = 0X06;
            status_explo.payload[0] = 0xFF;
            status_explo.payload[1] = 20;
            status_explo.payload[2] = 450;
            com_send_message(&status_explo);
        } else if (strcmp(input, "08") == 0) {
            // Exemple d'envoi de message : position 150mm 2000mm
            message_t position;
            position.dlc = 0x02;
            position.id = 0X08;
            position.payload[0] = 150;
            position.payload[1] = 2000;
            com_send_message(&position);
        } else {
            printf("ID invalide.\n");
        }
    }

    com_stop();
    com_free();
    printf("Fin du programme.\n");
    return EXIT_SUCCESS;
}