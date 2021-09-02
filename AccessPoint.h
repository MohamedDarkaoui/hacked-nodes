//
// Created by mohamed on 9/2/21.
//

#ifndef PACK_ACCESSPOINT_H
#define PACK_ACCESSPOINT_H

#include <queue>
#include <functional>
#include <random>
#include "Packet.h"
#include "Attack.h"

namespace network {

template<class T, unsigned int SIZE>
class AccessPoint {

private:
    std::deque<up_packet<T>> packets;
    double probability;
    std::vector<up_attack<T>> attacks;

public:

    explicit AccessPoint(double prob) : probability(prob){}

    void infect(up_attack<T>&& attack);

    void run(void (*print) (network::Packet<T>, unsigned int));

    friend AccessPoint<T,SIZE>& operator << (AccessPoint<T,SIZE>& ap, up_packet<T>&& p){
        if (ap.packets.size() == SIZE)
            throw std::runtime_error("Too many packages, max amount of packages = " + std::to_string(SIZE));
        else {
            std::cout<<"Added packet with value "<< *p <<"\n";
            ap.packets.push_back(std::move(p));
        }
        return ap;
    }
};
}

#endif //PACK_ACCESSPOINT_H
