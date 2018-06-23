//
// Created by romain on 23/06/18.
//

#include <network.h>
#include <protocol.h>
#include <stderr.h>

void on_unwrapped(player_t *player, char **unwrapped) {
    switch (player->state) {
        case AWAIT_TEAM_NAME:
            //TODO: associate the right team by the name (holded in unwrapped[0])
            //TODO: send remaining authorized connections for the team
            //TODO: send map dimensions
            player->state = VALID_PLAYER;
            break;
        case VALID_PLAYER:
            eprintf("Received non-handled packet: key=%s\n", unwrapped[0]);
            break;
        default:
            break;
    }
}