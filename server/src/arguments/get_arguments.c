/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Get argument of server binary
*/

#include "zappy.h"
#include "util.h"
#include "arguments.h"

void get_arguments(int ac, char **av)
{
	int c;
	int argument;

	initialize_options();
	c = getopt(ac, av, "p:x:y:n:c:f:");
	while (c != -1) {
		argument = set_argument(c);
		if (argument == 1)
			print_usage();
		c = getopt(ac, av, "p:x:y:n:c:f:");
	}
	set_team();
}

static void set_team(void)
{
	int i = 0;
	char **split = charset_split(server.name, strlen(server.name), " ");

	while (split[i] != NULL) {
		add_team(split[i]);
		i++;
	}
}

static void initialize_options(void)
{
	server.port = 5050;
	server.width = 50;
	server.height = 50;
	server.name = strdup("Team 1 Team2 Team3 Team4");
	server.nb_clients = 50;
	server.freq = 50;
}

static void print_usage(void)
{
	printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2");
	printf(" ... -c clientsNb -f freq\n");
	printf("\tport\t\tis the port number\n");
	printf("\twidth\t\tis the width of the world\n");
	printf("\theight\t\tis the height of the world\n");
	printf("\tnameX\t\tis the name of the team X\n");
	printf("\tcliensNb\tis the number of authorized clients per team\n");
	printf("\tfreq\t\tis the reciprocal of time unit for execution of actions\n");
	exit(84);
}

static int set_argument(int c)
{
	if (c == 'p')
		server.port = atoi(optarg);
	if (c == 'x')
		server.width = atoi(optarg);
	if (c == 'y')
		server.height = atoi(optarg);
	if (c == 'n')
		server.name = strdup(optarg);
	if (c == 'c')
		server.nb_clients = atoi(optarg);
	if (c == 'f')
		server.freq = atoi(optarg);
	if (c == '?')
		return (1);
	return (0);
}