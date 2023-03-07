/**************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * STL Container Template
 * This program uses a function template and use of C++'s STLs including
 * Vector, Deque and Std sort algorithm.
 * Output: A sorted vector of ints and a sorted deque of doubles.
 * Use the STL standard sort algorithm to sort a vector of stack<int>s.
**************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

template <typename Container>               // Function Prototype Declaration
void display(const Container& c);

bool intLessThan(int a, int b)              // Less Than function for INTs
{
    return a > b;
}

bool dubLessThan(double a, double b)        // Less Than function for DOUBLEs
{
    return a > b;
}

// Main Driver Program
int main()
{

    int ints[] = {555, 33, 444, 22, 222, 777, 1, 66};

    vector<int> v(ints, ints + 5);          // Use only first 5 elements of ints

    sort(v.begin(), v.end(), intLessThan);  // C++ STL standard sort function

    cout << "Sorted vector of integers:" << endl;

    display(v);

    double dubs[] = {55.5, 3.3, 44.4, 2.2, 22.2, 77.7, 0.1};

    deque<double> d(dubs, dubs + 7);        // Use all 7 elements of ints

    sort(d.begin(), d.end(), dubLessThan);  // C++ STL standard sort function

    cout << endl << "Sorted deque of doubles:" << endl;

    display(d);

    return 0;
}

/***************************************************************************
Function Name: display()
Description: This function template displays elements of any type
(for which the output operator is defined) stored in a container 'c' 
(for which [] and size() are defined).
Precondition: Container is a type parameter.
Postcondition: Values stored in 'c' are output to cout.
***************************************************************************/
template <typename Container>
void display(const Container& c)
{
    for (int i = 0; i < (int)c.size(); i++)
        {
            cout << c[i] << "  ";
        }
    cout << endl;
}