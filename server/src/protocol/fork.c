/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** FORK COMMAND
*/

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
	//list_add(&(server.map).eggs, egg);
}

void add_spawn_team(player_t *player)
{
	spawn_t *spawn = malloc(sizeof(spawn_t));

	send_unwrapped(player->client, "egg ok");
	if (spawn == NULL)
		exit(84);
	spawn->x = player->x;
	spawn->y = player->y;
	(player->team)->spawn.size += 1;
	list_add(&(player->team)->spawn, spawn);
}

bool fork_handler(player_t *player, packet_fork_t *packet)
{
	if ((player->team)->player == 0) {
		send_unwrapped(player->client, "ko");
		return (false);
	}
	if (!packet->delayed) {
		create_egg(player, packet);
		delay(packet,
		(handler_t) &fork_handler, player, 42);
	}
	else {
		if (!packet->egg->layed) {
			send_unwrapped(player->client, "ok");
			packet->egg->layed = true;
			delay(packet, (handler_t) &fork_handler, player, 300);
		}
		else
			add_spawn_team(player);
	}
	return (false);
}

void fork_serialize(packet_fork_t *packet, list_t *buffer)
{
}