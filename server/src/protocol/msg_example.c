/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command MSG
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

//delay of 10 tics
static size_t const DELAY = 10;

bool msg_example_handler(player_t *player, packet_example_t *msg)
{
	//packet received from network, delay it!
	if (!msg->delayed) {
		delay(msg, (handler_t) &msg_example_handler, player, DELAY);

		//packet received from delayManager, execute it now :)
	} else {
		packet_example_t to_send = {.shiet = 10, .some = 99};
		send_packet(player->client, &to_send);
		send_unwrapped(player->client, "ok");
		// packet delimiter automatically handled, dont put any \n
	}
	return (false);
}

packet_example_t *msg_example_deserialize(char **args)
{
	if (str_array_length(args) != 3)
		return (NULL);
	packet_example_t *packet = malloc(sizeof(*packet));
	if (!parse_int(args[0], &packet->some) || !parse_int(args[2], &packet->shiet)) {
		free(packet);
		return (NULL);
	}
	strcpy(packet->str, args[1]);
	return (packet);
}

void msg_example_serialize(packet_example_t *msg, list_t *buffer) {
	list_add(buffer, to_string((msg->some)));
	list_add(buffer, strdup(msg->str));
	list_add(buffer, to_string(msg->shiet));
}