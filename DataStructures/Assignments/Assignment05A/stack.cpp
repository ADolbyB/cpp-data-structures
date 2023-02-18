/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 02/26/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 5: Stack ADT
Description: This program manages a stack of string objects, each containing a string object
named "data" and a pointer named "next". ----------------
*********************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <limits>                   // numeric_limits

using namespace std;

#include "stack.h"

/*************************************************************************************
Function Name: stack()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
stack::stack()
{
    cout << "* Default Constructor Called *" << endl;

    s_top = 0;                                // sets top of the new stack to NULL (since there are no elements in it the new object
    count = 0;
}

/*************************************************************************************
Function Name: ~stack()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Destructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
stack::~stack()
{
    cout << "* Destructor Called *" << endl;

	while(s_top != 0)
        {
            pop();
        }
}

/*************************************************************************************
Function Name: push()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
void stack::push(const stack_element& item)
{
	cout << "\'Push\' Called" << endl;                          // works for an empty or non-empty stack

	stack_node *p = new stack_node;                             // allocate a new stack node with pointer
	count++;

	p->data = item;                                             // assign the input item to the data field
	p->next = s_top;                                            // assign the next field to the current *s_top pointer
	s_top = p;                                                  // move the *s_top pointer up a node to *p (the new top of stack)

}

/*************************************************************************************
Function Name: pop()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
void stack::pop()
{

    cout << "\'Pop\' Called" << endl;

	stack_node *p;                                              // declare stack_node pointer

	if (s_top != 0)                                             // pop only if the stack is not empty
        {
            p = s_top;                                          // point *p at the top of the stack
            s_top = s_top->next;                                // move *s_top to the next one down the list
            delete p;                                           // delete the top node in the stack.
            count--;
        }
    else // if stack is empty and pop() is called
        {
            //cout << "Stack is empty..." << endl << endl;        // debug
        }

}

/*************************************************************************************
Function Name: top()
        Retrieve value at top of stack (if any).
        Precondition:  Stack is nonempty
        Postcondition: Value at top of stack is returned, unless
        the stack is empty; in that case, an error message is
        displayed and a "garbage value" is returned.
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
stack_element stack::top()
{
	cout << "\'Top\' Called" << endl;

	if (s_top == 0)
        {
            cout << "Stack Empty: No data to return" << endl;   // if the stack is empty, then a message is displayed
            return ("");
        }
	else
        {
            return s_top->data;                                 // otherwise returns the top value of the stack as a TYPEDEF stack_element
        }
}

/*************************************************************************************
Function Name: empty()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
bool stack::empty() const                                       // Definition of empty()
{

    return (s_top == 0);                                        // if s_top == 0, then the stack is empty and returns TRUE

}

/*************************************************************************************
Function Name: postfix_to_infix()
Precondition: An object has been declared in the main with no arguments.
Postcondition: An object is created and initialized to null, since it doesn't contain any data.
Description: Default Constructor: The default constructor will initialize your state variables.
The front of the linked list is initially set to NULL or 0; this implies a non-header node
implementation of the link list.
*************************************************************************************/
void stack::postfix_to_infix()
{

    char user_choice;                                                   // variable for user to repeat the equation conversion

    string right_side_eq = "";                                          // This becomes the right side of the equation
    string left_side_eq = "";                                           // This becomes the left side of the equation
    string left_plus_right = "";                                        // string to concatenate the left and right expressions into
    string temp_string = "";                                            // temp string to concatenate operand names into by for loop

    string postfix_entry;                                               // string variable for user entered postfix string
    string converted_infix;                                             // string object after conversion to infix

    do
    {
        cout << endl << "Press Enter To Continue:" << endl;
        cin.ignore(numeric_limits<int>::max(),'\n');

        cout << "Enter a postfix expression with spaces:" << endl;
        getline(cin, postfix_entry);

        if(postfix_entry == "" || postfix_entry == " ")
            {
                converted_infix = postfix_entry;                         // condition if no operands or operators are entered.
            }
        else if(postfix_entry == "*" || postfix_entry == "/" || postfix_entry == "+" || postfix_entry == "-")
            {
                converted_infix = "Too many operators and not enough operands...";
            }
        else
            {
                int i;
                for(i = 0; i < (int)postfix_entry.length(); i++)
                    {
                        cout << "FOR: postfix_entry[i] = " << postfix_entry[i] << endl;               // debug

                        if((i != (int)postfix_entry.length() - 1) && (postfix_entry[i] == '*' || postfix_entry[i] == '/' || postfix_entry[i] == '+' || postfix_entry[i] == '-'))
                            {
                                if(!empty())
                                    {
                                        right_side_eq = top();                                          // top stack value is the right side operand
                                        pop();                                                          // delete the top value after its been used
                                        cout << "right_side_eq = " << right_side_eq << endl;            // debug
                                    }
                                if(empty())
                                    {
                                        converted_infix = "Too many operators and not enough operands...";
                                    }
                                if(!empty())
                                    {
                                        left_side_eq = top();                                           // next down top value is the left side operand
                                        pop();                                                          // delete the top value after its been used
                                        cout << "left_side_eq = " << left_side_eq << endl;              // debug
                                    }
                                if(empty())
                                    {
                                        converted_infix = "Too many operators and not enough operands...";
                                    }
                                if(left_side_eq != "" && right_side_eq != "")
                                    {
                                        left_plus_right = "(" + left_side_eq + " " + postfix_entry[i] + " " + right_side_eq + ")";
                                        push(left_plus_right);                                          // push the new equation to the top of the stack
                                        cout << "left_plus_right = " << left_plus_right << endl;        // debug
                                    }

                            }
                        else if(postfix_entry[i] != '*' && postfix_entry[i] != '/' && postfix_entry[i] != '+' && postfix_entry[i] != '-' && postfix_entry[i] != ' ')
                            {
                                temp_string += postfix_entry[i];                                       // concatenate each variable letter to a temp_string
                                cout << "else if: += temp_string = " << temp_string << endl;            // debug
                            }
                        else if(temp_string != "")
                            {
                                cout << "else if: pushing: temp_string = " << temp_string << endl;      // debug
                                push(temp_string);                                                      // push the temp_string to the stack
                                temp_string = "";                                                       // reset temp_string to empty.
                            }
                    }
                if((int)postfix_entry.length() == 1)                                    // if only one operand was entered, then the expression is valid and needs to be returned.
                    {
                        cout << "else if((int)postfix_entry.length() == 1: TRUE" << endl;
                        converted_infix = temp_string;
                    }
                else if(empty())
                    {
                        cout << "if(empty()) TRUE" << endl;
                        converted_infix = "Invalid Entry Format!!";
                    }
                else if(!empty() && temp_string != "")
                    {
                        cout << "else if(!empty() && temp_string != \"\")...Too Many Operands" << endl;
                        converted_infix = "Too many operands and not enough operators...";
                    }
                else if(s_top->next == 0 && temp_string == "" && count < 2)  // if the stack only has one item on it, and there are not extra operands leftover in the temp_string
                    {

                        cout << "else if(s_top->next == 0 && temp_string == \"\") TRUE" << endl;
                        converted_infix = top();                           // make the output the top of the stack
                    }
            }

        cout << "Count = " << count << endl;
        temp_string = "";                                                           // clear the temp string;
        do { pop(); } while(s_top != 0);                                            // empty stack

        cout << endl << "The RPN/Postfix expression: " << postfix_entry << endl;
        cout << "As an Infix expression is: " << endl;
        cout << converted_infix << endl;

        cout << endl << "Press Enter to Continue..." << endl;
        cin.ignore(numeric_limits<int>::max(),'\n');

        cout << endl << "Would you like to convert another expression? ";
        cin >> user_choice;

    } while(user_choice == 'Y' || user_choice == 'y');

    cout << "See you next time!!" << endl << endl;

}