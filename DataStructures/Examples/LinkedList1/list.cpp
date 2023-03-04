/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implemtation file for a single linked list
*/

#include <iostream>
#include <string>
#include "list.h"

using namespace std;

/************************************************************************
Function Name: LINKED_LIST_CLASS()
Description: Default Constructor
The Default Constructor is used to initialize the state of the class.
In this case, the state of the class are the front and back pointers. 
*************************************************************************/
LINKED_LIST_CLASS::LINKED_LIST_CLASS()
{

	cout << "Inside the default constructor" << endl;

	front = back = 0;
}

/************************************************************************
Function Name: ~LINKED_LIST_CLASS()
Description: Destructor 
The Destructor de-allocates all the memory allocated to the class.
It is called automatically by the compiler when the current object goes out of scope. 
*************************************************************************/
LINKED_LIST_CLASS::~LINKED_LIST_CLASS()
{

	cout << endl << "Destructor has been called" << endl;

	while (front != 0)
        {
            LIST_NODE *p = front;
            front = front->next;
            delete p;
        }
}

/*************************************************************************
Function Name: Print()
Description: Prints all the data stored in the linked list of the current 
object. In this case, printing starts at the front of the list. 
**************************************************************************/
void LINKED_LIST_CLASS::Print() // Accessor Function
{

	LIST_NODE *p = front;

	cout << endl;

	while (p != 0)
        {
            cout << p->data << ' ';
            p = p->next;
        }

	cout << endl;
}

/**************************************************************************
Function Name: Insert_FRONT()
Description: Adds a new List_Type node to the front of the linked list.
If the list is null, memory is allocated for a new node, 'key' is
stored in the data field, 0 (null) is stored in the 'next' field,
& front and back are set to point to the single node.
If the list is not null, memory is allocated for a new node, 'key' is 
stored in the data field, 'front' is stored in the next field, and 'front'
is set to point to the new node.
***************************************************************************/
void LINKED_LIST_CLASS::Insert_FRONT(const List_Type& key)
{

	if (front == 0)
        {
            front = new LIST_NODE;
            front->data = key;
            front->next = 0;
            back = front;
        }
	else
        {
            LIST_NODE *p = new LIST_NODE;

            p->data = key;
            p->next = front;
            front = p;
        }
}

/***************************************************************************
Function Name: Insert_BACK()
Description: Insert_BACK adds a new List_Type data item to the back
of the linked list.  If the list is null, memory is allocated for a
new node, 'key' is stored in the data field, 0 (null) is stored in the next
field, & front and back are set to point to the node. 
If the list is not null, memory is allocated for a new node,
'key' is stored in the data field, 0 (null) is stored in the next field,
and 'back' is set to point to the new node. 
****************************************************************************/
void LINKED_LIST_CLASS::Insert_BACK(const List_Type& key)
{

	if (front == 0)
        {
            front = new LIST_NODE;
            front->data = key;
            front->next = 0;
            back = front;
        }
	else
        {
            LIST_NODE *p = new LIST_NODE;
            p->next = 0;
            p->data = key;
            back->next = p;
            back = p;
        }
}

/****************************************************************************
Function Name: Create_List()
Description: The function Create_List creates a linked list from the string
's'. A copy of all the characters in s, are placed into separate nodes in the
linked list. The aux_front and aux_back represent pointers to the newly 
created front and back nodes of the linked list.
*****************************************************************************/
void LINKED_LIST_CLASS::Create_List(const string& s)
{

	if (front == 0)
        {
            for (int i = 0; i < (int)s.length(); i++)
                {
                    Insert_BACK(s[i]);
                }
        }
}

/*****************************************************************************
Function Name: Search()
Description: The function Search, performs a sequential search on the link
list. If key is found, a pointer to the node is returned, otherwise 0 (null)
is returned. 
*****************************************************************************/
LIST_NODE* LINKED_LIST_CLASS::Search(const List_Type& key)
{

    LIST_NODE *p = front;                           // initialize p to front to help in the traversal of the list

	while (p != 0)                                  // traverse (iterate through list)
        {
            if (p->data == key)                     // check if key equal to data in current node
                {
                    return p;                       // key located, return its location in list
                }
            p = p->next;                            // move to next node in the list
        }
	return p;                                       // return location if found, otherwise 0 (null)

}

/***************************************************************************
Function Name: Remove()
Description: Removes 'key' from the list, if it is in the list,
from any location: front, back, or in between. 
****************************************************************************/
void LINKED_LIST_CLASS::Remove(const List_Type& key)
{

    LIST_NODE *p = Search(key);                     // declare pointer to search: p = address of the node containing "key", otherwise NULL if not found

	if (p == 0)                                     // if key not found in the list
        {
            cout << "Key: " << key << " is not in list" << endl;
        }
	else                                            // if "key" was found
        {
            if (p == front && front == back)        // if there is only one node in the list
                {
                    delete p;                       // delete that only node
                    front = back = 0;               // set both pointers to null since list is now empty
                }
            else if (p == front)                    // if p = the front node: there are at least 2 nodes in the list
                {
                    front = front->next;            // move front pointer to the next node
                    delete p;                       // delete front node
                }
            else                                    // p != front or back, there are at least 2 nodes, and unwanted node is in the middle
                {
                    LIST_NODE *back_ptr = front;    // declare a new pointer to traverse through the list

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
                }
        }
}