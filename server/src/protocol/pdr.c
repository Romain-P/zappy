/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PDR Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void delete_ressource(player_t *player, size_t ressource)
{
	if (ressource == 0)
		player->inventory.q0--;
	if (ressource == 1)
		player->inventory.q1--;
	if (ressource == 2)
		player->inventory.q2--;
	if (ressource == 3)
		player->inventory.q3--;
	if (ressource == 4)
		player->inventory.q4--;
	if (ressource == 5)
		player->inventory.q5--;
	if (ressource == 6)
		player->inventory.q6--;
}

bool pdr_handler(player_t *player, packet_pdr_t *packet)
{
	player_t *list;
	iter_t *it;

	packet->player_number = (player->client)->id;
	delete_ressource(player, packet->ressource);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, &packet);
	}
	return true;
}

void pdr_serialize(packet_pdr_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}