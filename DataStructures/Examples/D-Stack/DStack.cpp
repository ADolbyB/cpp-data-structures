/**
 * Joel Brigida
 * COP3530: Data Structures
 * This file implements Stack member functions.
*/

#include <iostream>
#include <cassert>
#include <new>
using namespace std;

#include "DStack.h"

/*************************************************************
Function Name: Stack()
Description: Construct a Stack object.
Precondition:  None.
Postcondition: An empty Stack object has been constructed
(myTop is initialized to -1 and myArray is an array
with numElements (default 128) elements of type
StackElement).
*************************************************************/
Stack::Stack(int numElements)                                       // Definition of Stack constructor
{

    assert (numElements > 0);                                       // check precondition
    myCapacity = numElements;                                       // set stack capacity

    myArray = new(nothrow) StackElement[myCapacity];                // allocate array of this capacity

    if (myArray != 0)                                               // memory available
        {
            myTop = -1;
        }

    else    // or assert(myArray != 0);
        {
            cerr << "Inadequate memory to allocate stack " << endl;
            cerr << "*** terminating execution ***" << endl;
            exit(1);
        }
}

/*************************************************************
Function Name: Stack()
Description: Copy Constructor
Precondition:  original is the stack to be copied and
is received as a const reference parameter.
Postcondition: A copy of original has been constructed.
*************************************************************/
Stack::Stack(const Stack& original) //: myCapacity(original.myCapacity), myTop(original.myTop) /// Alternative
{
    cout << "Stack Copy Constructor called" << endl;

    myCapacity = original.myCapacity;
    myTop = original.myTop;

    myArray = new(nothrow) StackElement[myCapacity];                // Get new array for copy, allocate array in copy

    if (myArray != 0)                                               // check if memory available
        {
            for (int pos = 0; pos < myCapacity; pos++)
                {
                    myArray[pos] = original.myArray[pos];           // copy original's array member into this new array
                }
        }
    else
        {
            cerr << "*Inadequate memory to allocate stack ***\n";
            exit(1);
        }
}

/*************************************************************
Function Name: ~Stack()
Description: Class destructor
Precondition:  None
Postcondition: The dynamic array in the stack has been
deallocated.
**************************************************************/
Stack::~Stack()                                                     // Definition of Stack Destructor
{
    cout << "Stack Destructor Called" << endl;
    delete [] myArray;
}

/**************************************************************
Function Name: operator=
Description: Assignment Operator
Precondition:  original is the stack to be assigned and
is received as a const reference parameter.
Postcondition: The current stack becomes a copy of
original and a reference to it is returned.
**************************************************************/
Stack& Stack::operator=(const Stack& original)                                      // Definition of overloaded assignment operator
{
    if (this != &original)                                                          // check that not st = st
        {
            if (myCapacity != original.myCapacity)                                  // Allocate a new array if necessary
                {
                    delete[] myArray;                                               // destroy previous array
                    myCapacity = original.myCapacity;                               // copy myCapacity
                    myArray = new StackElement[myCapacity];

                    if (myArray == 0)                                               // check if memory available
                        {
                            cerr << "*** Inadequate memory ***" << endl;
                            exit(1);
                        }
                }

            for (int pos = 0; pos < myCapacity; pos++)
                {
                    myArray[pos] = original.myArray[pos];                           // Copy original's array into this myArray
                }

            myTop = original.myTop;                                                 // copy myTop member
        }

    return *this;
}

/***************************************************************
Function Name: empty()
Description: Check if stack is empty.
Precondition: None
Postcondition: Returns true if stack is empty and
false otherwise.
**************************************************************/
bool Stack::empty() const                                                           // Definition of empty()
{
    return (myTop == -1);

}

/***************************************************************
Function Name: push()
Description: Add a value to a stack.
Precondition:  value is to be added to this stack
Postcondition: value is added at top of stack provided
there is space; otherwise, a stack-full message is
displayed and execution is terminated.
**************************************************************/
void Stack::push(const StackElement& value)                                         // Definition of push()
{
    if (myTop < myCapacity - 1)                                                     // Preserve stack invariant
        {
            ++myTop;
            myArray[myTop] = value;
        }
    else
        {
            cerr << "*** Stack full -- can't add new value ***" << endl;
            cerr << "Must increase value of STACK_CAPACITY in Stack.h" << endl;
            exit(1);
        }
}

/*************************************************************
Function Name: display()
Description: Display values stored in the stack.
Precondition:  ostream out is open.
Postcondition: Stack's contents, from top down, have
been output to out.
**************************************************************/
void Stack::display(ostream &out) const
{

    cout << "Call to DISPLAY" << endl;

    for (int i = myTop; i >= 0; i--)
        {
            out << myArray[i] << endl;
        }
}

/*************************************************************
Function Name: top()
Description: Retrieve value at top of stack (if any).
Precondition:  Stack is nonempty
Postcondition: Value at top of stack is returned, unless
the stack is empty; in that case, an error message is
displayed and a "garbage value" is returned.
************************************************************/
StackElement Stack::top() const                                                     // Definition of top()
{
    cout << "--Call to top()--" << endl;

    if ( !empty() )
        {
            return (myArray[myTop]);
        }
    else
        {
            cerr << "*** Stack is empty ***" << endl;
            cerr << "*** returning new StackElement ***" << endl;
            return *(new StackElement);
        }
}

/***********************************************************
Function Name: pop() 
Description: Remove value at top of stack (if any).
Precondition:  Stack is nonempty.
Postcondition: Value at top of stack has been removed,
unless the stack is empty; in that case, an error
message is displayed and execution allowed to proceed.
************************************************************/
void Stack::pop()                                                                   // Definition of pop()
{
    cout << "Call to pop()" << endl;

    if ( !empty() )
        {
            myTop--;
        }
    else
        {
            cerr << "*** Stack is empty ***" << endl;
            cerr << "*** can't remove a value ***" << endl;
        }
}