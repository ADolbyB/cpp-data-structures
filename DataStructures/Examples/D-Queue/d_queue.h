/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines a double linked queue data type.
 * Basic operations:
 * constructor: Constructs an empty queue
 * empty: Checks if queue is empty
 * enQueue: Adds node to the back of queue.
 * deQueue: Deletes the front node.
 * Front: Returns the front node.
 * Print: prints the list of nodes.
****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#ifndef DQUEUE_H
#define DQUEUE_H

class DQUEUE
{
    public:

        class Qnode
        {
            public:

                string data;                            // data stored in the node
                Qnode *next, *prev;                     // pointers point to next and the previous nodes.
                Qnode() { next = prev = 0;};            // default constructor for each Qnode (optional)
        };

        DQUEUE();                                       // default constructor
        ~DQUEUE();                                      // destructor
        DQUEUE(const DQUEUE & );                        // copy constructor
        void enQueue(const string & );                  // Add a node to the BACK
        void deQueue();                                 // delete a node from the FRONT
        bool Empty() {return front == 0;}               // check if the queue is empty
        string& Front();                                // returns the front node data item as a string
        void Print();                                   // iterates the queue and prints the list of nodes.

    private:

        Qnode *front;                                   // points to the front of the queue
        Qnode *back;                                    // points to the back of the queue
};

#endif