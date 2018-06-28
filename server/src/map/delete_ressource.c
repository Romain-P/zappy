/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Delete Ressource
*/

#include "zappy.h"
#include "level.h"
#include "protocol.h"

size_t check_condition_incantation(player_t *player)
{
	size_t count = 0;
	int *tab = malloc(sizeof(int) * (100));
	player_t *list;
	size_t nb;
	iter_t *it;

	if (tab == NULL)
		exit(84);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->x == player->x && list->y == player->y &&
		player->level == list->level)
			tab[count++] = player->client->id;
	}
	if (count != get_need_level(player->level))
		return (1);
	nb = count;
	count = check_ressource_tile(player);
	if (count != 1)
		send_pic(player, nb, tab);
	return (check_ressource_tile(player));	
}

size_t get_need_level(size_t level)
{
	switch (level) {
		case 1:
			return (1);
			break;
		case 2:
		case 3:
			return (2);
			break;
		case 4:
		case 5:
			return (4);
			break;
		case 6:
		case 7:
			return (6);
			break;
	}
	return (1);
}

size_t compare_level(const level_t *need, level_t *here)
{
	if (here->q1 < need->q1 ||
		here->q2 < need->q2 ||
		here->q3 < need->q3 ||
		here->q4 < need->q4 ||
		here->q5 < need->q5 ||
		here->q6 < need->q6)
		return (1);
	return (0);
}

void increment_ressource_level(level_t *level, resource_type_t type)
{
	if (type == 1)
		level->q1 += 1;
	if (type == 2)
		level->q2 += 1;
	if (type == 3)
		level->q3 += 1;
	if (type == 4)
		level->q4 += 1;
	if (type == 5)
		level->q5 += 1;
	if (type == 6)
		level->q6 += 1;
}

void init_level_ressource(level_t *level)
{
	level->q1 = 0;
	level->q2 = 0;
	level->q3 = 0;
	level->q4 = 0;
	level->q5 = 0;
	level->q6 = 0;
}