/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIC Command
*/


#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pic_handler(packet_pic_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->x = 0;
	packet->y = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "pic", &packet);
	}
}

void pic_serialize(packet_pic_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->incantation_level));
	list_add(buffer, to_string(packet->player_nb1));
	list_add(buffer, to_string(packet->player_nb2));
}