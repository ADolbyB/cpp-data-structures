/******************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines a template for a Stack data type.
 * StackElement is a type parameter received from a client program.
 * Basic operations:
 * constructor: Constructs an empty stack
 * copy constructor: Makes a copy of a stack
 * destructor: Deallocates memory allocated by constructor
 * = : Assignment operator
 * empty: Checks if a stack is empty
 * push: Modifies a stack by adding a value at the top
 * top: Accesses the top stack value; leaves stack unchanged
 * pop: Modifies stack by removing the value at the top
 * << and display: Display all the stack elements
 * Class Invariant:
 * 1. The stack elements (if any) are stored in positions
 *    0, 1, . . ., myTop of myArray.
 * 2. -1 <= myTop < myCapacity
******************************************************************************/

#ifndef DSTACKT
#define DSTACKT

#include <iostream>
#include <cassert>
#include <new>

using namespace std;

template <typename StackElement>
class Stack
{
    public:

        Stack(int numElements = 128);
        Stack(const Stack<StackElement>& original);
        ~Stack();
        const Stack<StackElement>& operator=(const Stack<StackElement>& original);
        bool empty() const;
        void push(const StackElement& value);
        void display(ostream& out) const;
        StackElement top() const;
        void pop();

    private:

        int myCapacity;                 // capacity of stack
        int myTop;                      // top of stack
        StackElement *myArray;          // dynamic array to store elements

};

/*******************************************************************************
Function Name: Stack()
Description: Default Constructor. Constructs a Stack object.
Precondition: None.
Postcondition: An empty Stack object has been constructed (myTop is
initialized to -1 and myArray is an array with numElements
(default 128) elements of type StackElement).
******************************************************************************/
template <typename StackElement>
Stack<StackElement>::Stack(int numElements)
{
    assert (numElements > 0);       // check if stack empty
    myCapacity = numElements;       // set stack capacity

    // allocate array of this capacity
    myArray = new(nothrow) StackElement[myCapacity];
    if (myArray != 0)               // memory is available
        {
            myTop = -1;
        }
    else
        {
            cerr << "Inadequate memory to allocate stack: terminating program" << endl;
            exit(1);
        }                           // or assert(myArray != 0);
}

/*******************************************************************************
Function Name: Stack()
Description: Copy Constructor
Precondition: original is the stack to be copied and is received as
a const reference parameter.
Postcondition: A copy of original has been constructed.
******************************************************************************/
template <typename StackElement>
Stack<StackElement>::Stack(const Stack<StackElement>& original) : myCapacity(original.myCapacity), myTop(original.myTop)
{
    myArray = new(nothrow) StackElement[myCapacity];    // New default array to copy items into
    if (myArray != 0)                                   // check if array is empty
        {
            for (int pos = 0; pos <= myTop; pos++)      // copy original array's data into this new array
                {
                    myArray[pos] = original.myArray[pos];
                }
        }
    else
        {
            cerr << "*** Array to be Copied Is Empty ***" << endl;
            exit(1);
        }
}

/*******************************************************************************
Function Name: ~Stack()
Description: Class destructor
Precondition: None
Postcondition: The dynamic array in the stack has been deallocated.
******************************************************************************/
template <typename StackElement>
inline Stack<StackElement>::~Stack()
{
   delete[] myArray;
}
        
/*******************************************************************************
Function Name: operator=
Description: Overloaded Assignment Operator
Precondition: original is the stack to be assigned and is received as
a const reference parameter.
Postcondition: The current stack becomes a copy of original and a
const reference to it is returned.
******************************************************************************/
template <typename StackElement>
const Stack<StackElement>& Stack<StackElement>::operator=(const Stack<StackElement>& rightHandSide)
{
    if (this != &rightHandSide)                                 // check that not st = st
        {
            if (myCapacity != rightHandSide.myCapacity)         // Allocate a new array if necessary
                {
                    delete[] myArray;                           // destroy previous array

                    myCapacity = rightHandSide.myCapacity;
                    myArray = new StackElement[myCapacity];

                    if (myArray == 0)                           // check if empty array
                        {
                            cerr << "*** Array is Empty: Exiting ***" << endl;
                            exit(1);
                        }
                }

            myTop = rightHandSide.myTop;                        // copy myTop member
            for (int pos = 0; pos <= myTop; pos++)              // copy stack elements
                {
                    myArray[pos] = rightHandSide.myArray[pos];
                }
        }
    return *this;
}

/*******************************************************************************-
Function Name: empty()
Description: Checks if stack is empty.
Precondition: None
Postcondition: Returns true if stack is empty and false otherwise.
******************************************************************************/
template <typename StackElement>
inline bool Stack<StackElement>::empty() const
{
    return (myTop == -1);
}

/*******************************************************************************-
Function Name: push()
Description: Add a value to a stack.
Precondition: value is to be added to this stack
Postcondition: value is added at top of stack provided there is space;
otherwise, a stack-full message is displayed and execution is terminated.
******************************************************************************/
template <typename StackElement>
inline void Stack<StackElement>::push(const StackElement& value)
{
    if (myTop < myCapacity - 1)
        {
            ++myTop;
            myArray[myTop] = value;
        }
    else
        {
            cerr << "*** Stack full: can't add new value must increase Stack capacity" << endl;
            exit(1);
        }
}

/*******************************************************************************-
Function Name: display()
Description: Displays values stored in the stack.
Precondition: ostream out is open.
Postcondition: Stack's contents, from top down, have been output to out.
******************************************************************************/
template <typename StackElement>
inline void Stack<StackElement>::display(ostream& out) const
{
    for (int i = myTop; i >= 0; i--)
        {
            out << myArray[i] << endl;
        }
}

/*******************************************************************************-
Function Name: operator<<
Description: Overloaded << operator.
Display values stored in the stack.
Precondition: ostream out is open.
Postcondition: Stack's contents, from top down, have been output to out.
******************************************************************************/
template <typename StackElement>
inline ostream& operator<<(ostream& out, const Stack<StackElement>& st)
{
    st.display(out);
    return out;
}

/*******************************************************************************-
Function Name: top()
Description: Retrieves value at top of stack (if any).
Precondition: Stack is nonempty
Postcondition: Value at top of stack is returned, unless stack is empty,
in that case, an error message is displayed and a "garbage value" is returned.
******************************************************************************/
template <typename StackElement>
inline StackElement Stack<StackElement>::top() const
{
    if (!empty())
        {
            return (myArray[myTop]);
        }
    else
        {
            cerr << "*** Stack Empty: returning garbage value ***" << endl;
            return (myArray[myCapacity - 1]);
        }
}

/*******************************************************************************-
Function Name: pop()
Description: Remove value at top of stack (if any).
Precondition: Stack is nonempty.
Postcondition: Value at top of stack has been removed, unless the stack is empty,
in that case, an error message is displayed and execution allowed to proceed.
******************************************************************************/
template <typename StackElement>
inline void Stack<StackElement>::pop()
{
    if (myTop >= 0)
        {
            myTop--;
        }
    else
        {
            cerr << "*** Stack empty: can't remove a value ***" << endl;
        }
}

#endif