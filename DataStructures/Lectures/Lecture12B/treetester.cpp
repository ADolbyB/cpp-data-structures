 /**************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * Driver file for testing a class template Binary Search Tree ADT.
**************************************************************************/

#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST<int> intBST;        // Declare a BST of INTs.

    cout << "Constructing empty BST" << endl;
    cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty" << endl;

    cout << "Inorder Traversal of BST: " << endl;
    intBST.inorder(cout);

    cout << endl << "Now insert a bunch of integers into the BST." << endl
         << "Try items not in the BST and some that are in it: " << endl;

    int number;
    for (;;)                // Loop for inserting values
        {
            cout << "Item to insert (Enter -999 to stop): ";
            cin >> number;

            if (number == -999)
                {
                    break;
                }
            intBST.insert(number);
        }

    intBST.graph(cout);

    cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty" << endl;
    cout << "Inorder Traversal of BST: " << endl;

    intBST.inorder(cout);

    cout << endl;

    cout << endl << endl << "Now testing the search() operation." << endl
         << "Try both items in the BST and some not in it: " << endl;

    for (;;)                // Loop for searching values
        {
            cout << "Item to find (-999 to stop): ";
            cin >> number;

            if (number == -999)
                {
                    break;
                }
            cout << (intBST.search(number) ? "Found" : "Not found") << endl;
        }

    cout << endl << "Now testing the remove() operation." << endl
         << "Try both items in the BST and some not in it: " << endl;

    for (;;)                // Loop for removing values
        {
            cout << "Item to remove (-999 to stop): ";
            cin >> number;

            if (number == -999)
                {
                    break;
                }
            intBST.remove(number);
            intBST.graph(cout);
        }
    cout << endl << "Inorder Traversal of BST: " << endl;
    intBST.inorder(cout);   // Print All contents of BST to cout.
    cout << endl;
}