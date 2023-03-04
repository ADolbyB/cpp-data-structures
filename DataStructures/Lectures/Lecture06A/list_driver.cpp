/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file for a single linked list
****************************************************************************/

#include <iostream>

using namespace std;

#include "List.h"

int main()
{

    List intList;                                           // Test the class constructor

    if (intList.empty())                                    // Test empty() and output of empty list
        {
            cout << "Print Empty List: " << endl << intList << endl;    // Test output of empty list
        }

    for (int i = 0; i < 9; i++)                             // Test insert()
        {
            cout << "Inserting i = " << i << " at position i/2 = " << (i / 2) << endl;
            intList.insert(i, i/2);                         // Insert i at position i/2
            cout << intList << endl;                        // Test output
        }

    cout << endl << "Is the List empty? " << (intList.empty() ? "Yes" : "No") << endl;
    cout << endl << "Try to insert at position -1: " << endl;
    
    intList.insert(0, -1);

    cout << endl << "Try to insert at position 10" << endl;
    
    intList.insert(0, 10);
    cout << endl;
    
    int index;
    
    while (!intList.empty())                                // Test erase function
        {
            cout << "Give an index of a list element to remove: ";
            cin >> index;
            intList.erase(index);
            cout << intList << endl;
        }

    cout << endl << "Is the List empty? " << (intList.empty() ? "Yes" : "No") << endl;

    cout << endl << "Inserting " << CAPACITY << " integers" << endl;

    for (int i = 0; i < CAPACITY; i++)
        {
            intList.insert(i, i);
        }

    cout << intList << endl;

    cout << "Attempt to insert one more integer: " << endl;
    intList.insert(-1, 0);

    return 0;
}