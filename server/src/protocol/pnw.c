/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PNW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void pnw_serialize(packet_pnw_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->orientation));
	list_add(buffer, to_string(packet->level));
	list_add(buffer, strdup(packet->name_team));
}