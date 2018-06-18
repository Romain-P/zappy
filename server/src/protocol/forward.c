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

void forward_handler(player_t *player, packet_forward_t *packet)
{
	size_t x = player->x;
	size_t y = player->y;
	size_t tile = get_valid_direction(player, player->orientation);

	if (tile == 0)
		send_packet(player->client, "ok", &packet);
	else
		send_packet(player->client, "ko", &packet);
}

void forward_serialize(packet_forward_t *packet, list_t *buffer)
{
}
