/*******************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for LQueue member functions.
 * This header file defines a Queue data type.
 * Basic operations:
 * constructor: Constructs an empty queue
 * empty: Checks if a queue is empty
 * enqueue: Modifies a queue by adding a value at the back
 * front: Accesses the top queue value; leaves queue unchanged
 * dequeue: Modifies queue by removing the value at the front
 * display: Displays all the queue elements
*******************************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#include <iostream>

typedef int QueueElement;

class Queue
{
    public:
    
        Queue();
        Queue(const Queue& original);
        ~Queue();
        const Queue& operator= (const Queue& rightHandSide);
        bool empty() const;
        void enqueue(const QueueElement& value);
        void display(ostream& out) const;
        QueueElement front() const;
        void dequeue();

    private: /*** Nested Node class ***/

        class Node
        {
            public:

                QueueElement data;
                Node* next;

                /*******************************************************************
                Function Name: Node()
                Description: Default Constructor for Node Class Objects
                Precondition:  value and link are received
                Postcondition: A Node has been constructed with value in its
                data part and its next part set to link (default 0).
                *******************************************************************/
                Node(QueueElement value, Node* link = 0) // Node constructor
                {
                    data = value;
                    next = link; 
                }
        };

        typedef Node* NodePointer;  /***** Data Members *****/
        NodePointer myFront;        // Pointer to front of Queue
        NodePointer myBack;         // Pointer to Back of Queue

}; // end of class declaration

#endif // LQUEUE_H_INCLUDED