/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** ENW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void enw_handler(player_t *player, packet_enw_t *packet)
{
	player_t *list;
	egg_t *egg = malloc(sizeof(egg_t));
	iter_t *it;

	egg->x = packet->x;
	egg->y = packet->y;
	egg->id = server.number_egg;
	server.number_egg++;
	packet->player_number = (player->client)->id;
	packet->egg = egg->id;
	list_add(&player->eggs, egg);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, "enw", &packet);
	}
}

void enw_serialize(packet_enw_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
}