#include <iostream>
#include <algorithm>
#include "ReadWords.h"
#include "BarChart.h"

using namespace std;

string *input = new string[5]; // array of inputted words by a user
int* ocr = new int[5]; //occurrences
int allWords = 0; // total amount of words in a file
int main() {
    for (int i = 0; i < 5; ++i) { //sets all occurrences to 0. roughly saying i meant that input[0] would occur in a file ocr[0] times.
        ocr[i] = 0;
    }
    for (int i = 0; i < 5; ++i) { //puts string inputted by the user into the array of input and puts them to lowercase
        inLoop:
            cout << "Word " << i + 1 << ":" << endl;
            getline(cin, input[i]);
        transform(input[i].begin(),
                  input[i].end(),
                  input[i].begin(),
                  [](unsigned char character)
                  {
                      return tolower(character);
                  });
            if (input[i].size() <= 1) {
                goto inLoop;
            }
    }
    ReadWords rw("1787.txt");
    /**
     * ReadWords rw(); creates an object and passes in a string of a file name that we expect to open.
     * */
    while (rw.isNextWord()){ //loops through a file specified above in an argument and counts total amount of words.
        string words = rw.getNextWord();
        allWords++;
        for (int i = 0; i < 5; ++i) { //then it checks if any word in a text file matches ones inputted by a user and counts occurrences.
            if (words == input[i]) {
                ocr[i]++;
            }
        }
    }
    BarChart bc(input, ocr, allWords); //creates an object of BarChart where we pass in 3 arguments as specified in BarChart.h and executes code in a constructor as specified in BarChart.cpp
    rw.close(); // closes read file.
    return 0;
}
