/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EDI Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void edi_handler(packet_edi_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->egg = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "edi", &packet);
	}
}

void edi_serialize(packet_edi_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}