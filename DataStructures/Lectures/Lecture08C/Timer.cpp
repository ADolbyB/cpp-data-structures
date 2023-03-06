/****************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implemetation file for definitions of the Timer
 * Class.
****************************************************************/

#include <cassert>
#include "Timer.h"

using namespace std;

/*****************************************************************
Function Name: Timer()
Description: Constructs a Timer object with an initial value.
Precondition: The initial value initTime to start the timer
is received.
Postcondition: myMinutes has been initialized to 
initTime minutes (default 0).
*****************************************************************/
Timer::Timer(int initTime)
{
    assert(initTime >= 0);
    myMinutes = initTime;
}

/*****************************************************************
Function Name: set()
Description: Set/reset the timer to a number of minutesS.
Precondition: None
Postcondition: myMinutes has been set to minutes.      
*****************************************************************/
void Timer::set(int minutes)
{
    assert(minutes >= 0);
    myMinutes = minutes;
}

/*****************************************************************
Function Name: tick()
Description: Advances the clock one minute.
Precondition: None
Postcondition: myMinutes has been decremented by 1.      
*****************************************************************/
void Timer::tick()
{
    myMinutes--;
}

/*****************************************************************
Function Name: timeRemaining()
Description: Find how much time remains on the countdown timer.
Precondition: None
Postcondition: Time left before timer runs out is returned.
*****************************************************************/
int Timer::timeRemaining() const
{
    return myMinutes;
}