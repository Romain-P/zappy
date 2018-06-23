/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** RIGHT COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_right_t *right_deserialize(char **args)
{
	packet_right_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool right_handler(player_t *player, packet_right_t *packet)
{
	player->orientation++;
	if (player->orientation == 0)
		player->orientation = 4;
	if (player->orientation == 5)
		player->orientation = 1;
	send_unwrapped(player->client, "ok");
	return (true);
}

void right_serialize(packet_right_t *packet, list_t *buffer)
{
}
