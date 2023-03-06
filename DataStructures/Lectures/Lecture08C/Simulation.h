/***************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * Header file to define a Simulation data type for simulating the operation
 * of an information/reservation center that services telephone calls.
 * Basic operations:
 * constructor:  constructs a Simulation object
 * run(): carry out the simulation
 * display(): output results of the simulation
 * service(): service an incoming call
 * checkForNewCall(): check if a new call has come in
 * Note: Assumes availability of a queue class with elements of type Call.
****************************************************************************/

#include <iostream>                         // istream, ostream, >>, <<
#include <ctime>

#ifndef SIMULATION
#define SIMULATION

#include "Timer.h"
#include "Call.h"
#include "LQueue.h"                         // Queue with elements of type Call

const int NUM_CATEGORIES = 5;

class Simulation
{
    public:

        Simulation();
        void run();
        void display(ostream& out);
        void service(int& busyTimeRemaining);
        void checkForNewCall();

    private: 

        int    myLengthOfSimulation;        // Inputs
        double myArrivalRate;
        int    myServicePercent[NUM_CATEGORIES];

        int    myCallsReceived;             // Outputs
        double myTotalWaitingTime;

        Timer myTimer;                      // Countdown Timer
        Queue myIncomingCalls;              // Queue of calls waiting for service

};

#endif