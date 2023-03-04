/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver program to test the Stack class.
 * It instantiates a Linked List as a stack, adds and removes nodes
*/

#include <iostream>
using namespace std;

#include "LStack.h"

void print(stack stack_obj);

int main()
{

    stack s;

    cout << "Stack created. Empty? " << boolalpha << s.empty() << endl;

    cout << "How many elements to add to the stack? ";

    int numItems;
    cin >> numItems;

    for (int i = 1; i <= numItems; i++)
        {
            s.push(i);
        }

    cout << "Stack empty? " << s.empty() << endl;

    cout << "Contents of stack s (via  print):" << endl;
    print(s);
    cout << endl;

    cout << "Check that the stack wasn't modified by print:" << endl;
    s.display(cout);
    cout << endl;

    stack t, u;
    t = u = s;

    cout << "Contents of stacks t and u after t = u = s (via  print):" << endl;
    cout << "u: " << endl;
    print(u);
    cout << endl;
    
    cout << "t: " << endl;
    print(t);
    cout << endl;

    cout << "Top value of stack t: " << t.top() << endl;

    while (!t.empty())
        {
            cout << "Popping t:  " << t.top() << endl;
            t.pop();
        }
    cout << "Stack t empty? " << t.empty() << endl;
    cout << endl << "Now try to retrieve top value from t." << endl;
    cout << "Top value in t: " << t.top() << endl;
    cout << endl << "Trying to pop t: " << endl;
    t.pop();
}

void print(stack stack_obj)
{

    stack_obj.display(cout);

}