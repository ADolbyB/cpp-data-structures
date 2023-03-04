/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file to test a single linked queue.
*/

#include <iostream>
#include <string>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class QUEUE
{
    public:

        class Qnode
        {
            public:

                string data;
                Qnode *next;
                Qnode() { next = 0;};
        };

        QUEUE();
        ~QUEUE();
        QUEUE(const QUEUE & );
        void enQueue(const string &);
        void deQueue();
        bool Empty() {return front == 0;};
        string& Front();
        void Print();

    private:

        Qnode *front, *back;
};

#endif