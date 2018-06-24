/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Incantation COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_incantation_t *incantation_deserialize(char **args)
{
	packet_incantation_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool incantation_handler(player_t *player, packet_incantation_t *packet)
{
	if (!packet->delayed) {
		delay(packet,
		(handler_t) &incantation_handler, player, 300);
	} else {
		send_unwrapped(player->client, "ok");
	}
	return (false);
}

void incantation_serialize(packet_incantation_t *packet, list_t *buffer)
{
}