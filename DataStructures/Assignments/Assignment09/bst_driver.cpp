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
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;

int main()
{

	cout << "**************************************************************" << endl;
	cout << "Test1: default constuctor" << endl;

	bst myTree;

	cout << "Print contents of bst inorder to the screen" << endl << endl;
	myTree.print_tree();
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	cout << "*************End Test1*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test2: insert" << endl;

	myTree.insert("New County", 234658);
	cout << endl << "Print contents of bst inorder to the screen" << endl << endl;;
	myTree.print_tree();
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	cout << "*************End Test2*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test3: county_ranges" << endl;
	cout << endl << endl;
	// myTree.root_node();                                                                     // JB: DEBUG
	// cout << endl << endl;
	cout << "Print contents of bst range between B and K inorder to the screen" << endl << endl;
	myTree.county_ranges("B","K");
	cout << endl << endl;
	// myTree.county_ranges("Clay","Polk");                                                    // JB: DEBUG
	// cout << endl << endl;
	// myTree.county_ranges("C","P");                                                          // JB: DEBUG
	cout << "*************End Test3*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test4: del_name" << endl;
	myTree.del_name("Miami Dade"); // node has ONE RIGHT child Node
	cout << endl << "Print contents of bst inorder, with Miami Dade removed, to the screen" << endl << endl;
	myTree.print_tree();
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	// myTree.del_name("Gulf");                                                                // JB: DEBUG: node has ONE LEFT child Node
	// myTree.print_tree();                                                                    // JB: DEBUG
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	// myTree.del_name("Alachua");                                                             // JB: DEBUG: node is a LEAF
	// myTree.print_tree();                                                                    // JB: DEBUG
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	// myTree.del_name("Lake");                                                                // JB: DEBUG: ROOT node w/ 2 child nodes
	// myTree.print_tree();                                                                    // JB: DEBUG
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	// myTree.root_node();                                                                     // JB: DEBUG
	cout << "*************End Test4*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test5: sorted_info" << endl << endl;
	cout << "Print contents of bst inorder to the output file, county_info.txt, with name and associated population size shown" << endl << endl;
	myTree.sorted_info();
	cout << "*************End Test5*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test6: empty_tree" << endl << endl;
	myTree.empty_tree();
	cout << endl << "Print contents of an empty bst to the screen" << endl << endl;;
	myTree.print_tree();
	// cout << endl << "MAIN: Total Node Count = " << myTree.total_node_count() << endl;       // JB: DEBUG
	// cout << endl << "MAIN: Created Node Count = " << myTree.created_node_count() << endl;   // JB: DEBUG
	cout << "*************End Test6*****************************************" << endl;
	cout << endl << endl;

	return 0;
}