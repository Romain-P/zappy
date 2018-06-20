//
// Created by romain on 20/06/18.
//

#ifndef ZAPPY_LIB_H
#define ZAPPY_LIB_H

#include "protocol.h"

typedef struct zappy_instance_s zappy_instance_t;
typedef struct waiting_s waiting_t;

struct zappy_instance_s {
    network_instance_t instance;
    network_handlers_t handlers;
    list_t waiting;
    bool thread_sync;
    pthread_mutex_t locker;
};

struct waiting_s {
    session_t client_id;
    handler_t handler;
    void *packet;
};

extern zappy_instance_t zappy_instance;

void configure_client_handler(client_handler_t *handler);
void parse_packet(network_client_t *client, char const *packet, size_t len);
void zappy_sync_push(session_t client_id, handler_t handler, void *packet);

#endif //ZAPPY_LIB_H
