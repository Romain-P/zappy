//
// Created by romain on 14/05/18.
//

#ifndef ZAPPY_H_
# define ZAPPY_H_

# define ZAPPY_BUFFER_SIZE        (512)
# define ZAPPY_ARG_DELIMITER   ("\r\n")
# define ZAPPY_PARAM_SEPARATOR    (" ")

# include "network.h"

typedef struct command_s message_t;
typedef struct zappy_instance_s zappy_instance_t;
typedef struct player_s player_t;

extern zappy_instance_t server;

struct player_s {
    network_client_t *client;
    char *name;
};

struct zappy_instance_s {
    list_t players;
};

typedef void (*handler_t)(player_t *, void *);
typedef void (*serialize_t)(void *msg, list_t *buffer);
typedef void *(*deserialize_t)(char **args);

struct command_s {
    char const *named;
    serialize_t serialize;
    deserialize_t deserialize;
    handler_t handler;
};

void configure_client_handler(client_handler_t *handler);

void parse_packet(network_client_t *client, char const *packet, size_t len);

void send_packet(network_client_t *client, char const *named, void *msg);

player_t *find_player(network_client_t *client);

#endif //ZAPPY_H_
