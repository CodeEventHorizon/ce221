#ifndef _GAMER_H_
#define _GAMER_H_

#include <string>
#include <map>
#include <stdexcept>
#include "Person.h"

using namespace std;

class NoScoreException: public exception
{
};

class Gamer: public Person
{   public:
    // constructor should initialise name and registration number using arguments
    // and initialise score map to be empty
    Gamer(const string &name, int regNo);

    // method to return registration number
    int getRegNo() const;

    // method to add the score to the map
    // if a score for the module is already present it should be overwritten
    void addScore(float score,string difficulty);

    // method to retrieve the score
    // should throw NoScoreException if gamer has no score yet
    // it should display the score based on the levels of difficulty the gamer player
    float getHighestScore(string difficulty) const;

private:
    int regNo;
    string name;
    map<string,float> scores;  // scores map, with each in range 0.0 to 100.0, and an
    //associated level of difficulty

    // friend function to output details of gamer to stream
    // should output name, regno, and minimum, maximum and average score on a single line
    // if the gamer has no scores "has no scores" should be output instead of the scores
    friend ostream& operator<<(ostream &str, const Gamer &s);
};



#endif
