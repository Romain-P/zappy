//
// Created by romain on 20/06/18.
//

#include <string>
#include <cstdlib>
#include <AIController.h>

int main(int ac, char **args) {
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

    zappy_init_connector_ai("86.202.209.67", 4242, false, handlers);
}