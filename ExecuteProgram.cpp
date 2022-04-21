
#include "ExecuteProgram.h"
#include "Omicron.h"
#include "Alpha.h"
#include "Delta.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <random>
#include <string>

using namespace std;


void ExecuteProgram::execute() {
    readFromConfigFile();
    readFromFirstGenerationFile();
    //Run until no hit is found between the current generation and the target or until the simulating run time is over.
    while(!checkForHit() && --simulatingRunTimes){

        //Update Individual
        for(SARS_CoV_2* sara_cov : currentGeneration){

            sara_cov->update();
        }
        updateGroup();
    }


    for(SARS_CoV_2 *sars_cov_2 : currentGeneration) {
        cout << (char)tolower(sars_cov_2->getType()) << " " << sars_cov_2->getSequence() << endl;
    }
    cout << endl;

    for(SARS_CoV_2 *sars_cov_2 : firstGeneration) {
        cout << (char)tolower(sars_cov_2->getType()) << " " << sars_cov_2->getSequence() << " "<<  sars_cov_2->getCountingReferences() << endl;
    }
    cout << endl;
    SARS_CoV_2 *strongest = currentGeneration[getStrongestVirus()];
    cout << (char)tolower(strongest->getType()) << " " << strongest->getSequence() << endl;

}

void ExecuteProgram::readFromConfigFile() {
    ifstream configData(configFile);
    if(!configData.is_open()) {
        cout << "Error opening config file" << endl;
        return;
    }
    configData >> this->lenOfVirus;
    getline(configData, this->target);
    getline(configData, this->target);
    configData >> simulatingRunTimes;

}

void ExecuteProgram::readFromFirstGenerationFile() {
    ifstream firstGenerationData(firstGenFile);
    if(!firstGenerationData.is_open()) {
        cout << "Error opening firstGeneration file" << endl;
        return;
    }
    int amountOFViruses;
    firstGenerationData >> amountOFViruses;
    string empty;
    getline(firstGenerationData, empty);
    for(int j = 0; j < amountOFViruses; j++) {
        string s;
        getline(firstGenerationData, s);
        char type = s[0];
        string gen = s.substr(2, s.length());

        if(type == 'a'){
            addNewAlpha(gen);
        }
        if(type == 'o'){
            addNewOmicron(gen);
        }
        if(type == 'd'){
            addNewDelta(gen);
        }
    }
}

void ExecuteProgram::addNewOmicron(const string& gen) {
    if((gen.length()+1)/2 == this->lenOfVirus) {
        auto *o = new Omicron(gen);
        this->firstGeneration.push_back(o);
        this->currentGeneration.push_back(o);
    }
    else
        cerr << "Error: length of virus is not equal to length of gen" << endl;
}

void ExecuteProgram::addNewAlpha(const string& gen) {
    if((gen.length()+1)/2 == this->lenOfVirus) {
        auto *a = new Alpha(gen);
        this->firstGeneration.push_back(a);
        this->currentGeneration.push_back(a);
    }
    else
        cerr << "Error: length of virus is not equal to length of gen" << endl;
}

void ExecuteProgram::addNewDelta(const string& gen) {
    if((gen.length()+1)/2 == this->lenOfVirus) {
        auto *d = new Delta(gen);
        this->firstGeneration.push_back(d);
        this->currentGeneration.push_back(d);
    }
    else
        cerr << "Error: length of virus is not equal to length of gen" << endl;
}

ExecuteProgram::~ExecuteProgram() {
    for(auto & i : this->firstGeneration) {
        delete i;
    }
    for(auto & i : this->currentGeneration) {
        delete i;
    }
}



bool ExecuteProgram::checkForHit() const {
    float match;
    // run for each in current generation
    for(auto i : this->currentGeneration) {
        match = checkMatch(i);
        if(match == 1) {
            return true;
        }
    }
    return false;

}

