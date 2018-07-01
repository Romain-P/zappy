/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Forward Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include "mouvement.h"

packet_forward_t *forward_deserialize(char **args)
{
	packet_forward_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool forward_handler(player_t *player, packet_forward_t *packet)
{
	size_t tile;

	if (!packet->delayed) {
		delay(packet,
		(handler_t) &forward_handler, player, 7);
	} else {
		tile = get_valid_direction(player, player->orientation);
		send_ppo(player);
		if (tile == 0)
			send_unwrapped(player->client, "ok");
		else
			send_unwrapped(player->client, "ko");
	}
	return (false);
}

void forward_serialize(packet_forward_t *packet, list_t *buffer)
{
}
