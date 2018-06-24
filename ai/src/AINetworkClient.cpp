//
// Created by romain on 24/06/18.
//

#include "AINetworkClient.h"


void AINetworkClient::requestMoveForward() {
    send_unwrapped(_id, "Forward");
}

void AINetworkClient::requestMoveLeft() {
    send_unwrapped(_id, "Left");
}

void AINetworkClient::requestMoveRight() {
    send_unwrapped(_id, "Right");
}

void AINetworkClient::requestFork() {
    send_unwrapped(_id, "Fork");
}

void AINetworkClient::requestLook() {
    send_unwrapped(_id, "Look");
}

void AINetworkClient::requestInventory() {
    send_unwrapped(_id, "Inventory");
}

void AINetworkClient::requestBroadcast(std::string &text) {
    std::string cmd("Broadcast");
    cmd += " ";
    cmd += text;
    send_unwrapped(_id, &cmd[0]);
}

void AINetworkClient::requestRemainingConnections() {
    send_unwrapped(_id, "Connect_nbr");
}

void AINetworkClient::requestEject() {
    send_unwrapped(_id, "Eject");
}

void AINetworkClient::requestTakeObject(std::string &object) {
    std::string cmd("Take");
    cmd += " ";
    cmd += object;
    send_unwrapped(_id, &cmd[0]);
}

void AINetworkClient::requestLeaveObject(std::string &object) {
    std::string cmd("Set");
    cmd += " ";
    cmd += object;
    send_unwrapped(_id, &cmd[0]);
}

void AINetworkClient::requestIncantation() {
    send_unwrapped(_id, "Incantation");
}

void AINetworkClient::sendTeamName(std::string &team) {
    send_unwrapped(_id, &team[0]);
}

AINetworkClient::NetworkState &AINetworkClient::getNetworkState() {
    return _state;
}