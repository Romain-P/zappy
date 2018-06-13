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

void pgt_handler(packet_pgt_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->player_number = 0;
	packet->ressource = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "pgt", &packet);
	}
}

void pgt_serialize(packet_pgt_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}