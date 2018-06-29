/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Ressource Tile
*/

#include "look.h"

void set_player_count_look(size_t count, char *str)
{
	size_t i = 0;

	while (i < count) {
		if (i + 1 == count)
			strcat(str, "player");
		else {
			strcat(str, "player ");
		}
		i++;
	}
}

int get_size_look(char **tab)
{
	size_t i = 0;
	size_t size = 0;

	while (tab[i] != NULL)
		size += strlen(tab[i++]);
	return (size + (i + i + 2));
}

char *prepare_packet_look(char **tab)
{
	char *packet = malloc(sizeof(char) * get_size_look(tab));
	int i = 0;

	if (packet == NULL)
		exit(84);
	packet[0] = '\0';
	strcat(packet, "[");
	while (tab[i] != NULL) {
		strcat(packet, tab[i]);
		if (tab[i + 1] && tab[i + 1][0] == '\0')
			strcat(packet, ",");
		else if (tab[i + 1] != NULL)
			strcat(packet, ", ");
		i++;
	}
	strcat(packet, "]");
	return (packet);
}

size_t get_count_tile(size_t level)
{
	size_t tile = 3;
	size_t i = 0;

	while (i < level) {
		tile += (tile + 2);
		i++;
	}
	return (tile + 1);
}