/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SEG Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void seg_serialize(packet_seg_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->team));
}