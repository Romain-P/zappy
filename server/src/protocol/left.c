/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** LEFT COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_left_t *left_deserialize(char **args)
{
	packet_left_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool left_handler(player_t *player, packet_left_t *packet)
{
	player->orientation--;
	if (player->orientation == 0)
		player->orientation = 4;
	if (player->orientation == 5)
		player->orientation = 1;
	send_unwrapped(player->client, "ok");
	return (true);
}

void left_serialize(packet_left_t *packet, list_t *buffer)
{
}
