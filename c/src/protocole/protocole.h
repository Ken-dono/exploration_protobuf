/**
 * @file protocole.h
 * @brief Fichier d'en-tête pour la gestion du protocole de communication.
 *
 * Ce fichier contient les déclarations des fonctions pour encoder, décoder et 
 * gérer les messages en fonction de leur structure et type.
 */

// Gestion des TRACE -----------------------
/**
 * @def TRACE(...)
 * @brief Macro pour la sortie de débogage conditionnelle.
 *
 * Cette macro permet l'affichage de messages de débogage si le mode DEBUG est activé.
 * Elle ne fait rien en mode de production (lorsque DEBUG n'est pas défini).
 */
#ifdef DEBUG
#define TRACE(...) printf(__VA_ARGS__)
#else
#define TRACE(...)
#endif

#ifndef C_PROTOCOLE_H
#define C_PROTOCOLE_H

/**
 * @def MAX_MSG_SIZE
 * @brief Taille maximale d'un message en octets.
 */
#define MAX_MSG_SIZE 27

/**
 * @def MAX_MESSAGES
 * @brief Nombre maximal de messages dans la file d'attente.
 */
#define MAX_MESSAGES 200

/**
 * @def SERVER_PORT
 * @brief Numéro de port sur lequel le serveur écoute.
 */
#define SERVER_PORT 12345

/**
 * @def MAX_CONNEXIONS_EN_ATTENTE
 * @brief Nombre maximal de connexions en attente sur le socket d'écoute.
 */
#define MAX_CONNEXIONS_EN_ATTENTE 5

#include <sys/types.h>
#include <inttypes.h>
#include "../proto/fichier.pb-c.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Structure représentant un message d'arrêt d'urgence de M_CTRL vers M_EMB.
 * 
 * Cette structure contient les informations nécessaires pour un message
 * d'arrêt d'urgence, y compris la taille du message (DLC), l'identifiant du message
 * et les données de charge utile.
 */
typedef struct
{
    uint8_t dlc; /**< Taille du message */
    uint32_t id; /**< Identifiant du message */
    uint32_t payload[MAX_MSG_SIZE]; /**< Données de la charge utile du message */
} message_t;

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