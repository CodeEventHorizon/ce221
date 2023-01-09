#include <iostream>
#include "Gamer.h"

using namespace std;

Gamer::Gamer(const string &name, int regNo):Person(name)
{
    this->name = name;
    this->regNo = regNo;
    this->scores.clear(); //empty score map
}

int Gamer::getRegNo() const {
    return regNo;
}

void Gamer::addScore(float score, string difficulty){
    scores.insert(pair<string, float> (difficulty, score)); //inserts the pair of key and value into the map<>
}

float Gamer::getHighestScore(string difficulty) const {
    auto it = scores.find(difficulty);
    if (!it->first.empty()) {
    } else {
        throw NoScoreException();
    }
}

ostream& operator<<(ostream& str, const Gamer& s) {
    // should output name, regno, and minimum, maximum and average score on a single line
    float min, max, average = 0;

    str << s.getName() << s.getRegNo() << average;
    return str;
}