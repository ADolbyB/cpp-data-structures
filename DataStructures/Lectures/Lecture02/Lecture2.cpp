/**
 * Joel Brigida
 * COP 3530: Data Structures
 * Some Practice code I wrote for Lecture 2.
 * 3 programs that demostrate overflow
 * 1 program to demonstrate pointers and addresses
*/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void overflow1(void);
void overflow2(void);
void overflow3(void);
void pointers_addresses(void);

int main()
{

   overflow1();
   overflow2();
   overflow3();
   pointers_addresses();

   return 0;
}

void overflow1(void)
{
    cout << "OVERFLOW 1:" << endl;
    cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
    cout << "4 bytes = " << 4 * 8 << " bits" << endl;
    cout << "So INT_MAX should be " << long(pow(2, 32)) / 2 << endl;
    cout << "And INT_MIN should be " << -((long(pow(2, 32))) / 2) + 1 << endl << endl;

    int number = 2;

    for (int i = 1; i <= 15; i++)
        {
            cout << number << endl;
            number *= 10;
        }
    cout << endl;
}

void overflow2(void)
{
    cout << "OVERFLOW 2:" << endl << endl;

    int number = INT_MAX - 3;

    cout << "INT_MIN = " << INT_MIN << endl;
    cout << "INT_MAX = " << INT_MAX << endl << endl;

    for (int i = 1; i <= 10; i++)
        {
            cout << number << endl;
            number++;
        }
    cout << endl;
}

void overflow3(void)
{
    cout << "OVERFLOW 3:" << endl << endl;

    int number = INT_MAX - 3;

    for (int i = 1; i <= 7; i++)
        {
            cout << number << endl;
            number++;
        }
    cout << endl;
}

void pointers_addresses(void)
{
    cout << "POINTERS:" << endl << endl;

    int i = 11, j = 22;
    double d = 3.3, e = 4.4;

    int *iPtr, *jPtr;                                   // Declare pointer variables that store addresses of ints
    double *dPtr, *ePtr;                                // store addresses of doubles

    iPtr = &i;                                          // value of iPtr is address of i
    jPtr = &j;                                          // value of jPtr is address of j
    dPtr = &d;                                          // value of dPtr is address of d
    ePtr = &e;                                          // value of ePtr is address of e

    cout << "&i: " << iPtr << endl                      // print addresses of the actual variables
         << "&j: " << jPtr << endl
         << "&d: " << dPtr << endl
         << "&e: " << ePtr << endl << endl;

    cout << "&iPtr = " << &iPtr << endl                 // prints addresses of the pointers
         << "&jPtr = " << &jPtr << endl
         << "&dPtr = " << &dPtr << endl
         << "&ePtr = " << &ePtr << endl << endl;

    cout << "value of i: " << *iPtr << endl             // prints the values of the variables
         << "value of j: " << *jPtr << endl             // "dereferences" the address of the pointer to the variable value
         << "value of d: " << *dPtr << endl
         << "value of e: " << *iPtr << endl << endl;
}