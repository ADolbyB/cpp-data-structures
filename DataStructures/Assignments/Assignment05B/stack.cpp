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

#include "stack.h"

/*************************************************************************************
Function Name: stack()
Precondition: An object has been declared with no arguments.
Postcondition: An object is created and initialized to 0 values, since it doesn't
contain any data yet.
Description: Default Constructor: The default constructor initializes state variables
to default values.
*************************************************************************************/
stack::stack()
{
    //cout << "* Default Constructor Called *" << endl;

    s_top = 0;                                                          // top of new stack = NULL (0 elements in new stack)
    num_operands = 0;                                                   // create 'num_operands'
    num_operators = 0;                                                  // create 'num_operators'
    node_count = 0;                                                     // create 'node_count'

}

/*************************************************************************************
Function Name: ~stack();
Precondition: An object has already been declared and initialized.
Postcondition: The object is deleted by calling pop() and dynamic memory is freed.
Description: Destructor: The destructor will de-allocate all memory allocated for each node.
*************************************************************************************/
stack::~stack()
{
    //cout << "* Destructor Called *" << endl;

	while(s_top != 0)
        {
            pop();                                                      // deallocate nodes
        }
}

/*************************************************************************************
Function Name: push();
Precondition: An object has already been declared and initialized.
Postcondition: The variable in the argument of the function is allocated a new node in
the stack at the top of the stack.
Description: Mutator Function: This function "pushes" data to the top of the stack and
moves the pointer to the top of the stack to point to the new top of the stack.
*************************************************************************************/
void stack::push(const stack_element& item)
{
	//cout << "\'Push\' Called" << endl;                                  // debug - works for an empty or non-empty stack

	stack_node *p = new stack_node;                                     // allocate a new stack node with pointer
	node_count++;                                                       // increment the node counter

	p->data = item;                                                     // assign the input item to the data field
	p->next = s_top;                                                    // assign the next field to the current *s_top pointer
	s_top = p;                                                          // move the *s_top pointer up a node to *p (the new top of stack)

}

/*************************************************************************************
Function Name: pop();
Precondition: An object has already been declared and initialized.
Postcondition: The top stack node is deleted.
Description: Mutator Function: This function "pops" the top node of the stack. The pointer
to the top of the stack is moved to the next topmost node, and the top node is then deleted.
If there are no nodes in the stack, then the function does nothing and returns.
*************************************************************************************/
void stack::pop()
{

    //cout << "\'Pop\' Called" << endl;                                   // debug

	stack_node *p;                                                      // declare a stack_node pointer

	if (s_top != 0)                                                     // pop only if the stack is not empty
        {
            p = s_top;                                                  // point *p at the top of the stack
            s_top = s_top->next;                                        // move *s_top to the next one down the list
            delete p;                                                   // delete the top node in the stack.
            node_count--;                                               // decrement the node counter
        }
    else // if stack is empty and pop() is called
        {
            //cout << "Stack is empty..." << endl;                      // debug
            return;
        }

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
	//cout << "\'Top\' Called" << endl;

	if (s_top == 0)
        {
            //cout << "Stack Empty: No data to return" << endl;           // debug - if the stack is empty, then a message is displayed
            return ("");
        }
	else
        {
            return s_top->data;                                         // otherwise returns the top value of the stack as a TYPEDEF stack_element
        }
}

/*************************************************************************************
Function Name: empty();
Precondition: An object has already been declared and initialized.
Postcondition: A boolean value is returned after the stack is checked.
Description: Accessor function: This function checkes if the stack is empty. It returns
False if the stack has atleast 1 node, True if the stack is empty.
*************************************************************************************/
bool stack::empty() const                                               // Definition of empty()
{

    return (s_top == 0);                                                // if s_top == 0, then the stack is empty

}

/*************************************************************************************
Function Name: validate(string_arg);
Precondition: An object has already been declared and initialized, and the user has entered
a postfix string that needs to be converted.
Postcondition: The private variables "num_operators" and "num_operands" contain the
corresponding number  of operands and operators in the postfix expression.
Description: Mutator function: After the user enters a string postfix expression, this
function changes state variables by parsing a copy (call by value) of the argument string to
count "num_operands" and the "num_operators".
*************************************************************************************/
void stack::validate(string user_input)
{

    string to_parse;
    to_parse = user_input;
    stringstream the_stream(to_parse);

    while(the_stream >> to_parse)
        {
            if(to_parse == "*" || to_parse == "/" || to_parse == "+" || to_parse == "-")
                {
                    num_operators++;                                            // state change
                }
            else
                {
                    num_operands++;                                             // state change
                }
        }
    //cout << "Validate: num_operators = " << num_operators << endl;              // debug
    //cout << "Validate: num_operands = " << num_operands << endl;                // debug

}

