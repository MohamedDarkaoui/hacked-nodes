//
// Created by mohamed on 9/2/21.
//

#include "SniffingAttack.h"

template<class T>
void network::SniffingAttack<T>::operator()(Packet<T>& packet) {
    T dummy;
    std::cout << "\nSniffing Attack: \n";
    std::cout<< "\tType of the packet: " << typeid(dummy).name() <<"\n";
    std::cout << "\tContents of the packet: " << packet <<"\n\n";
}