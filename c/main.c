#include <stdio.h>
#include <stdlib.h>
#include "com/com.h"

int main() {
    // Initialise la connexion
    com_init();

    // Exemple d'envoi de message : message batterie 20%
    message_t msg_battery_lvl;
    msg_battery_lvl.dlc = 0x02;
    msg_battery_lvl.id = 0X04;
    msg_battery_lvl.payload[0] = 20;
    com_send_message(&msg_battery_lvl);
    
    // Boucle d'execution avec interruption
    printf("Appuyez sur 'q' pour quitter.\n");

    int ch;
    while ((ch = getchar()) != 'q') {}
    
    com_free();
    printf("Fin du programme.\n");
    return EXIT_SUCCESS;
}