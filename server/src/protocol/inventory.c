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
	sprintf(packet->result, "[food %zu, linemate %zu, deraumere %zu, "
		"sibur %zu, mendiane %zu, phiras %zu, thystame %zu]",
	(player->inventory).q0,
	(player->inventory).q1,
	(player->inventory).q2,
	(player->inventory).q3,
	(player->inventory).q4,
	(player->inventory).q5,
	(player->inventory).q6);
	send_unwrapped(player->client, packet->result);
	return (true);
}

void increment_inventory(player_t *player, size_t id)
{
	if (id == 0)
		(player->inventory).q0 += 1;
	if (id == 1)
		(player->inventory).q1 += 1;
	if (id == 2)
		(player->inventory).q2 += 1;
	if (id == 3)
		(player->inventory).q3 += 1;
	if (id == 4)
		(player->inventory).q4 += 1;
	if (id == 5)
		(player->inventory).q5 += 1;
	if (id == 6)
		(player->inventory).q6 += 1;
}

void set_ressource(player_t *player, size_t id)
{
	resource_t *ressource = malloc(sizeof(*ressource));

	if (ressource == NULL)
		exit(84);
	ressource->x = player->x;
	ressource->y = player->y;
	ressource->type = (resource_type_t) id;
	list_add(&(server.map).ressources, ressource);
}

void inventory_serialize(packet_inventory_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->result));
}
