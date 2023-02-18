/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 02/22/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 4: Linked List String ADT
Description: This program manages a singly linked list of objects, each containing a string object
named "term" and a word object pointer named "next"
*********************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include "sentence.h"

using namespace std;

/*************************************************************************************
Function Name: sentence()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
sentence::sentence()                                    // default constructor
{

    //cout << "Default Constructor Called" << endl;

    front = 0;
    back = 0;                                   // initialize front and back pointers to NULL since there are no nodes in the list
    node_count = 0;                             // initialize the node_count to zero.

}

/*************************************************************************************
Function Name: sentence()
Precondition: An object has been declared in the main with explicit argumants.
Postcondition: An object is created as a linked list with nodes that correspond to the words of the list
Description: Explicit-value constructor: This constructor will have one argument: a
C-style string or a C++ string representing each word to be created as a node of the linked list.
*************************************************************************************/
sentence::sentence(const string& s)                                                     // explicit value constructor
{
    //cout << "Explicit Value Constructor Called" << endl;                              // debug

    front = 0;
    back = 0;
    node_count = 0;                                                                     // initialize node_count to zero.

    //int num_characters;                                                               // debug
    //num_characters = (int)s.length();                                                 // stores the number of characters of the string into a variable
    //cout << "EVC: Length of String: num_characters = " << num_characters << endl;     // debug - number of characters passed in the argument: as counted in the function

    string temp_string = "";                                                            // temporary string to parse words of string 's' into
    string add_space = " ";                                                             // temporary string that consists of only a space;

    int k;
    if((int)s.length() != 0)                                                            // if the string length is not zero
        {
            for(k = 0; k < (int)s.length(); k++)                                        // declare a loop to iterate through the string
                {
                    if(s[k] != ' ')                                                     // if the current character of the string is not a space
                        {
                            temp_string += s[k];                                        // add that character to the 'temp_string'
                            //cout << "1st if: temp_string = (" << temp_string << ")"<< endl;             //debug
                        }
                    else if(s[k] == ' ')                                                // when a space is found
                        {
                            if(temp_string != "")                                       // if the 'temp_string' is not empty
                                {
                                    //cout << "2nd if: temp_string = (" << temp_string << ")"<< endl;     // debug
                                    add_back(temp_string);                              // drop the whole word from 'temp_string' and add it as the back node
                                }
                            //cout << "3rd if: temp_string = (" << temp_string << ")"<< endl;             // debug
                            add_back(add_space);                                        // then add a space to the next back node
                            temp_string = "";                                           // clear the content of the 'temp_string' to prep for the next word
                        }
                    if(k == (int)s.length() - 1)                                        // at the end of the string
                        {
                            //cout << "4th if: temp_string = (" << temp_string << ")"<< endl;             // debug
                            add_back(temp_string);                                      // drop the current word into the next index of 'another_array'
                            temp_string = "";                                           // clear contents of 'temp_string'
                        }
                }
        }

    //cout << "End of Explicit Value constructor" << endl;                                // debug

}

/*************************************************************************************
Function Name: sentence()
Precondition: An the object to be copied has already been declared and initialized.
Postcondition: A deep copy of the object passed as an argument to this function is created.
Description: Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object
*************************************************************************************/
sentence::sentence(const sentence& original)                             // Copy Constructor
{
    //cout << "Copy Constructor Called" << endl;

    front = 0;
    back = 0;
    node_count = 0;

    word *p = original.front;
    while(p != 0)
        {
            add_back(p->term);                          // traverse through original list (org) to make copy of each node term.
            p = p->next;
        }

}

/*************************************************************************************
Function Name: ~sentence()
Precondition: An object has already been declared and initialized.
Postcondition: The object is deleted and dynamic memory is freed.
Description: Destructor: The destructor will de-allocate all memory allocated for each node.
*************************************************************************************/
sentence::~sentence()                                               // Destructor
{
    cout << "Destructor Called" << endl;

	while (front != 0)
        {
            word *p = front;
            front = front->next;                                    // Traverse through list
            delete p;
        }
}

