//
// Created by romain on 14/05/18.
//

#ifndef ZAPPY_H_
# define ZAPPY_H_

# define ZAPPY_BUFFER_SIZE        (512)
# define ZAPPY_ARG_DELIMITER   ("\r\n")
# define ZAPPY_PARAM_SEPARATOR    (" ")

#include <time.h>
#include "network.h"
#include "team.h"

typedef struct command_s message_t;
typedef struct zappy_instance_s zappy_instance_t;
typedef struct player_s player_t;
typedef struct team_s team_t;
typedef struct map_s map_t;
typedef struct resource resource_t;
typedef struct inventory_s inventory_t;
typedef struct egg_s egg_t;
typedef struct waiting_s waiting_t;
typedef enum resource_type_e resource_type_t;

extern zappy_instance_t server;

struct team_s {
    char *name;
    int player;
};

struct inventory_s {
    size_t q0;
    size_t q1;
    size_t q2;
    size_t q3;
    size_t q4;
    size_t q5;
    size_t q6;
};

struct player_s {
    network_client_t *client;
    char *name;
    size_t x;
    size_t y;
    size_t orientation;
    size_t level;
    team_t team;
    inventory_t inventory;
    list_t eggs;
    size_t waiting_commands;
};

struct map_s {
    size_t width;
    size_t height;
    size_t max;
    size_t nb_ressource;
    list_t ressources;
};

struct egg_s {
    size_t id;
    size_t x;
    size_t y;
};

enum resource_type_e {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

struct resource {
    size_t x;
    size_t y;
    resource_type_t type;
};

struct zappy_instance_s {
    list_t players;
    int port;
    int width;
    int height;
    char *name;
    int nb_clients;
    int freq;
    list_t teams;
    map_t map;
    size_t number_egg;
    list_t waiting_commands;
};

typedef bool (*handler_t)(player_t *, void *);
typedef void (*serialize_t)(void *msg, list_t *buffer);
typedef void *(*deserialize_t)(char **args);

struct waiting_s {
    player_t *player;
    time_t exec_time;
    handler_t command_handler;
    void *packet;
};

struct command_s {
    char const *named;
    serialize_t serialize;
    deserialize_t deserialize;
    handler_t handler;
};

void configure_client_handler(client_handler_t *handler);

void parse_packet(network_client_t *client, char const *packet, size_t len);

void send_packet(network_client_t *client, void *msg);

player_t *find_player(network_client_t *client);

int to_seconds(int tics);

bool delay(void *packet, handler_t handler, player_t *player, int tics);

void check_delayed_tasks();

#endif //ZAPPY_H_
