//
// Created by mohamed on 9/2/21.
//

#ifndef PACK_SNIFFINGATTACK_H
#define PACK_SNIFFINGATTACK_H

#include "Attack.h"

namespace network {
template<class T>
class SniffingAttack : public Attack<T> {


public:
    void operator()(Packet<T>& packet) override;

};

}


#endif //PACK_SNIFFINGATTACK_H
