/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * Base 10 to Binary Converter w/ Stack
 * 
 * This program uses a stack to convert the base-ten representation
 * of a positive integer entered as input to base two, which is
 * then output.
****************************************************************************/

#include <iostream>
#include "Stack.h"                              // include from local directory

using namespace std;

int main()
{

    int number;                                 // the number to be converted
    unsigned remainder;                         // remainder when number is divided by 2

    Stack stackOfRemainders;                    // stack of remainders

    cout << "=>> Positive Base 10 to Binary string converter <<=" << endl;
    cout << "* Enter a negative number at an time to exit *" << endl << endl;

    do {

        cout << "Enter positive integer to convert: ";
        cin >> number;

        if(number >= 0)
            {
                while (number != 0)
                    {
                        remainder = number % 2;
                        stackOfRemainders.push(remainder);
                        number /= 2;
                    }

            cout << "Binary representation: ";

            while ( !stackOfRemainders.empty() )
                {
                    remainder = stackOfRemainders.top();
                    stackOfRemainders.pop();
                    cout << remainder;
                }

            cout << endl << endl;

            }

        else
            {
                number = -1;
            }

    } while (number >= 0);
}