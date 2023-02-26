/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 03/26/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 8: Recursion
Description:
    1) This program takes a user entered string and processes it through a recursive function
        to determine if it is a palindrome or not.
    2) The 2nd function is a recursive function that reverses the characters of the user-entered
        string. The function recursively calls itself, deleting the last character of the string
        after each call. Each time this is done, the new last character is then concatenated
        into a globally declared string called "temp", which is returned so it can be printed to
        the screen in the main
    3) The 3rd function is an iterative function that reverses the characters of the string.
        This function iterates the string from the last character to the 1st with a for loop
        and concatenates this into a temporary string containing the backwards string.
        This backwards string is then returned so it can be printed to the screen in the main.
*********************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string temp = "";  // temp string to concatenate recursive "PrintReversel()" string into;

bool palindrome(const string& s);
string printReversel(const string& s);
string printIterReverse(const string& s);

int main()
{

	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
        {
            cout << " please enter string: ";
            getline(cin, s);

            if (palindrome(s) == true)
                {
                    cout << s << " is a palindrome \n";
                }
            else
                {
                    cout << s << " is NOT a palindrome \n";
                }

            cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
            cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
            cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";

            cin >> response;
            cin.ignore();                                                       // ignore the '\n' in the stream
        }

	return 0;
}

/**************************************************************************************
> Function Name: palindrome(const string& s);
> Precondition: The string that is being checked if it's a palindrome has been declared
> Postcondition: A boolean value is returned TRUE if the string is a palindrome, FALSE
    is returned if the string is NOT a palindrome
> Description: This function uses the substr() function with recursion to trim the 1st
    and last character upon each recursive call. On each recursive call, the first and
    last characters are checked if they are the same. If they are the same, the function
    continues until:
    1) There is no match and FALSE is returned
    2) All characters that match are trimmed down to where the string length is 0 or 1,
        and TRUE is returned.
***************************************************************************************/
bool palindrome(const string& s)                                                // evaluates if a user entered string is a palindrome
{

    int first_char = 0;                                                         // first index number of the string

    int last_char = (int)s.length() - 1;                                        // index number for the last character

    //cout << "Before IF: String s = " << s << endl;                            // debug
    //cout << "(1) s[0] = (" << s[0] << ") && s[last_char] = (" << s[last_char] << ")" << endl;

    if(s.length() <= 1)                                                         // if string length is 0 or 1 then it is automatically a palindrome
        {
            return true;
        }
    else
        {
            //cout << "Inside Else: String s = " << s << endl;                  // debug
            //cout << "(2) s[0] = (" << s[0] << ") && s[last_char] = (" << s[last_char] << ")" << endl;
            if(tolower(s[0]) != tolower(s[last_char]))                          // shortcut to skip most non-palindromes
                {
                    return false;
                }
            else
                {
                    return palindrome(s.substr(++first_char, --last_char));     // trim the 1st and last characters BEFORE recursive function call
                }
        }
    //cout << "End of Palindrome" << endl;                                      // debug
}

/**************************************************************************************
> Function Name: printReversel(const string& s);
> Precondition: The string to be printed has been declared.
> Postcondition: The string is printed in reverse by recursion
> Description: This function recursively calls itself, deleting the last character of the
    string after each call. Each time this is done, the new last character is then
    concatenated into a globally declared string called "temp"
***************************************************************************************/
string printReversel(const string& s)                                           // prints a backwards string using recursion
{

    int last_char = s.length() - 1;                                             // index position of the last character of string "s"

    string local_temp2 = "";                                                    // local temp string to dump global string into upon recursion completion

    if(s.length() != 0)
        {
            temp += s[last_char];                                               // concatenate each last character into the globally declared string
            //cout << "s.length() = " << s.length() << endl;                    // debug
            //cout << "s[last_char] = " << s[last_char] << endl;                // debug
            //cout << "String s = " << s << endl;                               // debug
            //cout << "IF: string temp = " << temp << endl;                     // debug
            return printReversel(s.substr(0 , s.length() - 1));                 // recursive call: cuts last character off string until string is empty
        }
    else
        {
            //cout << "ELSE: string temp = " << temp << endl;                   // debug
            local_temp2 = temp;                                                 // dump globally concatenated string into local string
            temp = "";                                                          // clear global string variable upon completion of recursion
            return local_temp2;                                                 // returns the concatenated reversed string after s.length() == 0 from
        }                                                                       // the recursive function calls
}

/**************************************************************************************
> Function Name: printIterReverse(const string& s);
> Precondition: The string to be printed has been declared.
> Postcondition: The string is printed in reverse by iteration
> Description: Iterates the string from the last character to the 1st
    and concatenates that character into a temporary string containing the backwards string.
    This backwards string is then returned so it can be printed to the screen in the main.
***************************************************************************************/
string printIterReverse(const string& s)                                        // Print backwards string by iteration of the string
{

    int i;                                                                      // for loop counter variable

    string local_temp = "";                                                     // temporary string that holds the concatenated backwards string

    if((int)s.length() == 0 || (int)s.length() == 1)
        {
            return s;                                                           // every 0 or 1 character string does not need to be reversed
        }
    else
        {
            for(i = (int)s.length() - 1; i >= 0; i--)                           // iterates the input string in reverse
                {
                    local_temp += s[i];                                         // concatenate each character into the temp string
                    //cout << endl<< "Temp String = " << temp << endl;          // debug
                }
        }
    return local_temp;                                                          // return the backwards string
}