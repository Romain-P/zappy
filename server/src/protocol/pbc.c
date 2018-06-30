/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PBC Command
*/


#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_pbc(player_t *player, char *text)
{
	char *packet = malloc(sizeof(char) * strlen("pbc")
	+ 10);
	player_t *list;
	iter_t *it;

	if (player->is_gui == 0)
		return;
	if (packet == NULL)
		exit(84);
	sprintf(packet, "pbc %d %s", player->client->id, text);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui == 1)
			send_unwrapped(list->client, packet);
	}
	free(packet);
}

void loop_segment(int *x, int *y, int map_x, int map_y)
{
	int save_x = *x;
	int save_y = *y;
	int value = set_segment(save_x + map_x, save_y + map_y, *x, *y);

	if (value == 1)
		change_value(x, y, save_x + map_x, save_y + map_y);
	value = set_segment(save_x + map_x, save_y - map_y, *x , *y);
	if (value == 1)
		change_value(x, y, save_x + map_x, save_y - map_y);
	value = set_segment(save_x + map_x, save_y, *x, *y);
	if (value == 1)
		change_value(x, y, save_x + map_x, save_y);
	loop_segment2(x, y, save_x, save_y);
}

int set_segment(int x, int y, int dx, int dy)
{
	double height;
	double width;

	height = sqrt((y * y) + (x * x));
	width = sqrt((dy * y) + (dx * dx));
	if (width <= height)
		return (0);
	return (1);
}

void change_value(int *x, int *y, int dx, int dy)
{
	*x = dx;
	*y = dy;
}

void loop_segment2(int *x, int *y, int save_x, int save_y)
{
	int map_x = (server.map).width;
	int map_y = (server.map).height;
	int value = set_segment(save_x - map_x, save_y + map_y, *x, *y);

	if (value == 1)
		change_value(x, y, save_x - map_x, save_y + map_y);
	value = set_segment(save_x - map_x, save_y - map_y, *x, *y);
	if (value == 1)
		change_value(x, y, save_x - map_x, save_y - map_y);
	value = set_segment(save_x - map_x, save_y, *x, *y);
	if (value == 1)
		change_value(x, y, save_x - map_x, save_y);
	value = set_segment(save_x, save_y + map_y, *x, *y);
	if (value == 1)
		change_value(x, y, save_x, save_y + map_y);
	value = set_segment(save_x, save_y - map_y, *x, *y);
	if (value == 1)
		change_value(x, y, save_x, save_y - map_y);	
}