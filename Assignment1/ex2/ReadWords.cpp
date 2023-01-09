using namespace std;

#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>

string removePunct(string word)
{
    word.erase(word.begin(), find_if_not(word.begin(), word.end(), ispunct));
    word.erase(find_if_not(word.rbegin(), word.rend(), ispunct).base(), word.end());
    return word;
}
/**
 * removePunct() takes in a string as an argument and erases punctuation only in the beginning or ending of the words
 * (considering a word might have more than one punctuation)
 * any type of punctuation in the middle of the word is regarded as a part of the word and is not removed.
 * */
ReadWords::ReadWords(const char *fname)
{   wordfile.open(fname);
    if (!wordfile)
    {   cout << "Failed to open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword;
    eoffound = false;
}
/**
 * constructor opens a file and outputs an error if file failed to open
 * */
string ReadWords::getNextWord()
{
    string word = nextword;
    wordfile >> nextword;

    if (wordfile.eof())
        eoffound = true;

    word = removePunct(word);
    transform(word.begin(),
              word.end(),
              word.begin(),
              [](unsigned char character)
              {
                return tolower(character);
              });
    if (word.empty()) {
        return "";
    }
    return word;
}
/**
 * getNextWord() method returns next word in a file, where words are separated by a whitespace.
 * method lowers the word by the transform() method that is taken from #include <algorithm>
 * basically transform() splits a string into chars and loops through them and puts each char to lowercase
 * if word is empty is returns an empty string;
 * */
bool ReadWords::isNextWord()
{
    return !eoffound;
}
/**
 * isNextWord() method returns false if text file doesn't have a next word to read
 * */
void ReadWords::close()
{
    wordfile.close();
}
/**
 * close() method closes a file
 * */