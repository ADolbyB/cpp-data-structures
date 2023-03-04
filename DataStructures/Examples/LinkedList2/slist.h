/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for a single linked list
*/

#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include <string>

using namespace std;

typedef string List_Type;

class LIST_NODE                                     // declaration for a node in the list
{
    public:

        List_Type data;                             // data element
		LIST_NODE *next;                            // pointer element
};

class LINKED_LIST_CLASS                             // declaration of a list class
{
    public:

        LINKED_LIST_CLASS();                        // default constructor
        ~LINKED_LIST_CLASS();
        void Print();                               // accessor function
        bool Is_Empty(){return front == 0;};        // accessor function
        void Insert(const List_Type &);
        LIST_NODE * Search(const List_Type &);
        void Remove(const List_Type &);
        void node_counter();

    private:

        LIST_NODE *front, *back;
};

#endif