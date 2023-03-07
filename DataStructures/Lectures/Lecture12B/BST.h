/**************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a CLASS implementation of the Binary Search Tree ADT.
 * * Basic operations:
 * Constructor: Constructs an empty BST
 * empty: Checks if a BST is empty
 * search: Search a BST for an item
 * insert: Inserts a value into a BST
 * remove: Removes a value from a BST
 * inorder: Inorder traversal of a BST -- output the data values
 * graph: Output a grapical representation of a BST
 * * Private utility helper operations:
 * search2: Used by delete
 * inorderAux: Used by inorder
 * graphAux: Used by graph
 * * Other operations:
 * destructor
 * copy constructor
 * Overloaded assignment operator
 * preorder, postorder, level-by-level traversals & level finder.
 * Note: Execution terminates if memory isn't available for a new BST node.
**************************************************************************/
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <iomanip>

using namespace std;

template <typename DataType>
class BST
{
    public:

        BST();
        bool empty() const;
        bool search(const DataType& item) const;
        void insert(const DataType& item);
        void remove(const DataType& item);
        void inorder(ostream& out) const;
        void graph(ostream& out) const;

    private:

        class BinNode // Nested Node Class
        {
            public:

                DataType data;
                BinNode *left;              // Pointer to Left Child
                BinNode *right;             // Pointer to Right Child

                // Default Node Constructor for Empty Node
                BinNode() : left(0), right(0) {}

                // Explicit Value Constructor: Inserts 'item'
                BinNode(DataType item) : data(item), left(0), right(0) {}

        };  // End BinNode Class Declaration

        typedef BinNode *BinNodePointer;

