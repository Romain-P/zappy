/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** FORK COMMAND
*/

#include <team.h>
#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_fork_t *fork_deserialize(char **args)
{
	packet_fork_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

void create_egg(player_t *player, packet_fork_t *packet)
{
	egg_t *egg;

	egg = malloc(sizeof(egg_t));
	if (egg == NULL)
		exit(84);
	egg->id = (server.map).nb_eggs;
	egg->x = player->x;
	egg->y = player->y;
	egg->layed = false;
	packet->egg = egg;
	(server.map).nb_eggs += 1;
	send_enw(player, (server.map).nb_eggs);
	send_pfk(player);
}

void add_spawn_team(player_t *player, packet_fork_t *packet)
{
	spawn_t *spawn = malloc(sizeof(spawn_t));
	player_t *each;

	send_eht(player, packet->egg);
	if (spawn == NULL)
		exit(84);
	spawn->x = player->x;
	spawn->y = player->y;
	(player->team)->spawn.size += 1;
	list_add(&(player->team)->spawn, spawn);
	for (iter_t *it = iter_begin(&server.pending_players); it; iter_next(it)) {
		each = it->data;
		if (player->team == each->team) {
			send_unwrapped(each->client,
			get_team_char(each, 0));
			send_unwrapped(each->client,
			get_team_char(each, 1));
			list_remove(&server.pending_players, each);
			list_add(&server.players, each);
			send_pnw(each);
			each->state = VALID_PLAYER;
			break;
		}
	}
}

bool fork_handler(player_t *player, packet_fork_t *packet)
{
	if (!packet->delayed) {
		create_egg(player, packet);
		delay(packet, (handler_t) &fork_handler, player, 42);
	}
	else {
		if (!packet->egg->layed) {
			send_unwrapped(player->client, "ok");
			packet->egg->layed = true;
		packet_fork_t *dup = malloc(sizeof(packet_fork_t));
		if (!dup)
		    exit(84);
		dup->egg = packet->egg;
		dup->delayed = true;
		delay(dup, (handler_t) &fork_handler, player, 300);
		}
		else {
			add_spawn_team(player, packet);
		}
	}
	return (false);
}

void fork_serialize(packet_fork_t *packet, list_t *buffer)
{
}