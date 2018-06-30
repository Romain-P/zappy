/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Team Management
*/

#include <stderr.h>
#include "zappy.h"
#include "team.h"
#include "protocol.h"

void init_coord_player(player_t *player, team_t *team)
{
	spawn_t *list;
	iter_t *it;

	for (it = iter_begin(&team->spawn); it; iter_next(it)) {
		list = it->data;
		player->x = list->x;
		player->y = list->y;
		list_remove(&team->spawn, list);
		free(list);
		team->spawn.size -= 1;
		return;
	}
}

void init_player_join(player_t *player, team_t *team)
{
	if ((team->spawn).size == 0) {
		player->x = rand() % (server.map).width;
		player->y = rand() % (server.map).height;
	}
	else
		init_coord_player(player, team);
	player->team = team;
	player->orientation = (rand() % 4) + 1;
	player->level = 1;
	(player->inventory).q0 = 0;
	(player->inventory).q1 = 1;
	(player->inventory).q2 = 0;
	(player->inventory).q3 = 0;
	(player->inventory).q4 = 0;
	(player->inventory).q5 = 0;
	(player->inventory).q6 = 0;
	player->is_gui = 0;
	send_pnw(player);
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
		sprintf(packet, "%d", (player->team)->player);
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
	team->player = server.nb_clients;
	(team->spawn) = *list_new();
	(team->spawn).size = 0;
	list_add(&server.teams, team);
}