/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implementation file which defines a double linked queue data type.
****************************************************************************/

#include <iostream>
#include "Queue.h"

using namespace std;

/***********************************************************************
Function Name: Queue()
Description: Constructs a Queue object.
Precondition: None.
Postcondition: An empty Queue object has been constructed;
myFront and myBack are initialized to 0 (null) and myArray
is an array with QUEUE_CAPACITY elements of type QueueElement.
***********************************************************************/
Queue::Queue() : myFront(0), myBack(0) 
{}

/***********************************************************************

Function Name: empty()
Description: Check if queue is empty.
Precondition: None.
Postcondition: True is returned if the queue is empty and
false is returned otherwise.
***********************************************************************/
bool Queue::empty() const
{
    return (myFront == myBack);
}

/***********************************************************************
Function Name: enqueue()
Description: Adds a value to the back of the queue.
Precondition: value is to be added to this queue.
Postcondition: value is added at back of queue provided there is space. 
Otherwise, a queue-full message is displayed and execution is terminated.
***********************************************************************/
void Queue::enqueue(const QueueElement& value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;

    if (newBack != myFront)     // queue isn't full
        {
            myArray[newBack] = value;
            myBack = newBack;
        }
    else
        {
            cerr << "*** Queue full -- can't add new value ***" << endl
                 << "Must increase value of QUEUE_CAPACITY in Queue.h" << endl;
            exit(1);
        }
}

/***********************************************************************
Function Name: display()
Description: Output the values stored in the queue
Precondition: out is ostream to use for output
Postcondition: Queue's contents, from top down, have
been output to out.
***********************************************************************/
void Queue::display(ostream& out) const
{
    for (int i = myFront; i != myBack; i = (i + 1) % QUEUE_CAPACITY)
        {
            out << myArray[i] << "  ";
        }
    cout << endl;
}

/***********************************************************************
Retrieve value at front of queue (if any)
Precondition:  Queue is nonempty
Postcondition: Value at front of queue is returned, unless
queue is empty; in that case, an error message is
displayed and a "garbage value" is returned.
***********************************************************************/
QueueElement Queue::front() const
{
    if ( !empty() )
        {
            return (myArray[myFront]);
        }
    else
        {
            cerr << "*** Queue is empty: returning garbage value ***" << endl;
            return myArray[QUEUE_CAPACITY - 1]; // "Garbage" value
        }
}

/***********************************************************************
Function Name: dequeue()
Description: Removes value at front of queue (if any)
Precondition: Queue is nonempty
Postcondition: Value at front of queue has been removed,
unless queue is empty. If empty, an error message is displayed and
execution is terminated.
***********************************************************************/
void Queue::dequeue()
{
    if ( !empty() )
        {
            myFront = (myFront + 1) % QUEUE_CAPACITY;
        }
    else
        {
            cerr << "*** Queue is empty: can't remove a value ***" << endl;
            exit(1);
        }
}