/*************************************************************************************
Function Name: length()
Precondition: The calling object has been declared and initialized
Postcondition: The total length of all string terms of the node is calculated and returned as an int.
Description: Length: Accessor function. Determines the character length of a word in a node
*************************************************************************************/
int sentence::length()
{

    int total_characters = 0;                                           // variable to count total number of characters in the linked list
    string test_string;                                                 // variable to copy the contents of the 'term' in each node so it can be counted
    //int num_nodes = 0;                                                // debug - local node variable: counts number of nodes traversed with this function

    if(!isEmpty())                                                      // if front is not null, then at least one node exists
        {
            //cout << endl << "INSIDE 1st Length IF" << endl;                                       // debug
            word *p_count = front;                                                                  // declare pointer at front of this object
            while(p_count->next != 0)                                                               // while the pointer isn't at the back of the list
                {
                    //cout << "test_string = (" << test_string << ")" << endl;                      // debug
                    //cout << "test_string.length() = " << (int)test_string.length() << endl;       // debug
                    //cout << "total characters = " << total_characters << endl;                    // debug
                    test_string = p_count->term;                            // test string becomes contents of "term" inside node
                    total_characters += (int)test_string.length();          // the # of characters of the "term" variable is added to the total characters
                    p_count = p_count->next;                                // traverse object
                    //num_nodes++;                                          // debug - local node tracker variable
                }
                    test_string = p_count->term;                            // when p_count->next == 0; you are at the end of the string and need to add the term to the test_string
                    total_characters += (int)test_string.length();          // add those characters to the total characters
                    //num_nides++;                                          // debug - local node tracker variable

        }
    else
        {
            return 0;                                                       // if the list is empty, then there are no characters to count.
        }

    //cout << endl << "Inside END of length() TOTAL CHAR: " << total_characters << endl;          // debug
    //cout << "Inside length(): num_nodes = " << num_nodes << endl;                               // debug
    //cout << endl << ".length TOTAL CHAR = " << total_characters<< endl;                         // debug
    return (total_characters);

}

/*************************************************************************************
Function Name: add_back()
Precondition: An object has been declared and initialized in the main.
Postcondition: The calling object is appended with a new node at the back of itself.
Description: Mutator Function: add a node to the back of the Linked List
*************************************************************************************/
void sentence::add_back(string& s)
{

    if(s.length() != 0)
        {
            if(isEmpty())
                {
                    front = new word;
                    front->term = s;
                    front->next = 0;
                    back = front;
                    node_count++;                                                    // increment the node counter
                }
            else
                {
                    word *p = new word;
                    p->next = 0;
                    p->term = s;
                    back->next = p;
                    back = p;
                    node_count++;                                                    // increment the node counter
                }
        }

}

/*************************************************************************************
Function Name: operator=
Precondition: An object has been declared an initialized in the main.
Postcondition: The calling object is made as an equivalent linked list to the argument in the main.
Description: Mutator Function: Overloads the assignment operator as a member function
to take a string as an argument and assigns the string value to the current object.
*************************************************************************************/
void sentence::operator=(const string& s)
{

    //cout << "\'Operator = called\'" << endl;

    front = 0;
    back = 0;
    node_count = 0;

    //int num_characters;
    //num_characters = (int)s.length();                                                   // stores the number of characters of the string into a variable

    string temp_string = "";                                                            // temporary string to parse words of string 's' into
    string add_space = " ";                                                             // temporary string that consists of only a space;

    int k;
    if((int)s.length() != 0)                                                            // if the string length is not zero
        {
            for(k = 0; k < (int)s.length(); k++)                                        // declare a loop to iterate through the string
                {
                    if(s[k] != ' ')                                                     // if the current character of the string is not a space
                        {
                            temp_string += s[k];                                        // add that character to the 'temp_string'
                            //cout << "1st if: temp_string = (" << temp_string << ")"<< endl;             //debug
                        }
                    else if(s[k] == ' ')                                                     // when a space is found
                        {
                            if(temp_string != "")                                       // if the 'temp_string' is not empty
                                {
                                    //cout << "2nd if: temp_string = (" << temp_string << ")"<< endl;     // debug
                                    add_back(temp_string);                              // drop the whole word from 'temp_string' and add it as the back node
                                }
                            //cout << "3rd if: temp_string = (" << temp_string << ")"<< endl;             // debug
                            add_back(add_space);                                        // then add a space to the next back node
                            temp_string = "";                                           // clear the content of the 'temp_string' to prep for the next word
                        }
                    if(k == (int)s.length() - 1)                                                // at the end of the string
                        {
                            //cout << "4th if: temp_string = (" << temp_string << ")"<< endl;             // debug
                            add_back(temp_string);                                      // drop the current word into the next index of 'another_array'
                            //temp_string = "";                                           // clear contents of 'temp_string'
                        }
                }
        }

    //cout << "\'Operator =\': Length of String: num_characters = " << num_characters << endl;       // debug

    //cout << "End of \'Operator =\'" << endl;                                // debug

}

