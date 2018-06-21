/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EDI Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void edi_serialize(packet_edi_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}