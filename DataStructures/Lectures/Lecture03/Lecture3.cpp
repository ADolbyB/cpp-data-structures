/**
 * Joel Brigida
 * COP 3530: Data Structures
 * Some Practice code I wrote for Lecture 3.
 * 3 programs that demostrate overflow
 * 1 program to demonstrate pointers and addresses
*/

#include <iostream>
#include <cassert>
#include <new> // directive for "new" and "bad_alloc" operators

using namespace std;

const int CAPACITY = 4;
typedef int IntArray[CAPACITY];

void read(IntArray theArray, int capacity, int numValues);
void display(IntArray theArray, int numValues);
void array_OOR(void);
void new_fail1(void);
void new_fail2(void);

int main()
{

    array_OOR();
    //new_fail1();
    //new_fail2();

    return 0;
}

void array_OOR(void)
{
    /**
     * Demonstration of what can happen when array indices get out of bounds.
     * Input:  Three arrays of integers
     * Output: The three arrays before and after modification using out-of-range indices.
    */

    IntArray a, b, c;

    cout << "Enter " << CAPACITY << " integer values for:" << endl;
    cout << "Array a: ";
    read(a, CAPACITY, CAPACITY);

    cout << "Array b: ";
    read(b, CAPACITY, CAPACITY);

    cout << "Array c: ";
    read(c, CAPACITY, CAPACITY);

    cout << endl << "Part I of the demonstration:" << endl << endl << "The arrays are:" << endl;

    cout << "a: ";
    display(a, CAPACITY);

    cout << "b: ";
    display(b, CAPACITY);

    cout << "c: ";
    display(c, CAPACITY);

    // Change array elements using out-of-range indices.

    int below = -3;
    int above = 6;

    b[below] = -999;
    b[above] = 999;

    cout << endl << "Part II of the demonstration" << endl << endl 
            << "The arrays after out-of-range errors are:" << endl;

    cout << "a: ";
    display(a, CAPACITY);

    cout << "b: ";
    display(b, CAPACITY);

    cout << "c: ";
    display(c, CAPACITY);

    cout << endl;
}

/***************************************************************************
Function Name: read()
Description: Array Input Function: input values into an array of 
integers from the keyboard.
Preconditions: 0 <= numValues < capacity of theArray.
Postcondition: numValues integers entered from the keyboard have been
stored in the first NumValues positions of theArray
***************************************************************************/
void read(IntArray theArray, int capacity, int numValues)
{
    assert(numValues >= 0 && numValues <= capacity);

    for (int i = 0; i < numValues; i++)
        {
            cin >> theArray[i];
        }
}

/***************************************************************************
Function Name: display()
Description: Array Output Function Displays values in an array of integers.
Precondition:  0 <= numValues < capacity of theArray.
Postcondition: The first numValues integers stored in theArray have
been output to cout.
**************************************************************************/
void display(int theArray[], int numValues)
{
    for (int i = 0; i < numValues; i++)
        {
            cout << theArray[i] << " ";
        }
    cout << endl;
}

void new_fail1(void)
{
    // Demonstration #1 of new failure: Uncaught bad_alloc exception

    const int NUM_ARRAYS = 10;
    double *arrayPtr[NUM_ARRAYS];
    int i, capacity;

    cout << "How many indices in the array of doubles? ";
    cin >> capacity;

    for (i = 0; i < NUM_ARRAYS; i++)
        {
            arrayPtr[i] = new double [capacity];
            cout << "Allocated " << capacity << " doubles for i = " << i << endl;
        }
    cout << "All " << NUM_ARRAYS << " arrays of " << capacity << " doubles were allocated successfully." << endl;
}

void new_fail2(void)
{
    // Demonstration #2 of new failure: Use try-catch to handle bad_alloc exception.

    const int NUM_ARRAYS = 10;
    double *arrayPtr[NUM_ARRAYS];
    int i, capacity;

    cout << "How many indices in the array of doubles? ";
    cin >> capacity;

    try
    {
        for (i = 0; i < NUM_ARRAYS; i++)
            {
                arrayPtr[i] = new double [capacity];
                cout << "Allocated " << capacity << " doubles for i = " << i << endl;
            }
    }

    catch (bad_alloc ex)
    {
        cout << endl << "Exception: " << ex.what() << " -- for i = " << i << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }
    cout << "All " << NUM_ARRAYS << " arrays of " << capacity << " doubles were allocated successfully." << endl;
}