/**
 * Joel Brigida
 * Unit 6 Chapter 6
 * This is an example of a list implementation of the list ADT
 * Operations:
 * Constructor: initializes the state of the class.
 * destructor: de-allocates memory allocated using the new operator.
 * Is_Empty: checks if the list is empty.
 * Search: finds the location of key in list and returns pointer to the node it is stored in.
 * Add: adds an element to the front of the list.
 * Remove: removes an element from the list.
 * Print: prints all the elements in the list.
 */

#include <iostream>
using namespace std;

class NODE
{
    public:

        int data;
        NODE *next;

};

class LIST
{
    public:

        LIST();                                             // default constructor
        ~LIST();                                            // de-allocates all memory allocated using the new operator
        bool Is_Empty(){ return front == 0;}                // inline implementation
        NODE* Search(int key);                              // returns pointer to node that hold key if is in list; otherwise return 0  (NULL)
        void Add(int key);                                  // adds item to the front of the list
        void Remove(int key);                               // removes an item from the list if it is there
        void Print();                                       // prints all the elements in the list to the screen

    private:

        NODE *front;                                        //points to the front of the singly linked list
};

/****************************************************************************
Name: LIST
Precondition: front has not been initialized
Postcondition: front has been set to zero (NULL)
Decription: default constructor
****************************************************************************/
LIST::LIST(): front(0)
{

    cout << "Default Constructor has been Called" << endl;
    // Default Constructor Initializes the front pointer to NULL

}

/*****************************************************************************
Name: ~LIST
Precondition: front points to the front of the list. list may be empty
Postcondition: all memory allocated to the list have been returned to system
Decription: destructor
*****************************************************************************/
LIST::~LIST()
{

    cout << endl << "Destructor has been called" << endl;

	NODE *p;

	while (front != 0)
        {
            p = front;
            front = front->next;
            delete p;
        }
}

/****************************************************************************************
Name: Search
Precondition: front has been initalized
Postcondition: returns a pointer to key if it is in list; otherwize 0 (NULL) is returned
Decription: locates key in the LIST (array) A
****************************************************************************************/
NODE* LIST::Search(int key)
{
	if (!Is_Empty())
        {
            NODE *p = front;

            while(p != 0 && p->data != key)
                {
                    p = p->next;
                }
            return p;
        }
    return 0;
}

/****************************************************************************
Name: Add
Precondition: front has been initialized
Postcondition: key has been added to the list
Decription: adds key to the list; duplicates are allowed
***************************************************************************/
void LIST::Add(int key)
{
	NODE *p = new NODE;

	p->data = key;
	p->next = front;
	front = p;
}

/****************************************************************************
Name: Remove
Precondition: front has been initialized
Postcondition: if list is not empty, and if key is in list, then key was removed.
Decription: removes key from the list
*****************************************************************************/
void LIST::Remove(int key)
{
	NODE *p = Search(key);

	if (p != 0)
        {
            NODE *prev;

            if (p == front)
                {
                    front = front->next;
                    delete p;
                }
            else
                {
                    prev = front;

                    while(prev->next != p)
                        {
                            prev = prev->next;
                        }

                    prev->next = p->next;
                    delete p;
                }
        }
}

/****************************************************************************
Name: Print
Precondition: front been initialized
Postcondition: the contents of the list was printed to the screen in not empty
Decription: prints the contents of list to the screen
****************************************************************************/
void LIST::Print()
{
    cout << endl;

	NODE *p = front;

	while (p != 0)
        {
            cout << p->data << ' ';
            p = p->next;
        }

    cout << endl;
}

int main()
{

    LIST myList;

	myList.Add(8);
	myList.Add(11);
	myList.Add(14);
	myList.Add(4);
	myList.Print();

	myList.Remove(4);
	myList.Print();

	myList.Remove(14);
	myList.Print();

	return 0;
}