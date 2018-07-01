/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Network Server
*/

#include "network.h"
#include "network_epoll.h"
#include "stderr.h"

static void config_socket(network_server_t *server)
{
	struct sockaddr_in sin;
	int status = 1;

	server->id = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = server->config->host;
	sin.sin_port = htons(server->config->port);
	setsockopt(server->id,
		SOL_SOCKET, SO_REUSEADDR, &status, sizeof(status));
	bind(server->id, (struct sockaddr *)&sin, sizeof(sin));
	listen(server->id, SOMAXCONN);
}

static void new_connection(network_server_t *server)
{
	struct sockaddr_in in;
	socklen_t sz = sizeof(in);
	network_client_t *client;
	int new_connection =
		accept(server->id, (struct sockaddr *) &in, &sz);

	epoll_add_client(server->epoll_id, new_connection);
	client = malloc(sizeof(network_client_t));
	if (client == NULL)
		exit(84);
	client->id = new_connection;
	client->length = 0;
	client->server = server;
	client->closed = false;
	list_add(&server->clients, client);
	server->client_handler.on_connect(client);
}

static void read_data(network_server_t *server, int client)
{
	char buffer[NETWORK_READ_SIZE];
	ssize_t bytes =
		read(client, buffer, NETWORK_READ_SIZE);
	network_client_t *found =
		network_client_find(&server->clients, client);

	found->bstate = FREED;
	if (bytes <= 0)
		network_client_close(found);
	else
		network_client_read(server, found, buffer, (size_t) bytes);
	if (found->closed) {
		server->client_handler.on_disconnect(found);
		list_remove(&server->clients, found);
		network_client_free(found);
	}
}

static void on_client_ready(session_t client, void *server_ptr)
{
	network_server_t *server = server_ptr;
	network_client_t *nc;
	iter_t *it;

	if (client == ERROR) {
		for (it = iter_begin(&server->clients); it; iter_next(it)) {
			nc = it->data;
			server->client_handler.on_disconnect(nc);
			network_client_close(nc);
		}
		list_clear(&server->clients, &network_client_free);
		close(server->id);
		server->config->on_server_close();
	} else if (client == server->id)
		new_connection(server);
	else
		read_data(server, client);
}

void network_server_start(network_server_t *server, server_config_t *config)
{
	server->config = config;
	config_socket(server);
	server->epoll_id = (session_t) epoll_create_instance(server->id);
	if (server->epoll_id == ERROR)
		raise_error(
		"Network epoll error: can't create epoll instance\n");
	server->clients = list_init;
	server->config->configure_handlers(&server->client_handler);
	epoll_listen(server->epoll_id,
	(epoll_config_t)
	{&on_client_ready, server->config->on_unblocked}, server);
}