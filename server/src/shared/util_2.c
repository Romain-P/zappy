/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Util 2
*/

#include "util.h"

char **charset_split(char const *str, size_t len, char const *delimiter)
{
	char cpy[len + 1];
	ssize_t i = 0;
	char **tab = malloc(sizeof(char *) * 2);
	char *token;

	if (!str)
		return NULL;
	strncpy(cpy, str, len);
	cpy[len] = 0;
	for (token = strtok(cpy, delimiter); token;
	token = strtok(NULL, delimiter), i++) {
		if (i)
			tab = realloc(tab, sizeof(char *) * (i + 2));
		tab[i] = strdup(token);
	}
	tab[i] = NULL;
	return (tab);
}

void parcour_str(char *str, int shifter)
{
	do {
		++str;
		shifter = shifter/10;
	} while (shifter);
}

char *to_string(int i)
{
    static char hold[100];
    char const digit[] = "0123456789";
    char *p = hold;

    if(i<0) {
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do {
        ++p;
        shifter = shifter/10;
    } while(shifter);
    *p = '\0';
    do {
        *--p = digit[i%10];
        i = i/10;
    } while(i);
    return strdup(hold);
}

int read_content(int signal_fd, epoll_t ev,
	epoll_config_t config, void *network_ptr)
{
	int client_notifier = ev.data.fd;
	struct signalfd_siginfo info;

	if (client_notifier == signal_fd) {
		if (read(signal_fd, &info, sizeof(info)) != sizeof(info))
			return (0);
		else if (info.ssi_signo == SIGINT) {
			config.on_data(-1, network_ptr);
			return (1);
		}
	}
	else
		config.on_data(client_notifier, network_ptr);
	return (0);
}