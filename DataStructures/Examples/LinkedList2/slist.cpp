/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implemetation file for a single linked list
*/

#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

LINKED_LIST_CLASS::LINKED_LIST_CLASS()
{
	cout << "Default constructor has been called" << endl;

	front = back = 0;
}

LINKED_LIST_CLASS::~LINKED_LIST_CLASS()
{

	cout << "Destructor has been called" << endl;

	while (front != 0)
        {
            LIST_NODE *p = front;
            front = front->next;
            delete p;
        }
}

void LINKED_LIST_CLASS::Print()
{

	LIST_NODE *p = front;

	cout << endl;

	while( p != 0)
        {
            cout << p->data << ' ';
            p = p->next;
        }

	cout << endl;
}

void LINKED_LIST_CLASS::Insert(const List_Type& key)
{
	LIST_NODE *p = new LIST_NODE;

	p->next = 0;
	p->data = key;

	if (front == 0)
        {
            front = p;
            back = front;
        }
	else
        {
            p->next = front;
            front = p;
        }
}

LIST_NODE* LINKED_LIST_CLASS::Search(const List_Type& key)
{

    cout << "Search invoked for: \'" << key << "\'" << endl;

	LIST_NODE *p = front;

	while(p != 0)
        {
            if (p->data == key)
                {
                    return p;
                }
            p = p->next;
        }
	return p;
}

void LINKED_LIST_CLASS::Remove(const List_Type& key)
{
	LIST_NODE *p = Search(key);

	cout << "Remove Invoked for: \'" << key << "\'" << endl;

	if (p == 0)
        {
            cout << "Key: \'" << key << "\' is not in the list" << endl;
        }
	else
        {
            if (p == front && front == back)
                {
                    delete p;
                    front = back = 0;
                }
            else if (p == front)
                {
                    front = front->next;
                    delete p;
                }
            else
                {
                    LIST_NODE *back_ptr = front;

                    while(back_ptr->next != p)
                        {
                            back_ptr = back_ptr->next;
                        }

                    if (p == back)
                        {
                            back = back_ptr;
                        }

                    back_ptr->next = p->next;
                    delete p;
                }
        }
}

void LINKED_LIST_CLASS::node_counter()
{

    int node_count = 0;
    LIST_NODE *c = front;

    if(front == 0)
        {
            node_count = 0;
        }
    else
        {
            node_count = 1;
            while(c->next != 0)
                {
                    node_count++;
                    c = c->next;
                }
        }

    cout << "Node Count: " << node_count << endl;
}