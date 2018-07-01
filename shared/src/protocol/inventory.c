/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Inventory
*/

#include <stdlib.h>
#include <linked_list.h>
#include <zappy_network.h>
#include <string.h>


packet_inventory_t *deserialize_inventory(char **args)
{
	packet_inventory_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	strcpy(packet->result, args[0]);
	return (packet);
}

void serialize_inventory(packet_inventory_t *packet, list_t *buffer)
{
}