/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Mouvement of player
*/

#include "zappy.h"
#include "mouvement.h"

int get_valid_direction(player_t *player, size_t direction)
{
	int x = (int) player->x;
	int y = (int) player->y;

	increment_direction(&x, &y, direction);
	if (check_player_in_tile(x, y) == 1)
		return (1);
	player->x = (size_t) x;
	player->y = (size_t) y;
	return (0);
}

void increment_direction(int *x, int *y, size_t direction)
{
	if (direction == 1)
		*y = *y - 1;
	if (direction == 2)
		*x = *x + 1;
	if (direction == 3)
		*y = *y + 1;
	if (direction == 4)
		*x = *x - 1;
	if (*x == ((server.map).width))
		*x = 0;
	if (*y == ((server.map).height))
		*y = 0;
	if (*y == -1)
		*y = ((server.map).height) - 1;
	if (*x == -1)
		*x = ((server.map).width) - 1;
}

int check_player_in_tile(size_t x, size_t y)
{
	player_t *player;
	iter_t *it;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		if (player->x == x && player->y == y)
			return (1);
	}
	return (0);
}