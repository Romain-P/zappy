/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Network Client
*/

#include "network.h"
#include "util.h"
#include "network_epoll.h"

void network_client_close(network_client_t *client)
{
	epoll_del_client(client->server->epoll_id, client->id);
	close(client->id);
	client->closed = true;
}

void network_client_free(void *ptr)
{
	network_client_t *client = ptr;

	//if (client->bstate != FREED)
		//free(client->buffer);
	free(client);
}

network_client_t *network_client_find(list_t *network_clients, session_t id)
{
	network_client_t *current = NULL;
	iter_t *it;

	for (it = iter_begin(network_clients); it; iter_next(it)) {
		current = it->data;
		if (current->id == id)
			return (current);
	}
	return (NULL);
}

bool too_much_data(network_client_t *client, size_t size, size_t max_size)
{
	if (size <= max_size)
		return (false);
	free(client->buffer);
	client->length = 0;
	client->bstate = FREED;
	return (true);
}

void network_client_send(network_client_t *client, char *packet, size_t len)
{
	send(client->id, packet, len, 0);
	client->server->client_handler.on_sent(client, packet, len);
}