/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Map Management
*/

#include "zappy.h"

void set_width_map(size_t width)
{
	(server.map).width = width;
}

void set_height_map(size_t height)
{
	(server.map).height = height;
}

void set_max_ressource_map(void)
{
	size_t x = (server.map).width;
	size_t y = (server.map).height;

	(server.map).max =
		((x * y) - (x));
	(server.map).nb_ressource = 0;
}