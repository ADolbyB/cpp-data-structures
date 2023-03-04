/*******************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver program to test the Stack class.
 * It instantiates a Linked List as a stack, adds and removes nodes
 * This is an implementation fIle for a Linked List Stack
 * This header file defines a Stack data type.
 * Basic operations:
 * constructor: Constructs an empty stack
 * empty: Checks if a stack is empty
 * push: Modifies a stack by adding a value at the top
 * top: Accesses the top stack value; leaves stack unchanged
 * pop: Modifies stack by removing the value at the top
 * display: Displays all the stack elements
 * Stack elements (if any) are stored in positions
 *    0, 1, ..., myTop of myArray.
 * -1 <= myTop < myCapacity
*******************************************************************/
#ifndef LSTACK_H_INCLUDED
#define LSTACK_H_INCLUDED

#include <iostream>

typedef int StackElement;

class stack
{
    public: /***** Function Members *****/

        stack();                                             /***** Constructors *****/
        stack(const stack& original);
        ~stack();                                            /***** Destructor *****/
        stack& operator= (const stack& original);            /***** Assignment *****/
        bool empty() const;
        void push(const StackElement& value);
        void display(ostream& out) const;
        StackElement top() const;
        void pop();


    private:

        class Node /*** Nested Node class ***/
        {
            public:

                StackElement data;
                Node *next;
                Node(StackElement value, Node *link = 0)    // Node constructor
                /*******************************************************
                Function Name: Node()
                Description: Constructor
                Precondition: value is received
                Postcondition: A Node is constructed with value in its 
                data part and it next part points to link
                (default 0 (null)).
                *******************************************************/
                { data = value; next = link; }              // Inline Implementation

        };

        typedef Node *NodePointer;                          /***** Data Members *****/
        NodePointer myTop;                                  // pointer to top of stack
        int node_count;

};  // end of class declaration

#endif // LSTACK_H_INCLUDED