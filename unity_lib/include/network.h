//
// Created by romain on 16/05/18.
//

#ifndef MYIRC_NETWORK_H
#define MYIRC_NETWORK_H

#include <sys/types.h>
#include <stdbool.h>
#include <stdint.h>
#include <netinet/in.h>
#include "linked_list.h"
#include "network_epoll.h"

#ifndef NETWORK_READ_SIZE
    #define NETWORK_READ_SIZE   (1024)
#endif

#define ERROR               (-1)

#define PACKED  __attribute__((__packed__))

#define PACKET_HEADER      char const *cmd

typedef struct network_client_s network_client_t;
typedef struct netinstance_s network_instance_t;
typedef int session_t;
typedef struct network_config_s network_config_t;
typedef struct client_handler_s client_handler_t;
typedef enum buffer_state_e buffer_state_t;
typedef struct network_packet_s network_packet_t;

enum buffer_state_e {
    FREED,
    INCOMPLETE,
    READY
};

struct PACKED network_packet_s {
    PACKET_HEADER;
};

struct network_client_s {
    session_t id;
    char *buffer;
    buffer_state_t bstate;
    size_t length;
    int status;
    network_instance_t *server;
    bool closed;
};

struct client_handler_s {
    void (*on_connect)(network_client_t *client);
    void (*on_disconnect)(network_client_t *client);
    void (*on_received)(network_client_t *client, char const *packet, size_t len);
    void (*on_sent)(network_client_t *client, char const *packet, size_t len);
};

struct netinstance_s {
    session_t epoll_id;
    network_config_t *config;
    client_handler_t client_handler;
    list_t clients;
};

struct network_config_s {
    char *host;
    uint16_t port;
    char *packet_delimiter;
    size_t packet_max_size;
    void (*on_server_close)();
    void (*configure_handlers)(client_handler_t *);
    on_epoll_unblocked on_unblocked;
};

bool network_connector_start(network_instance_t *instance, network_config_t *config);

network_client_t *network_new_connection(network_instance_t *instance);

void network_client_read(network_instance_t *server, network_client_t *client, char *buffer, size_t length);

void network_client_send(network_client_t *client, char *packet, size_t len);

void network_client_close(network_client_t *client);

void network_client_free(void *client_ptr);

network_client_t *network_client_find(list_t *network_clients, session_t id);

#endif //MYIRC_NETWORK_H
