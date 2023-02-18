/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 03/05/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT -
Description: This program takes a user entered string expression as a postfix expression, and
uses the stack to convert the postfix expression to a proper infix expression with parenthesis.
The program manages a stack of objects, each containing a string object
named "data" and a pointer named "next".
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

    welcome();

    return 0;
}

void welcome()
{

    cout << "=>> Postfix to Infix Conversion <<=" << endl << endl;

    stack equation;                             // declare a stack object

    equation.postfix_to_infix();                // call void function with the stack object

    cout << endl << "See you next time!!" << endl << endl;

}