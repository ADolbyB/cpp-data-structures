/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 02/26/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT
Description: This program manages a stack of string objects, each containing a string object
named "data" and a pointer named "next". ----------------
*********************************************************************************************/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;


typedef string stack_element;

class stack_node
{
    public:

        stack_element data;                                             // data portion of a stack node
        stack_node *next;                                               // pointer to the next value in the stack

};

class stack
{
    public:

        stack();                                                        // Default Constructor: Creates an Object
        ~stack();                                                       // Destructor: Deallocates memory
        stack_element top();                                            // 'Top' - returns a TYPEDEF 'stack_element' as the top stack value
        void pop();                                                     // 'Pop' - pops the stack until empty.
        void push(const stack_element& );                               // 'Push' - push a value to the top of the stack
        bool empty() const;                                             // returns TRUE if stack is empty
        void postfix_to_infix();                                        // function to do the expression conversion

    private:

        stack_node *s_top;                                              // pointer to the top of the stack
        int count;                                                      // stack node counter

};

#endif