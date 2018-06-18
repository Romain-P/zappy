//
// Created by romain on 26/05/18.
//

#ifndef MYIRC_NETWORK_EPOLL_H
#define MYIRC_NETWORK_EPOLL_H

#include <sys/types.h>
#include <time.h>
#include <stdbool.h>

#define ERROR   (-1)

typedef int session_t;
typedef int network_server_id_t;
typedef struct epoll_event epoll_t;
typedef void (*on_data_received)(session_t client, void *server_ptr);
typedef void (*on_epoll_unblocked)();
typedef struct epoll_config_s epoll_config_t;

struct epoll_config_s {
    on_data_received on_data;
    on_epoll_unblocked on_unblocked;
};

void epoll_listen(session_t epoll_instance, epoll_config_t callback, void *server_ptr);

ssize_t epoll_create_instance(network_server_id_t server);

bool epoll_add_client(session_t epoll_id, session_t new);

bool epoll_del_client(session_t epoll_id, session_t del);

#endif //MYIRC_NETWORK_EPOLL_H
