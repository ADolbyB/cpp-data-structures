/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Joel Brigida             Email: j*******9@f**.edu                    TOTAL POINTS:  25                DUE DATE: Friday 01/22/2021
COURSE: Data Structures COP 3530-001                                       Professor:  Dr. Bullard
Assignment Name:  Assignment #1
Description:  This program manages a dynamic array of records.
******************************************************************************************************************************************************/

#include <iostream>                                                             // directive for cin, cout, >> and <<
#include <fstream>                                                              // directive for File i/o file stream
#include <string>                                                               // directive for string class.
#include "state.h"                                                              // include our custom header with the class definition

using namespace std;

int main()
{
    cout << "***********************************************************************************\n";
	cout << "TEST 1:  Testing the default constructor, Is_Full, double_size, and Print_ALL\n\n";
	state_class S;          // declare object "S" of type "state_class (calls default constructor)
	S.Print_ALL();          // prints default values of object "S" to the screen
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 1:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;


	cout << "***********************************************************************************\n";
	cout << "TEST 2:  Testing the Remove, Is_Empty, Search, and Print_ALL\n\n";
	S.Remove("Alabama");    // Removes the array values from object "S" in the array index that matches the string value "Alabama"
	S.Remove("Florida");    // Removes the array values from object "S" in the array index that matches the string value "Florida"
	S.Remove("Wyoming");    // Removes the array values from object "S" in the array index that matches the string value "Wyoming"
	S.Print_ALL();          // Prints the modified array with the removed values to the screen
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 2:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 3 Testing operator+, Is_Full, double_size, and Print_ALL\n\n";
	population_record r;    // declares a new object "r" of type "population_record" and calls default constructor;
	r.state_name = "Alabama";   // adds a string value to object "r" private variable "state_name"
	r.population = 1111111;     // adds a double value to object "r" private variable "population"
	S + r;  // adds new object values in "r" to object "S" that contains pop_DB via the overloaded "operator+" function
	r.state_name = "Florida";
	r.population = 99999999;
	S + r;
	r.state_name = "Wyoming";
	r.population = 222222;
	S + r;
	S.Print_ALL();  // Prints the modified array with the appended values to the screen
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 3: \n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;


	cout << "***********************************************************************************\n";
	cout << "TEST 4:  Testing Print_Range\n\n";
	int min = 500000, max = 1500000;
	cout << "List of States with Population Sizes between " << min << " and " << max << " inclusive :" << endl << endl;
	S.Print_Range(min, max);    // prints the state names and populations between the min and max declared values
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 4:\n";
	cout << "***********************************************************************************\n";
	cout << endl << endl << endl;

	cout << "***********************************************************************************\n";
	cout << "TEST 5:  Testing State_Count\n\n";
	min = 500000;
	max = 1500000; // counts the number of states on the list between "min" and "max" and outputs a number
	cout << "Number of States with Population Sizes between " << min << " and " << max << " (inclusive) equals: " << S.State_Count(min, max) << endl;
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 5:\n";
	cout << "***********************************************************************************\n";

	cout << "***********************************************************************************\n";
	cout << "TEST 6:  copy constructor and Print_ALL\n\n";
	state_class New = S;    // declares an object "New" of type "state_class" and calls the copy constructor.
	New.Print_ALL();    // prints the values of the new copied array to the screen.
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 6:\n";
	cout << "***********************************************************************************\n";

	cout << "***********************************************************************************\n";
	cout << "TEST 7:  Sort and Print_ALL\n\n";
	New.Sort(); // runs the "sort" function on the new copied object and all array values are organized alphabetically.
	New.Print_ALL();    // prints the new sorted array to the screen
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 7:\n";
	cout << "***********************************************************************************\n";

	cout << "***********************************************************************************\n";
	cout << "TEST 8:  Print_ALL_To_File\n\n";
	New.Print_ALL_To_File("state_data_update.txt");     // prints the new copied object to a file named "state_data_update.txt"
	cout << "***********************************************************************************\n";
	cout << "END OF TEST 8:\n";
	cout << "***********************************************************************************\n";

	return 0;
}