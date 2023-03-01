/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is sample code for practice with dynamic arrays sample
*/

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <cmath>
#include <iomanip>

typedef int *IntPtr;                                            // declares an integer pointer variable type "IntPtr"
typedef int *IntArrayPtr;

void array1(void);
void array2(void);
void fill_array(int any_array[], int the_size);
void bubble_sort_ascending(int any_array[], int the_size);
void swap_values(int& value1, int& value2);
void print_array(int any_array[], int the_size);
void dynamic_array(void);

using namespace std;

int main()
{

    //array1();
    array2();
    //dynamic_array();

    return 0;
}

void array1(void)                                               // demonstrates using pointers with arrays
{

    IntPtr p;                                                   // declare a pointer of type "IntPtr"
    int a[10];                                                  // declaration of a static array a[]
    int index;                                                  // loop control variable

    for (index = 0; index < 10; index++)
        a[index] = index;                                       // initialize the array with integer values.

    p = a;                                                      // sets the pointer to point to the 1st array index

    for (index = 0; index < 10; index++)
        cout << p[index] << " " ;                               // print out values stored in the array using the pointer "p"
    cout << endl;

    for (index = 0; index < 10; index++)
        p[index] = p[index] + 1;                                // add 1 to each array element using the pointer "p"

    for (index = 0; index < 10; index++)                        // prints out the new array element values using the array itself
        cout << a[index] << " ";                                // iterating through a[] is the same as iterating through p[]

    cout << endl;

}

void array2(void)                                               // demonstrates using a dynamic array properly
{

    int array_size;

    cout << "This program sorts dynamic array elements from lowest to highest" << endl;
    cout << "How many numbers do you need to sort? ";
    cin >> array_size;                                          // NOTE: somehow only works for 10 or less, otherwise a "0" is generated after sorting (strange)
                                                                // and the largest value of the array is lost
    IntArrayPtr a;
    a = new int[array_size];
    int *b = new int[array_size];                               // alternate way to declare a dynamic array

    fill_array(a, array_size);
    fill_array(b, array_size);

    cout << "Here are the unsorted array a elements:" << endl;
    print_array(a, array_size);

    cout << endl;
    cout << "Here are the unsorted array b elements:" << endl;
    print_array(b, array_size);

    bubble_sort_ascending(a, array_size);
    bubble_sort_ascending(b, array_size);

    cout << "Here are the sorted array a elements:" << endl;
    print_array(a, array_size);

    cout << endl;

    cout << "Here are the sorted array b elements:" << endl;
    print_array(b, array_size);

    delete [] a;                                                        // frees up the heap/freestore memory taken up by the dynamic array (DON'T FORGET!)
    delete [] b;

}

void fill_array(int any_array[], int the_size)                          // fills array elements
{
    srand(time(NULL));
    int random_generated;

    for (int i = 0; i < the_size; i++)
        {
            random_generated = ((rand() % 99) + 1) * int(pow(-1, i));   // generates a list of alternating +/- integers and writes them to the array
            any_array[i] = random_generated;
        }
}

void bubble_sort_ascending(int any_array[], int the_size)               // sorts array in ascending order with "bubble" method
{

    for (int i = the_size; i > 0; i--)                                  // this shrinks the array search in increments from largest array index downward
        {
            for (int j = 0; j < i; j++)
                {
                    if (any_array[j] > any_array [j + 1])
                        {
                            swap_values(any_array[j], any_array[j + 1]);                        // this pushes or "bubbles" the largest value to the end
                        }
                }
        }
}

void swap_values(int& value1, int& value2)                              // performs swap of 2 variables with call-by-reference
{

    int temp;

    temp = value1;
    value1 = value2;
    value2 = temp;
}

void print_array(int any_array[], int the_size)
{

    for (int j = 0; j < the_size; j++)
        {
            cout << "[" << j << "] = " << any_array[j] << endl;         // prints out the random numbered array values.
        }

    cout << endl;
}

void dynamic_array(void)
{

    int d1, d2;
    cout << "Enter the # of rows and # of columns for the array separated by a space: ";
    cin >> d1 >> d2;

    IntArrayPtr *m = new IntArrayPtr[d1];

    int i, j;
    for (i = 0; i < d1; i++)
        {
            m[i] = new int[d2];             // m is now a d1 by d2 array
        }

    cout << "Enter " << d1 << " rows of " << d2 << " integers each:" << endl;
    for (i = 0; i < d1; i++)
        {
            for (j = 0; j < d2; j++)
                {
                    cout << "[" << i << "]" << "[" << j << "]: ";
                    cin >> m[i][j];                                     // user enter the values for each array index
                }
        }

    cout << endl << "Echo the 2 dimensional array:" << endl;
    for (i = 0; i < d1; i++)
        {
            for (j = 0; j < d2; j++)
                {
                    cout << setw(4) << m[i][j] << " ";                  // prints the values for the array
                }
            cout << endl;
        }

    for (i = 0; i < d1; i++)
        {
            delete[] m[i];                                              // There MUST be one call to "delete[]" for each call to "new" that created the array
        }
    delete[] m;
}