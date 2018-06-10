#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "stderr.h"
#include "network.h"
#include "zappy.h"
#include "arguments.h"

zappy_instance_t server = {
        .players = list_init
};

static void on_server_close() {
    //free anything we want (players already freed by network see @on_disconnect)
}

int main(int ac, char **args) {
    get_arguments(ac, args);

    network_server_t server;
    server_config_t config = {
            .host = INADDR_ANY,
            .port = atoi(args[1]),
            .packet_delimiter = ZAPPY_ARG_DELIMITER,
            .packet_max_size = ZAPPY_BUFFER_SIZE,
            .configure_handlers = &configure_client_handler,
            .on_server_close = &on_server_close
    };

    network_server_start(&server, &config);
    return 0;
}