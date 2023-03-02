/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is a pointers tutorial for C++
 * Here I try to demonstrate different properties of pointers.
*/

#include <iostream>

void pointers1(void);
void pointers2(void);

using namespace std;

int main()
{

    //pointers1();
    pointers2();

    return 0;
}

void pointers1(void)
{

    int *p1, *p2, v1, v2;                       // declares 2 integer pointers and 2 normal int variables.

    v1 = 0;
    v2 = v1;
    p1 = &v1;                                   // assigns the address of variable v1 to the pointer p1
    *p1 = 42;
    p2 = p1;                                    // assigns the address location of the pointer p1 to p2 so they both point to the same location;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "*p1 = " << *p1 << endl;            // prints the value stored in memory pointed to by pointer p1
    cout << "*p2 = " << *p2 << endl;            // prints the value stored in memory pointed to by pointer p2

    cout << endl << "&v1 = " << &v1 << endl;    // prints the address of the variable v1
    cout << "p1 = " << p1 << endl;              // prints the address pointed to by pointer p1 (same as the above)
    cout << "&p1 = " << &p1 << endl;            // prints the address of the pointer p1

    p2 = &v2;                                   // assigns the address of variable v2 to the pointer p2
    *p2 = 89;                                   // assigns the value 89 to the variable pointed to by p2

    cout << endl << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    *p1 = *p2;                                  // assigns the value pointed to by p2 into the variable referenced by p1

    cout << endl << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

}

void pointers2(void)
{

    int *p1, *p2;                               // the * is referred to as the "dereferencing operator"

    p1 = new int;                               // creates an unnamed dynamic variable of type int denoted by pointer p1
    *p1 = 42;                                   // "Assign the value 42 to the variable pointed to by p1"

    p2 = p1;

    cout << "*p1 = " << *p1 << endl;            // value of the variable stored where pointer points to
    cout << "*p2 = " << *p2 << endl;
    cout << "&p1 = " << &p1 << endl;            // memory location of the pointer p1
    cout << "p1 = " << p1 << endl;              // memory location of the variable pointed to by p1

    *p2 = 53;

    cout << endl << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    p1 = new int;
    *p1 = 88;

    cout << endl << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    int *p;
    p = new int;                                // dynamic variables are created and destroyed while the program is running.
    *p = 777;                                   // dynamic variables are stored in "freestore" aka "heap" memory

    cout << endl << "*p = " << *p << endl;
    cout << "p = " << p << endl;

    delete p;                                   // eliminates the dynamic variable created in line 46. Unfortunately this creates a "dangling pointer"

    cout << endl << "*p = " << *p << endl;      // supposed to be an undefined address and can result in unpredictable behavior
    cout << "p = " << p << endl;                // value is supposed to be now undefined, since the pointer is "dangling"

    typedef int *IntPtr;                        // deefines a type "IntPtr" that is a type for pointer variables that are pointers to int variables
    IntPtr p3;                                  // same as declaring "int *p3"
    p3 = new int;                               // dynamic variable allocation for pointer p3
    *p3 = 999;                                  // sets value of the dynamic variable to 999

    cout << endl << "*p3 = " << *p3 << endl << endl;

    int *p4 = NULL;                             // sets pointer to a NULL value - p3 is now "dangling"
    int *p5 = 0;                                // another way to set a pointer to NULL value (also dangling)

    cout << "p4 == NULL is: " << boolalpha << (p4 == 0) << endl;    // boolalpha flag is set until its unset with "noboolalpha"
    cout << "p5 == 0 is: " << (p5 == 0) << endl << endl;

    //cout << "*p3 = " << *p3 << endl;            // dereferencing a NULL pointer results in a segmentation fault since the memory location is NULL.

    int var1 = 25, var2 = 55, var3, var4;
    int *ptr4, *ptr5, *ptr6, *ptr7;

    ptr4 = &var1;                               // sets pointer to the address location of the variable.
    ptr5 = &var2;
    ptr6 = &var3;
    ptr7 = &var4;

    *ptr6 = 111;                                // assigns value 111 to var3 via the pointer dereferncing
    *ptr7 = 222;                                // assigns value 222 to var4 via the pointer dereferncing

    cout << "The value stored at var1 = " << *ptr4 << endl
         << "The value stored at var2 = " << *ptr5 << endl
         << "The value stored at var3 = " << *ptr6 << endl
         << "The value stored at var4 = " << *ptr7 << endl << endl;

    int array1[100][100][100];

    cout << "sizeof(int array1[]) = " << sizeof(array1[10]) << endl;

}