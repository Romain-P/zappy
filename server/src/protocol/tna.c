/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command TNA
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <string.h>

packet_tna_t *tna_deserialize(char **args)
{
	packet_tna_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

void tna_handler(player_t *player, packet_tna_t *packet)
{
	int i = 0;
	char **tab = charset_split(server.name, strlen(server.name), " ");

	while (tab[i] != NULL) {
		strcpy(packet->name, tab[i]);
		send_packet(player->client, "tna", &packet);
		i++;
	}
}

void tna_serialize(packet_tna_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->name));
}