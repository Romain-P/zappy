/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Player
*/

#include "zappy.h"
#include "util.h"

player_t *find_player(network_client_t *client)
{
	iter_t *it;
	player_t *user;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		user = it->data;
		if (user->client == client)
			return user;
	}
	return (NULL);
}