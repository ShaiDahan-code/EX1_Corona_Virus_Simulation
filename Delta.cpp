//
// Created by shai0 on 4/8/2022.
//

#include "Delta.h"
#include <iostream>
#include <random>

using namespace std;

void Delta::update() {
    if(getProbability()){
        string old_sequence = getSequence();
        for(int i=0;i<old_sequence.length();i+=2){

            if(old_sequence[i] == 'A')
                old_sequence[i] = 'T';
            else if(old_sequence[i] == 'C')
                old_sequence[i] = 'G';
            else if(old_sequence[i] == 'G')
                old_sequence[i] = 'C';
        }
        this->setSequence(old_sequence);
    }

}

float Delta::getProbability() {
    int ran = rand() ;

    float probability = ran % 100;
    int reach = (100/this->getSequenceLength());
    return probability < reach;
}
