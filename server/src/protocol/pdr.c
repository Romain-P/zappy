/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PDR Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void pdr_serialize(packet_pdr_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}