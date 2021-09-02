//
// Created by mohamed on 9/2/21.
//

#ifndef PACK_ATTACK_H
#define PACK_ATTACK_H

#include "Packet.h"

namespace network{
template<class T>
class Attack {

public:

    virtual void operator()(Packet<T>& packet) = 0;
};

template<typename T> using up_attack = std::unique_ptr<Attack<T>>;
}


#endif //PACK_ATTACK_H
