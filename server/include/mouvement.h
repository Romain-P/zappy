/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Mouvement HEADER
*/

#ifndef MOUVEMENT_H_
	#define MOUVEMENT_H_

	#include "zappy.h"
	#include <stdlib.h>

	int get_valid_direction(player_t *, size_t);
	void increment_direction(size_t *, size_t *, size_t);
	int check_player_in_tile(size_t x, size_t y);

#endif /* !MOUVEMENT_H_ */
