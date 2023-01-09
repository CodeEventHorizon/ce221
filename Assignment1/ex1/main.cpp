#include <iostream>
#include <ctime>
#include "Date.h"

string fullName;
string bdate;

int d, m, y;

void ageCalculator(int currentD, int currentM, int currentY, int bDay, int bMon, int bYear) {
    int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (bDay > currentD) {
        currentD = currentD + md[bMon - 1];
        currentM = currentM - 1;
    }
    if (bMon > currentM) {
        currentY = currentY - 1;
        currentM = currentM + 12;
    }
    cout << currentY-bYear << " years, " << currentM-bMon << " months and " << currentD-bDay << " days old. ";
}
//ageCalculator() method calculates age so that we dont get negative months and days in the output

int main() {
    /** current date */
    time_t t = time(0);
    tm* now = localtime(&t);

    yourName:
        cout << "Type your fullname: " << endl;
        getline(cin, fullName);
        if (fullName.empty()) {
            cout << "The line is empty!!" << endl;
            goto yourName;
        }
    yourBday:
        cout << "Type your birthday (format: dd/mm/yyyy): " << endl;
        getline(cin, bdate);
        if (bdate.empty()) {
            cout << "The Line is empty!!" << endl;
            goto yourBday;
        } else if (bdate.size() != 10) {
            cout << "Incorrect format!" << endl;
            goto yourBday;
        } else if ((bdate.substr(2,1) != "/") && (bdate.substr(5,1) != "/")) { //roughly says that 3rd and 6th character in a string must be slash character
            cout << "Incorrect format!" << endl;
            goto yourBday;
        } else { // stoi() stores day, month and year by converting string to integer
            d = stoi(bdate.substr(0,2)); // 2 digits
            m = stoi(bdate.substr(3,5)); // 2 digits
            y = stoi(bdate.substr(6,10)); // 4 digits

            Date d1(d,m,y); //creates an object for inputted date by the user and executes constructor
            Date d2(now->tm_mday,now->tm_mon+1,now->tm_year+1900); //creates an object for current date and executes constructor
            /**
             * ostream is executed once we call d1 or d2.
             * so to say
             * cout << d1
             * would output the format dd/mm/yyyy even tho we passed in 3 integers as arguments.
             */
            if (d1.operator>(d2)) {
                cout << "Above date is in the future" << endl;
                goto yourBday;
            } else if(d1.operator<(d2)) {
                cout << "Name: " << fullName << endl << endl
                     << "Birthday: " << string(d1)
                     <<", which is ";
                     ageCalculator(now->tm_mday,now->tm_mon+1,now->tm_year+1900, d, m, y);
                cout << "(End date considered: "
                     << d2 << ")." << endl;
                if (d1.isLeapYear()) {
                    cout << "Born in a leap year." << endl;
                } else {
                    cout << "Born in a common year." << endl;
                }
            } else {
                cout << "Something went wrong" << endl;
                goto yourBday;
            }
        }
    return 0;
}
