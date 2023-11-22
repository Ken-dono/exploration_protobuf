#include <stdio.h>
#include <stdlib.h>
#include "com/com.h"

int main() {
    // Initialise la connexion
    com_init();

    // Exemple d'envoi de message : battery_level 70%
    message_t battery_level;
    battery_level.dlc = 0x02;
    battery_level.id = 0X04;
    battery_level.payload[0] = 70;
    com_send_message(&battery_level);

    // Exemple d'envoi de message : status_explo 20% 450s
    message_t status_explo;
    status_explo.dlc = 0x02;
    status_explo.id = 0X06;
    status_explo.payload[0] = 0xFF;
    status_explo.payload[1] = 20;
    status_explo.payload[2] = 450;
    com_send_message(&status_explo);

    // Exemple d'envoi de message : position 150mm 2000mm
    message_t position;
    position.dlc = 0x02;
    position.id = 0X08;
    position.payload[0] = 150;
    position.payload[1] = 2000;
    com_send_message(&position);

    // Boucle d'execution avec interruption
    printf("Appuyez sur 'q' pour quitter.\n");

    int ch;
    while ((ch = getchar()) != 'q') {}

    com_stop();
    com_free();
    printf("Fin du programme.\n");
    return EXIT_SUCCESS;
}