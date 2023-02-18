/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 03/10/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 6: Queue ADT
Description: This is a doubly-linked, circular queue that uses only a pointer to the front.
*********************************************************************************************/

#include <iostream>
#include "bqueue.h"

using namespace std;

/*************************************************************************************
Function Name: bqueue()
Precondition: An object has been declared with no arguments.
Postcondition: An object is created and initialized to 0 values, since it doesn't
contain any data yet.
Description: Default Constructor: The default constructor initializes state variables
to default values.
*************************************************************************************/
bqueue::bqueue() : front(0)                                         // sets front to NULL;
{
    cout << "* Default Constructor Called *" << endl;

}

/*************************************************************************************
Function Name: ~bqueue();
Precondition: An object has already been declared and initialized.
Postcondition: An object and its related data are deleted by calling dequeue() and freeing
dynamic memory.
Description: Destructor: The destructor de-allocates all memory allocated for each object node.
*************************************************************************************/
bqueue::~bqueue()
{
	cout << "* Destructor Called *" << endl;

	while (!empty())
        {
            dequeue();                                              // delete nodes until the list is empty
        }
}

/*************************************************************************************
Function Name: bqueue(const bqueue& original);
Precondition: An object is declared equivalent to the values of another object in the same line.
Postcondition: An object is created and a deep sopy of the queue is created.
Description: Copy Constructor: The copy constructor is called when an object is declared
and assigned to the value of another object at the same time.
> bqueue j = k; invokes the copy constructor, since assignment and declaration happen
in the same line.
*************************************************************************************/
bqueue::bqueue(const bqueue& original)
{
    cout << endl << "* Copy Constructor Called *" << endl;

    front = 0;                                                      // set copy object initial front value to NULL;
    bqnode *p = original.front;                                     // declare pointer to original object front value;

    if(original.front != 0)
        {
            do
            {
                //cout << "CC: INSIDE IF-DO" << endl;               // debug
                enqueue(p->priority);                               // enqueue the data to a new node
                p = p->next;                                        // traverse the queue
                //cout << "CC: POINTER MOVED" << endl;              // debug

            } while(p != original.front);
        }
    cout << endl;
}

/*************************************************************************************
Function Name: enqueue();
Precondition: An object has already been declared.
Postcondition: The variable in the argument of this function is allocated a new node by the
calling object in the queue at the back of the queue.
Description: Mutator Function: This function creates a new node in the queue.
*************************************************************************************/
void bqueue::enqueue(int the_data)                                  // adds a new node to the BACK
{
    cout << "EnQueueing (" << the_data << ")" << endl;

	if (empty())
        {
            //cout << "enqueue: empty" << endl;                     // debug
            front = new bqnode;                                     // declare a new node, set front to point to the same new node.
            front->priority = the_data;                             // add the data to the new node
            front->next = front->prev = front;                      // circular 1 node queue: need to set "next" and "prev" fields to FRONT
        }
	else // if not empty
        {
            //cout << "enqueue: NOT empty" << endl;                 // debug
            front->prev->next = new bqnode;                         // declare a new node after "back->next," the current back node.
            front->prev->next->next = front;                        // ties the "back->next" to the 2nd last node.
            front->prev->next->prev = front->prev;                  // makes the front->prev equal to the back.
            front->prev = front->prev->next;                        // ties the back node to the front properly;
            front->prev->priority = the_data;                       // place data into the new node.
        }
    //cout << "End of EnQueue" << endl;                             // debug
}

/*************************************************************************************
Function Name: dequeue();
Precondition: An object has already been declared and initialized.
Postcondition: The front queue node is deleted.
Description: Mutator Function: This function deletes the frontmost node of the stack.
The pointer to the front of the queue is moved to the next node, and the front node is then deleted.
The *next and *prev pointers are patched appropriately to point at the new front node.
If there are no nodes in the stack, then the function displays a message and returns.
*************************************************************************************/
void bqueue::dequeue()                                              // deletes a node from the FRONT
{
    cout << "DeQueue() Called" << endl;

	if (empty())
        {
            cout << "Empty Queue...Cannot DeQueue..." << endl << endl;
        }
    else // if list not empty
        {
            //cout << "Non-Empty Queue" << endl;                    // debug

            bqnode *p = front;                                      // declare local pointer to list

            if(front == front->next)                                // if there is only one node in the list
                {
                    //cout << "Queue has 1 node" << endl;           // debug
                    delete p;                                       // delete the one node
                    front = 0;                                      // set front to NULL after deleting node
                }
            else
                {
                    //cout << "Queue has > 1 node" << endl;         // debug
                    front->prev->next = front->next;                // move pointer to next node
                    front->next->prev = front->prev;                // move pointer to prev node
                    front = front->next;                            // move front pointer
                    delete p;                                       // delete unwanted node.
                }
        }
}

/*************************************************************************************
Function Name: print();
Precondition: The calling object must have already been declared and initialized.
Postcondition: The values of the queue data are printed to the screen from front to back.
Description: Accessor Function: If there are no nodes in the queue, then the function
prints a message and returns. If there are nodes in the queue, then they are printed by
traversing the queue front to back.
*************************************************************************************/
void bqueue::print()                                                // iterates the list and prints front to back
{
    cout << endl << "Print Queue Nodes: ";

	if(empty())
        {
            cout << "Nothing to print...Queue empty..." << endl;
        }
    else // if list not empty
        {
            //cout << "INSIDE ELSE" << endl;
            bqnode *p = front;                                      // declare a pointer to point to the front

            do
            {
                cout << "[" << p->priority << "]   ";               // print front value first
                p = p->next;                                        // move to next node

            } while(p != front);
        }
    cout << endl;
}

/*************************************************************************************
Function Name: print_back();
Precondition: This function must be uncommented. The calling object must have already
been declared and initialized.
Postcondition: The values of the queue data are printed to the screen from back to front.
Description: Accessor Function: If there are no nodes in the queue, then the function
prints a message and returns. If there are nodes in the queue, then they are printed by
traversing the queue back to front. The purpose of this function is to primarily check
the integrity of all the *prev pointers in the queue. If all the *prev pointers are connected as
they should be, then the list will print. If all the *prev pointer are not correct, then
there will be a problem.
*************************************************************************************/
//void bqueue::print_back()                                           // DEBUG: prints the queue from back to front
//{
//    cout << "Print from Back: ";
//
//    bqnode *p = front;                                              // declare a pointer to point to the front
//
//	if(empty())
//        {
//            cout << "Nothing to print...Queue empty..." << endl;
//        }
//    else // if not empty
//        {
//            //cout << "Inside Else:" << endl;                       // debug
//            p = p->prev;                                            // move pointer to the back
//            cout << "[" << p->priority << "]   ";                   // print front value first
//
//            while(p != front)
//                {
//                    p = p->prev;                                    // advance to the previous node
//                    cout << "[" << p->priority << "]   ";           // print front value first
//                }
//        }
//    cout << endl << endl;
//}