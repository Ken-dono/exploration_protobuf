/**
 * @file protocole.h
 * @brief Fichier d'en-tête pour la gestion du protocole de communication.
 *
 * Ce fichier contient les déclarations des fonctions pour encoder, décoder et 
 * gérer les messages en fonction de leur structure et type.
 */

// Gestion des TRACE -----------------------
#ifdef DEBUG
#define TRACE(...) printf(__VA_ARGS__)
#else
#define TRACE(...)
#endif
//-----------------------------------------

#ifndef C_PROTOCOLE_H
#define C_PROTOCOLE_H

#define MAX_MSG_SIZE 27
#define MAX_MESSAGES 200
#define SERVER_PORT 12345
#define MAX_CONNEXIONS_EN_ATTENTE 5

#include <sys/types.h>
#include <inttypes.h>
#include "../proto/fichier.pb-c.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Encode un message en fonction de son ID et le prépare pour la transmission.
 * 
 * Cette fonction prend un message, le sérialise et le prépare pour la transmission
 * sur le réseau.
 * 
 * @param message Pointeur vers le message à encoder.
 * @param buffer Pointeur vers le tampon où le message encodé sera stocké.
 * @param len Pointeur vers la taille du message encodé.
 */
void protocole_code(message_t * message, uint8_t ** buffer, size_t *len);

/**
 * @brief Décodage d'un message reçu pour le traitement.
 * 
 * Cette fonction prend un message encodé, le désérialise et le prépare pour
 * le traitement.
 * 
 * @param message Pointeur vers le message à décoder.
 * @param buffer Tampon contenant le message encodé.
 * @param len Longueur du tampon contenant le message encodé.
 */
void protocole_decode(message_t *message, uint8_t *buffer, size_t len);

/**
 * @brief Libère la mémoire allouée pour un tampon de message.
 * 
 * @param buffer Pointeur vers le tampon à libérer.
 */
void protocole_free(uint8_t * buffer);

#endif //C_PROTOCOLE_H