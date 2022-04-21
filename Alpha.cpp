//
// Created by shai0 on 4/8/2022.
//

#include "Alpha.h"
#include <random>

void Alpha::update() {

    if(getProbability()){
        string old_sequence = getSequence();
        for(int i=0;i<old_sequence.length();i+=2){
            if(old_sequence[i] == 'A')
                old_sequence[i] = 'T';
            else if(old_sequence[i] == 'T')
                old_sequence[i] = 'A';
        }
        this->setSequence(old_sequence);
    }

}

bool Alpha::getProbability() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    unsigned long long  random = gen() % 100;
    return random<37;
}
