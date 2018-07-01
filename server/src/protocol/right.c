/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** RIGHT COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

size_t convert_orientation(size_t orientation)
{
	if (orientation == 1)
		return (0);
	if (orientation == 2)
		return (6);
	if (orientation == 3)
		return (4);
	if (orientation == 5)
		return (2);
	return (0);
}

packet_right_t *right_deserialize(char **args)
{
	packet_right_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool right_handler(player_t *player, packet_right_t *packet)
{
	if (!packet->delayed) {
		delay(packet,
		(handler_t) &right_handler, player, 7);
	} else {
		player->orientation++;
		if (player->orientation == 0)
			player->orientation = 4;
		if (player->orientation == 5)
			player->orientation = 1;
		send_ppo(player);
		send_unwrapped(player->client, "ok");
	}
	return (false);
}

void right_serialize(packet_right_t *packet, list_t *buffer)
{
}
