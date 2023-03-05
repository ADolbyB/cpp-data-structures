/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implementation file for a single linked list that
 * implements the List member functions.
****************************************************************************/

#include <cassert>
#include <new>

using namespace std;

#include "List.h"

/************************************************************************
Function Name: List()
Description: Default Constructor: Constructs an empty List object.
Precondition:  maxSize is a positive integer with default value 1024.
Postcondition: An empty List object is constructed; myCapacity ==
maxSize (default value 1024); myArrayPtr points to a run-time
array with myCapacity as its capacity; and mySize is 0.
************************************************************************/
List::List(int maxSize) : mySize(0), myCapacity(maxSize)
{
    cout << "Constructor Called" << endl;
    myArrayPtr = new(nothrow) ElementType[maxSize];

    assert(myArrayPtr != 0);
}

/*************************************************************************
Function Name: ~List()
Description: Destructor: Deallocates and destroys a List object.
Precondition: The life of the List object has been fulfilled.
Postcondition: The memory dynamically allocated by the constructor
for the array pointed to by myArrayPtr has been returned to the heap.
*************************************************************************/
List::~List()
{
    cout << "Destructor has been called" << endl;

    delete [] myArrayPtr;
}

/*************************************************************************
Function Name: List()
Description: Copy Constructor: deep copies a List object.
Precondition: origList is a const reference parameter.
Postcondition: A copy of origList has been constructed.
*************************************************************************/
List::List(const List& origList) : mySize(origList.mySize), myCapacity(origList.myCapacity)
{
    myArrayPtr = new(nothrow) ElementType[myCapacity];              // Get new array for copy

    if (myArrayPtr != 0)                                            // check if memory available
        {
            for(int i = 0; i < myCapacity; i++)
                {
                    myArrayPtr[i] = origList.myArrayPtr[i];         // Copy origList's array into this new array
                }
        }
    else
        {
            cerr << "*Inadequate memory to allocate stack ***" << endl;
            exit(1);
        }
}

/*************************************************************************
Function Name: operator=
Description: Overloaded operator= assigns a copy of a List object 
to the current object.
Precondition: none
Postcondition: A copy of origList has been assigned to this object.
A reference to this list is returned.
*************************************************************************/
List& List::operator=(const List& origList)
{
    if (this != &origList)                                          // check that they are not the same list
        {
            mySize = origList.mySize;
            myCapacity = origList.myCapacity;

            if (myCapacity != origList.myCapacity)                  // Allocate a new array if necessary
                {
                    delete[] myArrayPtr;
                    myArrayPtr = new(nothrow) ElementType[myCapacity];

                    if (myArrayPtr == 0)                            // check if memory available
                        {
                            cerr << "*Inadequate memory to allocate stack ***\n";
                            exit(1);
                        }
                }

            for(int i = 0; i < myCapacity; i++)
                {
                    myArrayPtr[i] = origList.myArrayPtr[i];         // Copy origList's array into this new array
                }
        }
    return *this;
}

/*************************************************************************
Function Name: empty()
Description: Checks if a list is empty.
Precondition: None
Postcondition: true is returned if the list is empty, false if not.
*************************************************************************/
bool List::empty() const                                            // Definition of empty()
{
    return (mySize == 0);
}

/*************************************************************************
Function Name: display()
Description: Displays the contents of the linked list.
Precondition: The ostream out is open.
Postcondition: The list represented by this List object has been
inserted into out.
*************************************************************************/
void List::display(ostream& out) const                             // Definition of display()
{
    for (int i = 0; i < mySize; i++)
        {
            out << myArrayPtr[i] << "  ";
        }
}

/*************************************************************************
Function Name: insert()
Description: Inserts a value into the list at a given position.
Precondition: item is the value to be inserted; there is room in
the array (mySize < CAPACITY); and the position satisfies
0 <= pos <= mySize.
Postcondition: item has been inserted into the list at the position
determined by pos (provided there is room and pos is a legal position).
*************************************************************************/
void List::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)
        {
            cerr << "*** No space for list element -- terminating execution ***" << endl;
            exit(1);
        }
    if (pos < 0 || pos > mySize)
        {
            cerr << "*** Illegal location to insert \'" << pos << "\'.  List unchanged. ***" << endl;
            return;
        }

    for(int i = mySize; i > pos; i--)
        {
            myArrayPtr[i] = myArrayPtr[i - 1];                      // First shift array elements right to make room for item
        }

    myArrayPtr[pos] = item;                                         // Now insert item at position pos and increase list size
    mySize++;
}

/*************************************************************************
Function Name: erase()
Description: Remove a value from the list at a given position.
Precondition: The list is not empty and the position satisfies
0 <= pos < mySize.
Postcondition: element at the position determined by pos has been
removed (provided pos is a legal position).
************************************************************************/
void List::erase(int pos)
{
    if (mySize == 0)
        {
            cerr << "*** List is empty ***\n";
            return;
        }
    if (pos < 0 || pos >= mySize)
        {
            cerr << "Illegal location to delete \'" << pos << "\'.  List unchanged. ***" << endl;
            return;
        }

    for(int i = pos; i < mySize; i++)
        {
            myArrayPtr[i] = myArrayPtr[i + 1];                      // Shift array elements left to close the gap
        }

    mySize--;                                                       // Decrease list size
}

/****************************************************************************
Function Name: operator<<
Description: Non-Class Function which overloads the << operator 
to print out all linked list values
****************************************************************************/
ostream& operator<< (ostream& out, const List& any_list_obj)
{
    any_list_obj.display(out);

    return out;
}

/****************************************************************************
Function Name: f()
Description: Non-Class Function w/ List value parameter to test the copy constructor
****************************************************************************/
void f(List any_list_obj)
{
    for (int i = 1; i < 5; i++)
        {
            any_list_obj.insert(100*i, i); // insert into the copy
            cout << any_list_obj << endl;  // output the copy
        }
}

/****************************************************************************
Function Name: print()
Description: Non-Class Function to print a list.
Precondition:  aList is a value parameter
Postcondition: Contents of aList have been displayed
***************************************************************************/
void print (List any_list_obj)
{
    cout << any_list_obj << endl;
}