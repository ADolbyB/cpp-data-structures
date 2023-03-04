/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is a simplified implementation file for a stack class
*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Stack.h"

int main()
{

    Stack s;

    cout << "Stack created. Is it empty? True or False: " << boolalpha << s.empty() << endl;

    cout << "Enter how many elements to add to the stack: ";
    int numItems;
    cin >> numItems;

    for (int i = 1; i <= numItems; i++)
        {
            s.push(i);
        }

    cout << "Stack contents" << endl;
    s.display(cout);

    cout << "Stack empty? " << s.empty() << endl;

    cout << "Top value: " << s.top() << endl;

    while (!s.empty())
        {
            cout << "Popping " << s.top() << endl;
            s.pop();
        }

    cout << "Stack empty? " << s.empty() << endl;
    cout << "Top value: " << s.top() << endl;
    cout << "Trying to pop: " << endl;

    s.pop();

}