//
// Created by shai0 on 4/8/2022.
//

#ifndef EX1_DELTA_H
#define EX1_DELTA_H

#include "SARS_CoV_2.h"

class Delta : public SARS_CoV_2 {
public:
    Delta(string seq) : SARS_CoV_2(seq) {}
    Delta(SARS_CoV_2* sars , string seq) : SARS_CoV_2(sars, seq) {}

    virtual char getType() { return 'D'; }
    virtual void update();
    float getProbability();

};


#endif //EX1_DELTA_H
