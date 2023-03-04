/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implementation file for the single linked queue.
*/

#include "s_queue.h"

using namespace std;

QUEUE::QUEUE():front(0), back(0)
{
    // default constructor - set front and back pointers to NULL
}

QUEUE::~QUEUE()
{
	cout << "~QUEUE has been called\n";

	while (!Empty())
        {
            deQueue();                          // delete nodes until the queue is empty
        }
}

void QUEUE::enQueue(const string& item)         // QUEUE(const QUEUE &);
{
	if (Empty())
        {
            front = back = new Qnode;           // declare a new node
            front->data = item;                 // add the data to front->data
        }
	else
        {
            back->next = new Qnode;             // declare a new node "after" the back.
            back = back->next;                  // advance the back pointer
            back->data = item;                  // insert the data
        }
}

void QUEUE::deQueue()
{
	if (!Empty())
        {
            Qnode *p = front;                   // declare a new temporary pointer at the front
            front = front->next;                // move the front pointer to the next node.
            delete p;                           // delete the front node
            if (front == 0)                     // if the queue is now empty
                {
                    back = 0;                   // set the back pointer to NULL also.
                }
        }
	else
        {
            cout << "Cannot deQueue because queue is empty\n";
        }
}

string& QUEUE::Front()                          // accessor function
{
    string s;

	if (!Empty())
        {
            s = front->data;                    // assign data to local string
        }
	else
        {
            s = "";                             // keep string empty if the queue is empty
        }

    return s;                                   // return value of local string
}

void QUEUE::Print()
{
	Qnode *p = front;                           // declare a local pointer to traverse the list.

	while(p!=0)
        {
            cout << p->data << endl;            // print each node's data
            p = p->next;                        // traverse
        }
}