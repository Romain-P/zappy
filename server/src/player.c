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