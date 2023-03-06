/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file which implements operations 
 * for AdditionProblem objects.
 * This header file contains the declaration of class AdditionProblem.
 * Basic operations:
 * constructor: Generates problem with random addends -- uses
 * random number generator rand() from cstdlib
 * display(): Displays the problem
 * answer(): Returns answer to problem
****************************************************************************/

#ifndef ADDITIONPROBLEM_H_INCLUDED
#define ADDITIONPROBLEM_H_INCLUDED

#include <iostream>

class AdditionProblem
{
    public:           /***** Function Members *****/

        AdditionProblem(int maxAddend = 100);
        void display(ostream& out) const;
        int answer() const;

    private:          /***** Data Members *****/

        int myAddend1;
        int myAddend2;
        int myAnswer;
};

/****************************************************************************
Non-Class Function Prototype Declarations
*****************************************************************************/
void initialize(); // Initialize random number generator
ostream& operator<<(ostream& out, const AdditionProblem& problem); // Output operatorgi

#endif // ADDITIONPROBLEM_H_INCLUDED