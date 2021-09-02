//
// Created by mohamed on 9/2/21.
//

#ifndef PACK_PACKET_H
#define PACK_PACKET_H

#include <iostream>
#include <memory>

namespace network {

template<class T>
class Packet {

private:
    T content;

public:

    explicit Packet(T content) : content(content) {}

    void operator - () {
        if (typeid(T) == typeid(int))
            content = -content;
        else if (typeid(T) == typeid(bool))
            content = !content;
    };

    friend std::ostream& operator<<(std::ostream &out, const Packet<T> &packet) {
        out << packet.content;
        return out;
    }

};

template<typename T> using up_packet = std::unique_ptr<Packet<T>>;
}
#endif //PACK_PACKET_H
