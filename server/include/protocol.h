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



#endif //ZAPPY_PROTOCOL_H