/*************************************************************************************
Function Name: operator+
Precondition: An object has been declared and initialized.
Postcondition: The calling object data is appended to with additional nodes as indicated
in the argument
Description: Mutator Function: Overloads the ‘+” operator as a member function without
chaining to add word B (the set of symbols that makeup B's linked list to the back of
A's (in the main) linked list).
*************************************************************************************/
void sentence::operator+(sentence& B)
{

    word *p = B.front;

    if(p != 0)
        {
            while(p != 0)
                {
                    add_back(p->term);                  // adds a node to the back with add_back function
                    p = p->next;                        // traverse the loop to add back each overloaded object
                }
        }
    else
        {
            return;
        }

}

/*************************************************************************************
Function Name: isEqual()
Precondition: The object variables to be output to the stream must be initialized with values.
Postcondition: a boolean value if true or false is returned.
Description: Accessor Function: Returns true if two word objects are equal; otherwise false;
remember A (in the main) is the current object.
*************************************************************************************/
bool sentence::isEqual(sentence& B)
{

    word *p = this->front;
    word *the_other = B.front;

    if(this->node_count != B.node_count)                                               // if the objects do not have the same # of nodes, they are not equal
        {
            return false;
        }
    else
        {
            while(p != 0)
                {
                    //cout << "p->term = " << p->term << endl;                          // debug - shows term in node
                    //cout << "the_other->term = " << the_other->term << endl;          // debug - shows term in node
                    if(p->term != the_other->term)
                        {
                            return false;
                        }
                    p = p->next;
                    the_other = the_other->next;
                }
            return true;
        }
}

/*************************************************************************************
Function Name: search()
Precondition: The object to be searched has been declared and initialized.
Postcondition: A pointer is returned pointing to the matching node (null if string is not matched)
Description: Accessor Function: Finds any string in the linked list equal to the function argument
*************************************************************************************/
word* sentence::search(const string& s)
{

    word *p = front;                                // initialize p to front to help in the traversal of the list

	while (p != 0)                                  // traverse (iterate through list)
        {
            if (p->term == s)                       // check if key equal to data in current node
                {
                    return p;                       // 's' located, return its location in list
                }
            p = p->next;                            // move to next node in the list
        }
	return p;                                       // return location if found, otherwise 0 (null)

}

