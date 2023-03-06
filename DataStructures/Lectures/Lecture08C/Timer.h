/**************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines a class Timer that models a 
 * countdown timer.
 * Basic operations:
 * constructor: constructs a Timer object
 * set(): mutator to set/reset the timer
 * tick(): decrease timer by 1 time unit (minute)
 * hasTimeLeft(): checks if any time remains
 * timeRemaining(): determines how much time remains
***************************************************************/

#ifndef TIMER
#define TIMER

class Timer
{
    public:

        Timer (int initTime = 0);       // Set timer
        void set(int minutes);          // Decrement timer
        void tick();                    // Check time remaining
        int timeRemaining() const;

    private:

        int myMinutes;
};

#endif