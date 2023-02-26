/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date:  4/17/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment #9: Binary Search Tree
Description: This program manages a Binary Search Tree. It adds nodes to the tree from an
    external file named "county_data.txt". This function inserts, deletes, prints to screen,
    and prints to file the specified nodes in alphabetical order using recursive function calls.
    The output file is named "county_info.txt" and is organized in alphabetical order.
*********************************************************************************************/

#include <iostream>
#include <fstream>                                                      // file i/o directive
#include <string>                                                       // string class directive
#include <cstdlib>                                                      // exit() function directive
#include <iomanip>
#include "bst.h"

using namespace std;

/**************************************************************************************
> Function Name: bst();
> Precondition: An object is declared in the main with no arguments.
> Postcondition: The object declared is initialized with default values
> Description: Default Constructor: This default constructor reads an input file named
    "county_data.txt", then sends each line out to "parse_file" function, and then
    creates a node for a binary search tree with 2 data fields: a string field
    "county_name" and a double field "population_size" from each line of text in the file.
***************************************************************************************/
bst::bst()
{
    cout << "Default Constructor Called" << endl << endl;

    root = 0;                                                           // set root pointer to NULL for empty list
    total_nodes = 0;                                                    // set number of nodes to 0
    created_nodes = 0;

    ifstream file_in;                                                   // declare ifstream object to read file
    string the_line = "";                                               // string used to read each line of text from file
    string population = "";                                             // parsed string of population data from "parse_file" function
    string place = "";                                                  // parsed string of location data from the "parse_file" function

    cout.setf(ios::fixed);                                              // display debug values as fixed decimal notation (not e-notation)
    cout.precision(0);                                                  // display debug values with 0 decimal places.

    file_in.open("county_data.txt");

    if(file_in.fail())
        {
            cout << "Default Constructor failed to open data file" << endl;
            exit(1);
        }

    while (!file_in.eof())
        {
            getline(file_in, the_line);                                 // reads and outputs one line at a time from the input file stream
            //cout << "the_line = " << the_line << endl;                // debug - prints the file names so i know it is reading the file properly
            parse_file(the_line, place, population);                    // call function to parse each line of data from the file
            insert(place, stod(population));                            // add the parsed file contents to the tree
        }

    file_in.close();
}

/**************************************************************************************
> Function Name: ~bst();
> Precondition: An object has been declared.
> Postcondition: Any dynamic memory associated with the object is deleted, and the
    object itself is then deleted.
> Description: Destructor: Deallocates all dynamic memory associated with a bst object
***************************************************************************************/
bst::~bst()
{
    cout << "Destructor Called" << endl;                                // debug

    empty_tree();                                                       // function call to empty_tree();
}

/**************************************************************************************
> Function Name: parse_file();
> Precondition: An object has been declared.
> Postcondition: The input argument "text_line" is parsed into 2 separate strings.
> Description: This function does not Access or Mutate the state of the class.
    This function takes a string "text_line" as an argument from the default
    constructor, then parses the line of text into 2 separate strings "the_place" being
    the name of the county, and "the_pop" being the population number of the county, then
    sends those strings back to the default constructor so they can be added to each
    data field of a new BST node.
***************************************************************************************/
void bst::parse_file(string& text_line, string& the_place, string& the_pop)
{
    // parse the file contents here and send back to the default constructor

    int location = 0;                                                   // location of the last space of the particular line read from the file.
    int digit_length = 0;                                               // amount of integers in the population size

    for (int i = (text_line.length() - 1); i >= 0; i--)
        {
            if (isdigit(text_line[i]))
                {
                    location = i;                                       // this finds the 1st space from the end of the string
                }
        }

    //cout << "location = " << location << endl;                        // debug to show the value of "location"

    for (int k = location; k < int(text_line.length()); k++)
        {
            digit_length++;                                             // counts how many digits are in the population part of the string
        }

    //cout << "digit_length = " << digit_length << endl;                // debug to show value of "digit length"

    the_place = text_line.substr(0, (location - 1));                    // puts the location part of the string into a separate string variable
    the_pop = text_line.substr(location, digit_length);                 // puts the numeric part of the string into a separate string variable

    //cout << "the_place = " << the_place << endl;                      // debug to show parsed string values.
    //cout << "the_pop = " << the_pop << endl;                          // debug

}
/**************************************************************************************
> Function Name: empty();
> Precondition: A BST object has been declared.
> Postcondition: Returns TRUE if the Binary tree is empty, otherwise returns FALSE.
> Description: Accessor Function: Checks whether root is NULL. If root is NULL, then the
    object is empty, and TRUE is returned. Otherwise, returns FALSE.
***************************************************************************************/
bool bst::empty()
{
    //cout << "Empty Called" << endl;

	return (root == 0);
}

