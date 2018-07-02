//
// Created by romain on 23/06/18.
//

#ifndef ZAPPY_AIPLAYER_H
#define ZAPPY_AIPLAYER_H


#include <string>
#include "zappy_network.h"
#include "network/AINetworkClient.h"
#include "Types.h"
#include "AbstractAI.h"
#include "BasicAI.h"
#include <memory>

class AIPlayer: public AINetworkClient {
public:
    explicit AIPlayer(session_t id) :
            AINetworkClient(id),
            _inventory(),
            _ai(std::make_unique<BasicAI>(*this)),
            _looked(),
            _lastSource(DIR_UNKNOWN),
            _readyToBroadcast(false)
    {
        for (size_t type = LINEMATE; type != UNDEFINED; type++)
            _inventory[static_cast<ObjectType>(type)] = 0;
    }

    enum State {
        CASTING,
        CASTER_READY,
        MOVING_TO_CASTER,
        READY_TO_LEAVE_ITEMS,
        READY_TO_CAST,
        WORKING
    };

    void addItem(ObjectType type, size_t count = 1);
    void delItem(ObjectType type, size_t count = 1);
    void updateItems(objects_t &&items);
    bool &readyToBroadcast();

    objects_t const &getObjects() const;
    State &getState();
    AbstractAI &getAI();
    cells_t &getLooked();
    SoundSource &getLastSoundSource();

private:
    State _state = WORKING;
    objects_t _inventory;
    std::unique_ptr<AbstractAI> _ai;
    cells_t _looked;
    SoundSource _lastSource;
    bool _readyToBroadcast;
};


#endif //ZAPPY_AIPLAYER_H
