#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

using namespace std;

class Person
{   public:
    Person(const string &name);
    string getName() const;
    void changeName(const string &newName);
protected:
    string name;
};

#endif
