//
// Created by romain on 08/06/18.
//

#ifndef ZAPPY_PROTOCOL_H
#define ZAPPY_PROTOCOL_H

#include "zappy.h"

typedef struct packet_example_s packet_example_t;
typedef struct packet_msz_s packet_msz_t;
typedef struct packet_bct_tile_s packet_bct_tile_t;
typedef struct packet_tna_s packet_tna_t;
typedef struct packet_pnw_s packet_pnw_t;
typedef struct packet_ppo_s packet_ppo_t;
typedef struct packet_plv_s packet_plv_t;
typedef struct packet_pin_s packet_pin_t;
typedef struct packet_pex_s packet_pex_t;
typedef struct packet_pbc_s packet_pbc_t;
typedef struct packet_pic_s packet_pic_t;
typedef struct packet_pie_s packet_pie_t;
typedef struct packet_pfk_s packet_pfk_t;
typedef struct packet_pdr_s packet_pdr_t;
typedef struct packet_pgt_s packet_pgt_t;
typedef struct packet_pdi_s packet_pdi_t;
typedef struct packet_enw_s packet_enw_t;
typedef struct packet_eht_s packet_eht_t;
typedef struct packet_ebo_s packet_ebo_t;
typedef struct packet_edi_s packet_edi_t;
typedef struct packet_sgt_s packet_sgt_t;
typedef struct packet_sst_s packet_sst_t;
typedef struct packet_seg_s packet_seg_t;
typedef struct packet_smg_s packet_smg_t;
typedef struct packet_suc_s packet_suc_t;
typedef struct packet_sbp_s packet_sbp_t;

struct packet_example_s {
    int64_t some;
    char str[100];
    int64_t shiet;
};

struct packet_msz_s {
    size_t x;
    size_t y;
};

struct packet_bct_tile_s {
    size_t x;
    size_t y;
    size_t q0;
    size_t q1;
    size_t q2;
    size_t q3;
    size_t q4;
    size_t q5;
    size_t q6;
};

struct packet_tna_s {
    char name[1024];
};

struct packet_pnw_s {
    char player_number[42];
    size_t x;
    size_t y;
    size_t orientation;
    size_t level;
    char name_team[1024];
};

struct packet_ppo_s {
    size_t player_number;
    size_t x;
    size_t y;
    size_t orientation;
};

struct packet_plv_s {
    size_t player_number;
    size_t level;
};

struct packet_pin_s {
    size_t player_number;
    size_t x;
    size_t y;
    size_t q0;
    size_t q1;
    size_t q2;
    size_t q3;
    size_t q4;
    size_t q5;
    size_t q6;
};

struct packet_pex_s {
    size_t player_number;
};

struct packet_pbc_s {
    size_t player_number;
    char message[1024];
};

struct packet_pic_s {
    size_t x;
    size_t y;
    size_t incantation_level;
    size_t player_nb1;
    size_t player_nb2;
};

struct packet_pie_s {
    size_t x;
    size_t y;
    size_t result;
};

struct packet_pfk_s {
    size_t player_number;
};

struct packet_pdr_s {
    size_t player_number;
    size_t ressource;
};

struct packet_pgt_s {
    size_t player_number;
    size_t ressource;
};

struct packet_pdi_s {
    size_t player_number;
};

struct packet_enw_s {
    size_t egg;
    size_t player_number;
    size_t x;
    size_t y;
};

struct packet_eht_s {
    size_t egg;
};

struct packet_ebo_s {
    size_t egg;
};

struct packet_edi_s {
    size_t egg;
};

struct packet_sgt_s {
    size_t time;
};

struct packet_sst_s {
    size_t time;
};

struct packet_seg_s {
    char team[1024];
};

struct packet_smg_s {
    char message[1024];
};

struct suc_s {
};

struct sbp_s {
};

void msg_example_handler(player_t *player, packet_example_t *msg);
packet_example_t *msg_example_deserialize(char **args);
void msg_example_serialize(packet_example_t *msg, list_t *buffer);

