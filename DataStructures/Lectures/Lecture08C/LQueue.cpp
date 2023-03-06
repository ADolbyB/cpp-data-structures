/*********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This file implements LQueue member functions.
*********************************************************************/
 
#include <new>
#include "LQueue.h"

using namespace std;

/*************************************************************************
Function Name: Queue()
Description: Default Constructor. Constructs an empty Queue object.
Precondition: None.
Postcondition: An empty Queue object has been constructed.
(myFront and myBack are initialized to null pointers).
*************************************************************************/
Queue::Queue() : myFront(0), myBack(0) {}

/*************************************************************************
Function Name: Queue()
Description: Copy Constructor: Makes a deep copy of a Queue object 
Precondition: original is the queue to be copied and is received 
as a const reference parameter.
Postcondition: A copy of original has been constructed.
*************************************************************************/
Queue::Queue(const Queue& original)
{
    myFront = myBack = 0;
    if (!original.empty())
        {
            myFront = myBack = new Queue::Node(original.front()); // Copy first node

            Queue::NodePointer origPtr = original.myFront->next;
            while (origPtr != 0) // Set pointer to run through original's linked list
                {
                    myBack->next = new Queue::Node(origPtr->data);
                    myBack = myBack->next;
                    origPtr = origPtr->next;
                }
        }
}
  
/*************************************************************************
Function Name: ~Queue
Description: Class destructor: Deallocates all memory from Queue object.
Precondition: None.
Postcondition: The linked list in the queue has been deallocated.
*************************************************************************/
Queue::~Queue()
{ 
    Queue::NodePointer prev = myFront, ptr; // Set pointer to run through the queue
    while (prev != 0)
        {
            ptr = prev->next;
            delete prev;
            prev = ptr;
        }
}

/*************************************************************************
Function Name: operator=
Description: Overloaded Assignment Operator.
Precondition: rightHandSide is the queue to be assigned and is 
received as a const reference parameter.
Postcondition: The current queue becomes a copy of rightHandSide 
and a reference to it is returned.
*************************************************************************/
const Queue& Queue::operator=(const Queue& rightHandSide)
{
    if (this != &rightHandSide)             // check that not q = q
        {
            this->~Queue();                 // destroy current linked list
            if (rightHandSide.empty())      // empty queue
                myFront = myBack = 0;
            else                            // copy rightHandSide's list
            {                               
                myFront = myBack = new Queue::Node(rightHandSide.front()); // Copy first node

                Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
                while (rhsPtr != 0)         // Set pointer to run through rightHandSide's linked list
                    {
                        myBack->next = new Queue::Node(rhsPtr->data);
                        myBack = myBack->next;
                        rhsPtr = rhsPtr->next;
                    }
            }
        }
    return *this;
}

/*************************************************************************
Function Name: empty()
Description: Checks if Queue object is empty.
Precondition: None.
Postcondition: Returns true if queue is empty and false otherwise.
*************************************************************************/
bool Queue::empty() const
{ 
    return (myFront == 0);
}

/*************************************************************************
Function Name: enqueue()
Description: Adds a value to the back of a Queue object.
Precondition: A value is to be added to this queue.
Postcondition: value is added at back of queue.               
*************************************************************************/
void Queue::enqueue(const QueueElement& value)
{
    Queue::NodePointer newptr = new Queue::Node(value);
    if (empty())
        myFront = myBack = newptr;
    else
        {
            myBack->next = newptr;
            myBack = newptr;
        }
}

/*************************************************************************
Function Name: display()
Description: Display values stored in the queue.
Precondition: ostream out is open.
Postcondition: Queue's contents, from front to back, have been 
output to out.
*************************************************************************/
void Queue::display(ostream& out) const
{
    Queue::NodePointer ptr;
    for (ptr = myFront; ptr != 0; ptr = ptr->next)
        out << ptr->data << "  ";
        
    out << endl;
}

/*************************************************************************
Function Name: front()
Description: Retrieve value at front of queue (if any).
Precondition: Queue is nonempty.
Postcondition: Value at front of queue is returned, unless the queue 
is empty; in that case, an error message is displayed and a 
"garbage value" is returned.
*************************************************************************/
QueueElement Queue::front() const
{
    if (!empty())
        return (myFront->data);
    else
        {
            cerr << "*** Queue is empty: returning garbage value ***" << endl;
            QueueElement *temp = new(QueueElement);  
            QueueElement garbage = *temp; // "Garbage" value
            delete temp;
            return garbage;
        }
}

/*************************************************************************
Function Name: dequeue()
Description: Removes a value at the front of a Queue object.
Precondition: Queue is nonempty.
Postcondition: Value at front of queue has been removed, unless
queue is empty; in that case, an error message is displayed 
and execution allowed to proceed.
*************************************************************************/
void Queue::dequeue()
{
    if (!empty())
        {
            Queue::NodePointer ptr = myFront;
            myFront = myFront->next;
            delete ptr;
            if (myFront == 0) // queue is now empty
                myBack = 0;
        }   
    else
    cerr << "*** Queue is empty: can't remove a value ***" << endl;
}