/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file to test a single linked queue.
*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "stack_deck.h"

template <typename T>
void print(Stack<T> st)
{
    st.display(cout);
}

int main()
{
    int cap;

    cout << "Enter stack capacity: ";
    cin >> cap;

    Stack<int> intSt;    // stack of ints
    Stack<char> charSt;  // stack of chars

    for (int i = 1; i <= cap; i++)
        {
            intSt.push(i);
        }

    intSt.display(cout); cout << endl;

    for (char ch = 'A'; ch <= 'D'; ch++)
        {
            charSt.push(ch);
        }

    charSt.display(cout); cout << endl;

    cout << "Contents of stack intSt (via  print):" << endl;
    print(intSt);
    cout << endl;

    Stack<int> t;
    t = intSt;

    cout << "Contents of stack t after t = stInt (via  print):" << endl;
    print(t);
    cout << endl;

    cout << "Stack t empty? " << t.empty() << endl;

    cout << "Top value in t: " << t.top() << endl;

    while (!t.empty())
        {
            cout << "Popping t:  " << t.top() << endl;
            t.pop();
        }

    cout << "Stack t empty? " << t.empty() << endl;
    cout << "HERE" << endl;
    cout << "Top value in t: " << t.top() << endl;
    cout << "HERE2" << endl;
    cout << "Trying to pop t: " << endl;

    t.pop();
}