/**************************************************************************************
> Function Name: insert();
> Precondition: The calling object has been declared in the main.
> Postcondition: The Mutator function insert() is called.
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it just calls the Mutator Function insert() using root as an argument.
***************************************************************************************/
void bst::insert(const string& item, const double& population)          // auxiliary function that calls the mutator function
{
    //cout << "Inserting: \'" << item << "\' & " << "\'" << population << "\'" << endl;     // DEBUG

	insert(root, item, population);                                     // call to insert function
}

/**************************************************************************************
> Function Name: insert();
> Precondition: An object has been declared
> Postcondition: A new node is created and inserted into the binary search tree
    in alphabetical order
> Description: Mutator Function: Creates a new node and inserts it into the Binary
    Search Tree in alphabetical order.
***************************************************************************************/
void bst::insert(treenode*& loc_ptr, const string& item, const double& population)
{

	if (loc_ptr == 0)                                                   // base case for an empty tree
        {
            //cout << "Insert IF" << endl;                              // debug
            loc_ptr = new treenode;
            created_nodes++;                                            // increment the number of nodes in the tree
            loc_ptr->lchild = loc_ptr->rchild = 0;                      // new node is always a leaf with both child pointers NULL
            loc_ptr->county_name = item;                                // insert string data
            loc_ptr->population_size = population;                      // insert double data
        }
	else if (loc_ptr->county_name > item)
        {
            //cout << "Insert Else If (1)" << endl;                     // debug
            insert(loc_ptr->lchild, item, population);                  // recursive call to alphabetically lower left child
        }
	else if (loc_ptr->county_name < item)
        {
            //cout << "Insert Else If (2)" << endl;                     // debug
            insert(loc_ptr->rchild, item, population);                  // recursive call to alphabetically higher left child
        }
	else
        {
            cout << "Item Already in Tree" << endl;                     // DON'T insert if item already exists.
        }
}

/**************************************************************************************
> Function Name: del_name();
> Precondition: The calling object has been declared
> Postcondition: The Mutator Function del_name() is called
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it just calls the Mutator Function del_name() using root as an argument.
***************************************************************************************/
void bst::del_name(string item)
{
    cout << "Deleting: \'" << item << "\'" << endl;                     // Debug

	del_name(root, item);                                               // Function call to Mutator Function
}

