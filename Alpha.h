//
// Created by shai0 on 4/8/2022.
//

#ifndef EX1_ALPHA_H
#define EX1_ALPHA_H

#include "SARS_CoV_2.h"

class Alpha : public SARS_CoV_2 {
public:
    //Not create a Big three because we don't need them
    Alpha(string seq) : SARS_CoV_2(seq) {}
    Alpha(SARS_CoV_2* sars , string seq) : SARS_CoV_2(sars, seq) {}
    virtual char getType() const { return 'A'; }
    virtual void update();
    bool getProbability() const;



};


#endif //EX1_ALPHA_H
