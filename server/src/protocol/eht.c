/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EHT Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void eht_serialize(packet_eht_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}