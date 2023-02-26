/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: COP3530: Data Structures        Professor: Dr. Lofton Bullard
Due Date: 03/03/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT
Description: This program manages a linked list stack of objects, each containing a string object
named "data" and a pointer named "next". 
*********************************************************************************************/

//includes that may or may not be necessary.
#include "stack.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef string stack_element; //makes the name stack_element a valid type.

/*************************************************************************************
Function Name: stack()
Precondition: An object has been declared with no arguments.
Postcondition: An object is created and initialized to 0 values, since it doesn't
contain any data yet.
Description: Default Constructor: The default constructor initializes state variables
to default values.
*************************************************************************************/
stack::stack(string s)
{
    // sets all necessary values to 0 before filling the stack.
    (*this).s_top = 0;
    (*this).operandCount = 0;
    (*this).operatorCount = 0;
    
    // cout << "\nExplicit constructor called." << endl;
    for(int i = s.length() - 1; i >= 0; i--) // iterates through the string.
    {
        // sets a temporary string to an empty value and adds the character from s at index i for its value.
        string tempString = "";
        tempString += s[i];
        
        // if the string is not a space
        if(tempString != " ")
        {
            // adds tempString to the top of the stack.
            (*this).push(tempString);
            
            // if the pushed value is an operator
            if(top() == "+"|| top() == "-" || top() == "*" || top()== "/")
                operatorCount++; //increases the count of operatorCount.
            else // if the pushed value is anything else.
                operandCount++; //increases the count of operandCount.
            
            // cout << "Node: " << tempString << endl;  //Debug
        }
    }
}

/*************************************************************************************
Function Name: ~stack();
Precondition: An object has already been declared and initialized.
Postcondition: The object is deleted by calling pop() and dynamic memory is freed.
Description: Destructor: The destructor will de-allocate all memory allocated for each node.
*************************************************************************************/
stack::~stack()
{
    // cout << "Inside !stack \n";
    while(s_top != 0) // iterates through the stack and deletes the whole stack.
    {
        pop();
    }
}

/*************************************************************************************
Function Name: pop()
Precondition: a stack must have been declared.
Postcondition: the top value will have been removed from the stack.
Description: pops the top node off of the list.
*************************************************************************************/
string stack::pop()
{
    // cout << "Inside pop \n";
    stack_node *p; // creates a pointer p.
    string temp;
    
    if (s_top != 0) // checks to see if there is any nodes
    {
        p = s_top; // sets the p to the value of s_top.
        s_top = s_top->next;  // iterates to the next item in the stack.
        
        temp = p->data;
        delete p; // deletes p from the computer.
    }
    return temp; // returns temp
}

/*************************************************************************************
Function Name: push()
Precondition: a stack must have been declared.
Postcondition: a new item will be at the top of the stack.
Description: pushes an item onto the top of the stack.
*************************************************************************************/
void stack::push(const stack_element & item)
{
    // cout << "Inside push \n";
    stack_node *p = new stack_node; // creates a temporary stack node.

    p->data = item; // sets the temporary data to the value of item.
    p->next = s_top; // makes the former top be the following next value.
    s_top = p; // sets the new top to the value at p.
    
}

/*************************************************************************************
Function Name: print()
Precondition: a stack must be declared.
Postcondition: the stack will be printed.
Description: prints the stack.
*************************************************************************************/
string stack::print()
{
    // cout << "Inside print \n";
    string tempString = ""; // creates a temporary string.
    for(stack_node *p = s_top; p != 0; p = p->next) // iterates through the stack that starts at location "s_top".
    {
        tempString += p->data; // adds the data at p to the tempString.
    }
    return tempString; // outputs the whole stack as tempString.
}

/*************************************************************************************
Function Name: top();
Precondition: An object has already been declared and initialized.
Postcondition: The value at the top of the stack is returned, unless the stack is empty.
In that case, an empty string is returned.
Description: Accessor Function: This function retrieves the value of the data at the
top of the stack. If the stack is empty, then an empty string is returned.
*************************************************************************************/
stack_element stack::top()
{
    // cout << "Inside top \n";

    if (s_top == 0) // if the top is a null character
    {
        exit(1);
    }
    else // if the top of the stack has a  value
    {
        return s_top->data; // returns the data stored at top.
    }
}

