/**
 * ReadWords Interface for Assignment 1
 */

#ifndef READWORDS_H
#define READWORDS_H
/**
 * ReadWords class. Provides mechanisms to read a text file, and return
 * lower-case versions of words from that file.
 */
using namespace std;

#include <string>
#include <fstream>

class ReadWords
{
public:

    /**
     * Constructor. Opens the file with the given filename and associates in
     * with the wordfile stream.
     * Initailises the other members.
     * Prints an error message then terminates the program if thr file cannot be opened.
     * Must not perform any other processing
     * @param filename - a C string naming the file to read.
     */
    ReadWords(const char *filename);

    /**
     * Closes the file.
     */
    void close();

    /**
     * Returns a string, being the next word in the file.
     * All letters should be converted to lower case
     * Leading and trailing punctuation symbols should not be included in the word
     * but punctuation elsewhere should not be removed
     * Returns an empty string if next word contains no letters
     * @return - string - next word.
     */
    string getNextWord();

    /**
     * Returns true if there is a further word in the file, false if we have reached the
     * end of file.
     * @return - bool - !eof
     */
    bool isNextWord();

private:
    ifstream wordfile;
    string nextword;
    bool eoffound;
};

#endif
