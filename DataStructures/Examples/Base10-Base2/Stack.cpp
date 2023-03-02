/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implementation file for stack member functions.
*/

#include <iostream>
#include "Stack.h"

using namespace std;

/************************************************************
Function Name: Stack()
Description: Construct a Stack object.
Precondition:  None.
Postcondition: An empty Stack object has been constructed
(myTop is initialized to -1 and myArray is an array
with STACK_CAPACITY elements of type StackElement).
************************************************************/
Stack::Stack() : myTop(-1)                          // Default Constructor
{

    //cout << "Default Constructor Called" << endl;
}

/************************************************************
Function Name: empty()
Description: Check if stack is empty.
Precondition: None
Postcondition: Returns true if stack is empty and
false otherwise.
***********************************************************-*/
bool Stack::empty() const                           // Definition of empty()
{

    return (myTop == -1);
}

/************************************************************
Function Name: push()
Description: Add a value to a stack.
Precondition: value is to be added to this stack
Postcondition: value is added at top of stack provided
there is space; otherwise, a stack-full message is
displayed and execution is terminated.
***********************************************************-*/
void Stack::push(const StackElement& value)         // Definition of push()
{

    if (myTop < STACK_CAPACITY - 1)                 // Preserve stack invariant
        {
            ++myTop;
            myArray[myTop] = value;
        }
   else
        {
            cerr << "*** Stack full -- can't add new value ***" << endl;
            cerr << "Must increase value of STACK_CAPACITY in Stack..." << endl;
            cerr << "...Exiting" << endl;
            exit(1);
        }
}

/************************************************************
Function Name: display()
Description: Display values stored in the stack.
Precondition:  ostream out is open.
Postcondition: Stack's contents, from top down, have
been output to out.
************************************************************/
void Stack::display(ostream& out) const             // Definition of display()
{
    for (int i = myTop; i >= 0; i--)
        {
            out << myArray[i] << endl;
        }
}

/************************************************************
Function Name: top() 
Description: Retrieve value at top of stack (if any).
Precondition:  Stack is nonempty
Postcondition: Value at top of stack is returned, unless
the stack is empty; in that case, an error message is
displayed and a "garbage value" is returned.
************************************************************/
StackElement Stack::top() const                     // Definition of top()
{

    if ( !empty() )
        {
            return (myArray[myTop]);
        }
    else
        {
            cerr << "*** Stack is empty ***" << endl;
            cerr << "*** Returning garbage value ***";
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
void Stack::pop()                                   // Definition of pop()
{

    if ( !empty() )
        {
            myTop--;
        }
    else
        {
            cerr << "*** Stack is empty ***" << endl;

            cerr << "*** Can't remove a value ***" << endl;
        }
}