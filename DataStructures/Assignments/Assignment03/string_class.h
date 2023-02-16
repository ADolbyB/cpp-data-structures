/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 02/05/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 3: String Class
Description: This program tests string objects a few different ways.
1) Initializes string object w/ default constructor and attempts to print it. 
2) Initializes a string object with an Explicit value and prints it.
3) Initializes a string object and asks for user input to check if that word or phrase 
is a palindrome. 4) Initializes string objects, user enters a sentence and can search and
replace phrases in that sentence.
*********************************************************************************************/
#ifndef STRING_CLASS_H_INCLUDED
#define STRING_CLASS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class string_class
{

    public:

        string_class();                                                     // Default Constructor
        string_class(string word);                                          // Explicit Value Constructor
        bool palindrome();                                                  // this function checks if the current string is a palindrome
        void replace_all(string& old_substring, string& new_substring);     // this function replaces part of a string with something else
        bool match_strings(const string& old_substring, int& index);        // this function searches a string for a match of part of another string

        friend ostream& operator<<(ostream& file_out, const string_class& the_string);  // overloaded operator << as a friend function with chaining

    private:

        string current_string;                                              // private variable for user input from keyboard.

};

#endif // STRING_CLASS_H_INCLUDED