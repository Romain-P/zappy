#include "zappy_network.h"

#include <stdio.h>
#include "lib.h"
#include <stdlib.h>
#include <pthread.h>

zappy_instance_t zappy_instance = {
        .waiting = list_init,
        .locker = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER
};

static void on_close() {

}

static void on_unblocked() {

}

bool zappy_init_connector(char *address, uint16_t port, bool thread_sync, network_handlers_t *handlers) {
    network_config_t config = {
            .host = address,
            .port = port,
            .packet_delimiter = ZAPPY_ARG_DELIMITER,
            .packet_max_size = ZAPPY_BUFFER_SIZE,
            .configure_handlers = &configure_client_handler,
            .on_server_close = &on_close,
            .on_unblocked = &on_unblocked
    };
    zappy_instance.thread_sync = thread_sync;
    zappy_instance.handlers = *handlers;
    return network_connector_start(&zappy_instance.instance, &config);
}

session_t zappy_new_connection() {
    return network_new_connection(&zappy_instance.instance)->id;
}

void zappy_sync_poll() {
    list_t *queue = &zappy_instance.waiting;
    if (queue->size == 0)
        return;
    pthread_mutex_lock(&zappy_instance.locker);
    waiting_t *popped = list_pop(queue);
    pthread_mutex_unlock(&zappy_instance.locker);
    popped->handler(popped->client_id, popped->packet);
    free(popped->packet);
    free(popped);
}

void zappy_sync_push(session_t client_id, handler_t handler, void *packet) {
    waiting_t *waiting = malloc(sizeof(*waiting));
    waiting->client_id = client_id;
    waiting->handler = handler;
    waiting->packet = packet;
    pthread_mutex_lock(&zappy_instance.locker);
    list_add(&zappy_instance.waiting, waiting);
    pthread_mutex_unlock(&zappy_instance.locker);
}