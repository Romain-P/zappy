//
// Created by romain on 08/06/18.
//

#ifndef ZAPPY_PROTOCOL_H
#define ZAPPY_PROTOCOL_H

#include <stdint.h>
#include <sys/types.h>
#include "zappy_network.h"
#include "network.h"

# define ZAPPY_BUFFER_SIZE        (2048)
# define ZAPPY_PACKET_DELIMITER   ("\n")
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

packet_example_t *msg_example_deserialize(char **args);
void msg_example_serialize(packet_example_t *msg, list_t *buffer);

// FORWARD COMMAND
packet_forward_t *forward_deserialize(char **);
void forward_serialize(packet_forward_t *, list_t *);

// TURN COMMAND
packet_turn_t *turn_deserialize(char **);
void turn_serialize(packet_turn_t *, list_t *);

// IVENTORY COMMAND
packet_inventory_t *inventory_deserialize(char **);
void inventory_serialize(packet_inventory_t *, list_t *);

// MSZ COMMAND
packet_msz_t *msz_deserialize(char **);
void msz_serialize(packet_msz_t *, list_t *);

// BCT COMMAND (One Tile)
packet_bct_tile_t *bct_tile_deserialize(char **);
void bct_tile_serialize(packet_bct_tile_t *, list_t *);
void init_bct_tile_packet(packet_bct_tile_t *packet);
void get_ressource_tile(size_t, packet_bct_tile_t *);

// BCT COMMAND (All Tile)
packet_bct_tile_t *bct_all_deserialize(char **);
void bct_all_serialize(packet_bct_tile_t *, list_t *);

// TNA COMMAND
packet_tna_t *tna_deserialize(char **);
void tna_serialize(packet_tna_t *, list_t *);

// PNW COMMAND
void pnw_serialize(packet_pnw_t *, list_t *);

// PPO COMMAND
packet_ppo_t *ppo_deserialize(char **);
void ppo_serialize(packet_ppo_t *, list_t *);

// PLV COMMAND
packet_plv_t *plv_deserialize(char **);
void plv_serialize(packet_plv_t *, list_t *);

// PIN COMMAND
packet_pin_t *pin_deserialize(char **);
void pin_serialize(packet_pin_t *, list_t *);

// PEX COMMAND
void pex_serialize(packet_pex_t *, list_t *);

// PBC COMMAND
void pbc_serialize(packet_pbc_t *, list_t *);

// PIC COMMAND
void pic_serialize(packet_pic_t *, list_t *);

// PIE COMMAND
void pie_serialize(packet_pie_t *, list_t *);

// PFK COMMAND
void pfk_serialize(packet_pfk_t *, list_t *);

// PDR COMMAND
void pdr_serialize(packet_pdr_t *, list_t *);

// PGT COMMAND
void pgt_serialize(packet_pgt_t *, list_t *);

// PDI COMMAND
void pdi_serialize(packet_pdi_t *, list_t *);

// ENW COMMAND
void enw_serialize(packet_enw_t *, list_t *);

// EHT COMMAND
void eht_serialize(packet_eht_t *, list_t *);

// EBO COMMAND
void ebo_serialize(packet_ebo_t *, list_t *);

// EDI COMMAND
void edi_serialize(packet_edi_t *, list_t *);

// SGT COMMAND
void sgt_serialize(packet_sgt_t *, list_t *);
packet_sgt_t *sgt_deserialize(char **);

// TEAM COMMAND
void team_serialize(packet_team_t *, list_t *);
packet_team_t *team_deserialize(char **);

// SST COMMAND
void sst_serialize(packet_sst_t *, list_t *);
packet_sst_t *sst_deserialize(char **);

// SEG COMMAND
void seg_serialize(packet_seg_t *, list_t *);

// SMG COMMAND
void smg_serialize(packet_smg_t *, list_t *);

// SUC COMMAND
void suc_serialize(packet_suc_t *, list_t *);

// SBP COMMAND
void sbp_serialize(packet_sbp_t *, list_t *);

#endif //ZAPPY_PROTOCOL_H
