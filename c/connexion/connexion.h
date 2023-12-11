//
// Created by buryhugo on 02/06/23.
//

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
 * Init connexion with M_CTRL
 */
void connexion_init();

/**
 * Close connexion with M_CTRL
 */
void connexion_close();

/**
 * Wait for M_CTRL connexion
 * @return the socket number used by M_CTRL
 */
int connexion_accept();

/**
 * Read message from received on a specific socket
 * @param buffer        the variable used to store the reveived message
 * @param length        the size of the buffer
 * @return              the buffer filled with the message
 */
ssize_t connexion_read(uint8_t *buffer, size_t length) ;

/**
 * Write a message on a specific socket
 * @param data          the data to send
 * @param length        the size of the data
 * @return              the number of written bytes
 */
ssize_t connexion_write(const uint8_t* data, size_t length);

#endif //C_CONNEXION_H