        // Private Member Function Prototype Declarations
        void search2(const DataType& item, bool& found, BinNodePointer& locptr, BinNodePointer& parent) const;
        void inorderAux(ostream& out, BST<DataType>::BinNodePointer subtreePtr) const;
        void graphAux(ostream& out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const;
        
        BinNodePointer myRoot; // Private Data Member

}; // end of class template declaration

/******************************************************************
Function Name: BST()
Description: Default Constructor for BST Object. Constructs a 
BST object.
Precondition: None.
Postcondition: An empty BST has been constructed.
******************************************************************/
template <typename DataType>
inline BST<DataType>::BST() : myRoot(0) {}

/******************************************************************
Function Name: empty()
Description: Checks if BST is empty.
Precondition: None.
Postcondition: Returns true if BST is empty and false otherwise.
******************************************************************/
template <typename DataType>
inline bool BST<DataType>::empty() const
{
    return myRoot == 0;
}

/*******************************************************************
Function Name: search()
Description: Searches the BST for item.
Precondition: None.
Postcondition: Returns true if item found, and false otherwise.
******************************************************************/
template <typename DataType>
bool BST<DataType>::search(const DataType& item) const
{
    BST<DataType>::BinNodePointer locptr = myRoot;

    bool found = false;
    while (!found && locptr != 0)
        {
            if (item < locptr->data)                    // descend left
                {
                    locptr = locptr->left;
                }
            else if (locptr->data < item)               // descend right
                {
                    locptr = locptr->right;
                }
            else                                        // item found
                {
                    found = true;
                }
        }
    return found;
}

/******************************************************************
Function Name: insert()
Desription: Inserts item into BST.
Precondition: None.
Postcondition: BST has been modified with item inserted at proper
position to maintain BST property.
******************************************************************/
template <typename DataType>
inline void BST<DataType>::insert(const DataType& item)
{
    BST<DataType>::BinNodePointer locptr = myRoot;      // search pointer
    BST<DataType>::BinNodePointer parent = 0;           // pointer to parent of current node

    bool found = false;                                 // indicates if item already in BST
    while (!found && locptr != 0)
        {
            parent = locptr;
            if (item < locptr->data)                    // descend left
                {
                    locptr = locptr->left;
                }
            else if (locptr->data < item)               // descend right
                {
                    locptr = locptr->right;
                }
            else                                        // item found
                {
                    found = true;
                }
        }

    if (!found)
        {                                               // construct node containing item
            locptr = new BST<DataType>::BinNode(item);

            if (parent == 0)                            // empty tree
                {
                    myRoot = locptr;
                }
            else if (item < parent->data )              // insert to left of parent
                {
                    parent->left = locptr;
                }
            else                                        // insert to right of parent
                {
                    parent->right = locptr;
                }
        }
    else
        {
            cout << "Item already in the tree" << endl;
        }
}

/******************************************************************
Function Name: remove()
Description: Remove item from BST.
Precondition: None.
Postcondition: BST has been modified with item removed (if present)
and BST property is maintained.
Note: remove uses auxiliary function search2() to locate the node
containing item and its parent.
******************************************************************/
template <typename DataType>
void BST<DataType>::remove(const DataType& item)
{
    bool found;                                         // signals if item is found

    BST<DataType>::BinNodePointer
        x,                                              // points to node to be deleted
        parent;                                         // points to parent of x and xSucc

    search2(item, found, x, parent);

    if (!found)
        {
            cout << "Item not in the BST" << endl;
            return;
        }

    if (x->left != 0 && x->right != 0)                  // If node has 2 children
        {
            BST<DataType>::BinNodePointer xSucc = x->right;
            parent = x;                                 // Find x's inorder successor and its parent

            while (xSucc->left != 0)                    // descend left
                {
                    parent = xSucc;
                    xSucc = xSucc->left;
                }

            x->data = xSucc->data;                      // Move contents of xSucc to x and change x
            x = xSucc;                                  // to point to successor, which will be removed.
        }

    // Case If Node has 0 or 2 children
    BST<DataType>::BinNodePointer subtree = x->left;    // pointer to a subtree of x

    if (subtree == 0)
        {
            subtree = x->right;
        }
    if (parent == 0)                                    // root node being removed
        {
            myRoot = subtree;
        }
    else if (parent->left == x)                         // left child of parent
        {
            parent->left = subtree;
        }
    else                                                // right child of parent
        {
            parent->right = subtree;
        }
    delete x;
}

/******************************************************************
Function Name: inorder()
Description: Performs an Inorder traversal of BST.
Precondition: ostream out is open.
Postcondition: BST has been inorder traversed and values in nodes
have been output to out stream.
Note: inorder uses private auxiliary function inorderAux().
******************************************************************/
template <typename DataType>
inline void BST<DataType>::inorder(ostream& out) const
{
   inorderAux(out, myRoot);
}

/******************************************************************
Function Name: graph()
Description: Graphic output of BST.
Precondition: ostream out is open.
Postcondition: Graphical representation of BST has been output to out.
Note: graph() uses private auxiliary function graphAux().
******************************************************************/
template <typename DataType>
inline void BST<DataType>::graph(ostream& out) const
{
    graphAux(out, 0, myRoot);
}

/******************************************************************
Function Name: search2()
Description: Locates a node containing item and its parent.
Precondition: None.
Postcondition: locptr points to node containing item or is null if
not found, and parent points to its parent.
******************************************************************/
template <typename DataType>
void BST<DataType>::search2(const DataType& item, bool& found, BST<DataType>::BinNodePointer& locptr, BST<DataType>::BinNodePointer& parent) const
{
    locptr = myRoot;
    parent = 0;
    found = false;

    while (!found && locptr != 0)
        {
            if (item < locptr->data)                    // descend left
                {
                    parent = locptr;
                    locptr = locptr->left;
                }
            else if (locptr->data < item)               // descend right
                {
                    parent = locptr;
                    locptr = locptr->right;
                }
            else                                        // item found
                {
                    found = true;
                }
        }
}

/*******************************************************************
Function Name: inorderAux()
Description: Performes Inorder traversal (auxiliary function.)
Precondition: ostream out is open and subtreePtr points to a subtree
of this BST.
Postcondition: Subtree with root pointed to by subtreePtr has been
output to out.
*******************************************************************/
template <typename DataType>
void BST<DataType>::inorderAux(ostream& out, BST<DataType>::BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
        {
            inorderAux(out, subtreeRoot->left);         // L operation
            out << subtreeRoot->data << "  ";           // V operation
            inorderAux(out, subtreeRoot->right);        // R operation
        }
}

/*******************************************************************
Function Name: graphAux()
Description: Graph auxiliary function.
Precondition: ostream out is open & subtreePtr points to a subtree
of this BST.
Postcondition: Graphical representation of subtree with root pointed
to by subtreePtr has been output to out, indented indent spaces.
*******************************************************************/
template <typename DataType>
void BST<DataType>::graphAux(ostream& out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
        {
            graphAux(out, indent + 8, subtreeRoot->right);
            out << setw(indent) << " " << subtreeRoot->data << endl;
            graphAux(out, indent + 8, subtreeRoot->left);
        }
}

#endif