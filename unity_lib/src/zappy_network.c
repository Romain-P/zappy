#include "zappy_network.h"

#include <stdio.h>
#include <lib.h>

zappy_instance_t zappy_instance;

static void on_close() {

}

static void on_unblocked() {

}

bool zappy_init_connector(char *address, uint16_t port, network_handlers_t handlers) {
    network_config_t config = {
            .host = address,
            .port = port,
            .packet_delimiter = ZAPPY_ARG_DELIMITER,
            .packet_max_size = ZAPPY_BUFFER_SIZE,
            .configure_handlers = &configure_client_handler,
            .on_server_close = &on_close,
            .on_unblocked = &on_unblocked
    };
    zappy_instance.handlers = handlers;
    return network_connector_start(&zappy_instance.instance, &config);
}

session_t zappy_new_connection() {
    return network_new_connection(&zappy_instance.instance)->id;
}