/**************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the header file which implements operations 
 * for AdditionProblem objects.
**************************************************************/

#include <cstdlib>
#include <ctime>
using namespace std;

#include "AdditionProblem.h"

/**************************************************************
Construct an addition problem.
Precondition:  Receives maxAddend, the largest integer to
use in a problem
Postcondition: An addition problem has been constructed
with addends that are random integers in the range
0 through maxAddend and myTries initialized to 1.
**************************************************************/
AdditionProblem::AdditionProblem(int maxAddend)
{
    myAddend1 = rand() % (maxAddend + 1);
    myAddend2 = rand() % (maxAddend + 1);
    myAnswer = myAddend1 + myAddend2;
}

/**************************************************************
Display values stored in the stack
Precondition:  out is ostream to use for output
Postcondition: Stack's contents, from top down, have
been output to out.
**************************************************************/
void AdditionProblem::display(ostream& out) const
{
   out << myAddend1 << " + " << myAddend2 << " = ? ";
}

/**************************************************************
Get answer to addition problem.
Precondition:  None
Postcondition: Answer to this addition problem is retrieved.
**************************************************************/
int AdditionProblem::answer() const
{
    return (myAddend1 + myAddend2);
}

/***************************************************************
Function Name: operator<<
Description: Overloaded << Operator for printing to any
output stream.
***************************************************************/
ostream& operator<<(ostream& out, const AdditionProblem& problem)
{
    problem.display(out);

    return out;
}

/***************************************************************
Function Name: initialize()
Description: Initilizes the Random Number Generator
****************************************************************/
void initialize()
{
    long seed = long(time(0));          // seed for random number generator
    srand(seed);
}