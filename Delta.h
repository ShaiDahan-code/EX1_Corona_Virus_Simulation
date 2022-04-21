//
// Created by shai0 on 4/8/2022.
//

#ifndef EX1_DELTA_H
#define EX1_DELTA_H

#include <utility>

#include "SARS_CoV_2.h"

class Delta : public SARS_CoV_2 {
public:
    //Not create a Big three because we don't need them

    Delta(string seq) : SARS_CoV_2(std::move(seq)) {}
    Delta(SARS_CoV_2* sars , string seq) : SARS_CoV_2(sars, seq) {}

    char getType() const override { return 'D'; }
    void update() override;
    bool getProbability() const;

};


#endif //EX1_DELTA_H
