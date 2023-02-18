/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 03/12/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 6: Queue ADT
Description: Description: This is a doubly-linked, circular queue that uses only a pointer to the front.
*********************************************************************************************/

#include <iostream>
#include "bqueue.h"

using namespace std;

int main()
{

    bqueue k;

    k.print();                          // test print_front() when empty
    //k.print_back();                   // test print_back() when empty

    k.enqueue(60);

    k.print();
    //k.print_back();                   // test print_back()

    k.enqueue(20);
    k.enqueue(30);

    k.print();
    //k.print_back();                   // test print_back()

    k.enqueue(10);

    k.print();
    //k.print_back();                   // test print_back()

    k.enqueue(50);
    k.enqueue(40);

    k.print();
    //k.print_back();                   // test print_back()

    bqueue j = k;                       // test copy constructor

    j.dequeue();

    j.print();
    //j.print_back();

    j.dequeue();
    j.dequeue();
    j.dequeue();

    j.print();
    //j.print_back();

    j.dequeue();
    j.dequeue();

    j.print();
    //j.print_back();

    j.dequeue();                        // test dequeue with an empty queue
    j.dequeue();                        // test dequeue with an empty queue

    j.print();                          // test print at empty queue
    //j.print_back();                   // test print iteration from back

    return 0;
}