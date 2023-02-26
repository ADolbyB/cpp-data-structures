/*****************************************************************************
    P R O G R A M	H E A D E R

    Name:	Joel Brigida

    Z#:	Z***************
    Instructor:	Dr. Bullard
    Class:	COP3530: Data Structures
    Term:	Spring 2021
    Assignment #7 (vlist)
    Due Date:	March 19, 2021
    Due Time:	11:59PM
    Points:	25

    Description: This program manages a vector by performing the following functions:
    (1) Allocate and de-allocate memory, insert in order & remove.
    (2) Implement a default constructor and a copy constructor.
    (3) Implement an insert function to add a string, in order, into a vector
    (4) Implement a remove function to delete a string from a vector

******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "vlist.h"

using namespace std;

int main()
{

	//Testing default constructor
	cout << "***********************************************************" << endl;
	cout << "Test1: Testing default constructor: " << endl;
	vlist String_List;
	cout << "*****************End of Test1******************************" << endl;
	cout << endl << endl;
	//Testing functionality for string list
	cout << "***********************************************************" << endl;
	cout << "Test2: Testing Insert:" << endl << endl;
	String_List.insert("Hello");
	String_List.insert("Zebra");
	String_List.insert("Good_Bye");
	String_List.insert("Space");
	String_List.insert("No_One");
	String_List.print();
	cout << "*****************End of Test2******************************" << endl;
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 3: Testing copy constructor for string:" << endl << endl;
	vlist Copied_String = String_List;
	//cout << "Printing Copied_String: " << endl;
	Copied_String.print();
	//cout << "Printing String_List: " << endl;
	String_List.print();
	cout << "*****************End of Test3******************************" << endl;
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 4: Testing Remove for string: " << endl << endl;
	cout << "Testing Search and IsEmpty also\n";
	cout << "Removing from String_List:" <<  endl;
	String_List.remove("Zebra");
	String_List.print();                                                  // debug
	String_List.remove("Good_Bye");
	String_List.print();                                                  // debug
	String_List.remove("Hello");
	String_List.print();                                                  // debug
	String_List.remove("No_One");
	String_List.print();                                                  // debug
	String_List.remove("Space");
	String_List.print();                                                  // debug
	String_List.remove("Hello");
	String_List.print();                                                  // debug

    cout << "Is Object \'String_List\' Empty?" << endl;             // debug
	if (String_List.isEmpty())
        {
            cout << "String_List is Empty!" << endl;
        }
	else
        {
            cout << "String_List is NOT Empty!" << endl;
        }
	cout << endl << "*****************End of Test4******************************" << endl;
	cout << endl << endl;
	cout << "Leaving MAIN: destructor will be called" << endl;

	return 0;
}