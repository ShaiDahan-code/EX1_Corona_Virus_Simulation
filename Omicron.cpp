//
// Created by shai0 on 4/8/2022.
//

#include "Omicron.h"
#include <random>

using namespace std;

void Omicron::update() {
    if(getProbability()){
        string old_sequence = getSequence();
        for(int i=0;i<old_sequence.length();i+=2){
            if(old_sequence[i] == 'T')
                old_sequence[i] = 'A';
            else if(old_sequence[i] == 'C')
                old_sequence[i] = 'G';
            else if(old_sequence[i] == 'G')
                old_sequence[i] = 'C';
        }
        this->setSequence(old_sequence);
    }

}

bool Omicron::getProbability() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    unsigned long long ran = gen() ;
    float probability = ran % 100;
    int reach = (200/this->getSequenceLength());
    return probability < reach;
}
