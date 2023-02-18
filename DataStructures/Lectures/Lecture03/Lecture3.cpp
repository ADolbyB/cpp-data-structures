/**
 * Joel Brigida
 * COP 3530: Data Structures
 * Some Practice code I wrote for Lecture 3.
 * 3 programs that demostrate overflow
 * 1 program to demonstrate pointers and addresses
*/


#include <iostream>
#include <cassert>
#include <new>                      // directive for "new" and "bad_alloc" operators

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

    cout << "Enter " << CAPACITY << " integer values for:\n";
    cout << "Array a: ";
    read(a, CAPACITY, CAPACITY);

    cout << "Array b: ";
    read(b, CAPACITY, CAPACITY);

    cout << "Array c: ";
    read(c, CAPACITY, CAPACITY);

    cout << "\n------ Part I of the demonstration -----\n\nThe arrays are:\n";

    cout << "a: ";
    display(a, CAPACITY);

    cout << "b: ";
    display(b, CAPACITY);

    cout << "c: ";
    display(c, CAPACITY);

    // Change array elements using out-of-range indices.

    int below = -3, above = 6;

    b[below] = -999;
    b[above] = 999;

    cout << "\n------ Part II of the demonstration -----\n\n"
            "The arrays after out-of-range errors are:\n";

    cout << "a: ";
    display(a, CAPACITY);

    cout << "b: ";
    display(b, CAPACITY);

    cout << "c: ";
    display(c, CAPACITY);

    cout << endl;


}

void read(IntArray theArray, int capacity, int numValues)
{
/**-------------------------------------------------------------------------
=>> Figure 3.4 Array Input Function <<=

Input values into an array of integers from the keyboard.

Preconditions: 0 <= numValues < capacity, which is the capacity of theArray.
Postcondition: numValues integers entered from the keyboard
    have been stored in the first NumValues positions of theArray
--------------------------------------------------------------------------*/

    assert(numValues >= 0 && numValues <= capacity);

    for (int i = 0; i < numValues; i++)
        {
            cin >> theArray[i];
        }

}

void display(int theArray[], int numValues)
{
/**-----------------------------------------------------------------
=>> Figure 3.3 Array Output Function <<=

Display values in an array of integers.

Precondition:  0 <= numValues < capacity of theArray.

Postcondition: The first numValues integers stored in theArray have
    been output to cout.

-------------------------------------------------------------------------*/

    for (int i = 0; i < numValues; i++)
        {
            cout << theArray[i] << " ";
        }

   cout << endl;

}

void new_fail1(void)
{
/** Demonstration #1 of new failure -- Uncaught bad_alloc exception */

    const int NUM_ARRAYS = 10;
    double *arrayPtr[NUM_ARRAYS];
    int i, capacity;

    cout << "How large should the arrays of doubles be? ";
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
/** Demonstration #2 of new failure -- Use try-catch mechanism to handle bad_alloc exception. */

    const int NUM_ARRAYS = 10;
    double *arrayPtr[NUM_ARRAYS];
    int i, capacity;

    cout << "How large should the arrays of doubles be? ";
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

        cout << "\nException: " << ex.what() << " -- for i = " << i << endl;
        exit(1);

   }

   cout << "All " << NUM_ARRAYS << " arrays of " << capacity << " doubles were allocated successfully." << endl;

}