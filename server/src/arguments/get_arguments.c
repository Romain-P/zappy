/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Get argument of server binary
*/

#include "zappy.h"
#include "util.h"
#include "arguments.h"
#include "map.h"

static int set_argument(int c)
{
	switch(c) {
		case 'p':
			server.port = atoi(optarg);
			break;
		case 'x':
			set_width_map(atoi(optarg));
			break;
		case 'y':
			set_height_map(atoi(optarg));
			break;
		case 'n':
			server.name = strdup(optarg);
			break;
		case 'c':
			server.nb_clients = atoi(optarg);
			break;
		case 'f':
			server.freq = atoi(optarg);
			break;
		case '?':
		default:
			return (1);
	}
	return (0);
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

static void initialize_options(void)
{
	server.port = 5050;
	(server.map).width = 50;
	(server.map).height = 50;
	server.name = strdup("Team 1 Team2 Team3 Team4");
	server.nb_clients = 50;
	server.freq = 50;
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
	set_max_ressource_map();
	generate_ressource();
}