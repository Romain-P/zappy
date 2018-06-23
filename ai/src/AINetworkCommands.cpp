//
// Created by romain on 22/06/18.
//

#include "AINetworkCommands.h"

namespace AINetworkCommands {
    void requestMoveForward(session_t client) {
        send_unwrapped(client, "Forward");
    }

    void requestMoveLeft(session_t client) {
        send_unwrapped(client, "Left");
    }

    void requestMoveRight(session_t client) {
        send_unwrapped(client, "Right");
    }

    void requestFork(session_t client) {
        send_unwrapped(client, "Fork");
    }

    void requestLook(session_t client) {
        send_unwrapped(client, "Look");
    }

    void requestInventory(session_t client) {
        send_unwrapped(client, "Inventory");
    }

    void requestBroadcast(session_t client, std::string text) {
        std::string cmd("Broadcast");
        cmd += " ";
        cmd += text;
        send_unwrapped(client, &cmd[0]);
    }

    void requestRemainingConnections(session_t client) {
        send_unwrapped(client, "Connect_nbr");
    }

    void requestEject(session_t client) {
        send_unwrapped(client, "Eject");
    }

    void requestTakeObject(session_t client, std::string object) {
        std::string cmd("Take");
        cmd += " ";
        cmd += object;
        send_unwrapped(client, &cmd[0]);
    }

    void requestLeaveObject(session_t client, std::string object) {
        std::string cmd("Set");
        cmd += " ";
        cmd += object;
        send_unwrapped(client, &cmd[0]);
    }

    void requestIncantation(session_t client) {
        send_unwrapped(client, "Incantation");
    }

    void sendTeamName(session_t client, std::string &team) {
        send_unwrapped(client, &team[0]);
    }
}