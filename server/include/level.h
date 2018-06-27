/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Header Level
*/

#ifndef LEVEL_H_
	#define LEVEL_H_

	#include "zappy.h"

	size_t check_condition_incantation(player_t *);
	size_t check_ressource_tile(player_t *);
	size_t get_ressource_tile_incan(const level_t *, size_t, size_t);
	size_t compare_level(const level_t *, level_t *);
	void increment_ressource_level(level_t *, resource_type_t);
	size_t get_condition_player_level(player_t *);
	size_t get_need_level(size_t);
	void init_level_ressource(level_t *);
	void delete_ressource(player_t *);
	level_t *get_delete_level(level_t const *);
	size_t get_valid_ressource(resource_t *, level_t *);
	void unset_ressource_map(resource_t *, level_t *);

#endif /* !LEVEL_H_ */
