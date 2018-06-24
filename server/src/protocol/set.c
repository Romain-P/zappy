/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SET COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_set_t *set_deserialize(char **args)
{
	packet_set_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	strcpy(packet->node, args[0]);
	return (packet);
}

static size_t get_ressource_exist(inventory_t *inventory, size_t nb)
{
	if (nb == 0 && inventory->q0 > 0)
		return (0);
	if (nb == 1 && inventory->q1 > 0)
		return (1);
	if (nb == 2 && inventory->q2 > 0)
		return (2);
	if (nb == 3 && inventory->q3 > 0)
		return (3);
	if (nb == 4 && inventory->q4 > 0)
		return (4);
	if (nb == 5 && inventory->q5 > 0)
		return (5);
	if (nb == 6 && inventory->q6 > 0)
		return (6);
	return (7);
}

static void delete_ressource(player_t *player, size_t ressource)
{
	if (ressource == 0)
		(player->inventory).q0 -= 1;
	if (ressource == 1)
		(player->inventory).q1 -= 1;
	if (ressource == 2)
		(player->inventory).q2 -= 1;
	if (ressource == 3)
		(player->inventory).q3 -= 1;
	if (ressource == 4)
		(player->inventory).q4 -= 1;
	if (ressource == 5)
		(player->inventory).q5 -= 1;
	if (ressource == 6)
		(player->inventory).q6 -= 1;
}

bool set_handler(player_t *player, packet_set_t *packet)
{
	size_t id = get_ressource_exist(&(player->inventory),
		get_id_ressource(packet->node));

	if (id == 7)
		send_unwrapped(player->client, "ko");
	else {
		delete_ressource(player, id);
		set_ressource(player, id);
		send_unwrapped(player->client, "ok");
	}
	return (true);
}

void set_serialize(packet_set_t *packet, list_t *buffer)
{
}