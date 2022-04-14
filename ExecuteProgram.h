//
// Created by shai0 on 4/8/2022.
//

#ifndef EX1_EXECUTEPROGRAM_H
#define EX1_EXECUTEPROGRAM_H

#include <string>
#include <vector>
#include "SARS_CoV_2.h"
using namespace std;

class ExecuteProgram {
private:
    int lenOfVirus;
    int simulatingRunTimes;
    string target;
    vector<SARS_CoV_2*> firstGeneration;
    vector<SARS_CoV_2*> currentGeneration;

public:
    ExecuteProgram() : lenOfVirus(0),target("") , simulatingRunTimes(0){}
    ~ExecuteProgram();

    void execute(); // Exectue the program
    void readFromConfigFile(); // Read the config file
    void readFromFirstGenerationFile(); // Read the first generation

    //Check for each virus in the current generation if it's hit.
    bool checkForHit();
    float checkMatch(SARS_CoV_2* virus); // Check if the virus is a match to the target

    //Function to add new virus to the first generation
    void addNewOmicron(string gen); // Add new Omicron to the first generation
    void addNewAlpha(string gen); // Add new Alpha to the first generation
    void addNewDelta(string gen); // Add new Delta to the first generation

    //Function for "Individual update"
    void updateIndividual(); // Update the individual

    //Function for "Group update"
    void updateGroup(); // Update the group
    int getWeakestVirus(); // Get the weakest virus in the group
    int getStrongestVirus(); // Get the strongest virus in the group


};




#endif //EX1_EXECUTEPROGRAM_H
