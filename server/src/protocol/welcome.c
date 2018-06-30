/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command WELCOME
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_welcome_t *welcome_deserialize(char **args)
{
	packet_welcome_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool welcome_handler(player_t *player, packet_welcome_t *packet)
{
	player->is_gui = 1;
	return (true);
}

void welcome_serialize(packet_welcome_t *packet, list_t *buffer)
{
}