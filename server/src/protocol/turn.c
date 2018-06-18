/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Turn Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_turn_t *turn_deserialize(char **args)
{
	packet_turn_t *packet;

	if (str_array_length(args) != 2)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	strcpy(packet->orientation, args[1]);
	return (packet);
}

void turn_handler(player_t *player, packet_turn_t *packet)
{
	if (!strcmp(packet->orientation, "right"))
		player->orientation++;
	else
		player->orientation--;
	if (player->orientation == 0)
		player->orientation = 4;
	if (player->orientation == 5)
		player->orientation = 1;
	send_packet(player->client, "ok", &packet);
}

void turn_serialize(packet_turn_t *packet, list_t *buffer)
{
}
