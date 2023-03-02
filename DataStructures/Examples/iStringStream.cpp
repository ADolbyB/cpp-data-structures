/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is some test code I wrote for using iStringStream
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <sstream>

using namespace std;

int main()
{

    string date = "U.S. Independence: July 4, 1776";                // any string with whitespace

    cout << "Test string: " << date << endl;

    istringstream istr(date);                                       // declare object istr that reads in the "date" string.

    string word1, word2, month;
    int day, year;
    char comma;

    istr >> word1 >> word2 >> month >> day >> comma >> year;        // istr object parses the string "date" into individual variables since ">>" ignores the whitespace characters

    cout << endl << "The contents of the String Stream istr are listed 1 per line:" << endl;
    cout << word1 << endl << word2 << endl << month << endl << day << comma << endl << year << endl << endl;

    cout << endl << "Enter a sentence to echo:" << endl;

    string sentence;
    getline(cin, sentence);                                         // getline does not ignore whitespace character input like "cin >>" does, but does ignore and discard the '\n' by default
    cout << endl << "Echoed text: " << sentence << endl;

    string test1 = "District of Columbia 1234567";                  // not sure how to get just the words separated from the numbers here.

    return 0;
}