#include "Manager.h"
#include <string>

Manager::Manager(const string &name, int regNo):Person(name) {
    this->name = name;
    this->regNo = regNo;
}

int Manager::getRegNo() const {
    return regNo;
}