/*************************************************************************************
Function Name: stack()
Precondition: A stack must already be declared.
Postcondition: A copy will be taken of the stack in the argument
Description: Copy Constructior: copies the stack in the argument to the stack that is using the function.
*************************************************************************************/
//stack::stack(const stack & Org)
//{
//    cout<<"Inside the Copy Constructor\n";
//
//    (*this).s_top = 0;
//    (*this).operandCount = 0;
//    (*this).operatorCount = 0;
//
//    stack temp;
//    stack_node *p=Org.s_top;
//    while(p!=0)
//    {
//        temp.push(p->data);
//        p=p->next;
//    }
//
//    p = temp.s_top;
//    while (p != 0)
//    {
//        (*this).push(p->data);
//        p = p->next;
//    }
//}

/*************************************************************************************
Function Name: empty()
Precondition: a stack must be declared.
Postcondition: a boolean value will have been returned.
Description: checks to see if the stack is empty.
*************************************************************************************/
bool stack::IsEmpty() const // Definition of IsEmpty()
{
    return (s_top == 0); // if s_top == 0, then the stack is empty and returns TRUE
}

/*************************************************************************************
Function Name: infixConversion()
Precondition: a string must be declared and called.
Postcondition: the expression will have been converted into infix notation.
Description: Converts the postfix expression into an infix expression.
*************************************************************************************/
void stack::infixConversion()
{
    
    if(IsEmpty()) //if the string is empty.
    {
        cout << "Error: You entered an empty string" << endl; //makes the expression the same as before.
    }
    else if(s_top->next == NULL && (top() == "+" || top() == "-" || top() == "*" || top()== "/")) // Only Operator Entered
    {
        cout << "too many operators not enough operands"<< endl;
    }
    else if(s_top->next == NULL) // Only an Operand Entered
    {
        if(!(top() == "+" || top() == "-" || top() == "*" || top()== "/"))
        {
            cout << "(" << top() << ")" << endl;
        }
    }
    else if(operatorCount != (operandCount - 1)) // imbalance of operators and operands.
    {
        if(operatorCount < (operandCount - 1)) // too many operands and not enough operators
            cout << "Too many operands not enough operators" << endl;
        if(operatorCount > (operandCount - 1)) // too many operators and not enough operands
            cout << "Too many operators not enough operands" << endl;
    }
    else
    {
        for(stack_node *p = s_top; p != 0; p = p->next)
        {
            
            if(p->data == "+" || p->data == "-" || p->data == "*" || p->data == "/")
            {
                string num1 = top(); //pops a character out of the stack to compute
                pop();
                string num2 = top(); //pops a character out of the stack to compute
                pop();
                // cout << "(" + num1 + " " + throwAway +" " + num2 + ")";
                string throwAway = top(); //pops the operator.
                
                // cout << "num1: " << num1 << endl << "num2: " << num2 << endl << "throwAway: " << throwAway << endl; //debug
                if((throwAway == "+" || throwAway == "-" || throwAway == "*" || throwAway == "/"))
                {
                    pop();
                    (*this).push("(" + num1 + " " + throwAway +" " + num2 + ")"); // pushes the equation back into the stack.
                }
                else
                {
                    pop(); // pops throwAway of the stack.
                    
                    string num3 = throwAway;
                    string newThrowAway = top();
                    
                    if((newThrowAway == "+" || newThrowAway == "-" || newThrowAway == "*" || newThrowAway == "/"))
                    {
                        pop();
                        (*this).push("(" + num2 + " " + newThrowAway +" " + num3 + ")"); // pushes the equation back into the stack.
                        push(num1);
                    }
                }
            }
        }
        cout << "Infix Expression: " << (*this).print() << endl;
    }
}