void msz_handler(player_t *, packet_msz_t *);
packet_msz_t *msz_deserialize(char **);
void msz_serialize(packet_msz_t *, list_t *);

packet_bct_tile_t *bct_tile_deserialize(char **);
void bct_tile_handler(player_t *, packet_bct_tile_t *);
void bct_tile_serialize(packet_bct_tile_t *, list_t *);

packet_bct_tile_t *bct_all_deserialize(char **);
void bct_all_handler(player_t *, packet_bct_tile_t *);
void bct_all_serialize(packet_bct_tile_t *, list_t *);

// TNA COMMAND
packet_tna_t *tna_deserialize(char **);
void tna_handler(player_t *, packet_tna_t *);
void tna_serialize(packet_tna_t *, list_t *);

// PNW COMMAND
void pnw_handler(packet_pnw_t *);
void pnw_serialize(packet_pnw_t *, list_t *);

// PPO COMMAND
packet_ppo_t *ppo_deserialize(char **);
void ppo_handler(player_t *, packet_ppo_t *);
void ppo_serialize(packet_ppo_t *, list_t *);

// PLV COMMAND
packet_plv_t *plv_deserialize(char **);
void plv_handler(player_t *, packet_plv_t *);
void plv_serialize(packet_plv_t *, list_t *);

// PIN COMMAND
packet_pin_t *pin_deserialize(char **);
void pin_handler(player_t *, packet_pin_t *);
void pin_serialize(packet_pin_t *, list_t *);

// PEX COMMAND
void pex_handler(packet_pex_t *);
void pex_serialize(packet_pex_t *, list_t *);

// PBC COMMAND
void pbc_handler(packet_pbc_t *);
void pbc_serialize(packet_pbc_t *, list_t *);

// PIC COMMAND
void pic_handler(packet_pic_t *);
void pic_serialize(packet_pic_t *, list_t *);

// PIE COMMAND
void pie_handler(packet_pie_t *);
void pie_serialize(packet_pie_t *, list_t *);

// PFK COMMAND
void pfk_handler(packet_pfk_t *);
void pfk_serialize(packet_pfk_t *, list_t *);

// PDR COMMAND
void pdr_handler(packet_pdr_t *);
void pdr_serialize(packet_pdr_t *, list_t *);

// PGT COMMAND
void pgt_handler(packet_pgt_t *);
void pgt_serialize(packet_pgt_t *, list_t *);

// PDI COMMAND
void pdi_handler(packet_pdi_t *);
void pdi_serialize(packet_pdi_t *, list_t *);

// ENW COMMAND
void enw_handler(packet_enw_t *);
void enw_serialize(packet_enw_t *, list_t *);

// EHT COMMAND
void eht_handler(packet_eht_t *);
void eht_serialize(packet_eht_t *, list_t *);

// EBO COMMAND
void ebo_handler(packet_ebo_t *);
void ebo_serialize(packet_ebo_t *, list_t *);

// EDI COMMAND
void edi_handler(packet_edi_t *);
void edi_serialize(packet_edi_t *, list_t *);

// SGT COMMAND
void sgt_handler(player_t *, packet_sgt_t *);
void sgt_serialize(packet_sgt_t *, list_t *);
packet_sgt_t *sgt_deserialize(char **);

// SST COMMAND
void sst_handler(player_t *, packet_sst_t *);
void sst_serialize(packet_sst_t *, list_t *);
packet_sst_t *sst_deserialize(char **);

// SEG COMMAND
void seg_handler(packet_seg_t *);
void seg_serialize(packet_seg_t *, list_t *);

// SMG COMMAND
void smg_handler(packet_smg_t *);
void smg_serialize(packet_smg_t *, list_t *);

// SUC COMMAND
void suc_handler(player_t *, packet_suc_t *);
void suc_serialize(packet_suc_t *, list_t *);

// SBP COMMAND
void sbp_handler(player_t *, packet_sbp_t *);
void sbp_serialize(packet_sbp_t *, list_t *);

#endif //ZAPPY_PROTOCOL_H
