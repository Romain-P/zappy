//
// Created by romain on 24/06/18.
//

#ifndef ZAPPY_AINETWORKCLIENT_H
#define ZAPPY_AINETWORKCLIENT_H


#include <zappy_network.h>
#include <string>

class AINetworkClient {

public:
    explicit AINetworkClient(session_t id) : _id(id) {}
    virtual ~AINetworkClient() = default;

    enum NetworkState {
        AWAIT_ACCEPT,
        AWAIT_REMAINING_PLAYERS,
        AWAIT_MAP_SIZE,
        READY
    };

    void requestMoveForward();
    void requestMoveLeft();
    void requestMoveRight();
    void requestFork();
    void requestLook();
    void requestInventory();
    void requestBroadcast(std::string &text);
    void requestRemainingConnections();
    void requestEject();
    void requestTakeObject(std::string &object);
    void requestLeaveObject(std::string &object);
    void requestIncantation();
    void sendTeamName(std::string &team);

    NetworkState &getNetworkState();

private:

    session_t const _id;
    NetworkState _state = AWAIT_ACCEPT;
};


#endif //ZAPPY_AINETWORKCLIENT_H
