/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 03/10/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 6: Queue ADT
Description: Description: This is a doubly-linked, circular queue that uses only a pointer to the front.
*********************************************************************************************/

#ifndef BQUEUE_H_INCLUDED
#define BQUEUE_H_INCLUDED

class bqnode
{
    public:

        int priority;                       // data in the queue are integers in this case
        bqnode *prev, *next;

};

class bqueue
{
    public:

        bqueue();                           // default constructor
        ~bqueue();                          // destructor
        bqueue(const bqueue& );             // copy constructor
        void enqueue(int );                 // adds node to the BACK of the queue
        void dequeue();                     // removes node at the FRONT of the queue
        void print();                       // prints the queue from front to back
        //void print_back();                // DEBUG USE: prints the queue from back to front
        bool empty() {return front == 0;}   // check if the queue is empty: inline implementation

    private:

        bqnode *front;                      //use ONLY one pointer

};

#endif // BQUEUE_H_INCLUDED