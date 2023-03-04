/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file file for a single linked list
 * In this Driver, a Linked list is instantiated and nodes are added and removed.
*/


#include <iostream>
#include <string>

#include "list.h"

using namespace std;

int main()
{
	LINKED_LIST_CLASS L;
	L.Print();

	L.Insert_FRONT('A');
	L.Insert_FRONT('Z');
	L.Insert_BACK('X');
	L.Insert_FRONT('3');
	L.Insert_FRONT('2');
	L.Insert_BACK('9');
	L.Print();

	L.Remove('X');
	L.Print();

	L.Remove('A');
	L.Print();

	L.Remove('9');
	L.Print();
	
	return 0;
}