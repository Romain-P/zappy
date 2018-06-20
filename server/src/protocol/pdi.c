/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PDI Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void pdi_serialize(packet_pdi_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}