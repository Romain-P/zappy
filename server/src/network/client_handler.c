//
// Created by romain on 26/05/18.
//

#include <unistd.h>
#include "network.h"
#include "stderr.h"
#include "zappy.h"
#include "util.h"

static void on_connect(network_client_t *client) {
    eprintf("[Client %d] connected\n", client->id);
    player_t *player = malloc(sizeof(player_t));

    player->client = client;
    (player->inventory).q0 = 0;
    (player->inventory).q1 = 0;
    (player->inventory).q2 = 0;
    (player->inventory).q3 = 0;
    (player->inventory).q4 = 0;
    (player->inventory).q5 = 0;
    (player->inventory).q6 = 0;
    player->state = AWAIT_TEAM_NAME;
    player->waiting_commands = 0;
    list_add(&server.players, player);
    send_unwrapped(client, "WELCOME");
    player->level = 0;
}

static void on_disconnect(network_client_t *client) {
    player_t *found = find_player(client);

    if (found) {
        list_remove(&server.players, found);
        free(found);
    }
    eprintf("[Client %d] disconnected\n", client->id);
}

static void on_sent(network_client_t *client, char const *packet, size_t len) {
    eprintf("[Server] Sent \t-->\t[Client %d]:\t\t", client->id);
    fflush(stderr);
    write(STDERR_FILENO, packet, len - 1);
    eprintf("\n");
}

static void on_received(network_client_t *client, char const *packet, size_t len) {
    eprintf("[Server] Recv \t<--\t[Client %d]:\t\t", client->id);
    fflush(stderr);
    write(STDERR_FILENO, packet, len);
    eprintf("\n");

    player_t *found = find_player(client);

    if (found)
        parse_packet(client, packet, len);
}

void configure_client_handler(client_handler_t *handler) {
    handler->on_received = &on_received;
    handler->on_connect = &on_connect;
    handler->on_sent = &on_sent;
    handler->on_disconnect = &on_disconnect;
}