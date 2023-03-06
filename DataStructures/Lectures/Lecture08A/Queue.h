/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines a double linked queue data type.
 * Basic operations:
 * Constructor: Constructs an empty queue
 * empty: Checks if a queue is empty
 * enqueue: Modifies a queue by adding a value at the back
 * front: Accesses the front queue value; leaves queue unchanged
 * dequeue: Modifies a queue by removing the value at the front
 * display: Displays the queue elements from front to back
 * Class Invariant:
 * 1.  The queue elements (if any) are stored in consecutive
 *     positions in myArray, beginning at position myFront.
 * 2.  0 <= myFront, myBack < QUEUE_CAPACITY
 * 3. Queue's size < QUEUE_CAPACITY
****************************************************************************/

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include "AdditionProblem.h"

const int QUEUE_CAPACITY = 128;
typedef AdditionProblem QueueElement;

class Queue
{
    public:

        Queue();                                    // Constructor
        bool empty() const;                         // Checks if Queue is empty
        void enqueue(const QueueElement& value);    // Add to the back of the queue
        void display(ostream& out) const;           // Disply Contents of Queue
        QueueElement front() const;                 
        void dequeue();

    private:        /***** Data Members *****/

        QueueElement myArray[QUEUE_CAPACITY];
        int myFront;
        int myBack;

}; // end of class declaration

#endif // QUEUE_H_INCLUDED