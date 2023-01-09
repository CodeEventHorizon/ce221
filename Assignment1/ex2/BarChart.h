#ifndef BARCHART_H
#define BARCHART_H

using namespace std;

#include <string>
#include <fstream>

class BarChart {
public:
    BarChart(string* input, int* ocr, int allWords);
    /**
     * constructor takes in 3 arguments,
         * first: array of inputs (pointer).
         * second: array of ocr, which stands for occurrences of a specific word in a read text file, which is counted by incrementation
         * third: value of total words in a read text file
     * */
    double round(double val, int dec);
    /**
     * round method takes in a value decimal places and rounds it to amount of decimal places inputted
     * inside a second argument
     * */
};


#endif //BARCHART_H
