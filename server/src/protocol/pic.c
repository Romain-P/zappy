/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIC Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_pic_t *pic_deserialize(char **args)
{
	packet_pic_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool pic_handler(player_t *player, packet_pic_t *packet)
{
	player_t *list;
	iter_t *it;

	packet->x = 0;
	packet->y = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, &packet);
	}
	return (true);
}

void pic_serialize(packet_pic_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->incantation_level));
	list_add(buffer, to_string(packet->player_nb1));
	list_add(buffer, to_string(packet->player_nb2));
}