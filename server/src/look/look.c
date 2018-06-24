/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Look Command
*/

#include "look.h"

void loop_tile(player_t *player, packet_look_t *packet, size_t pos, char **tab)
{
	size_t i = 0;

	get_start_coord(player, packet, pos + 1);
	printf("Coord: %d - %d\n", packet->x, packet->y);
	while (i < packet->tile) {
		tab[packet->number] = get_content_tile(packet);
		increment_pos(packet, player);
		packet->number++;
		i++;
	}
}

void get_start_coord(player_t *player, packet_look_t *packet, size_t i)
{
	packet->y = player->y;
	packet->x = player->x;
	if (player->orientation == 1) {
		packet->y -= i;
		packet->x -= i;
	}
	if (player->orientation == 2) {
		packet->x += i;
		packet->y -= i;
	}
	if (player->orientation == 3) {
		packet->y += i;
		packet->x += i;
	}
	if (player->orientation == 4) {
		packet->x -= i;
		packet->y += i;
	}
	ajust_position(packet);
}

void increment_pos(packet_look_t *packet, player_t *player)
{
	if (player->orientation == 1)
		packet->x += 1;
	if (player->orientation == 2)
		packet->y += 1;
	if (player->orientation == 3)
		packet->x -= 1;
	if (player->orientation == 4)
		packet->y -= 1;
	ajust_position(packet);
}

void ajust_position(packet_look_t *packet)
{
	if (packet->y <= -1)
		packet->y = (server.map).height + (packet->y);
	if (packet->x >= (int) (server.map).width)
		packet->x = 0 + (packet->x - (server.map).width);
	if (packet->y >= (int) (server.map).height)
		packet->y = 0 + (packet->y - (server.map).height);
	if (packet->x <= -1)
		packet->x = (server.map).width + (packet->x);
}

char **get_result_look(player_t *player, packet_look_t *packet)
{
	int i = 0;
	char **tab = malloc(sizeof(char *) * get_count_tile(player->level));

	if (tab == NULL)
		exit(84);
	packet->level = player->level;
	tab[0] = strdup("player");
	packet->number = 1;
	while (i < player->level) {
		packet->x = 0;
		packet->y = 0;
		loop_tile(player, packet, i, tab);
		packet->tile += 2;
		i += 1;
	}
	tab[packet->number] = NULL;
	return (tab);
}