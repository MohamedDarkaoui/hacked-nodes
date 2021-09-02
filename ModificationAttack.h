//
// Created by mohamed on 9/2/21.
//

#ifndef PACK_MODIFICATIONATTACK_H
#define PACK_MODIFICATIONATTACK_H

#include "Attack.h"

namespace network {
template<class T>
class ModificationAttack : public Attack<T> {


public:
    void operator()(Packet<T>& packet) override{
        T dummy;

        std::cout << "\nModification Attack: \n";
        std::cout<< "\tType of the packet: " << typeid(dummy).name() <<"\n";
        std::cout << "\tContents of the packet: " << packet <<"\n";
        std::cout << "\t--> No modification \n\n";
    };

};

template<>
class ModificationAttack<int> : public Attack<int>{

public:
    void operator()(Packet<int>& packet) override {
        Packet<int> temp = packet;
        -packet;
        std::cout << "\nModification Attack: \n";
        std::cout<< "\tType of the packet: " << typeid(int).name() <<"\n";
        std::cout << "\tContents of the packet: " << temp <<" changed to: " << packet << "\n\n";
    };

};

template<>
class ModificationAttack<bool> : public Attack<bool>{

public:
    void operator()(Packet<bool>& packet) override {
        Packet<bool> temp = packet;
        -packet;
        std::cout << "\nModification Attack: \n";
        std::cout<< "\tType of the packet: " << typeid(int).name() <<"\n";
        std::cout << "\tContents of the packet: " << temp <<" changed to: " << packet << "\n\n";
    };

};

}

#endif //PACK_MODIFICATIONATTACK_H
