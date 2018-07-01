//
// Created by romain on 24/06/18.
//

#include <cstring>
#include <network/AINetworkController.h>
#include <AIManager.h>
#include "network/AINetworkClient.h"

AINetworkClient::NetworkState &AINetworkClient::getNetworkState() {
    return _state;
}

void AINetworkClient::request(AIAction action, std::string const &param) {
    static const char *serialized[] = {
            "Forward",
            "Left",
            "Right",
            "Fork",
            "Look",
            "Inventory",
            "Broadcast",
            "Connect_nbr",
            "Eject",
            "Take",
            "Set",
            "Incantation"
    };

    if (_state != READY) return;

    std::string data(serialized[action]);
    if (!param.empty()) {
        data += " ";
        data += param;
    }
    _pending.push((Request) { data, action });
    if (_pending.size() == 1)
        send_unwrapped(_id, &data[0]);
}

AIAction AINetworkClient::popPending() {
    AIAction action = _pending.front().action;
    _pending.pop();

    if (!_pending.empty()) {
        Request &request = _pending.front();
        send_unwrapped(_id, &request.serialized[0]);
    }

    return action;
}

bool AINetworkClient::gotPendingTasks() const {
    return !_pending.empty();
}

void AINetworkClient::abortTasks() {
    if (_pending.size() <= 1) return;

    Request request = _pending.front();
    while (!_pending.empty())
        _pending.pop();
    _pending.push(request);
}