/**************************************************************************************
> Function Name: del_name();
> Precondition: An object has been declared
> Postcondition: The unwanted node in the binary search tree is deleted
> Description: Mutator Function: This function calls the search function to find the
    node to be deleted. The function then rearranges the tree if needed, then deletes
    the unwanted node, maintaining the alphabetical order of the tree.
***************************************************************************************/
void bst::del_name(treenode*& loc_ptr, string item)
{

	if (loc_ptr == 0)                                                   // if pointer is NULL, there is no match
        {
            cout << "Item Not In Tree" << endl;
        }
	else if (loc_ptr->county_name > item)                               // if "item" is higher than the search item
        {
            del_name(loc_ptr->lchild, item);                            // recursive call to this function to the LEFT child
        }
	else if (loc_ptr->county_name < item)                               // if "item" is lower than the search item
        {
            del_name(loc_ptr->rchild, item);                            // recursive call to this fuction to the RIGHT child
        }
	else // if (loc_ptr->county_name == item)
        {
            treenode *ptr;                                              // declare a pointer to the BST

            if (loc_ptr->lchild == 0 && loc_ptr->rchild == 0)           // if the node to be deleted is a leaf
                {
                    delete loc_ptr;                                     // delete the leaf
                    loc_ptr = 0;                                        // set the pointer to the leaf to NULL
                    created_nodes--;                                    // decrement the # of created nodes
                }
            else if (loc_ptr->lchild == 0)                              // if greater child node pointer is NULL
                {
                    ptr = loc_ptr->rchild;                              // make pointer point to right child
                    delete loc_ptr;                                     // delete matching "item" node
                    created_nodes--;                                    // decrement the # of created nodes
                    loc_ptr = ptr;                                      // tie in the child node to the parent
                }
            else if (loc_ptr->rchild == 0)                              // if lesser child node pointer is NULL
                {
                    ptr = loc_ptr->lchild;                              // make pointer point to the left child
                    delete loc_ptr;                                     // delete matching "item" node
                    created_nodes--;                                    // decrement the # of created nodes
                    loc_ptr = ptr;                                      // tie in the child node to the parent
                }
            else  // if NEITHER child node is NULL
                {
                    ptr = inorder_succ(loc_ptr);                        // find inorder successor to the parent node and make the new pointer point to it

                    if (ptr->lchild == 0 && ptr->rchild == 0)           // if the inorder successor is a leaf
                        {
                            loc_ptr->county_name = ptr->county_name;            // put the county_name from inorder successor into the unwanted node
                            loc_ptr->population_size = ptr->population_size;    // put the population_size from inorder successor into the unwanted node
                            delete ptr;                                         // call the delete function to delete the unwanted node
                            ptr = 0;                                            // set the pointer to NULL
                            created_nodes--;                                    // decrement the # of created nodes
                        }
                    else if (ptr->lchild == 0)
                        {
                            loc_ptr->county_name = ptr->county_name;            // put the county_name from inorder successor into the unwanted node
                            loc_ptr->population_size = ptr->population_size;    // put the population_size from inorder successor into the unwanted node
                            loc_ptr->rchild = ptr->rchild;                      // tie in the right child to the BST
                            delete ptr;                                         // call the delete function to delete the unwanted node
                            ptr = 0;                                            // set the pointer to NULL
                            created_nodes--;                                    // decrement the # of created nodes
                        }
                    else if (ptr->rchild == 0)
                        {
                            loc_ptr->county_name = ptr->county_name;            // put the county_name from inorder successor into the unwanted node
                            loc_ptr->population_size = ptr->population_size;    // put the population_size from inorder successor into the unwanted node
                            loc_ptr->lchild = ptr->lchild;                      // tie in the right child to the BST
                            delete ptr;                                         // call the delete function to delete the unwanted node
                            ptr = 0;                                            // set the pointer to NULL
                            created_nodes--;                                    // decrement the # of created nodes
                        }
                    else // If (ptr->rchild != 0 && ptr->lchild != 0)
                        {
                            cout << "This condition should not exist in a BST" << endl;
                        }
                }
        }
}

/**************************************************************************************
> Function Name: search_tree();
> Precondition: The calling object has been declared
> Postcondition: A pointer to the node containing "item" is returned.
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it calls the Accessor Function search_tree() using root as an argument. This function
    returns a pointer to the node containing the string "item". If the item is not found,
    a NULL pointer is returned.
***************************************************************************************/
treenode* bst::search_tree(string item)
{
    cout << "Searching for: \'" << item << "\'" << endl;                // debug

	return search_tree(root, item);                                     // return the pointer from the function call to Accessor Function "search_tree"
}

/**************************************************************************************
> Function Name: search_tree();
> Precondition: An object has been declared
> Postcondition: A pointer to the node matching "item" is returned
> Description: Accessor Function: This function returns a pointer to the node
    containing the string "item". If the item is not found, a NULL pointer is returned.
***************************************************************************************/
treenode* bst::search_tree(treenode *loc_ptr, string item)
{
	if (loc_ptr != 0)                                                   // if the BST is not empty, or the pointer is not NULL, then traverse the tree
        {
            if (loc_ptr->county_name == item)                           // if "county_name" matches "item"
                {
                    return loc_ptr;                                     // return a pointer to the matching node
                }
            else if (loc_ptr->county_name > item)                       // If "county_name" is alphabetically lower than "item"
                {
                    return search_tree(loc_ptr->lchild, item);          // Recursive function call to traverse to the LEFT child
                }
            else                                                        // If "county_name" is alphabetically higher than "item"
                {
                    return search_tree(loc_ptr->rchild, item);          // Recursive function call to traverse to the RIGHT child
                }
        }
	else                                                                // The BST is empty, so we retun a NULL pointer
        {
            return loc_ptr;                                             // return null pointer if not found
        }
}

/**************************************************************************************
> Function Name: inorder_succ();
> Precondition: An object has been declared.
> Postcondition: A pointer is returned pointing to the inorder sucessor in the BST.
> Description: Accessor Function: This function takes a pointer argument to a node.
    The function then traverses the Binary Search Tree to find the inorder successor,
    which is the leftmost child node of the right child node of the node in the
    argument
***************************************************************************************/
treenode* bst::inorder_succ(treenode *loc_ptr)                          // finds the right child inorder successor to the specified node.
{
    cout << "\'Inorder_Successor\' called" << endl;

	treenode *ptr = loc_ptr->rchild;                                    // declare a pointer to the right child node

	while (ptr->lchild != 0)                                            // when ptr->lchild == 0, the bottom leftmost node is found
        {
            ptr = ptr->lchild;                                          // traverse the leftmost child nodes for the inorder successor
        }

	return ptr;                                                         // return pointer to the inorder successor (leftmost child node of the right child)
}

