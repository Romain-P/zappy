/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** UNWRAPPED
*/

#include "network.h"
#include "protocol.h"
#include "stderr.h"
#include "team.h"

void on_unwrapped(player_t *player, char **unwrapped)
{
	int status;

	if (player->state == AWAIT_TEAM_NAME) {
		status = check_free_team(player, unwrapped[0]);
		if (status == 0) {
			send_unwrapped(player->client, "ko");
		}
		else {
			if (player->team->player == server.nb_clients - 1) {
				send_unwrapped(player->client,
							   get_team_char(player, 0));
				send_unwrapped(player->client,
							   get_team_char(player, 1));
				player->state = VALID_PLAYER;
			} else {
			    list_remove(&server.players, player);
			    list_add(&server.pending_players, player);
            }
		}
	}
	else if (player->state == VALID_PLAYER) {
		eprintf("Received non-handled packet: key=%s\n", unwrapped[0]);
		send_unwrapped(player->client, "ko");
	}
}