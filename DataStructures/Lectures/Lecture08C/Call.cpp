/*********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This implementation file contains definitions of the basic 
 * Call operations.
*********************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

#include "Call.h"

/***************************************************************
Function Name: Call()
Description: Default Constructor. Constructsa Call object (default).
Precondition:  None
Postcondition: All data members are initialized to 0.
***************************************************************/
Call::Call()
{ 
    myTimeOfArrival = myServiceTime = 0; 
}

/***************************************************************
Function Name: Call()
Description: Explicit Value Constructor. Constructs a Call object
with the given values
Precondition:  Countdown timer t is received
Postcondition: myTimeOfArrival has been set to time left
on Timer t and myServiceTime to serviceTime.
****************************************************************/
Call::Call(const Timer& t, int serviceTime)
{
    myTimeOfArrival = t.timeRemaining();    // record call's time of arrival

    myServiceTime = serviceTime;            // set its service time
}

/***************************************************************
Function Name: getArrivalTime()
Description: Accessor function for call arrival time.
Precondition: None
Postcondition: Value of myTimeOfArrival was returned.
****************************************************************/
int Call::getArrivalTime() const
{
    return myTimeOfArrival;
}

/***************************************************************
Function Name: getServiceTime()
Description: Accessor function for call service time.
Precondition: None
Postcondition: Value of myServiceTime was returned.
****************************************************************/
int Call::getServiceTime() const
{
    return myServiceTime;
}

/***************************************************************
Function Name: display()
Description: Displays call to an output stream.
Precondition: ostream out is a reference parameter
Postcondition: Call has been output to out.
****************************************************************/
void Call::display(ostream& out) const
{
    out << "Arrival Time:    " << myTimeOfArrival << endl << "Service Time:    " << myServiceTime << endl;
}

/***************************************************************
Function Name: operator<<
Description: Overloaded << Operator. Non Class function which 
returns an ostream object to an output stream.
****************************************************************/
ostream& operator<<(ostream& out, const Call& aCall)
{
    aCall.display(out);
    return out;
}