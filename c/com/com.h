//
// Created by buryhugo on 02/06/23.
//

#ifndef C_COM_H
#define C_COM_H
#include <inttypes.h>
#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>

#include "../protocole/protocole.h"

/**
 * Init connection with M_CTRL
 */
void com_init();

void com_free();

/**
 * Send a message to M_CTRL
 * @param msg   The message to send
 */
void com_send_message(message_t *msg);

/**
 * Start threads
 */
void com_stop();

/**
 * Stop threads
 */
void com_stop();



#endif //C_COM_H
