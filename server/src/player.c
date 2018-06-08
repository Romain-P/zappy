//
// Created by romain on 28/05/18.
//

#include <string.h>
#include <stdlib.h>
#include "zappy.h"

player_t *find_player(network_client_t *client) {
    for (iter_t *it = iter_begin(&server.players); it; iter_next(it)) {
        player_t *user = it->data;
        if (user->client == client)
            return user;
    }
    return NULL;
}

void send_packet(player_t *player, char const *msg) {
    size_t len = strlen(msg);
    char packet[len + 2];
    strncpy(packet, msg, len);
    packet[len] = '\r';
    packet[len + 1] = '\n';
    network_client_send(player->client, packet, len + 2);
}