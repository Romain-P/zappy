/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** ENW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void enw_serialize(packet_enw_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
}