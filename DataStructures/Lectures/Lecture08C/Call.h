/***************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines a class Call that models phone calls.
 * Basic operations:
 * constructors: construct a Call object
 * getArrivalTime(): accessor to get time call arrived
 * getServiceTime(): get time needed to service the call
 * display(): display information about the call
 * <<: output operator for a Call object
***************************************************************/
#ifndef CALL
#define CALL

#include <iostream>
#include "Timer.h"

class Call
{
    public:

        Call();
        Call(const Timer& t, int serviceTime);
        int getArrivalTime() const;
        int getServiceTime() const;
        void display(ostream& out) const;

    private:

        int myTimeOfArrival;
        int myServiceTime;
};

/**************************************************************
Function Prototype Declaration for Non-Class Function
***************************************************************/
ostream& operator<<(ostream& out, const Call& aCall);

#endif