/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Ressource for incantation
*/

#include "level.h"

level_t *get_delete_level(level_t const *level)
{
	level_t *delete = malloc(sizeof(level_t));

	if (delete == NULL)
		exit(84);
	delete->q1 = level->q1;
	delete->q2 = level->q2;
	delete->q3 = level->q3;
	delete->q4 = level->q4;
	delete->q5 = level->q5;
	delete->q6 = level->q6;
	return (delete);
}

size_t get_valid_ressource(resource_t *ressource, level_t *level)
{
	if (ressource->type == 1 && level->q1 > 0)
		return (1);
	if (ressource->type == 2 && level->q2 > 0)
		return (1);
	if (ressource->type == 3 && level->q3 > 0)
		return (1);
	if (ressource->type == 4 && level->q4 > 0)
		return (1);
	if (ressource->type == 5 && level->q5 > 0)
		return (1);
	if (ressource->type == 6 && level->q6 > 0)
		return (1);
	return (0);
}

void unset_ressource_map(resource_t *ressource, level_t *level)
{
	if (ressource->type == 1 && level->q1 > 0)
		level->q1 -= 1;
	if (ressource->type == 2 && level->q2 > 0)
		level->q2 -= 1;
	if (ressource->type == 3 && level->q3 > 0)
		level->q3 -= 1;
	if (ressource->type == 4 && level->q4 > 0)
		level->q4 -= 1;
	if (ressource->type == 5 && level->q5 > 0)
		level->q5 -= 1;
	if (ressource->type == 6 && level->q6 > 0)
		level->q6 -= 1;
}