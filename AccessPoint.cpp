//
// Created by mohamed on 9/2/21.
//

#include "AccessPoint.h"

template<class T, unsigned int SIZE>
void network::AccessPoint<T, SIZE>::infect(up_attack<T>&& attack) {
    if (attacks.size() < 2)
        attacks.push_back(std::move(attack));
    else
        throw std::runtime_error("Too many attacks added, max amount of attacks is 2!");
}

template<class T, unsigned int SIZE>
void network::AccessPoint<T, SIZE>::run(void (*print) (network::Packet<T>, unsigned int)) {
    if(attacks.size() < 2)
        throw std::logic_error("Two attacks myst be present!");

    unsigned int i = 0;
    for(auto it = packets.begin(); it != packets.end(); it++){
        print(**it, i);
        i++;
        std::uniform_real_distribution<double> uni(0,1);
        std::random_device rd;
        std::mt19937 engine(rd());
        double random1 = uni(engine);

        if (random1 <= probability){
            std::uniform_int_distribution<int> val(0,1);
            int random2 = val(engine);
            if (random2 == 0)
                attacks[0]->operator()(**it);
            else
                attacks[1]->operator()(**it);
        }

    }



}
