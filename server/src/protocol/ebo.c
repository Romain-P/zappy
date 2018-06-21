/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EBO Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void ebo_serialize(packet_ebo_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}