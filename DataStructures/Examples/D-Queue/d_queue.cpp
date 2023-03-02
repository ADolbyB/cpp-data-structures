/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for a double linked queue.
*/

#include "d_queue.h"

using namespace std;

DQUEUE::DQUEUE():front(0), back(0)
{
    // default constructor: sets front and back equal to NULL
    cout << "Default Constructor Called" << endl;
}

DQUEUE::~DQUEUE()
{
	cout << "~QUEUE has been called\n";

	while (!Empty())
        {
            deQueue();                          // delete nodes until the list is empty
        }
}

void DQUEUE::enQueue(const string& item)        // adds a new node to the BACK
{
    cout << "EnQueue Called" << endl;

	if (Empty())
        {
            front = back = new Qnode;           // declare a new node, set front and back to point to the same new node.
            front->data = item;                 // add the data to the new node
            front->prev = front->next = 0;      // since it's a 1 node queue, need to set "next" and "prev" fields to NULL
        }
	else    // if not empty
        {
            back->next = new Qnode;             // declare a new node after the current back node. (default constructor makes *back & *front of new node = NULL already
            back->next->prev = back;            // point the "previous" of the NEW node to the current back node.
            back = back->next;                  // move the back pointer to the new node, which is now in the back
            back->data = item;                  // drop the data into the new node.
            back->next = 0;                     // set the "next" field of the back node to NULL
        }
}

void DQUEUE::deQueue()                          // deletes a node from the FRONT
{
    cout << "DeQueue Called" << endl;

	if (!Empty())
        {
            Qnode *p = front;                   // declare pointer to point to the front node.
            front = front->next;                // move the front pointer to the next one down the queue
            if (front != 0)
                {
                    front->prev = 0;            // if front is not NULL after moving pointer, then there are still nodes in the queue,
                }                               // so set the new front->prev to NULL.
            else
                {
                    back = 0;                   // if front is NULL after moving pointer, then there are no nodes left in the queue,
                }                               // so set the back pointer to NULL also (as a precaution)
            delete p;                           // delete unwanted node.
        }
	else
        {
            cout << "Cannot deQueue because queue is empty\n";
        }
}

string& DQUEUE::Front()
{
    cout << "Front Called" << endl;

	string s = "";

	if (!Empty())
        {
            return front->data;                 // returns the data in the node if the queue is not empty
        }
	else
        {
            cout << "Queue Empty: Nothing to Print" << endl;
            return s;                           // returns empty string if the queue is empty
        }
}

void DQUEUE::Print()
{
    cout << "Print Called" << endl;

	Qnode *p = front;                           // declare a pointer to point to the front
	//Qnode *p = back;                            // can print from back to front if you need to

	while(p != 0)
        {
            cout << p->data << endl;            // print the data in each node
            p = p->next;                        // traverse to the next node
            //p = p->prev;                        // if you wanted to print from back to front
        }
}