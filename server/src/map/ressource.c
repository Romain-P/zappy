/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Map Ressource
*/

#include "map.h"
#include "zappy.h"

void generate_ressource(void)
{
	size_t nb = 0;
	size_t x = 0;
	size_t y = 0;
	map_t map = server.map;

	while (map.nb_ressource < map.max) {
		nb = rand() % 7;
		x = rand() % (map.width);
		y = rand() % (map.height);
		set_ressource_in_map(x, y, nb);
		map.nb_ressource++;
	}
}

static void set_ressource_in_map(size_t x, size_t y, size_t nb)
{
	resource_t *node = malloc(sizeof(resource_t));

	if (node == NULL) {
		puts("Malloc of Node FAIL");
		exit(84);
	}
	node->x = x;
	node->y = y;
	node->type = (resource_type_t) nb;
	list_add(&(server.map).ressources, node);
}