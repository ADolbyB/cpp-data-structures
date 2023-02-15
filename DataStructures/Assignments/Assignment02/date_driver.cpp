/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 1/29/2021                     Due Time: 11:59pm
Total Points: 25                        Assignment 2: Date program for Module 4
Description: This program prints out dates in a specified format and has the capability to
check them for a valid MM/DD/YYYY format, and checks for leap years.
*********************************************************************************************/

#include <iostream>
#include "date.h"

using namespace std;

int main()
{

	Date myDate;                                                    // Declare and initialize object "myDate" and calls Default Constructor
	Date herDate(11, 14, 1953);                                     // Declare and initialize object "herDate" and calls Explicit Constructor
	Date test1Date(25, 1, 1982);                                    // Generates error message for an invalid month value
	Date test22Date(2, 29, 2020);                                   // Acceptable input: should recognize a leap year
	Date test3Date(2, 30, 2021);                                    // Generates error message for an invalid day value
	Date test4Date(1, 25, 0000);                                    // Generates error message for an invalid year value
	Date test5Date(80, 40, 0000);                                   // Generates error message for an invalid month, day and year

	herDate.display();                                              // Displays the values of the object "herDate"
	cout << herDate.getMonth() << endl;                             // calls accessor function to print the month variable of "herDate"
	cout << herDate.getDay() << endl;                               // calls accessor function to print the day variable of "herDate"
	cout << herDate.getYear() << endl;                              // calls accessor function to print the Year variable of "herDate"
	myDate.setMonth(11);                                            // calls mutator function to set the Month Value of "myDate"
	myDate.setDay(12);                                              // calls mutator function to set the Day Value of "myDate"
	myDate.setYear(2015);                                           // calls mutator function to set the Year Value of "myDate"

	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;   // calls operator<< to print all values of the three objects.

	return 0;

}