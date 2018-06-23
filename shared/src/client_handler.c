//
// Created by romain on 26/05/18.
//

#include <unistd.h>
#include "network.h"
#include "stderr.h"
#include "lib.h"
#include "util.h"

static void on_connect(network_client_t *client) {
    eprintf("[Client %d] connected to [Server]\n", client->id);
    zappy_instance.gui_handlers.on_connect(client->id);
}

static void on_disconnect(network_client_t *client) {
    zappy_instance.gui_handlers.on_disconnect(client->id);
    eprintf("[Client %d] disconnected to server\n", client->id);
}

static void on_received(network_client_t *client, char const *packet, size_t len) {
    eprintf("[Client %d] Recv \t<--\t[Server]:\t\t", client->id);
    fflush(stderr);
    write(STDERR_FILENO, packet, len);
    eprintf("\n");

    parse_packet(client, packet, len);
}

static void on_sent(network_client_t *client, char const *packet, size_t len) {
    eprintf("[Client %d] Sent \t-->\t[Server]:\t\t", client->id);
    fflush(stderr);
    write(STDERR_FILENO, packet, len - 1);
    eprintf("\n");
}

void configure_client_handler(client_handler_t *handler) {
    handler->on_received = &on_received;
    handler->on_connect = &on_connect;
    handler->on_sent = &on_sent;
    handler->on_disconnect = &on_disconnect;
}