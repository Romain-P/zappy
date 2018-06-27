/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Check Incantation
*/

#include "level.h"

static level_t const levels[] = {
	{ 2, 1, 0, 0, 0, 0, 0 },
	{ 3, 1, 1, 1, 0, 0, 0 },
	{ 4, 2, 0, 1, 0, 2, 0 },
	{ 5, 1, 1, 2, 0, 1, 0 },
	{ 6, 1, 2, 1, 3, 9, 0 },
	{ 7, 1, 2, 3, 0, 1, 0 },
	{ 8, 2, 2, 2, 2, 2, 1 },
	{ 100, 100, 100, 100, 100, 100, 100}
};

void loop_ressource_incan(player_t *player, level_t *level)
{
	iter_t *it;
	resource_t *resource;

	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		resource = it->data;
		if (resource->x == player->x && resource->y == player->y
		&& get_valid_ressource(resource, level) == 1) {
			unset_ressource_map(resource, level);
			list_remove(&(server.map).ressources, resource);
			free(resource);
			loop_ressource_incan(player, level);
			return;
		}
	}
}

void delete_ressource(player_t *player)
{
	size_t i = 0;
	level_t *level;

	for (i = 0; levels[i].level != 100; i++) {
		if (player->level + 1 == levels[i].level) {
			level = get_delete_level(levels + i);
			break;
		}
	}
	loop_ressource_incan(player, level);
}

size_t check_ressource_tile(player_t *player)
{
	size_t i = 0;
	size_t compare = 1;
	level_t const *level = NULL;

	for (i = 0; levels[i].level != 100; i++) {
		if (player->level + 1 == (levels[i].level)) {
			level = levels + i;
			compare = get_ressource_tile_incan(level,
			player->x, player->y);
			break;
		}
	}
	return (compare);
}

size_t get_ressource_tile_incan(const level_t *need, size_t x, size_t y)
{
	resource_t *ressource;
	iter_t *it;
	size_t compare = 1;
	level_t *level = malloc(sizeof(level_t));

	if (level == NULL)
		exit(84);
	init_level_ressource(level);
	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		ressource = it->data;
		if (x == ressource->x && y == ressource->y) {
			increment_ressource_level(level, ressource->type);
		}
	}
	compare = compare_level(need, level);
	return (compare);
}

size_t get_condition_player_level(player_t *player)
{
	player_t *list;
	iter_t *it;
	size_t count = 0;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->x == player->x && list->y == player->y &&
		player->level == list->level)
			count++;
	}
	return (count);
}