float ExecuteProgram::checkMatch(SARS_CoV_2 *virus) const {
    string virusGen = virus->getSequence();
    // if virusGen is equal to target return 1 else return the number of matches between virusGen and target (0-1)
    if(virusGen == this->target)
        return 1;
    else {
        int matches = 0;
        for(int i = 0; i < virusGen.length(); i+=2) {
            if(virusGen[i] == this->target[i])
                matches++;
        }

        return ((float)matches)/(float)this->target.length();
    }
}

void ExecuteProgram::updateGroup() {
    std::random_device rd;
    std::mt19937 gen(rd());

    int weak1 = getWeakestVirus();
    if(!currentGeneration[weak1]->is_Father())
        delete this->currentGeneration[weak1];
    else
        this->currentGeneration[weak1]->decrease_counting_references();
    currentGeneration.erase(currentGeneration.begin()+weak1);


    int weak2 = getWeakestVirus();
    if(!currentGeneration[weak2]->is_Father())
        delete this->currentGeneration[weak2];
    else
        this->currentGeneration[weak2]->decrease_counting_references();
    currentGeneration.erase(currentGeneration.begin()+weak2);

    unsigned long long father_index_1 = gen()%firstGeneration.size() , father_index_2 = gen()%firstGeneration.size();
    while(father_index_1 == father_index_2){
        father_index_1 = gen()%firstGeneration.size();
        father_index_2 = gen()%firstGeneration.size();
    }



    string father_1 = firstGeneration[father_index_1]->getSequence();
    char type_1 = firstGeneration[father_index_1]->getType();
    string father_2 = firstGeneration[father_index_2]->getSequence();
    char type_2 = firstGeneration[father_index_2]->getType();

    int len = target.length();
    unsigned long long s = gen()%len ,t = gen()%len;
    while(s > t || s<2 || s>len-2 || t<3 || t>len-3 || (t-s) < 3 ) {
        s = gen()&len;
        t = gen()&len;
    }



    string new_virus_one = father_1.substr(0,s) + father_2.substr(s,t-s) + father_1.substr(t,len); // from type_1
    string new_virus_two = father_2.substr(0,s) + father_1.substr(s,t-s) + father_2.substr(t,len); // from type_2


    if(type_1 == 'O') {
        auto *new_virus_one_obj = new Omicron(firstGeneration[father_index_1], new_virus_one);
        currentGeneration.push_back(new_virus_one_obj);
    }
    else if(type_1 == 'A') {
        auto *new_virus_one_obj = new Alpha(firstGeneration[father_index_1], new_virus_one);
        currentGeneration.push_back(new_virus_one_obj);
    }
    else if(type_1 == 'D') {
        auto *new_virus_one_obj = new Delta(firstGeneration[father_index_1], new_virus_one);
        currentGeneration.push_back(new_virus_one_obj);
    }



    if(type_2 == 'O') {
        auto *new_virus_one_obj = new Omicron(firstGeneration[father_index_2], new_virus_two);
        currentGeneration.push_back(new_virus_one_obj);
    }
    else if(type_2 == 'A') {
        auto *new_virus_one_obj = new Alpha(firstGeneration[father_index_2], new_virus_two);
        currentGeneration.push_back(new_virus_one_obj);
    }
    else if(type_2 == 'D') {
        auto *new_virus_one_obj = new Delta(firstGeneration[father_index_2], new_virus_two);
        currentGeneration.push_back(new_virus_one_obj);
    }

}

int ExecuteProgram::getWeakestVirus() const{
    int weakestVirus = 0;
    for(int i = 1; i < this->currentGeneration.size(); i++) {
        if(checkMatch(currentGeneration[i]) < checkMatch(currentGeneration[weakestVirus])) {
            weakestVirus = i;
        }
    }

    return weakestVirus;
}

int ExecuteProgram::getStrongestVirus() const {
    int strongestVirus = 0;
    for(int i = 1; i < this->currentGeneration.size(); i++) {
        if(checkMatch(currentGeneration[i]) > checkMatch(currentGeneration[strongestVirus])) {
            strongestVirus = i;
        }
    }

    return strongestVirus;
}

ExecuteProgram::ExecuteProgram(string FGN, string CF) : firstGenFile(std::move(FGN)) , configFile(std::move(CF)),lenOfVirus(0), simulatingRunTimes(0){}
