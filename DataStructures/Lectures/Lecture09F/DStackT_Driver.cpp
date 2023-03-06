/*****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This program is a class based example of declaring and using generic 
 * function templates which work on multiple data types. This can display
 * an array with elements of any type for which << is defined.
 * Output: Arrays of ints and an array of charsusing display()
*****************************************************************************/

#include <iostream>
#include <iomanip>
#include "DStackT.h"

using namespace std;

/***************************************************************************
Function Name: print()
Description: prints any data type to the cout stream.
***************************************************************************/
template <typename T>
void print(Stack<T> st)
{
    st.display(cout);
}

int main()
{
    int capacity;
    cout << "Enter stack capacity: ";
    cin >> capacity;

    Stack<int> intStack;       // stack of ints
    Stack<char> charStack;     // stack of chars

    for (int i = 1; i <= capacity; i++)
        {
            intStack.push(100 * i);
        }

    cout << intStack << endl;

    for (char ch = 'A'; ch <= 'X'; ch++)
        {
            charStack.push(ch);
        }

    cout << charStack << endl;
    cout << "Contents of stack intStack (via print):" << endl;
   
    print(intStack);
    cout << endl;

    Stack<int> t;
    t = intStack;

    cout << "Contents of stack t after t = intStack (via print):" << endl;

    print(t);

    cout << endl;
    cout << "Stack t empty? " << boolalpha << t.empty() << endl;
    cout << "Top value in t: " << t.top() << endl;

    while (!t.empty())
        {
            cout << "Popping t:  " << t.top() << endl;
            t.pop();
        }

    cout << "Stack t empty? " << t.empty() << endl;
    cout << "Top value in t: " << t.top() << endl;
    cout << "Trying to pop t: " << endl;

    t.pop();
}