/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Team Management
*/

#include "zappy.h"

void add_team(char *name)
{
	team_t *team = malloc(sizeof(team_t));

	if (team == NULL) {
		puts("Malloc Fail");
		exit(84);
	}
	if (strlen(name) >= 1023) {
		puts("Too long Team Name");
		exit(84);
	}
	team->name = strdup(name);
	team->player = 6;
	list_add(&server.teams, team);
}