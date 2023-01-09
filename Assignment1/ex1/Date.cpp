#include "Date.h"

Date::Date() { //constructor sets integers to 0
    d = m = y = 0;
}

Date::Date(unsigned int d, unsigned int m, unsigned int y) { //argument validation
    this -> d = d;
    this -> m = m;
    this -> y = y;
    if (y < 1000 || y > 9999) {
        cout << "Year is out of bound (1000-9999)" << endl;
        throw bad_exception();
    } else if (m > 12 || m < 1) {
        cout << "Month is out of bound (1-12)" << endl;
        throw bad_exception();
    } else if (d > 31 || d < 1) {
        cout << "Day is out of bound (1-31)" << endl;
        throw bad_exception();
    } else if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)) {
        cout << "This Month doesn't have 31 days" << endl;
        throw bad_exception();
    } else if (d == 30 && m == 2) {
        cout << "February never has 30 days" << endl;
        throw bad_exception();
    } else if (!isLeapYear() && d == 29) {
        cout << y << " is a common year so February should have 28 days" << endl;
        throw bad_exception();
    }
}
/**
 * constuctor with arguments checks the validity of the date inputted by the user.
 * if user fails to input the valid date, program throws an exception and stops the program.
 * */
bool Date::isLeapYear() const {
    if ((y%4) != 0) {
        return false;
    } else if((y%100) != 0) {
        return true;
    } else if((y%400) != 400) {
        return false;
    } else {
        return true;
    }
}
/**
 * isLeapYear() method is implemented by a leap year method pseudo code/algorithm, that i found on wikipedia:
 *
 * if (year is not divisible by 4) then (it is a common year)
 *   else if (year is not divisible by 100) then (it is a leap year)
 *   else if (year is not divisible by 400) then (it is a common year)
 *   else (it is a leap year)
 *
 * Reference for algorithm: https://en.wikipedia.org/wiki/Leap_year#Algorithm
 * */
bool Date::operator<(const Date &other) const {
    if (y < other.y) {
        return true;
    } else if (y > other.y) {
        return false;
    } else {
        if (m < other.m) {
            return true;
        } else if (m > other.m) {
            return false;
        } else {
            if (d < other.d) {
                return true;
            } else {
                return false;
            }
        }
    }
}
/**
 * compares 2 dates and checks which one is in the future and which one is in the past
 * (not considering current time, here even though it is for checking a current time and if the inputted date is greater than current date, program
 * tells the user that date is in the future).
 * */
bool Date::operator>(const Date &other) const {
    if (y > other.y) {
        return true;
    } else if (y < other.y) {
        return false;
    } else {
        if (m > other.m) {
            return true;
        } else if (m < other.m) {
            return false;
        } else {
            if (d > other.d) {
                return true;
            } else {
                return false;
            }
        }
    }
}
/**
 * compares 2 dates and checks which one is in the future and which one is in the past
 * (not considering current time, here even though it is for checking a current time and if the inputted date is greater than current date, program
 * tells the user that date is in the future).
 * */
bool operator<(const Date& d1, const Date& d2) {
    return d1.operator<(d2);
} //returns a false or true according to operator implementation above

bool operator>(const Date& d1, const Date& d2) {
    return d1.operator>(d2);
} //returns a false or true according to operator implementation above

Date::operator string() const { // dd/mm/yyyy to "Month Day, Year" format
    switch (m) {
        case 1:
            return "January " + to_string(d) + ", " + to_string(y);
        case 2:
            return "February " + to_string(d) + ", " + to_string(y);
        case 3:
            return "March " + to_string(d) + ", " + to_string(y);
        case 4:
            return "April " + to_string(d) + ", " + to_string(y);
        case 5:
            return "May " + to_string(d) + ", " + to_string(y);
        case 6:
            return "June " + to_string(d) + ", " + to_string(y);
        case 7:
            return "July " + to_string(d) + ", " + to_string(y);
        case 8:
            return "August " + to_string(d) + ", " + to_string(y);
        case 9:
            return "September " + to_string(d) + ", " + to_string(y);
        case 10:
            return "October " + to_string(d) + ", " + to_string(y);
        case 11:
            return "November " + to_string(d) + ", " + to_string(y);
        case 12:
            return "December " + to_string(d) + ", " + to_string(y);
    }
}

ostream& operator<<(ostream& o, const Date& d) { //Basically after creating an object. outputs inputted day, month, year in a format of dd/mm/yyyy as a string.
    o << d.d << '/' << d.m << '/' << d.y;
    return o;
}
