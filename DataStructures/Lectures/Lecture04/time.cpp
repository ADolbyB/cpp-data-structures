/***************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * This is the implementation for the Time class
 * These are definitions of the function members of the Time class
 * declared in Time.h and definitions of utility functions that convert
 * between military and standard time.
***************************************************************************/

#include <iostream>
#include "time.h"

using namespace std;

/** Non Class Function Prototype Declaration */
int toMilitary(unsigned hours, unsigned minutes, char am_pm);

/*************************************************************************
Function Name: set()
Description: Sets the data members of a Time object to specified values.
Preconditions: 1 <= hours <= 12, 0 <= minutes <= 59,
and am_pm is either 'A' or 'P'.
Postcondition: Data members myHours, myMinutes, and myAMorPM
are set to hours, minutes, and am_pm, respectively, and
myMilTime to the equivalent military time
*************************************************************************/
void Time::set(unsigned hours, unsigned minutes, char am_pm) // Definition of set function
{
    // Check class invariant
    if (hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 && (am_pm == 'A' || am_pm == 'P'))
        {
            myHours = hours;
            myMinutes = minutes;
            myAMorPM = am_pm;
            myMilTime = toMilitary(hours, minutes, am_pm);
        }
    else
        {
            cerr << "*** Can't set time with these values ***\n";
        }
    // Object's data members remain unchanged
}

/*************************************************************************
Function Name: display()
Description: Displays time in AM/PM & Military format using output stream out.
Precondition:  The ostream out is open.
Postcondition: The time represented by this Time object has been 
inserted into ostream out.
*************************************************************************/
void Time::display(ostream & out) const // Definition of display function
{

    out << myHours << ':' << (myMinutes < 10 ? "0" : "") << myMinutes << ' ' << myAMorPM << ".M.  ("<< myMilTime << " mil. time)";

}

/**************************************************************************
Function Name: toMilitary()
Description: Non-Class Function which converts standard time to military time.
Precondition:  hours, minutes, am_pm satisfy the class invariant.
Postcondition: Military time equivalent is returned.
**************************************************************************/
int toMilitary(unsigned hours, unsigned minutes, char am_pm) // Utility Functions -- Definitions
{
    if (hours == 12)
        {
            hours = 0;
        }
    return hours * 100 + minutes + (am_pm == 'P' ? 1200 : 0);
}