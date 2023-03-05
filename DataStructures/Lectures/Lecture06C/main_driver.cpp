/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a driver file for a single linked list
 * This program demonstrates how often a class's constructor, destructor,
 * and copy constructor can get called automatically by the compiler.
 * It uses the same List class but with output statements inserted into
 * the constructor, destructor and copy constructor to trace when they are called.
****************************************************************************/

#include <iostream>

using namespace std;

#include "List.h"

int main()
{

    int listLimit;
    cout << "Enter maximum number of list elements for \'listlimit\': ";
    cin >> listLimit;

    cout << endl << "Executing function: \'List list1(listLimit)\'" << endl;
    List list1(listLimit);

    for (int i = 0; i <= 10; i++)
        {
            cout << "Inside Loop, executing function:  \'list1.insert(i, i)\'" << endl;
            list1.insert(i, i);
            cout << list1;
            cout << endl;
        }

    cout << "Printing List 1:" << endl;
    cout << list1;

    cout << endl << "Executing Function: \'List list2 = list1\'" << endl;
    List list2 = list1;

    cout << endl << "Printing List 2: " << endl;
    cout << list2;

    cout << endl << "Executing Function:  \'List list3\'" << endl;
    List list3;

    cout << endl << "Executing Function:  \'list3 = list2\'" << endl;
    list3 = list2;

    cout << endl << "Printing List 3: " << endl;
    cout << list3;

    cout << endl << "End of this code block" << endl;

    return 0;
}