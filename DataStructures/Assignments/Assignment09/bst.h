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
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class treenode                                                  // each node in the BST
{
    public:

        string county_name;                                     // string data for each node
        double population_size;                                 // population data for each node
        treenode *lchild, *rchild;                              // pointers to left and right child nodes
};

class bst
{
    public:

        bst();                                                  // stores the data file (“county_data.txt”) into initial bst.
        ~bst();                                                 // destructor - checks if the tree is empty
        bool empty();                                           // returns TRUE if bst is NULL; otherwise FALSE is retured.
        void insert(const string& item, const double& population);              // auxiliary function can be called from main
        void insert(treenode*&, const string& item, const double& population);  //inserts an item into the bst - can access private ROOT
        void del_name(string item);                             // auxiliary function can be called from main
        void del_name(treenode*& loc_ptr, string item);         // function deletes item from bst - can access private ROOT
        treenode* search_tree(string item);                     // auxiliary fucntion can be called from main
        treenode* search_tree(treenode*, string item);          // returns a pointer to node in bst w/ county name that matches item.
        treenode* inorder_succ(treenode* );                     // returns a pointer to the inorder successor, based on county name.
        void county_ranges(const string& min_name, const string& max_name);     // auxiliary function.
        void county_ranges(treenode*&, const string& min_name, const string& max_name); // prints all county names between min_name and max_name, inclusive.
        void print_tree();                                      // auxiliary function.
        void print_tree(treenode* );                            // prints each county record to the screen sorted by county name.
        void sorted_info();                                     // auxiliary function.
        void sorted_info(ostream&, treenode*& );                // prints each county record to a file called “county_info.txt” sorted by county name”.
        void empty_tree(treenode*& );                           // auxiliary function can be called from main
        void empty_tree();                                      // de-allocate all nodes that were allocated to the bst
        void parse_file(string& text_line, string& the_place, string& the_pop); // function which parses the data in the file before insertion into the tree
        void root_node();                                       // auxiliary function can be called from main
        void root_node(treenode* );                             // displays the content of the root node and both child nodes
        int total_node_count();                                 // auxiliary function can be called from main
        int total_node_count(treenode*& );                      // counts # of nodes in tree and stores the number to "total_nodes"
        int created_node_count();                               // auxiliary function can be called from main - returns the integer "created_nodes".

    private:

        treenode *root;                                         // pointer to the ROOT node
        int created_nodes;                                      // integer variable that stores total number of treenodes using "insert", "del_name" and "empty_tree".
        int total_nodes;                                        // separate count of the nodes counted by the "node_counter" functions.

};

#endif // BST_H_INCLUDED