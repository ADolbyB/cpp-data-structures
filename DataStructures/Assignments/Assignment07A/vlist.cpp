/*************************************************************************************
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

**************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "vlist.h"

using namespace std;

/*************************************************************************************
> Function Name: vlist();
> Precondition: An object is declared in the main with no arguments.
> Postcondition: An Object is created and initialized to default values:
    count = 0; vector capacity = 9.
> Description: Default Constructor: Creates an instance of a vlist object.
*************************************************************************************/
vlist::vlist()
{
    cout << endl << "Default Constructor Invoked" << endl;

    count = 0;                                                              // intialize default node count to 0
    DB.reserve(9);                                                          // reserve 9 empty array indices

    //cout << "DC: DB.size() = " << DB.size() << endl;                      // debug
    //cout << "DC: DB.capacity() = " << DB.capacity() << endl;              // debug

}

/************************************************************************************
> Function Name: vlist(const vlist& original);
> Precondition: An object is declared equivalent to the values of another object in the same line.
> Postcondition: A deep copy of a vlist object is created.
> Description: Copy Constructor: Creates a deep copy of the calling vlist object.
*************************************************************************************/
vlist::vlist(const vlist& original)
{
    cout << "Copy Constructor Invoked" << endl;

    DB.reserve(9);                                                          // reserve 9 empty slots. Can use 'resize(9)' as well
    DB = original.DB;                                                       // assign original values to new object nodes
    count = original.count;                                                 // set node count the original count

    //cout << "C.C. count: " << count << endl;                              // debug

}

/*************************************************************************************
> Function Name: ~vlist();
> Precondition: An object is already declared and initialized.
> Postcondition: The object and its associated dynamic memory are deallocated
> Description: Destructor: Deallocates memory of a vlist object.
*************************************************************************************/
vlist::~vlist()
{
    cout << "Destructor Invoked" << endl;

    DB.clear();                                                             // clear all elements
    DB.shrink_to_fit();                                                     // destroy all empty elements
    count = 0;                                                              // reset node counter

    //cout << endl << "Dest: DB.size() = " << DB.size() << endl;            // debug
    //cout << "Dest: DB.capacity() = " << DB.capacity() << endl;            // debug

}

/*************************************************************************************
> Function Name: isEmpty();
> Precondition: An object has been declared.
> Postcondition: if the vector indices are all empty, the function returns TRUE
> Description: Accessor Function: Checks if the calling object has all empty indices.
**************************************************************************************/
bool vlist::isEmpty()
{

    if(DB.size() == 0)                                                      // IF EMPTY
        {
            return true;
        }
    else                                                                    // NOT EMPTY
        {
            return false;
        }
    //return (DB.empty())                                                   // also acceptable
}

/*************************************************************************************
> Function Name: search(const string& key);
> Precondition: The object to be searched has been declared.
> Postcondition: An interator is returned pointing to the matching vector index. If not
    found, DB.end() index is returned.
> Description: Accessor function: An iterator is declared at the start index and
    cycles through the vector looking for "key". If key is found, the iterator pointing
    to the matching index is returned. If "key" not found, DB.end() is returned.
**************************************************************************************/
vector<string>::iterator vlist::search(const string& key)                   // search function returns an iterator
{
    //cout << "Search Called - Searching For: \'" << key << "\'" << endl;   // debug

    vector<string>::iterator the_itr = DB.begin();                          // declare iterator at beginning of the vector

    for(the_itr = DB.begin(); the_itr < DB.end(); the_itr++)
        {
            if((*the_itr) == key)
                {
                    cout << "Search found: \'" << key << "\'" << endl;      // debug
                    //cout << "Returning: *the_itr = (" << *the_itr << ")" << endl;     // debug
                    return the_itr;                                         // return iterator to matching index
                }
        }

    //cout << "\'" << key << "\' NOT found" << endl;                        // debug
    //cout << "Returning: *the_itr = (" << *the_itr << ")" << endl;         // debug

    return DB.end();                                                        // return DB.end() if no match found (DB.end() is AFTER the last vector index)

}

/**************************************************************************************
> Function Name: insert(const string& key);
> Precondition: An object has been declared with capacity > 0
> Postcondition: "key" is inserted into the vector alphabetically sorted.
> Description: Mutator Function: Inserts "key" into vector index in alphabetical order.
***************************************************************************************/
void vlist::insert(const string& key)                                       // Inserts elements in order
{

    cout << "Inserting: (" << key << ")" << endl;                           // debug

    if(isEmpty())
        {
            DB.push_back(key);                                              // if empty, no need for sorting
            count++;                                                        // increase node count
        }
    else // if NOT empty
        {
            vector<string>::iterator the_it = DB.begin();                   // declare an iterator at the beginning of the vector
            while(the_it != DB.end())
                {
                    if(key < *the_it)                                       // Inserts if the string is in alphabetical order
                        {
                            DB.insert(the_it, key);                         // inserts a sorted value to the vector
                            count++;                                        // increase the node counter
                            return;                                         // exit after inserting
                        }
                    else if(the_it == DB.end() - 1)                         // If its at the end of the vector and hasn't been inserted yet
                        {
                            DB.push_back(key);                              // add it to the back of the array
                            count++;                                        // increase the node counter
                            return;                                         // exit after returning
                        }
                    the_it++;                                               // iterate/traverse the vector
                }
        }
}

/**************************************************************************************
> Function Name: remove(const string& key);
> Precondition: An object has been declared.
> Postcondition: The corresponding index of the vector is erased.
> Description: Mutator Function: This function takes a string argument and calls the
    search function with that "key" string. The search function returns an iterator
    pointing to the index that needs to be erased. If the corresponding iterator == DB.end(),
    then the vector was traversed fully and no match was found. Otherwise, the index which
    is pointed to by the iterator is erased, and the node_count is decremented.
***************************************************************************************/
void vlist::remove(const string& key)
{
    cout << "Removing:  (" << key << ")" << endl;                           // debug

    vector<string>::iterator the_it;
    the_it = search(key);                                                   // call search function to find "key" string

    if(the_it == DB.end())                                                  // IF NOT FOUND
        {
            cout << "\'" << key << "\' Not Found in Vector" << endl;        // debug
        }
    else
        {
            //cout << "Removing:  (" << *the_it << ")" << endl;             // debug
            DB.erase(the_it);                                               // deletes the object at the index
            count--;                                                        // decrement the node count
        }
}

/**************************************************************************************
> Function Name: print();
> Precondition: The object to be printed has been declared.
> Postcondition: A list of all vector elements is printed to the screen.
> Description: Accessor Function: Iterates the vector and prints the contents of each node
***************************************************************************************/
void vlist::print()
{

    cout << "Printing: ";
    //cout << endl << "Print: DB.size() = " << DB.size() << endl;           // debug
    //cout << "Print: DB.capacity() = " << DB.capacity() << endl;           // debug
    //cout << "count = " << count << endl;                                  // debug

    if(isEmpty())
        {
            cout << "* Vector empty...Nothing to print *" << endl;
        }
    else
        {
            vector<string>::iterator the_iterator;                          // declare iterator
            for(the_iterator = DB.begin(); the_iterator < DB.end(); the_iterator++)
                {
                    cout << " [" << (*the_iterator) << "] ";
                }
        }
    cout << endl;
}