/****************************************************************************
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
****************************************************************************/

#include <iostream>
#include "Call.h"

#ifndef LQUEUE
#define LQUEUE

typedef Call QueueElement;

class Queue
{
    public:

        Queue();
        Queue(const Queue& original);
        ~Queue(); 
        const Queue& operator=(const Queue& rightHandSide);
        bool empty() const;
        void enqueue(const QueueElement& value);
        void display(ostream& out) const;
        QueueElement front() const;
        void dequeue();

    private:

        class Node // Nested Private Node Class
        {
            public:

                QueueElement data;
                Node *next;
                
                /*******************************************************************
                Function Name: Node()
                Description: Nested Node Class Default Constructor.
                Precondition: value and link are received
                Postcondition: A Node has been constructed with value in its 
                data part and its next part set to link (default 0).
                ********************************************************************/
                Node(QueueElement value, Node *link = 0)
                {
                    data = value;
                    next = link; 
                }
        };

        typedef Node* NodePointer;
        NodePointer myFront;      // pointer to front of queue
        NodePointer myBack;       // pointer to back of queue
};

#endif