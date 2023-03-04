/**
 * Joel Brigida
 * COP 3530: Data Structures
 * This is the test driver for the Time class
 * This get and set type functions.
*/

#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time mealTime;

    mealTime.set(5, 30, 'P');

    cout << "We'll be eating at ";
    mealTime.display(cout);

    cout << endl;

    cout << endl << "Now trying to set time with illegal hours (13)" << endl;
    mealTime.set(13, 0, 'A');

    cout << "Now trying to set time with illegal minutes (60)" << endl;
    mealTime.set(5, 60, 'A');

    cout << "Now trying to set time with illegal AM/PM ('X')" << endl;
    mealTime.set(5, 30, 'X');

}