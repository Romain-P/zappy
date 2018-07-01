//
// Created by romain on 19/05/18.
//

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/signalfd.h>
#include <unistd.h>
#include "network_epoll.h"
#include "stderr.h"

static bool listen = true;

void epoll_stop() {
    listen = false;
}

void epoll_listen(session_t epoll_instance, epoll_config_t *config, void *network_ptr) {
    epoll_t ev;

    while (true) {
        int rdy = epoll_wait(epoll_instance, &ev, 1, config->timeout);

        if (config->on_unblocked)
            config->on_unblocked();
        if (rdy) {
            int client_notifier = ev.data.fd;
            config->on_data((session_t) client_notifier, network_ptr);
        }
    }
}

bool epoll_add_client(session_t epoll_id, session_t id) {
    epoll_t epoll = { 0 };

    epoll.events = EPOLLIN;
    epoll.data.fd = id;
    if (epoll_ctl(epoll_id, EPOLL_CTL_ADD, id, &epoll) == ERROR) {
        eprintf("[EpollInstance %d]: error adding new client (id=%d)\n", epoll_id, id);
        return false;
    }
    return true;
}

bool epoll_del_client(session_t epoll_id, session_t id) {
    epoll_t epoll = { 0 };
    epoll.events = EPOLLIN;
    epoll.data.fd = id;

    if (epoll_ctl(epoll_id, EPOLL_CTL_DEL, id, &epoll) == ERROR) {
        eprintf("[EpollInstance %d]: error deleting new client (id=%d)\n", epoll_id, id);
        return false;
    }
    return true;
}