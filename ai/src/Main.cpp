//
// Created by romain on 20/06/18.
//

#include <string>
#include <cstdlib>
#include <unistd.h>
#include <cstdlib>
#include <AIController.h>
#include <getopt.h>
#include <iostream>

static void display_help(char *path) {
    std::cerr << "USAGE: " << path << ":  -p port -n name -h host address" << std::endl;
    std::cerr << "\t-p\t is the port number" << std::endl;
    std::cerr << "\t-n\t is the name of the team" << std::endl;
    std::cerr << "\t-h\t is the remote host address" << std::endl;
}

static bool parse_options(int argc, char **argv, uint16_t &port, std::string &host) {
    int opt;
    char *path = *argv;
    int optcount = 0;

    while ((opt = getopt(argc, argv, "p:n:h:")) != -1) {
        optcount++;
        switch (opt) {
            case 'p':
                port = static_cast<uint16_t>(atoi(optarg));
                break;
            case 'n':
                AIController::manager.getTeam() = std::string(optarg);
                break;
            case 'h':
                host = std::string(optarg);
                break;
            default:
                goto error;
        }
    }

    if (optcount != 2 && optcount != 3) {
        std::cerr << "Too many or not enough options" << std::endl;
        error:
        display_help(path);
        return false;
    }
    return true;
}

int main(int ac, char **args) {
    uint16_t port;
    std::string host = "127.0.0.1";

    if (!parse_options(ac, args, port, host))
        return (EXIT_FAILURE);

    ai_handlers_t handlers = {
            &AIController::on_connect,
            &AIController::on_disconnect,
            &AIController::on_welcome,
            &AIController::on_look_reply,
            &AIController::on_message_reply,
            &AIController::on_connect_nummber_reply,
            &AIController::on_inventory_reply,
            &AIController::on_unwrapped
    };

    if (!zappy_init_connector_ai(&host[0], port, false, handlers)) {
        std::cerr << "Impossible to connect: check your internet connection" << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}