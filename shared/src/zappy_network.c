#include "zappy_network.h"

#include <stdio.h>
#include "lib.h"
#include <stdlib.h>
#include <pthread.h>
#include <stderr.h>
#include <time.h>

zappy_instance_t zappy_instance = {
        .pending = list_init,
        .locker = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER,
        .ai_handlers = {0},
        .gui_handlers = {0},
        .connected = false,

};

static void on_close() {}
static void on_unblocked() {}

static void *init(network_config_t *config) {
    network_connector_start(&zappy_instance.net, &zappy_instance.config);
    return (NULL);
}

static bool launch_network(size_t timeout) {
    pthread_t thread;

    pthread_create(&thread, NULL, (void *(*)(void *)) &init, NULL);
    pthread_detach(thread);

    bool connected = false;
    time_t timeout_timestamp = time(NULL) + timeout;

    while (time(NULL) <= timeout_timestamp) {
        pthread_mutex_lock(&zappy_instance.locker);
        connected = zappy_instance.connected;
        pthread_mutex_unlock(&zappy_instance.locker);
        if (connected)
            break;
    }
    return connected;
}

EXPORT bool zappy_init_connector(char *address, uint16_t port, gui_handlers_t handlers, uint32_t timeout) {
    zappy_instance.config = (network_config_t) {
            .host = address,
            .port = port,
            .packet_delimiter = ZAPPY_PACKET_DELIMITER,
            .packet_max_size = ZAPPY_BUFFER_SIZE,
            .configure_handlers = &configure_client_handler,
            .on_server_close = &on_close,
            .on_unblocked = &on_unblocked
    };
    zappy_instance.thread_sync = true;
    zappy_instance.gui_handlers = handlers;
    zappy_instance.ai_handlers.on_unwrapped = NULL;
    eprintf("zappy_network: trying to connect to %s:%d\n", address, port);
    return launch_network(timeout);
}

EXPORT bool zappy_init_connector_ai(char *address, uint16_t port, ai_handlers_t handlers, uint32_t timeout) {
    zappy_instance.config = (network_config_t) {
            .host = address,
            .port = port,
            .packet_delimiter = ZAPPY_PACKET_DELIMITER,
            .packet_max_size = ZAPPY_BUFFER_SIZE,
            .configure_handlers = &configure_client_handler,
            .on_server_close = &on_close,
            .on_unblocked = &on_unblocked
    };
    zappy_instance.thread_sync = false;
    zappy_instance.gui_handlers = (gui_handlers_t) {
            .on_welcome = handlers.on_welcome,
            .on_connect = handlers.on_connect,
            .on_disconnect = handlers.on_disconnect
    };
    zappy_instance.ai_handlers = handlers;
    return launch_network(timeout);
}

EXPORT session_t zappy_new_connection() {
    return network_new_connection(&zappy_instance.net)->id;
}

EXPORT void zappy_sync_poll() {
    list_t *queue = &zappy_instance.pending;
    size_t size;
    pthread_mutex_lock(&zappy_instance.locker);
    size = queue->size;
    pthread_mutex_unlock(&zappy_instance.locker);
    if (size == 0)
        return;
    pthread_mutex_lock(&zappy_instance.locker);
    waiting_t *popped = list_pop(queue);
    pthread_mutex_unlock(&zappy_instance.locker);
    popped->handler(popped->client_id, popped->packet);
    free(popped->packet);
    free(popped);
}

void zappy_sync_push(session_t client_id, handler_t handler, void *packet) {
    pthread_mutex_lock(&zappy_instance.locker);
    waiting_t *waiting = malloc(sizeof(*waiting));
    waiting->client_id = client_id;
    waiting->handler = handler;
    waiting->packet = packet;
    list_add(&zappy_instance.pending, waiting);
    pthread_mutex_unlock(&zappy_instance.locker);
}
