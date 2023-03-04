/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver program to test the Stack class.
 * It instantiates a Linked List as a stack, adds and removes nodes
 * This is an implementation fIle for a Linked List Stack
*/

#include <new>
#include "LStack.h"

using namespace std;

const int myCapacity = 128;

/**************************************************************
Function Name: stack()
Description: Constructs an empty Stack object.
Precondition: None.
Postcondition: An empty Stack object has been constructed, 
myTop initialized to 0 (null).
**************************************************************/
stack::stack()
{
    cout << "*** Default Constructor Called ***" << endl;

    this->myTop = 0;                // myTop is a pointer, so we can use 'this->' pointer since it is the current object.
    node_count = 0;                 // set node count of newly created object to zero;

}

/*************************************************************
Function Name: stack()
Description: Copy Constructor
Precondition: original is the stack to be copied and
received as a const reference parameter.
Postcondition: A copy of original has been constructed.
*************************************************************/
stack::stack(const stack& original)                                                     // Definition of Stack copy constructor
{

    cout << endl << "*** Copy Constructor Called ***" << endl;

    (*this).myTop = 0;              // current object is (*this), so we can use that notation, also
    //this->myTop = 0;              // myTop is a pointer, so we can use 'this->' pointer since it is the current object.
    //myTop = 0;                    // old school way to do it
    this->node_count = 0;           // set node count to zero for new copy object.

    if (!original.empty())
        {

            myTop = new stack::Node(original.top());                                    // Copy first node
            node_count++;                                                               // increment Node Counter

            stack::NodePointer lastPtr = myTop;                                         // Set pointers to run through the stack's linked lists
            stack::NodePointer origPtr = original.myTop->next;

            while (origPtr != 0)
                {
                    lastPtr->next = new stack::Node(origPtr->data);
                    node_count++;
                    //cout << endl << "CC: this->node_count = (" << this->node_count << ")"<< endl;
                    lastPtr = lastPtr->next;
                    origPtr = origPtr->next;
                }
        }
    cout << endl << "CC: this->node_count = (" << this->node_count << ")"<< endl;
}

/**************************************************************
Function Name: ~stack()
Description: Class destructor
Precondition: None
Postcondition: The dynamic array in the stack has been
deallocated.
**************************************************************/
stack::~stack()                                                                         // Definition of Stack destructor
{

    cout << endl << "*** Destructor Called ***" << endl;
                                                                                        // Set pointers to run through the stack
    stack::NodePointer currPtr = myTop,                                                 // node to be deallocated
                        nextPtr;                                                        // its successor

    while (currPtr != 0)
        {
            nextPtr = currPtr->next;
            delete currPtr;
            node_count--;                                                               // decrement the node counter after deletion
            //cout << endl << "this->node_count = (" << this->node_count << ")"<< endl; // debug for node count display
            currPtr = nextPtr;
        }

    cout << endl << "DS: this->node_count = (" << this->node_count << ")"<< endl;       // debug: track the # of stack nodes that exist.
}

/**************************************************************
Function Name: operator=
Description: Overloaded Assignment Operator
Precondition: original is the stack to be assigned and
received as a const reference parameter.
Postcondition: The current stack becomes a copy of
original and a reference to it is returned.
**************************************************************/
stack& stack::operator=(const stack& original)                                          // Definition of assignment operator
{

    cout << endl << "\'Operator=()\' Called" << endl;                                   // Debug

    myTop = 0;

    if (original.empty())
        {
            return *this;
        }

    if (this != &original)                                                              // check that not st = st
        {
            this->~stack();                                                             // destroy current linked list

            myTop = new stack::Node(original.top());                                    // Copy first node
            node_count++;                                                               // increment the node counter
            //cout << endl << "OP=: this->node_count = (" << this->node_count << ")"<< endl;  // debug: track the # of stack nodes that exist.

            stack::NodePointer lastPtr = myTop;                                         // Set pointers to run through the stacks' linked lists
            stack::NodePointer origPtr = original.myTop->next;

            while (origPtr != 0)
                {
                    lastPtr->next = new stack::Node(origPtr->data);
                    node_count++;                                                       // increment the node counter
                    //cout << endl << "OP=: this->node_count = (" << this->node_count << ")"<< endl;  // debug: track the # of stack nodes that exist.
                    lastPtr = lastPtr->next;
                    origPtr = origPtr->next;
                }
        }

    cout << endl << "OP=: this->node_count = (" << this->node_count << ")"<< endl;      // debug: track the # of stack nodes that exist.

    return *this;
}

/**************************************************************
Function Name: empty()
Description: Check if stack is empty.
Precondition: None
Postcondition: Returns true if stack is empty and
false otherwise.
**************************************************************/
bool stack::empty() const                                                               // Definition of empty()
{
    //cout << endl << "\'Empty()\' Called" << endl;

    return (myTop == 0);

}

/**************************************************************
Function Name: push()
Description: Adds a value to top of the stack.
Precondition:  value is to be added to this stack
Postcondition: value is added at top of stack provided
there is space; otherwise, a stack-full message is
displayed and execution is terminated.
**************************************************************/
void stack::push(const StackElement& value)                                             // Definition of push()
{
    //cout << endl << "\'Push()\' Called" << endl;
    cout << endl << "Pushing New Node onto the Stack:" << endl;

    myTop = new stack::Node(value, myTop);
    node_count++;                                                                       // increment the node counter

    cout << endl << "PUSH: this->node_count = (" << this->node_count << ")"<< endl;     // debug: track the # of stack nodes that exist.

}

/**************************************************************
Function Name: display()
Description: Display values stored in the stack.
Precondition: ostream out is open.
Postcondition: Stack's contents, from top down, have
been output to out.
**************************************************************/
void stack::display(ostream& out) const
{
    //cout << endl << "\'Display()\' Called" << endl;

    stack::NodePointer ptr;

    for (ptr = myTop; ptr != 0; ptr = ptr->next)
        {
            out << ptr->data << endl;
        }
}

/**************************************************************
Function Name: top()
Description: Retrieve value at top of stack (if any).
Precondition: Stack is nonempty
Postcondition: Value at top of stack is returned.
If the stack is empty an error message is displayed
and a garbage value is returned.
**************************************************************/
StackElement stack::top() const
{

    //cout << endl <<"\'Top()\' Called" << endl;

    if (!empty())
        {
            return (myTop->data);
        }
    else
        {
            cerr << "*** Stack is empty ***" << endl;
            cerr << "*** returning garbage ***" << endl;
            return *(new StackElement);                                                 // "Garbage" value
        }
}

/**************************************************************
Function Name: pop()
Description: Remove value at top of stack (if any).
Precondition: Stack is nonempty.
Postcondition: Value at top of stack has been removed,
unless the stack is empty; in that case, an error
message is displayed and execution allowed to proceed.
**************************************************************/
void stack::pop()                                                                       // Definition of pop()
{

    cout << endl << "\'Pop()\' called" << endl;
    cout << "Popping top value from stack..." << endl;

    if (!empty())
        {
            stack::NodePointer ptr = myTop;                                             // declare new pointer at top of stack
            myTop = myTop->next;                                                        // point the myTop pointer to the next node down
            delete ptr;                                                                 // delete the top node of the stack
            node_count--;                                                               // decrement the node counter
            cout << endl << "POP: this->node_count = (" << this->node_count << ")"<< endl;          // debug: track the # of stack nodes that exist.

        }
    else
        {
            cerr << "*** Stack empty: can't remove a value ***" << endl;
        }
}