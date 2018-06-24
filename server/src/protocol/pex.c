/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Pex Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void pex_serialize(packet_pex_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}