/*************************************************************************************
Function Name: remove()
Precondition: The object variables to be removed must be initialized with values.
Postcondition: The node pointed to as found in "search" is deleted from the linked list
Description: Mutator Function: Deletes the first occurrence of the string "s" from the list.
*************************************************************************************/
void sentence::remove(const string& s)
{

    word *p = search(s);                            // declare pointer to search: p = address of the node containing string 's', otherwise NULL if not found

	if (p == 0)                                     // if pointer p not found in the list
        {
            //cout << "String: " << s << " is not in list" << endl;
        }
	else                                            // if "p" was found
        {
            if (p == front && front == back)        // if there is only one node in the list
                {
                    delete p;                       // delete that only node
                    node_count = 0;                 // set node_counter to zero.
                    front = back = 0;               // set both pointers to null since list is now empty
                }
            else if (p == front)                    // if p == the front node: there are at least 2 nodes in the list
                {
                    front = front->next;            // move front pointer to the next node
                    delete p;                       // delete front node
                    node_count--;                   // keeps count of the # of nodes that exist
                }
            else                                    // p != front or back, there are at least 3 nodes, and unwanted node is in the middle
                {
                    word *back_ptr = front;         // declare a new pointer to traverse through the list

                    while (back_ptr != 0 && back_ptr->next != p)    // valid until back->next == p
                        {
                            back_ptr = back_ptr->next;              // traverse through the list to find node before *p
                        }
                    if (p == back)                  // if p == back node
                        {
                            back = back_ptr;        // set back to node before last node
                        }
                    back_ptr->next = p->next;       // set the "next" pointer to skip the unwanted node
                    delete p;                       // delete unwanted node.
                    node_count--;                   // keeps count of the # of nodes that exist;
                }
        }
}

/*************************************************************************************
Function Name: node_counter() - used for debug as a node counting cross reference.
*** For Internal Lab/Depot use only ***
Precondition: This function must be uncommented to track "num_nodes". Any sentence
object can call node_counter, which will traverse the list object independently of
another function for an unbiased count.
Postcondition: As the pointer traverses the list to count each node, this function
can track each node traversed separately for debug.
Description: Accessor function: counts the total amount of nodes in the linked list
and returns an integer
*************************************************************************************/
//int sentence::node_counter()
//{
//
//    int node_count = 0;                                 // declare a variable for counting nodes.
//    word *c = front;                                    // declare a pointer at the front of the list
//
//    if(isEmpty())                                       // If the list is empty, there are no nodes.
//        {
//            return (node_count);
//        }
//    else                                                // If the list is not empty, there is at least one node.
//        {
//            node_count = 1;                             // at least one node exists if the list is not empty
//            while(c->next != 0)
//                {
//                    node_count++;
//                    c = c->next;
//                }
//        }
//
//    return (node_count);
//}

/*************************************************************************************
Function Name: operator<<
Precondition: The calling object must be initialized with values.
Postcondition: The values of the "term" of each node is returned as an ostream object.
Description: Accessor Friend Function: accesses and displays the state of the class
by returning an ostream object. While loop iterates through each node, printing the
"term" of each node while the the value p points to is not NULL.
*************************************************************************************/
ostream& operator<<(ostream& out, const sentence& w)
{

    word *p = w.front;

    while(p != 0)
        {
            out << p->term;                                     // no space needed since each space is it's own node
            p = p->next;                                        // traverse through the linked list
        }

   return out;

}
/*************************************************************************************
Function Name: print()
Precondition: The calling object must be declared and initialized.
Postcondition: The values of the "term" of each node is printed to the screen
Description: Accessor Function: The following function, Print, prints all the data stored
in the linked list of the current object. In this case, printing starts at the front of
the list.
*************************************************************************************/
void sentence::Print() const
{

    //cout << "Print() called" << endl;

	word *p = front;

	cout << endl;

	while (p != 0)                  // once *p == NULL, the loop terminates
        {
            cout << p->term;
            p = p->next;
        }

	cout << endl;
}

/*************************************************************************************
Function Name: operator=
Precondition: The object to be copied must be declared and initialized
Postcondition: The object passed in the function argument is copied anda shallow copy is made.
Description: Mutator Function: Overloads the operator= sign to make an equivalent object.
*************************************************************************************/
sentence& sentence::operator=(const sentence& w)
{
    //cout << "2nd Operator= function called" << endl;

    if(this != &w)
        {
            //this->~sentence();                            // debug - call the destructor to deallocate all dynamic memory of current object.
                                                            // in this case it did not make a difference, and output was not matched if the destructor was called here
            front = 0;
            back = 0;
            node_count = 0;

            word *p = w.front;
            while(p != 0)
                {
                    add_back(p->term);
                    p = p->next;
                }

            return *this;
        }

    return *this;

}