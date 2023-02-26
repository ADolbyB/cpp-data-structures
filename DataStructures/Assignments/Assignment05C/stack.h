/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: COP3530: Data Structures        Professor: Dr. Lofton Bullard
Due Date: 03/03/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT

Description: This program manages a linked list stack of objects, each containing a string object
named "data" and a pointer named "next".
*********************************************************************************************/

#ifndef stack_h
#define stack_h
#include <iostream>
#include <string>

using namespace std;
typedef string stack_element; // makes it to where stack_element now refers to type string thoughout the file.

class stack_node
{
    public:
        stack_element data; // information stored in the node.
        stack_node *next; // points to the next node in the stack.
};

class stack
{
    public:
        // Default constructor: Sets the top of the stack to 0 and sets count to 0.
        stack(){ cout << "Inside Default Constructor\n"; s_top = 0; operatorCount = 0; operandCount = 0; }
        stack (string); // Explicit-Value Constructor.
        ~stack(); // Destructor: Deletes the whole stack.
        // stack(const stack &); // Copy Constructor.
        stack_element top();
        string pop(); // Pops the first item off of the stack.
        void push(const stack_element &); // Pushes an element onto the top of the stack.
        string print(); // Prints the stack.
        bool IsEmpty() const; // Checks to see if the stack is empty.
        void infixConversion(); // Converts the string from postfix to infix.

    private:

        stack_node *s_top; // Location of the top node in the stack.
        int operandCount;
        int operatorCount;
};

#endif /* stack_h */