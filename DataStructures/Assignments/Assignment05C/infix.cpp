/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: COP3530: Data Structures        Professor: Dr. Lofton Bullard
Due Date: 03/03/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT

Description: This program manages a linked list stack of objects, each containing a string object
named "data" and a pointer named "next".
*********************************************************************************************/

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;
typedef string stack_element;

int main()
{
    string postfix; // string variable to store the users input
    string YorN = "y";
    
    while (YorN == "y" || YorN == "Y")
    {
        cout << "Please input a postfix expression with spaces in between characters: " << endl;
        getline(cin, postfix);
        
        stack cStack = stack(postfix);
        
        cStack.infixConversion();
        
        cout << " Would You Like To Perform Another Conversion? (y/n)"<< endl;
        getline(cin, YorN);
    }
    cout << "See You Next Time!" << endl << endl;
    
    return 0;
}