/**************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * STL Container Template
 * This program uses function templates and use of C++'s STLs including
 * Vector and Stack
 * Output: A sorted vector of ints and a sorted deque of doubles.
 * Use the STL standard sort algorithm to sort a vector of stack<int>s.
**************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/***************************************************************************
Function Name: operator<
Description: Overloaded Less-Than Operator. Compares the value of the top
value of the 2 stacks used in the function call argument.
Precondition: ElementType is a type parameter.
Postcondition: Returns TRUE if s1.top() < s2.top() else false.
***************************************************************************/
template<typename ElementType>             // Less-than function for stack
bool operator<(const stack<ElementType>& s1, const stack<ElementType>& s2)
{
   return s1.top() < s2.top();
}

/***************************************************************************
Function Name: dump()
Description: Displays stack elements from top to bottom.
Precondition: ElementType is a type parameter.
Postcondition: Elements of a stack 's' are output to cout from top to bottom.
***************************************************************************/
template<typename ElementType>
void dump(stack<ElementType> s)
{
    cout << " Top-->";
    while (!s.empty())
        {
            cout << s.top() << "  ";        // Print individual stack elements
            s.pop();
        }
}

// Main Driver Program
int main()
{
    vector<stack<int>> s(4);                // A Vector of Stacks, each stack holds Ints

    s[0].push(90);                          // 1st index of vector = stack #1
    s[0].push(80);
    s[1].push(10);                          // 2nd index of vector = stack #2
    s[2].push(11);                          // 3rd index of vector = stack #3
    s[2].push(22);
    s[3].push(12);                          // 4th index of vector = stack #4
    s[3].push(56);
    s[3].push(34);

    cout << "Stacks in original order:" << endl;

    for (int i = 0; i < 4; i++)
        {
            cout << "Stack #" << i << ": ";
            dump(s[i]);
            cout << endl;
        }

    sort(s.begin(), s.end());               // C++ STL vector sort

    cout << endl << "Stacks in sorted order:" << endl;

    for (int i = 0; i < 4; i++)
        {
            cout << "Stack #" << i << ": ";
            dump(s[i]);
            cout << endl;
        }

    return 0;
}