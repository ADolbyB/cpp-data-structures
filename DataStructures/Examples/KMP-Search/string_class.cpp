/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for string_class
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "string_class.h"

using namespace std;

string_class::string_class()
{
    current_string = "";
}

string_class::string_class(string s)
{
    current_string = s;
}

bool string_class::palindrome()
{
    int length = current_string.length();

    for (int i = 0; i < length; i++)
    {
        if(tolower(current_string[i]) != tolower(current_string[(length-1)-i]))
            return false;
    }
    return true;
}

void string_class::replace_all(string old_substring, string new_substring)
{
    int m = old_substring.length();

    if(current_string.length() == 0)
        cout << "this string is empty.";
    
    //If old_substring is larger than current_string
    else if(old_substring.length() >  current_string.length())
        cout << "this cannot be done";
    
    //if the length stored in old_substring is smaller than the length of new_substring.
    else
    {
        int index_begin = 0;
        int index_end = 0;
        KMP(old_substring, index_begin, index_end, new_substring);
        //current_string.erase(index_begin, (m-1));
    }
}

ostream& operator<< (ostream& out, const string_class& stringObj)
{
    out << stringObj.current_string;
    return out;
}

void string_class::computeLPSArray(string pat, int M, int* lps)
{
    int j = 0;     // length of the previous longest prefix suffix

    lps[0] = 0;    // lps[0] is always 0

    int i = 1;

    while(i < M)   // M = pattern length -- this phrase is pretty much the same as index - 1 since its an array were gpin through
    {
        if(pat[i] == pat[j]) // if index i == j then they are the same char so move move j to next index and assign it to lps[i] then add1 to i
        {                    // we are moving up the string
            j++;
            lps[i] = j;
            i++;
        }

        else // if index 0 doesnt match index 1
        {
            if(j != 0) // so pretty much tells it to go backwards when we have substr pattern of more than one char ex abcabdd once it reaches d and compares
                j = lps[j - 1]; // it to c it will move back the location to j - 1 b/c the pattern in subctr is abc
            
            else // so if length of prefix = 0
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void string_class::KMP(string patt, int& index_begin, int& index_end, string newsub)
{
    string temp(current_string); //temporrary copy

    int M = int(patt.length()); //pattern length = M
    int N = current_string.length(); //length of string we wanna search

    //Mptr will hold the longest prefix and suffix

    int *Mptr;
    Mptr = new int[M];

    //now we calculat the lps using lps function
    computeLPSArray(patt, M, Mptr);

    int i = 0; // we usw this index for current string (the one we wanna search)
    int j = 0; // we use this index for the pattern


    while(i < N) //index for current < current length
    {
        if(patt[j] == current_string[i])
        {
            i++;
            j++;
        }

        if(j == M) //so if j has traveresed the whole pattern
        {
            int count = 0;
                index_begin = i - j;
                index_end = index_begin + (M -1);

                j = Mptr[j - 1];

                temp.insert(index_end +1 , newsub);
                temp.erase(index_begin, M );

                current_string = temp;
        }

        else if(i < N && patt[j] != current_string[i]) // mismatch after j matches
        {
            if(j != 0)
                j = Mptr[j - 1];
            else
                i = i + 1;
        }
    }
}