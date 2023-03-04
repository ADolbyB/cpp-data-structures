/****************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file to test a single linked queue.
 * This header file defines a Stack data type.
 * Basic operations:
 * constructor:  Constructs an empty stack
 * empty: Checks if a stack is empty
 * push: Modifies a stack by adding a value at the top
 * top: Retrieves the top stack value; leaves stack unchanged
 * pop: Modifies stack by removing the value at the top
 * display: Displays all the stack elements
 * 1. The stack elements (if any) are stored in positions
 *    0, 1, . . ., myTop of myArray.
 * 2. -1 <= myTop < STACK_CAPACITY
*****************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>

const int STACK_CAPACITY = 128;
typedef int StackElement;

class Stack
{
    public:                 /***** Function Members *****/

        Stack();            /***** Constructor *****/
        bool empty() const;
        void push(const StackElement & value);
        void display(ostream & out) const;
        StackElement top() const;
        void pop();

    private:                /***** Data Members *****/

        StackElement myArray[STACK_CAPACITY];
        int myTop;

}; // end of class declaration

#endif // STACK_H_INCLUDED