/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Team Management
*/

#include "zappy.h"
#include "team.h"

void init_player_join(player_t *player, team_t *team)
{
	player->x = rand() % (server.map).width;
	player->y = rand() % (server.map).height;
	player->team = *team;
	player->orientation = (rand() % 4) + 1;
	player->level = 2;
}

int check_free_team(player_t *player, char *name)
{
	team_t *team;
	iter_t *it;

	for (it = iter_begin(&server.teams); it; iter_next(it)) {
		team = it->data;
		if (!strcmp(team->name, name) && team->player > 0) {
			team->player--;
			init_player_join(player, team);
			return (1);
		}
	}
	return (0);
}

char *get_team_char(player_t *player, size_t status)
{
	char *packet = malloc(sizeof(char) * 10);

	if (packet == NULL)
		exit(84);
	if (status == 0)
		sprintf(packet, "%d", (player->team).player);
	else
		sprintf(packet, "%zu %zu",
		(server.map).width, (server.map).width);
	return (packet);
}

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