/**************************************************************************************
> Function Name: county_ranges();
> Precondition: The calling object has been declared.
> Postcondition: The accessor Function county_ranges() is called.
> Description: Auxiliary Function: This function can be called from the main, since root
    can't be accessed from outside the class. This function has access to root, so it just
    calls the Accessor Function county_ranges() using root as an argument.
***************************************************************************************/
void bst::county_ranges(const string& min_name, const string& max_name)
{
    // auxiliary function calls the other county_ranges function
    cout << "\'County Range Called\'" << endl;                          // DEBUG

    cout << "min_name = " << min_name << ", max_name = " << max_name << endl << endl;   // DEBUG

    county_ranges(root, min_name, max_name);                            // function call to the Accessor Function "county_ranges"

}

/**************************************************************************************
> Function Name: county_ranges();
> Precondition: An object has been declared.
> Postcondition: A formatted INCLUSIVE list of counties is printed to the screen.
> Description: Accessor Function: This function prints to the screen a formatted list
    of counties which INCLUDES all names from the "min_name" to the "max_name".
    1) If the arguments "min_name" and "max_name" contain only 1 character, example:
       If "min_name" = "C" and "max_name" = "P", then this function will print a
       formatted list containing all counties INCLUDING counties beginnning with "C" and
       "P". This uses the 1st condition "if (length == 1)".
    2) Otherwise, if the arguments are words: example: "min_name" = "Clay" and "max_name"
       = "Polk", the function will print the list INCLUDING counties from "Clay" to "Polk",
       which uses the last "else" statement.
***************************************************************************************/
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{

    cout.setf(ios::fixed);                                              // display values as fixed decimal notation (not e-notation)
    cout.setf(ios::left);                                               // set left justified text flag
    cout.precision(0);                                                  // display values with 0 decimal places.
    cout.width(20);                                                     // set width to 20 characters

    int length;                                                         // integer value representing # of characters
    length = max_name.length();
    string temp;                                                        // temp string holding the value of loc_ptr->county_name for parsing
    string first_char;                                                  // this string takes the value of the 1st character of the "temp" string

    if (loc_ptr == 0)
        {
            return;
        }
    else
        {
            temp = loc_ptr->county_name;                                // write county_name to the temp string
            first_char = temp[0];                                       // take the 1st character of the temp string and store to "first_char"
        }

    if (length == 1)                                                    // if function input arguments are 1 character, use this set of function calls
        {
            if (first_char > max_name)                                  // if the 1st character of county_name is HIGHER than max_name
                {
                    //cout << "(1) Else-If: > max = " << loc_ptr->county_name << endl;
                    county_ranges(loc_ptr->lchild, min_name, max_name); // recursive function call to the LEFT child node
                }
            else if (first_char < min_name)                             // if the 1st character of county_name is LOWER than min_name
                {
                    //cout << "(2) Else-If: < min = " << loc_ptr->county_name << endl;
                    county_ranges(loc_ptr->rchild, min_name, max_name); // recursive function call to the RIGHT child node
                }
            else                                                        // if the characters match
                {
                    //cout << "(3) Else: County Name = " << loc_ptr->county_name << endl;
                    county_ranges(loc_ptr->lchild, min_name, max_name);
                    cout << loc_ptr->county_name << loc_ptr->population_size << endl;
                    county_ranges(loc_ptr->rchild, min_name, max_name);
                }
        }
    else                                                                // if function input arguments are NOT 1 character, use this set of function calls
        {
            if (loc_ptr->county_name > max_name)                        // if the county_name is HIGHER than max_name
                {
                    //cout << "(4) Else-If: > max = " << loc_ptr->county_name << endl;
                    county_ranges(loc_ptr->lchild, min_name, max_name); // recursive function call to the LEFT child node
                }
            else if (loc_ptr->county_name < min_name)                   // if the county_name is LOWER than min_name
                {
                    //cout << "(5) Else-If: < min = " << loc_ptr->county_name << endl;
                    county_ranges(loc_ptr->rchild, min_name, max_name); // recursive function call to the RIGHT child node
                }
            else                                                        // if the county_name matches
                {
                    //cout << "(6) Else: County Name = " << loc_ptr->county_name << endl;
                    county_ranges(loc_ptr->lchild, min_name, max_name); // traverse leftmost nodes 1st before printing
                    cout << loc_ptr->county_name << loc_ptr->population_size << endl;
                    county_ranges(loc_ptr->rchild, min_name, max_name); // traverse rightmost nodes 2nd for inorder traversal
                }
        }
}

