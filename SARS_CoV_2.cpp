//
// Created by shai0 on 4/8/2022.
//

#include "SARS_CoV_2.h"
#include <cstring>
using namespace std;


SARS_CoV_2::SARS_CoV_2(string seq) {
    this->father = this;
    sequence = seq;
    this->counting_references = 1;
}

SARS_CoV_2::SARS_CoV_2(SARS_CoV_2 *father, string seq) {
    this->father = father;
    sequence = seq;
    this->father->counting_references++;
}

SARS_CoV_2::~SARS_CoV_2() {
    if(this->father != this){
        this->father->decrease_counting_references();
    }
}

void SARS_CoV_2::decrease_counting_references() {
    if(this->father != this){
        this->father->decrease_counting_references();
    }
    else{
        this->counting_references--;
    }

}
