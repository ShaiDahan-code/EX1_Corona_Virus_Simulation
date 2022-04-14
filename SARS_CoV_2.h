//
// Created by shai0 on 4/8/2022.
//

#ifndef EX1_SARS_COV_2_H
#define EX1_SARS_COV_2_H

#include <string>
#include <iostream>

using namespace std;


class SARS_CoV_2 {

private:
    SARS_CoV_2* father;
    string sequence;
    int counting_references;

public:
    SARS_CoV_2(string seq);
    SARS_CoV_2(SARS_CoV_2* father, string seq);
    ~SARS_CoV_2();
    //Getters and setters for sequence
    string getSequence() { return sequence; }
    int getSequenceLength() { return ((sequence.length()+1)/2); }
    void setSequence(string seq) {sequence = seq;};
    bool is_Father() { return (father == this); }
    void decrease_counting_references();
    int getCountingReferences() { return counting_references; }

    virtual char getType() = 0;
    virtual void update() = 0;

};


#endif //EX1_SARS_COV_2_H
