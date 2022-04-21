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
    //Not create a Big three because we don't need them
    Omicron(string seq) : SARS_CoV_2(seq) {}
    Omicron(SARS_CoV_2* sars , string seq) : SARS_CoV_2(sars, seq) {}
    ~Omicron() {}
    virtual char getType() const { return 'O'; }
    virtual void update();
    float getProbability() const;

};


#endif //EX1_OMICRON_H
