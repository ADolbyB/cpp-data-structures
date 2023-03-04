/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implementation file for a single linked list
 * Which implements List member functions.
****************************************************************************/

#include <cassert>

using namespace std;

#include "List.h"

/************************************************************************
Function Name: List()
Description: Default Constructor constructs an empty List object.
Precondition: None
Postcondition: An empty List object has been constructed & mySize = 0.
************************************************************************/
List::List() : mySize(0)
{
    // Definition of class constructor
    cout << "Default Constructor Called" << endl;
}

/************************************************************************
Function Name: empty()
Description: Checks if a list is empty.
Precondition: None
Postcondition: true is returned if the list is empty false if not.
************************************************************************/
bool List::empty() const
{
    return mySize == 0;
}

/*************************************************************************
Function Name: display()
Description: Displays the list.
Precondition: out is a reference parameter
Postcondition: The list represented by this List object has been
inserted into ostream out.
*************************************************************************/
void List::display(ostream& out) const
{
    for (int i = 0; i < mySize; i++)
        {
            out << myArray[i] << ' ';
        }
}

/*************************************************************************
Function Name: insert()
Description: Inserts a value into the list at the given position.
Precondition: item is the value to be inserted, there is room in the
array (mySize < CAPACITY), and the position satisfies 0 <= pos <= mySize.
Postcondition: item has been inserted into the list at the position
determined by pos (provided there is room and pos is a legal position).
*************************************************************************/
void List::insert(ElementType item, int pos)
{
    if (mySize == CAPACITY)
        {
            cerr << "***No space for list element: terminating execution***" << endl;
            exit(1);
        }
    if (pos < 0 || pos > mySize)
        {
            cerr << "*** Illegal location to insert: \'" << pos << "\'.  List unchanged. ***" << endl;
            return;
        }

    for(int i = mySize; i > pos; i--)
        {
            myArray[i] = myArray[i - 1]; // First shift array elements right to make room for item
        }

    myArray[pos] = item;                 // Now insert item at position pos and increase list size
    mySize++;
}

/************************************************************************
Function Name: erase()
Description: Removes a value from the list at a given position.
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
            cerr << "Illegal location to delete: \'" << pos << "\'.  List unchanged. ***" << endl;
            return;
        }

    for(int i = pos; i < mySize; i++)
        {
             myArray[i] = myArray[i + 1];               // Shift array elements left to close the gap
        }

    mySize--;                                           // Decrease list size
}

/************************************************************************
Function Name: operator<<
Description: Non-Class Function Which overloads the operator<<
for output.
************************************************************************/
ostream& operator<< (ostream& out, const List& aList)
{
    aList.display(out);

    return out;
}