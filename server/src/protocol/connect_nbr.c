/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** connect_nbr Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_connectnbr_t *connectnbr_deserialize(char **args)
{
	packet_connectnbr_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool connectnbr_handler(player_t *player, packet_connectnbr_t *packet)
{
	team_t *team;
	iter_t *it;
	int count = 0;
	char nb[1024];

	for (it = iter_begin(&server.teams); it; iter_next(it)) {
		team = it->data;
		if (team->player != 0)
			count++;
	}
	sprintf(nb, "%d", count);
	send_unwrapped(player->client, nb);
	return (true);
}

void connectnbr_serialize(packet_connectnbr_t *packet, list_t *buffer)
{
}
