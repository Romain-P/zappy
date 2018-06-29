/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Client Handler
*/

#include <unistd.h>
#include "network.h"
#include "stderr.h"
#include "zappy.h"
#include "util.h"

static void on_connect(network_client_t *client)
{
	player_t *player = malloc(sizeof(player_t));

	if (player == NULL)
		return;
	eprintf("[Client %d] connected\n", client->id);
	player->client = client;
	player->state = AWAIT_TEAM_NAME;
	player->waiting_commands = 0;
	list_add(&server.players, player);
	if (server.players.size == 1) {
        player->initialized = true;
		send_unwrapped(client, "WELCOME");
	} else
		player->initialized = false;
}

static void on_disconnect(network_client_t *client)
{
	player_t *found = find_player(client);

	if (found) {
		list_remove(&server.players, found);
		free(found);
	}
	eprintf("[Client %d] disconnected\n", client->id);
}

static void on_received(network_client_t *client,
	char const *packet, size_t len)
{
	player_t *found = find_player(client);

	eprintf("[Server] Recv \t<--\t[Client %d]:\t\t", client->id);
	fflush(stderr);
	write(STDERR_FILENO, packet, len);
	eprintf("\n");
	if (found)
		parse_packet(client, packet, len);
}

static void on_sent(network_client_t *client, char const *packet, size_t len)
{
	eprintf("[Server] Sent \t-->\t[Client %d]:\t\t", client->id);
	fflush(stderr);
	write(STDERR_FILENO, packet, len - 1);
	eprintf("\n");
}

void configure_client_handler(client_handler_t *handler)
{
	handler->on_received = &on_received;
	handler->on_connect = &on_connect;
	handler->on_sent = &on_sent;
	handler->on_disconnect = &on_disconnect;
}