/**************************************************************************************
> Function Name: print_tree();
> Precondition: The calling object has been declared.
> Postcondition: The Accessor Function "print_tree()" is called.
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it just calls the Accessor Function print_tree() using root as an argument.
***************************************************************************************/
void bst::print_tree()
{
    cout << "\'Print_Tree\' called" << endl << endl;                    // Debug

	print_tree(root);                                                   // function call to Accessor Function "print_tree"
}

/**************************************************************************************
> Function Name: print_tree();
> Precondition: An object has been declared.
> Postcondition: The contents of the BST is printed to the screen.
> Description: Accessor Function: This function can be called from the main, since root
    can't be accessed from outside the class. This function has access to root,
    so it just calls the Accessor Function print_tree() using root as an argument.
***************************************************************************************/
void bst::print_tree(treenode* loc_ptr)
{
    cout.setf(ios::fixed);                                              // display values as fixed decimal notation (not e-notation)
    cout.setf(ios::left);                                               // set left justified text flag
    cout.precision(0);                                                  // display values with 0 decimal places.
    cout.width(20);                                                     // set width to 20 characters

	if (loc_ptr != 0)
        {
            print_tree(loc_ptr->lchild);                                // traverse leftmost nodes 1st

            cout << loc_ptr->county_name << loc_ptr->population_size << endl;

            print_tree(loc_ptr->rchild);                                // traverse rightmost nodes 2nd
        }
    if (root == 0)                                                      // if the BST is empty
        {
            cout << "Tree is Empty...Nothing to print" << endl;         // There is nothing to print
        }
}

/**************************************************************************************
> Function Name: sorted_info()
> Precondition: The calling object has been declared.
> Postcondition: The contents of the Binary Search Tree are output to a file
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it calls the Accessor Function sorted_info() using root as an argument.
    This function declares an ofstream object and opens the file "county_info.txt",
    and calls the Accessor Function sorted_info() using the ofstream object "file_out"
    and "root" as an argument.
***************************************************************************************/
void bst::sorted_info()                                                 // auxiliary function that calls accessor function
{
    cout << "\'Sorted_info called\'" << endl;

    ofstream file_out;                                                  // declare ofstream object to read file
    file_out.open("county_info.txt");                                   // open file to read

    if(file_out.fail())
        {
            cout << "Sorted_Info failed to open output file" << endl;
            exit(1);
        }

    sorted_info(file_out, root);                                        // call accessor function

    file_out.close();                                                   // close file after sorting is finished
}

/**************************************************************************************
> Function Name: sorted_info()
> Precondition: An object has been declared
> Postcondition: All data fields of the BST is output to file and organized alphabetically.
> Description: Accessor Function: This function recieves a pointer argument (loc_ptr) and an
    ofstream object argument (f_out) from the Auxiliary function sorted_info(), then
    inorder traverses the BST, writing each data field to the output stream.
***************************************************************************************/
void bst::sorted_info(ostream& f_out, treenode*& loc_ptr)
{
    // traverse the tree inorder, then
    // prints each county record to a file called “county_info.txt” sorted by county name.

    f_out.setf(ios::fixed);                                             // display values as fixed decimal notation (not e-notation)
    f_out.setf(ios::left);                                              // set left justified text flag
    f_out.precision(0);                                                 // display values with 0 decimal places.
    f_out.width(20);

	if (loc_ptr != 0)
        {
            sorted_info(f_out, loc_ptr->lchild);                        // traverse leftmost nodes 1st

            f_out << loc_ptr->county_name << loc_ptr->population_size << endl;

            sorted_info(f_out, loc_ptr->rchild);                        // traverse rightmost nodes 2nd
        }
}

/**************************************************************************************
> Function Name: empty_tree()
> Precondition: The calling object has been declared.
> Postcondition: The Mutator Function "empty_tree()" is called.
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it calls the Accessor Function sorted_info() using root as an argument. This function
    calls the Mutator Function empty_tree().
***************************************************************************************/
void bst::empty_tree()
{

    cout << "\'Empty_Tree Called\'" << endl;                            // debug

    empty_tree(root);                                                   // function call to Mutator Function
}

