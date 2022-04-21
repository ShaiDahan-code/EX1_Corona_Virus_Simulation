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
    string getSequence() const { return sequence; }
    int getSequenceLength() const { return ((sequence.length()+1)/2); }
    void setSequence(string seq) {sequence = seq;};
    bool is_Father() const { return (father == this); }
    void decrease_counting_references();
    int getCountingReferences() const { return counting_references; }

    //operator =
    SARS_CoV_2& operator=(const SARS_CoV_2& other);

    virtual char getType() const { return 'S'; }
    virtual void update() {};

};


#endif //EX1_SARS_COV_2_H
