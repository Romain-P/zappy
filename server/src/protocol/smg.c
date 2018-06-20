/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SMG Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void smg_serialize(packet_smg_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->message));
}