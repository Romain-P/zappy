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
    struct signalfd_siginfo info;
    epoll_t ev;
    sigset_t all;
    sigset_t sw;

    sigfillset(&all);
    sigprocmask(SIG_SETMASK, &all, NULL);
    sigemptyset(&sw);
    sigaddset(&sw, SIGINT);

    int signal_fd = signalfd(-1, &sw, 0);
    epoll_add_client(epoll_instance, signal_fd);

    while (true) {
        if (!listen)
            goto closed;
        int rdy = epoll_wait(epoll_instance, &ev, 1, config->timeout);
        if (config->on_unblocked)
            config->on_unblocked();
        if (!rdy)
            continue;

        int client_notifier = ev.data.fd;

        if (client_notifier == signal_fd) {
            if (read(signal_fd, &info, sizeof(info)) != sizeof(info))
                continue;
            else if (info.ssi_signo == SIGINT) {
                closed:
                config->on_data(-1, network_ptr);
                break;
            }
        }
        else
            config->on_data(client_notifier, network_ptr);
    }

    epoll_del_client(epoll_instance, signal_fd);
    close(signal_fd);
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