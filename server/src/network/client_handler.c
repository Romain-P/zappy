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

<<<<<<< HEAD
    player->client = client;
    (player->inventory).q0 = 0;
    (player->inventory).q1 = 0;
    (player->inventory).q2 = 0;
    (player->inventory).q3 = 0;
    (player->inventory).q4 = 0;
    (player->inventory).q5 = 0;
    (player->inventory).q6 = 0;
    player->state = AWAIT_TEAM_NAME;
    player->waiting_commands = 0;
    list_add(&server.players, player);
    send_unwrapped(client, "WELCOME");
    player->level = 0;
=======
	if (player == NULL)
		exit(84);
	eprintf("[Client %d] connected\n", client->id);
	player->client = client;
	(player->inventory).q0 = 0;
	(player->inventory).q1 = 0;
	(player->inventory).q2 = 0;
	(player->inventory).q3 = 0;
	(player->inventory).q4 = 0;
	(player->inventory).q5 = 0;
	(player->inventory).q6 = 0;
	player->state = AWAIT_TEAM_NAME;
	player->waiting_commands = 0;
	list_add(&server.players, player);
	send_unwrapped(client, "WELCOME");
	player->level = 0;
	eprintf("[Client %d] connected\n", client->id);
>>>>>>> 1c0df150719986fac7240e5426dbf7096c1c9726
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

<<<<<<< HEAD
static void on_sent(network_client_t *client, char const *packet, size_t len) {
    eprintf("[Server] Sent \t-->\t[Client %d]:\t\t", client->id);
    fflush(stderr);
    write(STDERR_FILENO, packet, len - 1);
    eprintf("\n");
}

static void on_received(network_client_t *client, char const *packet, size_t len) {
    eprintf("[Server] Recv \t<--\t[Client %d]:\t\t", client->id);
    fflush(stderr);
    write(STDERR_FILENO, packet, len);
    eprintf("\n");
=======
static void on_received(network_client_t *client,
	char const *packet, size_t len)
{
	player_t *found = find_player(client);
>>>>>>> 1c0df150719986fac7240e5426dbf7096c1c9726

	eprintf("[Server] Recv \t<--\t[Client %d]:\t\t", client->id);
	fflush(stderr);
	write(STDERR_FILENO, packet, len);
	eprintf("\n");
	if (found)
		parse_packet(client, packet, len);
}

<<<<<<< HEAD
void configure_client_handler(client_handler_t *handler) {
    handler->on_received = &on_received;
    handler->on_connect = &on_connect;
    handler->on_sent = &on_sent;
    handler->on_disconnect = &on_disconnect;
=======
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
>>>>>>> 1c0df150719986fac7240e5426dbf7096c1c9726
}