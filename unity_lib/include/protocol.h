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

//PACKET PNW
packet_pnw_t *deserialize_pnw(char **args);

//PACKET PPO
packet_ppo_t *deserialize_ppo(char **args);
void serialize_ppo(packet_ppo_t *msg, list_t *buffer);

//PACKET PLV
packet_plv_t *deserialize_plv(char **args);
void serialize_plv(packet_plv_t *msg, list_t *buffer);

//PACKET PIN
packet_pin_t *deserialize_pin(char **args);
void serialize_pin(packet_pin_t *msg, list_t *buffer);

//PACKET PEX
packet_pex_t *deserialize_pex(char **args);

//PACKET PBC
packet_pbc_t *deserialize_pbc(char **args);

//PACKET PIE
packet_pie_t *deserialize_pie(char **args);

//PACKET PFK
packet_pfk_t *deserialize_pfk(char **args);

//PACKET PDR
packet_pdr_t *deserialize_pdr(char **args);

//PACKET PGT
packet_pgt_t *deserialize_pgt(char **args);

//PACKET PDI
packet_pdi_t *deserialize_pdi(char **args);
