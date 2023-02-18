/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 02/26/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT
Description: This program manages a linked list stack of objects, each containing a string object
named "data" and a pointer named "next". ----------------
*********************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;
void welcome();

#include "stack.h"

int main()
{

    welcome();                                  // single line function call in main

    return 0;
}

void welcome()
{

    cout << "=>> Postfix to Infix Conversion <<=" << endl << endl;

    stack equation;                             // declare a stack object

    equation.postfix_to_infix();                // call void function with the stack object

}