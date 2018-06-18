/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Inventory Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_inventory_t *inventory_deserialize(char **args)
{
	packet_inventory_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool inventory_handler(player_t *player, packet_inventory_t *packet)
{
	sprintf(packet->result, "[food %d, linemate %d, deraumere %d, "
		"sibur %d, mendiane %d, phiras %d, thystame %d]\n",
	(player->inventory).q0,
	(player->inventory).q1,
	(player->inventory).q2,
	(player->inventory).q3,
	(player->inventory).q4,
	(player->inventory).q5,
	(player->inventory).q6);
	send_packet(player->client, &packet); //TODO: tu voulais pas faire send_unwrapped(client, "ok"); ?
	return true;
}

void inventory_serialize(packet_inventory_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->result));
}
