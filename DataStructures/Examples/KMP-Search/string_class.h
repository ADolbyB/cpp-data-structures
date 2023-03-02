/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for string_class
*/

#ifndef string_class_h
#define string_class_h

#include <string>
#include <iostream>

using namespace std;

class string_class
{
    public:

        string_class();
        string_class(string s);
        bool palindrome();
        void replace_all(string old_substring, string new_substring);
        void computeLPSArray(string pat, int M, int* lps);
        void KMP(string patt,int& index_begin, int& index_end, string newsub);

        friend ostream& operator<<(ostream& out, const string_class& stringObj);

    private:
        string current_string;
};

#endif