/**************************************************************************************
> Function Name: empty_tree()
> Precondition: An object has been declared
> Postcondition: All BST nodes are deleted until the tree is empty.
> Description: Mutator Function: This function takes a pointer argument (root by default),
    deletes all child nodes and the node originally pointed to by the pointer argument.
***************************************************************************************/
void bst::empty_tree(treenode*& loc_ptr)
{

	if (empty())
        {
            cout << "Tree is Empty..." << endl << endl;
        }
    else // if tree not empty
        {
            //cout << "Non-Empty Tree" << endl;                         // debug

            if(loc_ptr->lchild != 0)                                    // if the left child node is not NULL
                {
                    empty_tree(loc_ptr->lchild);                        // recursive function call to keep traversing to the left child node
                }
            if (loc_ptr->rchild != 0)                                   // of the right child node is not NULL
                {
                    empty_tree(loc_ptr->rchild);                        // recursive function call to keep traversing to the right child node
                }
            delete loc_ptr;                                             // delete the bottom most node
            loc_ptr = 0;                                                // set that pointer to NULL
            created_nodes--;                                            // decrement the number of created nodes
        }
}

/**************************************************************************************
> Function Name: total_node_count()
> Precondition:
> Postcondition:
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it just calls the Accessor Function total_node_count() using root as an argument.
    This function calls the Accessor function and returns the integer "total_nodes" to the
    main function, which is returned to this function from the Accessor Function.
***************************************************************************************/
int bst::total_node_count()
{
    //cout << "Node Counter called" << endl;                            // debug

    total_nodes = total_node_count(root);                               // store total number of nodes to private variable

    return (total_nodes);
}

/**************************************************************************************
> Function Name: total_node_count()
> Precondition: An object has been declared.
> Postcondition: The total number of nodes in the BST is calculated independently.
> Description: Accessor Function: This function recursively traverses the entire BST and
    performs an independent count of all nodes and returns that number as an integer to
    the auxiliary function.
***************************************************************************************/
int bst::total_node_count(treenode*& loc_ptr)
{

    if (loc_ptr == 0)                                                   // trivial case
        {
            return 0;
        }
    else
        {
            return (1 + total_node_count(loc_ptr->rchild) + total_node_count(loc_ptr->lchild));
        }
}

/**************************************************************************************
> Function Name: created_node_count()
> Precondition: An object has been declared.
> Postcondition: The private variable "created_nodes" in the BST is returned as an integer.
> Description: Accessor Function: This function accesses the state of the class, and
    returns the integer value "created_nodes" to the main function.
***************************************************************************************/
int bst::created_node_count()
{

    return (created_nodes);                                             // returns # of nodes created/deleted by "insert()", "del_name()", and "empty_tree()"

}

/**************************************************************************************
> Function Name: root_node()
> Precondition: The calling object has been declared.
> Postcondition: The Accessor function "root_node()" is called.
> Description: Auxiliary / Accessor Function: This function can be called from the main,
    since root can't be accessed from outside the class. This function has access to root,
    so it calls the Accessor Function root_node() using root as an argument. This function
    calls the function "root_node()" using the private data pointer "root" as an
    argument.
***************************************************************************************/
void bst::root_node()
{
    cout << "\'Root_Node\' Called" << endl;

    root_node(root);
}

/**************************************************************************************
> Function Name: root_node()
> Precondition: An object has been declared
> Postcondition: The "county_name" of the root node and both its child nodes are printed
    to the screen.
> Description: Accessor Function: This function is called by the Auxiliary Function and
    displays the variable "county_name" contents of the BST root node, and both its child
    nodes. If any or all of the nodes are NULL, then the appropriate message is displayed.
***************************************************************************************/
void bst::root_node(treenode* loc_ptr)
{
    if (loc_ptr != 0)
        {
            cout << "root->county_name = " << root->county_name << endl;

            if (loc_ptr->lchild != 0)
                {
                    cout << "root->lchild->county_name = " << root->lchild->county_name << endl;
                }
            else
                {
                    cout << "root->lchild is EMPTY" << endl;
                }
            if (loc_ptr->rchild != 0)
                {
                    cout << "root->rchild->county_name = " << root->rchild->county_name << endl;
                }
            else
                {
                    cout << "root->rchild is EMPTY" << endl;
                }
        }
    else
        {
            cout << "The Binary Search Tree is EMPTY" << endl;
        }
}