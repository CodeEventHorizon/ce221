using namespace std;

#include "BarChart.h"
#include <iostream>


BarChart::BarChart(string* input, int* ocr, int allWords) {
    ofstream output ("searchedWords.txt");
    cout << "Searched Words: ";
    output << "Searched Words: ";
    for (int i = 0; i < 5; i++) {
        cout << input[i];
        output << input[i];
        if (i == 4) {
            cout << "." << endl << endl;
            output << "." << endl << endl;
        } else {
            cout << ", ";
            output << ", ";
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << input[i] << "\t=";
        for (int j = 0; j < ocr[i]/100; j++) {
            cout << "=";
        }
        cout << ocr[i] << "("
             << round((float)ocr[i] / (float)allWords, 4)*100 << "%)" << endl;
        //
        output << input[i] << "\t=";
        for (int k = 0; k < ocr[i]/100; k++) {
            output << "=";
        }
        output << ocr[i] << "("
               << round((float)ocr[i] / (float)allWords, 4)*100 << "%)" << endl;
    }
    output.close();
}
/**
 * BarChart constructor takes in arguments as specified in the header file.
 * first of all it creates an empty file called "searchedWords.txt",
 * then it outputs to both the terminal and created file, the 5 words that user searched for,
 * then it outputs how many times each specified word occurred in a text file that was read in ReadWords class and the percentage,
 * which is amount of occurrences divided by the total amount of words in the text file that was read.
 * */
double BarChart::round(double val, int dec) {
    const double multiplier = pow(10.0, dec);
    return ceil(val*multiplier) / multiplier;
}
/**
 * the way round() method works is, it takes in a double value as a first argument and decimal as the second.
 * then a constant double multiplier is created which is a pow() method. pow() takes in base as a first argument and exponent as a second.
 * So The pow() method returns base raised to the power of exponent.
 * then round() method returns rounded number.
 * The ceil() method returns the smallest possible integer value which is greater than or equal to the given argument.
 * */

