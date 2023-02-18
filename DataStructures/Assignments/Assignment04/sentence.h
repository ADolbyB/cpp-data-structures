/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 02/19/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 4: Linked List String ADT
Description: This program manages a singly linked list of word objects, each containing a string object
named "term" and a word object pointer named "next". Those objects are managed by the "sentence" class
condition and state.
*********************************************************************************************/

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class word
{
    public:

        string term;
        word* next;

};

class sentence
{
    public:

        sentence();
        /** The default constructor will initialize your state variables. The front of the linked list
        is initially set to NULL or 0; this implies a non-header node implementation of the link list. */

        sentence(const string& s);
        /** Explicit-value constructor: This constructor will have one argument, a C-style string or a
        C++ string representing the word to be created */

        sentence(const sentence& original);
        /** Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object */

        ~sentence();
        /** Destructor: The destructor will de-allocate all memory allocated for the word. Put the message
        "Destructor Called" inside the body of the destructor. */

        bool isEmpty() { return front == 0; } /** inline implementation - returns false if front pointer is NULL */

        int length(); /** Length: Determines the length of the word A; remember A is the current object */

        void add_back(string& s);   /** Add a node to the back of the Linked List */

        friend ostream& operator<<(ostream& out, const sentence& w);
        /** Overload the insertion operator as a friend function with chaining to print a word A */

        void operator=(const string& s);
        /** Overload the assignment operator as a member function to take a string (C-style or C++ string, just be consistent
        in your implementation) as an argument and assigns its value to A, the current object */

        sentence& operator=(const sentence& w);
        /** Overload the assignment operator as a member function with chaining to take a word object as an argument
        and assigns its value to A, the current object */

        void operator+(sentence& B);
        /** Overload the �+� operator as a member function without chaining to add word B (adds the set of symbols
        that makeup B's linked list to the back of A's linked list) to the back of word A. Remember A is the current object */

        bool isEqual(sentence& B); /** Returns true if two word objects are equal; otherwise false; remember A is the current object */

        void remove(const string& s); /** Deletes the first occurrence of the string s from the list A */

        //int node_counter(); /** counts the total amount of nodes in the linked list -- DEBUG -- Lab/Depot use */

        word* search(const string& s); /** Finds any string in the linked list equal to the function argument */

        void Print() const; /** Print function traverses nodes to print each string term */

    private:

        word* front;            /** Pointer to the front node of the linked list */
        word* back;             /** Pointer to the back node of the linked list */
        int node_count;         /** Variable to keep track of how many nodes exist */
};

#endif // HEADER_H_INCLUDED