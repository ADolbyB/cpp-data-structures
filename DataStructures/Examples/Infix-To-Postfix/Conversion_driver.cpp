/********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the Driver File for Infix to Postfix (RPN) expressions.
 * Input:  An infix expression and user responses
 * Output: The postfix expression
*********************************************************************/

#include <iostream>	                // <<, >>, cout, cin
#include <string>                   // string, ==, find, npos
#include <cassert>                  // assert()
#include <cctype>                   // alnum()

using namespace std;

#include "DStack.h"                 // Stack class with StackElement = char

string postfix(string exp);

int main()
{

    string exp;                     // infix expression
    cout << "NOTE: Enter # for infix expression to stop.\n";
    for (;;)
        {
            cout << "\nInfix expression? ";
            getline(cin, exp);

            if (exp == "#") break;

            cout << "Postfix expression is " << postfix(exp) << endl;
        }
}

/********************************************************************
Function Name: postfix()
Description: Non-Class based function to convert an infix expression
to postfix (aka RPN - Reverse Polish Notation).
Precondition: A Valid Expression is received
Postcondition: Postfix expression corresponding to exp is returned
or an error message displayed if an error was found in exp.
*********************************************************************/
string postfix(string exp)
{
    char token;                                             // character in exp
    char topToken;                                          // token on top of opStack

    Stack opStack;                                          // stack of operators

    string RPNexp;                                          // postfix expression
    const string BLANK = " ";

    for (int i = 0; i < (int)exp.length(); i++)
        {
            token = exp[i];
            switch(token)
                {
                    case ' ':
                        break;                              // do nothing -- skip blanks

                    case '(':

                        opStack.push(token);
                        break;

                    case ')':

                        for (;;)
                            {
                                assert (!opStack.empty());
                                topToken = opStack.top();
                                opStack.pop();
                                if (topToken == '(') break;
                                RPNexp.append(BLANK + topToken);
                            }
                        break;

                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':

                        for (;;)
                            {
                                if (opStack.empty() ||
                                opStack.top() == '(' ||
                                (token == '*' || token == '/' || token == '%') &&
                                (opStack.top() == '+' || opStack.top() == '-'))
                                    {
                                        opStack.push(token);
                                        break;
                                    }
                                else
                                    {
                                        topToken = opStack.top();
                                        opStack.pop();
                                        RPNexp.append(BLANK + topToken);
                                    }
                            }
                        break;

                        default:                // operand

                            RPNexp.append(BLANK + token);
                            for(;;)
                                {
                                    if ( !isalnum(exp[i+1]) )
                                        {
                                            break;  // end of identifier
                                        }
                                    i++;
                                    token = exp[i];
                                    RPNexp.append(1, token);
                                }
                }
        }

    for (;;)                 // Pop remaining operators on the stack
        {

            if (opStack.empty())
                {
                    break;
                }

            topToken = opStack.top();
            opStack.pop();

            if (topToken != '(')
                {
                    RPNexp.append(BLANK + topToken);
                }
            else
                {
                    cout << " *** Error in infix expression ***\n";
                    break;
                }
   }
   return RPNexp;
}