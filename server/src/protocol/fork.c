/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** FORK COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_fork_t *fork_deserialize(char **args)
{
	packet_fork_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool fork_handler(player_t *player, packet_fork_t *packet)
{
	egg_t *egg;

	if (!packet->delayed) {
		delay(packet,
		(handler_t) &fork_handler, player, 42);
	} else {
		egg = malloc(sizeof(egg_t));
		if (egg == NULL)
			exit(84);
		egg->id = (server.map).nb_eggs;
		egg->x = player->x;
		egg->y = player->y;
		list_add(&(server.map).eggs, egg);
		send_unwrapped(player->client, "ok");
	}
	return (false);
}

void fork_serialize(packet_fork_t *packet, list_t *buffer)
{
}