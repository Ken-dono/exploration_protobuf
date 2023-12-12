/**
 * @file com.h
 * @brief Interface pour la gestion de la communication entre serveur et client.
 *
 * Ce fichier définit les structures et prototypes nécessaires pour la gestion 
 * de la communication réseau entre un serveur et un client.
 */

#ifndef C_COM_H
#define C_COM_H

//Gestion des TRACE -----------------------
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


#include "../protocole/protocole.h"

/**
 * @brief Initialise la file de messages pour l'écriture.
 * 
 * Crée et configure la file de messages.
 */
void com_init();

/**
 * @brief Libère les ressources utilisées par le système de communication.
 * 
 * Ferme la file de messages et la supprime.
 */
void com_free();

/**
 * @brief Démarre le système de communication.
 * 
 * Initialise la connexion et lance les threads de lecture et d'écriture.
 */
void com_start();

/**
 * @brief Arrête le système de communication.
 * 
 * Envoie un message d'arrêt, ferme la connexion et les threads.
 */
void com_stop();

/**
 * @brief Envoie un message à travers la file de messages.
 * @param message Le message à envoyer.
 */
void com_send_message(message_t * message);

#endif //C_COM_H