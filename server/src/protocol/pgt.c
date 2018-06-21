/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PGT Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

/*static void add_ressource(player_t *player, size_t ressource)
{
	if (ressource == 0)
		player->inventory.q0++;
	if (ressource == 1)
		player->inventory.q1++;
	if (ressource == 2)
		player->inventory.q2++;
	if (ressource == 3)
		player->inventory.q3++;
	if (ressource == 4)
		player->inventory.q4++;
	if (ressource == 5)
		player->inventory.q5++;
	if (ressource == 6)
		player->inventory.q6++;
}*/

void pgt_serialize(packet_pgt_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}