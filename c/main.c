#include <stdio.h>
#include <stdlib.h>
#include "com/com.h"

int main() {
    // Initialise la connexion
    com_init();

    // Exemple d'envoi de message : message batterie 20%
    message_t deplacement_manuel;
    deplacement_manuel.id = 0X05;
    deplacement_manuel.payload[0] = 0xFF;
    deplacement_manuel.payload[1] = 100;
    com_send_message(&deplacement_manuel);

    // Boucle d'execution avec interruption
    printf("Appuyez sur 'q' pour quitter.\n");

    int ch;
    while ((ch = getchar()) != 'q') {}

    com_stop();
    com_free();
    printf("Fin du programme.\n");
    return EXIT_SUCCESS;
}