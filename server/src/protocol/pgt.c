/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PGT Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pgt_handler(player_t *player, packet_pgt_t *packet)
{
	player_t *list;
	iter_t *it;

	packet->player_number = (player->client)->id;
	add_ressource(player, packet->ressource);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, "pgt", &packet);
	}
}

void pgt_serialize(packet_pgt_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}

static void add_ressource(player_t *player, size_t ressource)
{
	if (ressource == 0)
		player->inventory.q0++;
	if (ressource == 1)
		player->inventory.q1++;
	if (ressource == 2)
		player->inventory.q2++;
	if (ressource == 3)
		player->inventory.q3++;
	if (ressource == 4)
		player->inventory.q4++;
	if (ressource == 5)
		player->inventory.q5++;
	if (ressource == 6)
		player->inventory.q6++;
}