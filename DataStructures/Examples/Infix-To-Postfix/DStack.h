/*******************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * 
 * This header file defines a Stack data type.
 * Basic operations:
 * constructor: Constructs an empty stack
 * empty: Checks if a stack is empty
 * push: Modifies a stack by adding a value at the top
 * top: Accesses the top stack value; leaves stack unchanged
 * pop: Modifies stack by removing the value at the top
 * display: Displays all the stack elements
 * 
 * Class Invariant:
 * 1. The stack elements (if any) are stored in positions
 *    0, 1, . . ., myTop of myArray.
 * 2. -1 <= myTop < myCapacity

******************************************************************/

#ifndef DSTACK_H_INCLUDED
#define DSTACK_H_INCLUDED

#include <iostream>

using namespace std;

typedef int StackElement;

class Stack
{
    public:                             /***** Function Members *****/

        Stack(int numElements = 128);   /***** Constructors *****/
        Stack(const Stack& original);
        ~Stack();                       /***** Destructor *****/
        Stack& operator= (const Stack& original);
        bool empty() const;
        void push(const StackElement& value);
        void display(ostream& out) const;
        StackElement top() const;
        void pop();

    private:                            /***** Data Members *****/

        int myCapacity;                 // capacity of stack
        int myTop;                      // top of stack
        StackElement *myArray;          // pointer to dynamic array to store elements

};

#endif // DSTACK_H_INCLUDED