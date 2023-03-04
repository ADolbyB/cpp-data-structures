/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file for a single linked list
 * It instantiates a Linked List, adds and removes nodes
*/

#include <iostream>
#include <string>

#include "slist.h"

using namespace std;

int main()
{
	LINKED_LIST_CLASS L;

	cout << "Part 1: construct a list with insert:" << endl;
	L.Insert("hello");
	L.Insert("bye");
	L.Insert("good");
	L.Insert("bad");
	L.Print();
	L.node_counter();

	cout << endl << "Part 2: Remove \'apple\'" << endl;
	L.Remove("apple");
	L.Print();
	L.node_counter();

    cout << endl << "Part 3: Remove \'hello\'" << endl;
	L.Remove("hello");
	L.Print();
	L.node_counter();

    cout << endl << "Part 3: Remove \'zebra\'" << endl;
	L.Remove("zebra");
	L.Print();
	L.node_counter();

    cout << endl << "Part 4: Remove \'bye\'" << endl;
	L.Remove("bye");
	L.Print();
	L.node_counter();

    cout << endl << "Part 5: Remove \'good\'" << endl;
	L.Remove("good");
	L.Print();
	L.node_counter();

    cout << endl << "Part 6: Remove \'bad\'" << endl;
	L.Remove("bad");
	L.Print();
	L.node_counter();

	//L.~LINKED_LIST_CLASS();           // redundant call to the destructor (irrelevent?)

	return 0;
}