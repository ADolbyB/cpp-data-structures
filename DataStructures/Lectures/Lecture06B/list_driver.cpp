/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a driver file for a single linked list
****************************************************************************/

#include <iostream>

using namespace std;

#include "List.h"

int main()
{
    List intList;

    if (intList.empty())                                            // Test empty() and output of empty list
        {
             cout << "Print Empty List: " << intList << endl;       // Test output of empty list
             cout << "Is List empty? " << (intList.empty() ? "Yes" : "No") << endl << endl;
        }

    for (int i = 0; i < 9; i++)                                     // Test insert()
        {
            intList.insert(i, i/2);                                 // Insert i at position i/2
            cout << intList << endl;                                // Test output
        }

    cout << "Is List empty? " << (intList.empty() ? "Yes" : "No") << endl << endl;
    cout << "Object \'intList\' is now: " << endl;
    cout << intList << endl;

    // Variables declared in the separate block of code are treated like local variables.
    {
        cout << endl << "Separate Block for Destructor Test: " << endl << endl;
        List anotherList;

        for (int i = 0; i < 10; i++)
            {
                anotherList.insert(100 * i, i);
            }

        cout << "Here's another list: " << endl << anotherList << endl;
        cout << "Now destroying this list: " << endl;
    }

    cout << endl << "Testing copy constructor and insert function: " << endl;
    f(intList);                                                     // Test the copy constructor

    cout << endl << endl << "Original list \'intList\': ";          // Output the original to make sure it hasn't been changed
    cout << intList << endl;

    int index;
    while (!intList.empty())
        {
            cout << "Enter an index of a list element to remove: ";
            cin >> index;
            intList.erase(index);                                   // Test erase
            cout << intList << endl;
        }
    cout << "Is List empty? " << (intList.empty() ? "Yes" : "No") << endl;
}