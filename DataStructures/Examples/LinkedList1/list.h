/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for a single linked list
*/

#include <iostream>
#include <string>

using namespace std;

#ifndef LIST_H
#define LIST_H

typedef char List_Type;

class LIST_NODE                                         // class declaration for nodes in the linked list
{
    public:

        List_Type data;                                 // data element of the node
        LIST_NODE *next;                                // pointer element to the next node

};

class LINKED_LIST_CLASS                                 // declaration of the Linked List Class
{
    public:

        LINKED_LIST_CLASS();                            // Default constructor - sets each LIST_NODE to null
        ~LINKED_LIST_CLASS();                           // Destructor for deallocating Linked Lists
        void Print();                                   // accessor to print node content to screen
        bool Is_Empty() { return front == 0; };         // accessor to check is the Linked List is an empty list
        void Insert_FRONT(const List_Type& );           // Inserts a new LIST_NODE to the front of the Linked List
        void Insert_BACK(const List_Type& );            // Inserts a new LIST_NODE to the back of the Linked List
        void Create_List(const string& );               // Creates a new Linked List with each node as one character of the string argument
        LIST_NODE* Search(const List_Type& );           // Search Function - returns pointer to the matched node
        void Remove(const List_Type& );                 // Remove Function - removes unwanted node from the Linked List

    private:

        LIST_NODE *front, *back;                        // pointers to the front and back of the linked list
};

#endif