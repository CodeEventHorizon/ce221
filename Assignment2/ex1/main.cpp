#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <random>
#include "Gamer.h"
#include "Manager.h"

using namespace std;

vector<string> split(string str, char delimiter) {  //creating a split method that works just like the one in Java to split string into vectors
    vector<string> internal;
    stringstream ss(str);
    string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}
int main() {
    string user;
    string line;
    vector<vector<string>> gamersVec;
    vector<vector<string>> gamersVecDup;
    vector<vector<string>> managersVec;
    bool inGame = false;
    bool isGamer = false;
    bool isManager = false;
    regex minMaxPattern("[0-9]+");
    string minEasy = "0", minMed = "0", minHard = "0",
            maxEasy = "10", maxMed = "100", maxHard = "1000";
    /**
     * game variables
     * */
    resetTheGame: // 1) GOTO: (Reset Game)
    cout << "Username:" << endl; //Asking for a Username
    getline(cin, user);
    // input files for reading
    ifstream gamers("gamers.txt");
    ifstream managers("managers.txt");

    if (!managers.is_open()) {
        cout << "Error opening file" << endl;
    } else {
        while (getline(managers, line)) { //store managers.txt table in the 2d vector managersVec
            vector<string> vectorLine = split(line, ' '); //splitting a line into elements
            managersVec.push_back(vectorLine); // storing split lines (Just like in Java)
        }

        for(int i = 0; i < managersVec.size(); i++){
            //check if user is a manager
            if((managersVec[i][1] + " " + managersVec[i][2]) == user) {
                inGame = true;
                isManager = true;
                Manager m1(user, stoi(managersVec[i][0])); //Manager Object
                cout << "Hello Manager " << user << endl << endl;
                while (isManager) {
                    cout << "1) Reset game" << endl
                         << "2) Change game levels" << endl
                         << "3) Change security key" << endl
                         << "4) Add another manager" << endl
                         << "5) Exit game" << endl << endl;
                    string choice;
                    getline(cin, choice); //choice

                    if (choice == "1") {
                        goto resetTheGame;
                    } else if (choice == "2") { //changing the boundaries, minimum and maximum of each game level, will work after Resetting the game and entering as a Gamer. (NOT RECOMPILING)
                        string choiceDifficulty;
                        cout << "Choose what level would you like to change: " << endl << endl
                             << "a) Easy" << endl
                             << "b) Medium" << endl
                             << "c) Hard" << endl << endl;
                        getline(cin, choiceDifficulty);
                        if (choiceDifficulty == "a") { //inputting the minimum and maximum values
                            cout << "Input new Minimum value: " << endl;
                            getline(cin, minEasy);
                            if (!regex_match(minEasy, minMaxPattern)) { // Must be an integer
                                cout << "minimum and maximum must be integer values!" << endl;
                                throw exception();
                            }
                            cout << "Input new Maximum value: " << endl;
                            getline(cin, maxEasy);
                            if (!regex_match(maxEasy, minMaxPattern)) {
                                cout << "minimum and maximum must be integer values!" << endl;
                                throw exception();
                            }
                        } else if(choiceDifficulty == "b") { //inputting the minimum and maximum values
                            cout << "Input new Minimum value: " << endl;
                            getline(cin, minMed);
                            if (!regex_match(minMed, minMaxPattern)) {
                                cout << "minimum and maximum must be integer values!" << endl;
                                throw exception();
                            }
                            cout << "Input new Maximum value: " << endl;
                            getline(cin, maxMed);
                            if (!regex_match(maxMed, minMaxPattern)) {
                                cout << "minimum and maximum must be integer values!" << endl;
                                throw exception();
                            }
                        } else if (choiceDifficulty == "c") { //inputting the minimum and maximum values
                            cout << "Input new Minimum value: " << endl;
                            getline(cin, minHard);
                            if (!regex_match(minHard, minMaxPattern)) {
                                cout << "minimum and maximum must be integer values!" << endl;
                                throw exception();
                            }
                            cout << "Input new Maximum value: " << endl;
                            getline(cin, maxHard);
                            if (!regex_match(maxHard, minMaxPattern)) {
                                cout << "minimum and maximum must be integer values!" << endl;
                                throw exception();
                            }
                        } else {
                            cout << "You must choose either a, b or c!" << endl << endl;
                        }
                    } else if (choice == "3") {
                        //Cypher
                    } else if (choice == "4") {  // adding a new manager to the Text file
                        string newName, newRegno;
                        ofstream writeManagers; //output file
                        writeManagers.open("managers.txt", fstream::app); //fstream::app means we are not deleting the file every time but appending to it
                        cout << "Type the name: " << endl;
                        getline(cin, newName);
                        cout << "Type the Registration Number: " << endl;
                        getline(cin, newRegno);
                        regex pattern("[0-9]{4}"); //pattern of digits in the length of only 4
                        if (!regex_match(newRegno, pattern)) {
                            cout << "Registration Number needs to contain 4 digits!" << endl;
                        } else {
                            writeManagers << newRegno << " " << newName << endl;
                            cout << "Manager has been added!" << endl;
                        }
                        writeManagers.close(); //closing a file to avoid errors
                    } else if (choice == "5") { //Exiting the game
                        isManager = false;
                    } else {
                        continue;
                    }
                }
            }
        }
        if(!gamers.is_open() && !inGame) {
            cout << "Error opening file" << endl;
        } else { // Gamer
            while (getline(gamers, line)) { // while file has lines
                vector<string> vectorLine = split(line, ' '); //split into elements
                gamersVec.push_back(vectorLine); //store split lines
            }
            for (int i = 0; i < gamersVec.size(); i++) {
                if((gamersVec[i][1] + " " + gamersVec[i][2]) == user) { //if the name entered matches the name in the text files
                    inGame = true;
                    isGamer = true;
                    Gamer g1(user, stoi(gamersVec[i][0])); //stoi() is string to integer, just like stof() string to float
                    cout << "Hello Gamer " << user << endl << endl;
                    while (isGamer) { //while true in this loop until 4) Exit Game chosen
                        cout << "1) Play game" << endl
                             << "2) Your statistics" << endl
                             << "3) Display top 10" << endl
                             << "4) Exit game" << endl << endl;
                        string choice;
                        getline(cin, choice);
                        if (choice == "1") {

                            cout << "Choose a difficulty: " << endl << endl
                                 << "a) Easy" << endl
                                 << "b) Medium" << endl
                                 << "c) Hard" << endl << endl;
                            string choiceDifficulty;
                            getline(cin, choiceDifficulty);
                            if (choiceDifficulty == "a") { //PLAY THE GAME
                                random_device rd; //random_device is a uniformly-distributed integer random number generator that produces non-deterministic random numbers.
                                mt19937 gen(rd()); //mt19937 - A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
                                uniform_int_distribution<> minMax(stoi(minEasy), stoi(maxEasy)); //setting boundaries, that can be changes as a manager
                                //above comments about random numbers is taken from www.cplusplus.com
                                int secretNumber = minMax(gen); // creating a secret number that needs to be found
                                string guessNumber = "-1"; //setting to negative number as i haven't expected minimum to be less than 0
                                int numberOfTries = 0;
                                while (secretNumber != stoi(guessNumber)) { //while secret number not found keep asking and saying higher/lower.
                                    cout << "input value between "<< minEasy << "-" << maxEasy << ":" << endl;
                                    getline(cin, guessNumber);
                                    regex pattern("[0-9]+");
                                    if (!regex_match(guessNumber, pattern)) {
                                        cout << "input value needs to be an integer!" << endl;
                                    } else {
                                        if (secretNumber < stoi(guessNumber)) {
                                            cout << "The secret number is lower" << endl;
                                            numberOfTries++;
                                        } else if (secretNumber > stoi(guessNumber)) {
                                            cout << "The secret number is higher" << endl;
                                            numberOfTries++;
                                        } else if (secretNumber == stoi(guessNumber)) { // Win
                                            cout << "Congratulations!" << endl << endl;
                                            numberOfTries++;
                                            g1.addScore((float) numberOfTries, "Easy");
                                            if(numberOfTries < stoi(gamersVec[i][3])) { //if the new value less than old one, overwrite the Text File
                                                ifstream inputFileEasy("gamers.txt"); //it doesn't overwrite empty parts of the text file.
                                                ofstream outputFileEasy; //I'm assuming that iterators would have been a much better solution(becuase of .end() etc), please let me know in a feedback, what would have been a better solution?
                                                if (!inputFileEasy.is_open()) {
                                                    cout << "Error opening file" << endl;
                                                } else {
                                                    string insideLine;
                                                    while (getline(inputFileEasy, insideLine)) { //makes a copy of the file
                                                        vector<string> vectorLine = split(insideLine, ' ');
                                                        gamersVecDup.push_back(vectorLine);
                                                    }
                                                    outputFileEasy.open("gamers.txt");

                                                    for (int k = 0; k < gamersVecDup.size(); k++) //Overwrites the file
                                                    {
                                                        for (int j = 0; j < gamersVecDup[k].size(); j++)
                                                        {
                                                            if (k == i && j == 3) {
                                                                outputFileEasy << numberOfTries << ".0 ";
                                                            } else {
                                                                outputFileEasy << gamersVecDup[k][j] << " ";
                                                            }
                                                        }
                                                        outputFileEasy << endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if(choiceDifficulty == "b") { //same as above
                                random_device rd;
                                mt19937 gen(rd());
                                uniform_int_distribution<> minMax(stoi(minMed), stoi(maxMed));
                                int secretNumber = minMax(gen);
                                string guessNumber = "-1";
                                int numberOfTries = 0;
                                while (secretNumber != stoi(guessNumber)) {
                                    cout << "input value between "<< minMed << "-" << maxMed << ":" << endl;
                                    getline(cin, guessNumber);
                                    regex pattern("[0-9]+");
                                    if (!regex_match(guessNumber, pattern)) {
                                        cout << "input value needs to be an integer!" << endl;
                                    } else {
                                        if (secretNumber < stoi(guessNumber)) {
                                            cout << "The secret number is lower" << endl;
                                        } else if (secretNumber > stoi(guessNumber)) {
                                            cout << "The secret number is higher" << endl;
                                        } else if (secretNumber == stoi(guessNumber)) { // Win
                                            cout << "Congratulations!" << endl << endl;
                                            numberOfTries++;
                                            g1.addScore((float) numberOfTries, "Medium");
                                            if(numberOfTries < stoi(gamersVec[i][4])) {
                                                ifstream inputFileMedium("gamers.txt");
                                                ofstream outputFileMedium;
                                                if (!inputFileMedium.is_open()) {
                                                    cout << "Error opening file" << endl;
                                                } else {
                                                    string insideLine;
                                                    while (getline(inputFileMedium, insideLine)) {
                                                        vector<string> vectorLine = split(insideLine, ' ');
                                                        gamersVecDup.push_back(vectorLine);
                                                    }
                                                    outputFileMedium.open("gamers.txt");

                                                    for (int k = 0; k < gamersVecDup.size(); k++)
                                                    {
                                                        for (int j = 0; j < gamersVecDup[k].size(); j++)
                                                        {
                                                            if (k == i && j == 4) {
                                                                outputFileMedium << numberOfTries << ".0 ";
                                                            } else {
                                                                outputFileMedium << gamersVecDup[k][j] << " ";
                                                            }
                                                        }
                                                        outputFileMedium << endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if(choiceDifficulty == "c") { //same as above
                                random_device rd;
                                mt19937 gen(rd());
                                uniform_int_distribution<> minMax(stoi(minHard), stoi(maxHard));
                                int secretNumber = minMax(gen);
                                string guessNumber = "-1";
                                int numberOfTries = 0;
                                while (secretNumber != stoi(guessNumber)) {
                                    cout << "input value between "<< minHard << "-" << maxHard << ":" << endl;
                                    getline(cin, guessNumber);
                                    regex pattern("[0-9]+");
                                    if (!regex_match(guessNumber, pattern)) {
                                        cout << "input value needs to be an integer!" << endl;
                                    } else {
                                        if (secretNumber < stoi(guessNumber)) {
                                            cout << "The secret number is lower" << endl;
                                        } else if (secretNumber > stoi(guessNumber)) {
                                            cout << "The secret number is higher" << endl;
                                        } else if (secretNumber == stoi(guessNumber)) { // Win
                                            cout << "Congratulations!" << endl << endl;
                                            numberOfTries++;
                                            g1.addScore((float) numberOfTries, "Hard");
                                            if(numberOfTries < stoi(gamersVec[i][5])) {
                                                ifstream inputFileHard("gamers.txt");
                                                ofstream outputFileHard;
                                                if (!inputFileHard.is_open()) {
                                                    cout << "Error opening file" << endl;
                                                } else {
                                                    string insideLine;
                                                    while (getline(inputFileHard, insideLine)) {
                                                        vector<string> vectorLine = split(insideLine, ' ');
                                                        gamersVecDup.push_back(vectorLine);
                                                    }
                                                    outputFileHard.open("gamers.txt");

                                                    for (int k = 0; k < gamersVecDup.size(); k++)
                                                    {
                                                        for (int j = 0; j < gamersVecDup[k].size(); j++)
                                                        {
                                                            if (k == i && j == 5) {
                                                                outputFileHard << numberOfTries << ".0 ";
                                                            } else {
                                                                outputFileHard << gamersVecDup[k][j] << " ";
                                                            }
                                                        }
                                                        outputFileHard << endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                cout << "You must choose either a, b or c!" << endl << endl;
                            }

                        } else if (choice == "2") { // friend function is not finished

                            cout << g1;
                        } else if (choice == "3") {  //choosing the top 10 scores to be displayed by difficulty
                            cout << "Select Difficulty of top 10: " << endl << endl
                                 << "a) Easy" << endl
                                 << "b) Medium" << endl
                                 << "c) Hard" << endl << endl;
                            string choiceDifficulty;
                            getline(cin, choiceDifficulty);
                            if (choiceDifficulty == "a") {
                                cout << "Top scores for Easy difficulty:" << endl << endl;
                                vector<int> sortedVect; //new vector
                                int index = 1;
                                for (auto & j : gamersVec) { //insert values into the new vector
                                    sortedVect.insert(sortedVect.end(), stoi(j[3]));
                                }
                                sort(sortedVect.begin(), sortedVect.end()); //sorting the new vector in ascending order
                                for (auto& k : sortedVect) { // looping through the sorted vector and enumerating it by int index
                                    cout << index++ << ") " << k << endl;
                                }
                                cout << endl;
                            } else if(choiceDifficulty == "b") {// same as above
                                cout << "Top scores for Medium difficulty:" << endl << endl;
                                vector<int> sortedVect;
                                int index = 1;
                                for (auto & j : gamersVec) {
                                    sortedVect.insert(sortedVect.end(), stoi(j[4]));
                                }
                                sort(sortedVect.begin(), sortedVect.end());
                                for (auto& k : sortedVect) {
                                    cout << index++ << ") " << k << endl;
                                }
                                cout << endl;
                            } else if(choiceDifficulty == "c") { // same as above
                                cout << "Top scores for Hard difficulty:" << endl << endl;
                                vector<int> sortedVect;
                                int index = 1;
                                for (auto & j : gamersVec) {
                                    sortedVect.insert(sortedVect.end(), stoi(j[5]));
                                }
                                sort(sortedVect.begin(), sortedVect.end());
                                for (auto& k : sortedVect) {
                                    cout << index++ << ") " << k << endl;
                                }
                                cout << endl;
                            } else {
                                cout << "You must choose either a, b or c!" << endl << endl;
                            }

                        } else if (choice == "4") { //exit game
                            isGamer = false;
                        } else {
                            continue;
                        }
                    }
                }
            }
        }
    }
    if (!inGame) { // New User
        cout << "Hello new user!" << endl;
    }
    return 0;
}