/*************************************************************************************
Function Name: postfix_to_infix();
Precondition: An object has already been declared and intialized.
Postcondition: User-entered Postfix string is converted into Infix expression w/ parenthesis.
Description: Mutator function: This function asks the user for a postfix expression,
which is then parsed and converted into an Infix expression with parenthesis using a stack.
This function changes state variables 'num_operands' and 'num_operators' directly by
resetting them to 0 after the conversion is done. It calls mutator functions push()
and pop() during execution.
*************************************************************************************/
void stack::postfix_to_infix()
{
    char user_choice;                                                   // variable for user to repeat the equation conversion

    string right_side_eq = "";                                          // The left side of the equation
    string left_side_eq = "";                                           // The right side of the equation
    string left_plus_right = "";                                        // concatenated left and right side of equation

    string postfix_entry;                                               // string variable for user entered postfix string
    string converted_infix;                                             // returned string object after conversion to infix

    do
    {

        cout << "Enter a postfix expression with spaces: ";
        getline(cin, postfix_entry);

        validate(postfix_entry);                                        // validate the number of operators and operands

        string each_word;                                               // declare a string to parse each word into
        each_word = postfix_entry;                                      // assign the user input to the string to be parsed
        stringstream the_string_stream(each_word);                      // declare a stringstream to parse the string "each_word"


        if(postfix_entry == "" || postfix_entry == " ")
            {
                the_string_stream.str("");                              // clear the string stream before returning
                converted_infix = "(" + postfix_entry + ")";            // condition if no operands or operators are entered.
            }
        else if(num_operands != (num_operators + 1))
            {
                if(num_operands > (num_operators + 1))
                    {
                        the_string_stream.str("");
                        converted_infix = "Too many operands and not enough operators!!";
                    }
                else // if (num_operands < (num_operators + 1))
                    {
                        the_string_stream.str("");
                        converted_infix = "Too many operators and not enough operands!!";
                    }
            }
        else if(num_operands == 1 && num_operators == 0)
            {
                the_string_stream.str("");                              // clear the string stream before returning
                converted_infix = "(" + postfix_entry + ")";
            }
        else
            {
                //cout << "ELSE inside DO" << endl;                     // debug
                while (the_string_stream >> each_word)                  // iterates through the string and parses each word, skipping white space.
                    {
                        //cout << "WHILE: each_word = " << each_word << endl;                               // debug
                        if(each_word == "*" || each_word == "/" || each_word == "+" || each_word == "-")
                            {
                                if(!empty())
                                    {
                                        right_side_eq = top();                                              // make 1st stack node the right side of the printed equation
                                        //cout << "right_side_eq = " << right_side_eq << endl;              // debug
                                        pop();                                                              // delete top node of stack
                                    }
                                else
                                    {
                                        the_string_stream.str("");                                          // clear the stringstream to exit loop
                                        converted_infix = "Too many operators and not enough operands!";
                                    }

                                if(!empty())
                                    {
                                        left_side_eq = top();                                               // make the next stack node the left side of the printed equation
                                        //cout << "left_side_eq = " << left_side_eq << endl;                // debug
                                        pop();                                                              // delete top node of stack
                                    }
                                else
                                    {
                                        the_string_stream.str("");                                          // clear the stringstream to exit loop
                                        converted_infix = "Too many operators and not enough operands!";
                                    }
                                left_plus_right = "(" + left_side_eq + " " + each_word + " " + right_side_eq + ")";
                                //cout << "left_plus_right = " << left_plus_right << endl;                  // debug
                                push(left_plus_right);
                            }
                        else // if(each_word != "*" || each_word != "/" || each_word != "+" || each_word != "-")
                            {
                                push(each_word); // push only the operands to the stack
                            }
                    }   /// End of while()
                if(s_top->next == 0) // there is only one thing left in the stack after the equation is converted fully
                    {
                        converted_infix = top();
                    }
                else // if after parsing, the stack has more than 1 node left in it, then there were too many operands entered
                    {
                        converted_infix = "Too many operators and not enough operands!";
                    }
        }   /// End of else

        do { pop(); } while(s_top != 0);                                            // keep the stack clear at end of conversion

        num_operands = 0;                                                           // clear counters after conversion
        num_operators = 0;

        cout << endl << "The RPN/Postfix expression: " << postfix_entry << endl << endl;
        cout << "As an Infix expression is: ";
        cout << converted_infix << endl << endl;                                    // print new Infix expression with parentheses

        cout << "Would you like to convert another RPN/Postfix Expression? ";
        cin >> user_choice;
        cin.ignore(numeric_limits<int>::max(),'\n');                                // keep input stream clear: '\n' remains after 'user_choice'

    } while(user_choice == 'Y' || user_choice == 'y');
}