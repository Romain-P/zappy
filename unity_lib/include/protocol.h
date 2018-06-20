//
// Created by romain on 08/06/18.
//

#ifndef ZAPPY_PROTOCOL_H
#define ZAPPY_PROTOCOL_H

#include <stdint.h>
#include <sys/types.h>
#include "zappy_network.h"
#include "network.h"

# define ZAPPY_BUFFER_SIZE        (512)
# define ZAPPY_ARG_DELIMITER   ("\r\n")
# define ZAPPY_PARAM_SEPARATOR    (" ")

typedef struct command_s message_t;

typedef bool (*handler_t)(session_t client, void *msg);
typedef void (*serialize_t)(void *msg, list_t *buffer);
typedef void *(*deserialize_t)(char **args);

struct command_s {
    char const *named;
    serialize_t serialize;
    deserialize_t deserialize;
    handler_t *handler;
};

//PACKET MSZ
packet_msz_t *deserialize_msz(char **args);
void serialize_msz(packet_msz_t *msg, list_t *buffer);

//PACKET BCT
packet_bct_tile_t *deserialize_bct(char **args);
void serialize_bct(packet_bct_tile_t *msg, list_t *buffer);

//PACKET TNA
packet_tna_t *deserialize_tna(char **args);
void serialize_tna(packet_tna_t *packet, list_t *buffer);