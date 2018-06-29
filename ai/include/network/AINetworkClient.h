//
// Created by romain on 24/06/18.
//

#ifndef ZAPPY_AINETWORKCLIENT_H
#define ZAPPY_AINETWORKCLIENT_H


#include <zappy_network.h>
#include <string>
#include <queue>
#include <Types.h>

class AINetworkClient {

public:
    explicit AINetworkClient(session_t id) : _id(id), _state(AWAIT_ACCEPT), _pending() {}
    virtual ~AINetworkClient() = default;

    enum NetworkState {
        AWAIT_ACCEPT,
        AWAIT_REMAINING_PLAYERS,
        AWAIT_MAP_SIZE,
        READY
    };

    struct Request {
        std::string serialized;
        AIAction action;
    };

    void request(AIAction action, std::string const &param = "");
    AIAction popPending();
    NetworkState &getNetworkState();
    bool gotPendingTasks() const;
    void abortTasks();

private:

    session_t const _id;
    NetworkState _state;
    std::queue<Request> _pending;
};


#endif //ZAPPY_AINETWORKCLIENT_H
