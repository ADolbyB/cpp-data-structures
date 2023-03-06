/**************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implemetation file for definitions of the Simulation class.
**************************************************************************/

#include <iostream>       // istream, ostream, >>, <<
#include <cstdlib>        // rand(), srand()
#include <ctime>          // time()

using namespace std;

#include "Simulation.h"

/**************************************************************************
Function Name: Simulation()
Description: Default Constructor. Constructs a Simulation object.
Precondition: None
Postcondition: Input data members have been initialized with values
entered by the user; output data members have been initialized 
to 0; and random number generator has been initialized.
**************************************************************************/
Simulation::Simulation()
{
    myCallsReceived = 0;                                // Initialize output statistics
    myTotalWaitingTime = 0;
    
    cout << "Enter arrival rate (calls per hour): ";    // Get simulation parameters
    int callsPerHour;
    cin >> callsPerHour;
    myArrivalRate = callsPerHour / 60.0;                // convert to calls per minute

    cout << "Enter percent of calls serviced in" << endl;
    int percent;
    int sum = 0;

    for (int i = 0; i < NUM_CATEGORIES - 1; i++)
        {
            cout << " <= " << i + 1 << " min. ";      
            cin >> percent;
            sum += percent;
            myServicePercent[i] = sum;
        }
    myServicePercent[NUM_CATEGORIES - 1] = 100;

    cout << "Enter # of minutes to run simulation: ";
    cin >> myLengthOfSimulation;

    myTimer.set(myLengthOfSimulation);                  // Set the countdown timer

    long seed = long(time(0));                          // Initialize random number generator
    srand(seed);
}

/**************************************************************************
Function Name: run()
Description: Runs the simulation.
Precondition: None.
Postcondition: Simulation of phone service has been completed and
performance statistics output.
**************************************************************************/
void Simulation::run()
{
    int busyTimeRemaining = 0;      // Begin the simulation
    while (myTimer.timeRemaining() > 0)
        {
            service(busyTimeRemaining);
            checkForNewCall();
            myTimer.tick();
        }
    
    cout << endl << "Not accepting more calls: service those waiting" << endl;

    while (!myIncomingCalls.empty()) // Service remaining calls in incomingCalls queue
        {
            service(busyTimeRemaining);
            myTimer.tick();
        }
    display(cout);      // Output the results
}

/**************************************************************************
Function Name: display()
Description: Displays results of the simulation.
Precondition: ostream out is open.
Postcondition: Total number of calls and the average waiting time
for calls have been output to out.
**************************************************************************/
void Simulation::display(ostream& out)
{
    out << endl << "Number of calls processed:   " << myCallsReceived << endl
        << "Avg. waiting time per call:  " << myTotalWaitingTime / myCallsReceived
        << " minutes" << endl;
}

/**************************************************************************
Function Name: service()
Description: Services the current call (if any).
Precondition: None
Postcondition: busyTimeRemaining has been decremented by one if a call
was being serviced; otherwise, if there were incoming calls, a 
call has been removed from myIncomingCalls, its service time      
assigned to busyTimeRemaining, and its waiting time in the queue
added to myTotalWaitingTime.
**************************************************************************/
void Simulation::service(int& busyTimeRemaining)
{
    if (busyTimeRemaining > 0)              // service a call
        {
            busyTimeRemaining--;            // service it for another minute
        }
    else
    if (!myIncomingCalls.empty())           // Answer Waiting Calls
        {
            Call nextCall = myIncomingCalls.front();
            myIncomingCalls.dequeue();         
            busyTimeRemaining = nextCall.getServiceTime();

            // Update total waiting time
            myTotalWaitingTime += nextCall.getArrivalTime() - myTimer.timeRemaining();
        }
}

/**************************************************************************
Function Name: checkForNewCall()
Description: Check if a new call has arrived and if so, add it to the
queue of incoming calls.
Precondition: None.
Postcondition: myIncomingCalls has been updated.
**************************************************************************/
void Simulation::checkForNewCall()
{
    int x = rand() % 100;

    if (x < 100 * myArrivalRate)
        {
            int r = rand() % 100; // Generate a random service time for incoming call.

            int serviceTime = 0;
            while (r > myServicePercent[serviceTime])
                serviceTime++;

            // Construct a new call and add it to queue of incoming calls
            Call newCall(myTimer, serviceTime + 1);
            myIncomingCalls.enqueue(newCall);
            myCallsReceived++;
        }
}