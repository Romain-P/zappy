/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIN Command
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

packet_pin_t *pin_deserialize(char **args)
{
	packet_pin_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (args[0][0] == '#')
		args[0]++;
	if (!parse_int(args[0], &packet->player_number)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

void pin_handler(player_t *player, packet_pin_t *packet)
{
	packet->x = 0;
	packet->y = 0;
	packet->q0 = 0;
	packet->q1 = 0;
	packet->q2 = 0;
	packet->q3 = 0;
	packet->q4 = 0;
	packet->q5 = 0;
	packet->q6 = 0;
	send_packet(player->client, "pin", &packet);
}

void pin_serialize(packet_pin_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->q0));
	list_add(buffer, to_string(packet->q1));
	list_add(buffer, to_string(packet->q2));
	list_add(buffer, to_string(packet->q3));
	list_add(buffer, to_string(packet->q4));
	list_add(buffer, to_string(packet->q5));
	list_add(buffer, to_string(packet->q6));
}