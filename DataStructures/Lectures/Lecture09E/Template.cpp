/*****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This program is a non-class based example of declaring and using generic 
 * function templates which work on multiple data types. This can display
 * an array with elements of any type for which << is defined.
 * Output:  An array of ints and an array of doubles using display()
*****************************************************************************/

#include <iostream>

using namespace std;

/****************************************************************************
Function Name: display()
Description: Display elements of any type (for which the output operator is 
defined) stored in an array.
Precondition: ElementType is a type parameter.
Postcondition: First numElements of array have been output to cout.
*****************************************************************************/
template <typename ElementType>
void display(ElementType array[], int numElements)
{
    for (int i = 0; i < numElements; i++)
        {
            cout << array[i] << "  ";
        }
    cout << endl;
}

// Main Driver
int main()
{

    double x[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    display(x, 5);

    int num[] = {1, 2, 3, 4};
    display (num, 4);

    return 0;
}