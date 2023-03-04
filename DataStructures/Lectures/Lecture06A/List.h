/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file for a single linked list
 * Basic operations:
 * Constructor
 * empty: Check if list is empty
 * insert: Insert an item
 * erase: Remove an item
 * display: Output the list
 * <<, >> : input and output operators
****************************************************************************/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

const int CAPACITY = 1024;
typedef int ElementType;

class List
{
    public:

        List();                                 /***** Class constructor *****/
        bool empty() const;
        void insert(ElementType item, int pos);
        void erase(int pos);
        void display(ostream& out) const;

    private:                                    /******** Data Members ********/

        int mySize;                             // current size of list stored in myArray
        ElementType myArray[CAPACITY];          // array to store list elements

};

ostream& operator<< (ostream & out, const List & aList);   // Prototype of output operator

#endif // LIST_H_INCLUDED