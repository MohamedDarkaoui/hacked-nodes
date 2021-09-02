#include "SniffingAttack.cpp"
#include "ModificationAttack.cpp"
#include "AccessPoint.cpp"
#include <exception>

template<typename T>
void print(network::Packet<T> packet, unsigned int index){
    std::cout<< "Packet " << std::to_string(index) <<" has value " << packet << ".\n";
}

int main() {
    try {
        // Initialize with 0.8 attack probability.
        network::AccessPoint<int, 5> ap(0.8);

        // Infect the access point.
        ap.infect(network::up_attack<int>(new network::ModificationAttack<int>()));
        ap.infect(network::up_attack<int>(new network::SniffingAttack<int>()));

        // Add the packets.
        ap << network::up_packet<int>(new network::Packet<int>(1.0));
        ap << network::up_packet<int>(new network::Packet<int>(2.0));
        ap << network::up_packet<int>(new network::Packet<int>(3.0));
        ap << network::up_packet<int>(new network::Packet<int>(4.0));
        ap << network::up_packet<int>(new network::Packet<int>(5.0));

        // Run, possibly attack the packets.
        ap.run(print<int>);

        using namespace network;

        AccessPoint<bool, 5> ap3 (0.8);

        ap3.infect(up_attack<bool>(new network::ModificationAttack<bool>()));
        ap3.infect(up_attack<bool>(new network::SniffingAttack<bool>()));

        ap3 << up_packet<bool>(new network::Packet<bool>(false));
        ap3 << up_packet<bool>(new network::Packet<bool>(true));
        ap3 << up_packet<bool>(new network::Packet<bool>(false));
        ap3 << up_packet<bool>(new network::Packet<bool>(true));
        ap3 << up_packet<bool>(new network::Packet<bool>(false));

        ap3.run(print<bool>);

        AccessPoint<char, 5> ap2 (0.8);

        ap2.infect(up_attack<char>(new network::ModificationAttack<char>()));
        ap2.infect(up_attack<char>(new network::SniffingAttack<char>()));

        ap2 << up_packet<char>(new network::Packet<char>('c'));
        ap2 << up_packet<char>(new network::Packet<char>('h'));
        ap2 << up_packet<char>(new network::Packet<char>('a'));
        ap2 << up_packet<char>(new network::Packet<char>('r'));
        ap2 << up_packet<char>(new network::Packet<char>('t'));

        ap2.run(print<char>);

        } catch (std::exception &e) {
            std::cout << "Fatal error encountered with message: " << e.what() << std::endl;
        }

    return 0;
}
