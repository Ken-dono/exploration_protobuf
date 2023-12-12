/**
 * @file connexion.h
 * @brief Ce fichier contient les déclarations des fonctions pour la gestion des connexions réseau.
 */

//Gestion des TRACE -----------------------
#ifdef DEBUG
#define TRACE(...) printf(__VA_ARGS__)
#else
#define TRACE(...)
#endif
//-----------------------------------------

#ifndef C_CONNEXION_H
#define C_CONNEXION_H

#include <sys/types.h>
#include <inttypes.h>
#include <stdint.h>

#include "../protocole/protocole.h"

/**
 * @brief Initialisation du serveur pour écouter sur un port spécifié.
 */
void connexion_init();

/**
 * @brief Ferme la connexion sur la socket spécifiée.
 */
void connexion_close();

/**
 * @brief Accepte une connexion entrante sur la socket du serveur.
 *
 * @return Un descripteur de fichier pour la socket connectée.
 */
int connexion_accept();

/**
 * @brief Lit des données sur la socket spécifiée.
 *
 * @param buffer Buffer pour stocker les données lues.
 * @param length Taille maximale des données à lire.
 * @return Le nombre d'octets lus.
 */
ssize_t connexion_read(uint8_t *buffer, size_t length) ;

/**
 * @brief Écrit des données sur la socket spécifiée.
 *
 * @param data Données à écrire.
 * @param length Taille des données à écrire.
 * @return Le nombre d'octets écrits.
 */
ssize_t connexion_write(const uint8_t* data, size_t length);

#endif //C_CONNEXION_H
