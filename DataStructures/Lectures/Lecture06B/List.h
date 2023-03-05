/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for a single linked list that
 * declares / defines the data type List for processing linked lists.
 * Basic operations are:
 * Constructor
 * Destructor
 * Copy constructor
 * Assignment operator
 * empty: Check if list is empty
 * insert: Insert an item
 * erase: Remove an item
 * display: Output the list
 * << : Output operator
****************************************************************************/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

typedef int ElementType;

class List
{                                               
    public:

        List(int maxSize = 1024);                   // Default Constructor
        ~List();                                    // Destructor
        List(const List& origList);                 // Copy Constructor
        List& operator=(const List& origList);      // Overloaded Assignment Operator
        bool empty() const;                         // Check if List is empty
        void insert(ElementType item, int pos);     // Insert a new element
        void erase(int pos);                        // Delete an element
        void display(ostream& out) const;           // output data to a stream

    private:

        int mySize;                                 // current size of list stored in array
        int myCapacity;                             // capacity of array
        ElementType *myArrayPtr;                    // pointer to dynamically-allocated array

};

/************************************************************
Non Class Function Prototype Declarations
*************************************************************/
ostream& operator<<(ostream& out, const List& any_list_obj);
void f(List any_list_obj);
void print (List any_list_obj);

#endif // LIST_H_INCLUDED