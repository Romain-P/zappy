/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Team Management
*/

#ifndef TEAM_H_
	#define TEAM_H_

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "zappy.h"

	void add_team(char *);
	void init_player_join(player_t *, team_t *);
	int check_free_team(player_t *, char *);
	char *get_team_char(player_t *, size_t);

#endif /* !TEAM_H_ */
