/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Network Epoll
*/

#include "network_epoll.h"
#include "stderr.h"
#include "util.h"

void init_epoll(void)
{
	sigset_t all;

	sigfillset(&all);
	sigprocmask(SIG_SETMASK, &all, NULL);
}

void epoll_listen(session_t epoll_instance,
	epoll_config_t config, void *network_ptr)
{
	epoll_t ev;
	sigset_t sw;
	int signal_fd;
	int rdy;

	sigemptyset(&sw);
	sigaddset(&sw, SIGINT);
	signal_fd = signalfd(-1, &sw, 0);
	epoll_add_client(epoll_instance, signal_fd);
	while (true) {
		rdy = epoll_wait(epoll_instance, &ev, 1, 10);
		config.on_unblocked();
		if (!rdy)
			continue;
		rdy = read_content(signal_fd, ev, config, network_ptr);
		if (rdy == 1)
			break;
	}
	epoll_del_client(epoll_instance, signal_fd);
	close(signal_fd);
}

ssize_t epoll_create_instance(network_server_id_t server)
{
	session_t epoll_instance = epoll_create(1);
	bool client = epoll_add_client(epoll_instance, server);

	if (client)
		return (epoll_instance);
	else
		return (-1);
}

bool epoll_add_client(session_t epoll_id, session_t id)
{
	epoll_t epoll = { 0 };
	int pol;

	epoll.events = EPOLLIN;
	epoll.data.fd = id;
	pol = epoll_ctl(epoll_id, EPOLL_CTL_ADD, id, &epoll);
	if (pol == ERROR) {
		eprintf(
		"[EpollInstance %d]: error adding new client (id=%d)\n",
		epoll_id, id);
		return (false);
	}
	return (true);
}

bool epoll_del_client(session_t epoll_id, session_t id)
{
	epoll_t epoll = { 0 };
	int pol;

	epoll.events = EPOLLIN;
	epoll.data.fd = id;
	pol = epoll_ctl(epoll_id, EPOLL_CTL_DEL, id, &epoll);
	if (pol == ERROR) {
		eprintf(
		"[EpollInstance %d]: error deleting new client (id=%d)\n",
		epoll_id, id);
		return (false);
	}
	return (true);
}