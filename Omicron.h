//
// Created by shai0 on 4/8/2022.
//

#ifndef EX1_OMICRON_H
#define EX1_OMICRON_H

#include <iostream>
#include <string>
#include "SARS_CoV_2.h"

using namespace std;

class Omicron : public SARS_CoV_2 {
public:
    Omicron(string seq) : SARS_CoV_2(seq) {}
    Omicron(SARS_CoV_2* sars , string seq) : SARS_CoV_2(sars, seq) {}
    ~Omicron() {}
    virtual char getType() { return 'O'; }
    virtual void update();
    float getProbability();

};


#endif //EX1_OMICRON_H
