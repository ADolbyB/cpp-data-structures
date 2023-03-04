/**************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * This header file defines the data type Time for processing time.
 * Basic operations:
 * set: To set the time
 * display: To display the time
**************************************************************************/

#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
    public: /*** Function Members ***/

        void set(unsigned hours, unsigned minutes, char am_pm);
        void display(ostream & out) const;

    private: /*** Data Members ***/

        unsigned myHours, myMinutes;
        char myAMorPM;                      // 'A' or 'P'
        unsigned myMilTime;                 // military time equivalent
};

#endif // TIME_H