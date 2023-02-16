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
#include <iostream>                     // directive for cin, cout, >>, <<
#include <fstream>                      // directive for file i/o ??
#include <string>                       // directive for string
#include <cctype>                       // directive for toupper()

#include "string_class.h"

using namespace std;

/*************************************************************************************
Function Name: string_class
Precondition: A string object has been declared.
Postcondition: The string object is initialized to an empty string.
Description: Default Constructor: This function initializes a new string object to an
empty string with no characters.
*************************************************************************************/
string_class::string_class()
{

   current_string = "";              // initializes "current string" to a blank string

}

/*************************************************************************************
Function Name: string_class
Precondition: A string object has been declared with an argument
Postcondition: The string object is intialized containing the characters in the
object declaration argument.
Description: Explicit Value Constructor: When an object is declared with an argument,
that argument is used as the initialization value of the string.
*************************************************************************************/
string_class::string_class(string word)
{

    current_string = word;          // initializes "current string" to the word in the function argument string

}

/*************************************************************************************
Function Name: palindrome
Precondition: A string has been declared and user has entered input via the keyboard
Postcondition: Returns "true" if string is a palindrome, returns "false" if it is not.
Description: Accessor function. This function accesses the current_string as was entered
by the user via keyboard. It then compares the beginning and end characters one at a
time, moving to the middle of the string. If all the characters match, then a value of
true is returned. Otherwise, fales is returned.
*************************************************************************************/
bool string_class::palindrome()                 // returns true if the "current_string" is a palindrome
{

    double length = current_string.length();    // set loop control variable to the length of "current_string"

    for (int i = 0; i <= (length / 2.0); i++)   // only need to run to the 1/2 way point
        {
            if(tolower(current_string[i]) != tolower(current_string[(length - 1) - i]))     // compares each character from the ends in
                {
                    return false;                                               // returns false if there is not a palindrome
                }
        }
    return true;                                                                // returns true when the loop ends due to finding a palindrome
}

/*************************************************************************************
Function Name: replace_all
Precondition: The user has entered a value for "current_string" via the keyboard, and
string objects "old_substring" and "new_substring" have been declared and user has entered
values via the keyboard
Postcondition: The "current_string" is modified with "new_string" if the "old_string"
matches a part or all of the "current_string". The "current_string" is not modified if
"old_string" does not match anything in the "current_string"
Description: Mutator function. This function mutates the "current_string" with
"new_string" if the "old_string" matches a part or all of the "current_string". The
"current_string" is not modified if "old_string" does not match anything in the "current_string"
*************************************************************************************/
void string_class::replace_all(string& old_substring, string& new_substring)
{
    /** Note special cases: or if old_substring is not located in current_string, then the value of current_string will not change. */

    if(current_string.empty())   // check if current_string is an empty string
        {
            cout << "This is an empty string...";
            return;
        }
    else if(old_substring.length() >  current_string.length())  // If old_substring is larger than current_string then it won't work.
        {
            cout << "Sorry, this is not possible..." << endl;
            return;
        }
    else    //if the length stored in old_substring is smaller than the length of current_string.
        {
            string modified_string = "";        // declare a blank string

            for (int i = 0; i < int(current_string.length()); i++)
                {
                    if(match_strings(old_substring, i))
                        {
                            //cout << "1) STRING MATCH" << endl;                                    // debug
                            modified_string.append(new_substring, 0, new_substring.length());       // appends new_substring to the end of modified string
                            //cout << "1) Modified String = " << modified_string << endl;           // debug
                            //cout << "1) Current String = " << current_string << endl;             // debug
                            //cout << "1) old_substring = " << old_substring << endl;               // debug
                            //cout << "1) i = " << i << endl;                                       // debug
                            i += (old_substring.length() - 1);                                      // moves the index to after old_substring
                        }
                    else
                        {
                            modified_string.append(current_string, i, 1);
                            //cout << "2) Modified String = " << modified_string << endl;           // debug
                            //cout << "2) Current String = " << current_string << endl;             // debug
                            //cout << "2) old_substring = " << old_substring << endl;               // debug
                            //cout << "2) i = " << i << endl;                                       // debug
                        }
                }
            current_string = modified_string;                                                       // replaces the current_string with the new modified_string
        }
}

/*************************************************************************************
Function Name: match_string
Precondition: a string object has been declared and intialized with user entered input
from the keyboard as "current_string", and user has entered a value for "old_substring"
Postcondition: Returns false if there is no match, True if there is a match
Description: Accessor Function: This function accesses the private variable "current_string"
and the user entered string "old_substring". This function returns True if the user entered
data matches any data in the "current_string", and False if the user entered data does
not match.
*************************************************************************************/
bool string_class::match_strings(const string& old_substring, int& index)
{

    int tempIndex = index;                                      // algorithm to check for token matches in a string

    if(index > int(current_string.length()))                    // the index can't be larger than the length of the current_string
        {
            cout << "This is not a valid index..." << endl;
        }
    else if(current_string.length() >= old_substring.length())
        {
            for(int j = 0; j < int(old_substring.length()); j++, tempIndex++)
                {
                    if (tolower(current_string[tempIndex]) != tolower(old_substring[j]))    // iterates through the strings to look for match
                    return false;                                                           // returns false if no match found
                }
            return true;                                                                    // returns true if loop ends from a match
        }
    return false;                                                                           // returns false when index is invalid

}
/*************************************************************************************
Function Name: operator<<
Precondition: The object variables to be output to the stream must be initialized with values.
Postcondition: The state of the class is output to the specified stream object (like cout)
Description: Accessor Friend Function:  accesses and displays the state of the class
by returning any ostream object.
*************************************************************************************/
ostream& operator<< (ostream& out_file, const string_class& the_string)
{

    out_file << the_string.current_string;                      // sends the current_string to an output stream

    return out_file;

}