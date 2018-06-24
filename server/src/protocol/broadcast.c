/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Broadcast Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_broadcast_t *broadcast_deserialize(char **args)
{
	packet_broadcast_t *packet = malloc(sizeof(*packet));

	if (str_array_length(args) != 1)
		return (NULL);
	if (packet == NULL)
		return (NULL);
	strcpy(packet->text, args[0]);
	return (packet);
}

bool broadcast_handler(player_t *player, packet_broadcast_t *packet)
{
	if (!packet->delayed) {
		delay(packet,
		(handler_t) &broadcast_handler, player, 7);
	} else {
		send_unwrapped(player->client, "ok");
	}
	return (false);
}

void broadcast_serialize(packet_broadcast_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->text));
}
