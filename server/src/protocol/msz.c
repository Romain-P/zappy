/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** MSZ Command
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

bool msz_handler(player_t *player, packet_msz_t *packet)
{
    packet_msz_t sample = {.x = server.width, .y = server.height};

    send_packet(player->client, &sample);
    return true;
}

packet_msz_t *msz_deserialize(char **args)
{
	packet_msz_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

void msz_serialize(packet_msz_t *packet, list_t *buffer)
{
    list_add(buffer, to_string(packet->x));
    list_add(buffer, to_string(packet->y));
}