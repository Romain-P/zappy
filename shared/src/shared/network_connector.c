//
// Created by romain on 19/05/18.
//

#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <lib.h>
#include "network.h"
#include "network_epoll.h"
#include "stderr.h"

static int create_socket(network_instance_t *instance) {
    int new = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(instance->config->host);
    sin.sin_port = htons(instance->config->port);

    if (connect(new, (struct sockaddr *) &sin, sizeof(sin)) == ERROR)
        return (ERROR);
    return new;
}

static network_client_t *hold_new_client(network_instance_t *instance, session_t id) {
    epoll_add_client(instance->epoll_id, id);

    network_client_t *client = malloc(sizeof(network_client_t));
    client->id = id;
    client->length = 0;
    client->server = instance;
    client->closed = false;
    client->bstate = FREED;

    list_add(&instance->clients, client);
    instance->client_handler.on_connect(client);
    return client;
}

static void read_data(network_instance_t *instance, int client) {
    char buffer[NETWORK_READ_SIZE];

    ssize_t bytes = read(client, buffer, NETWORK_READ_SIZE);
    network_client_t *found = network_client_find(&instance->clients, client);

    if (bytes <= 0)
        network_client_close(found);
    else
        network_client_read(instance, found, buffer, (size_t) bytes);

    if (found->closed) {
        if (!zappy_instance.thread_sync)
            instance->client_handler.on_disconnect(found);
        else
            zappy_instance.onDisconnect = found->id;
        list_remove(&instance->clients, found);
        network_client_free(found);

        if (instance->clients.size == 0)
            epoll_stop();
    }
}

static void on_client_ready(session_t client, void *server_ptr) {
    network_instance_t *server = server_ptr;

    if (client == ERROR) {
        for (iter_t *it = iter_begin(&server->clients); it; iter_next(it)) {
            network_client_t *nc = it->data;
            if (!zappy_instance.thread_sync)
                server->client_handler.on_disconnect(nc);
            network_client_close(nc);
        }
        zappy_instance.onDisconnect = client;
        list_clear(&server->clients, &network_client_free);
        server->config->on_server_close();
    }
    else
        read_data(server, client);
}

network_client_t *network_new_connection(network_instance_t *instance) {
    session_t socket_id = create_socket(instance);
    if (socket_id == ERROR)
        return NULL;
    return hold_new_client(instance, socket_id);
}

bool network_connector_start(network_instance_t *instance, network_config_t *config) {
    instance->config = config;
    instance->clients = list_init;
    instance->config->configure_handlers(&instance->client_handler);
    if ((instance->epoll_id = (session_t) epoll_create(1)) == ERROR)
        raise_error("Network epoll error: can't create epoll net\n");
    if (!network_new_connection(instance)) {
        close(instance->epoll_id);
        return false;
    }
    epoll_config_t econfig = {
            .on_data = &on_client_ready,
            .on_unblocked = config->on_unblocked,
            .timeout = -1
    };
    epoll_listen(instance->epoll_id, &econfig, instance);
    return true;
}