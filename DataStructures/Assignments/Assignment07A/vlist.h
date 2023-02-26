/*****************************************************************************
    P R O G R A M	H E A D E R

    Name:	Joel Brigida

    Z#:	Z***************
    Instructor:	Dr. Bullard
    Class:	COP3530: Data Structures
    Term:	Spring 2021
    Assignment #7 (vlist)
    Due Date:	March 19, 2021
    Due Time:	11:59PM
    Points:	25

    Description: This program manages a vector by performing the following functions:
    (1) Allocate and de-allocate memory, insert in order & remove.
    (2) Implement a default constructor and a copy constructor.
    (3) Implement an insert function to add a string, in order, into a vector
    (4) Implement a remove function to delete a string from a vector

******************************************************************************/

#include <vector>
#include <string>

using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist
{
    public:

        vlist();
        vlist(const vlist& );
        ~vlist();
        bool isEmpty();
        vector<string>::iterator search(const string& );
        void insert(const string& );
        void remove(const string& );
        void print();

    private:

        vector<string> DB;
        int count;                      // # of elements in the vector
};

#endif