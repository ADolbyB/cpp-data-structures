/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 1/29/2021                     Due Time: 11:59pm
Total Points: 25                        Assignment 2: Date program for Module 4
Description: This program prints out dates in a specified format and has the capability to
check them for a valid MM/DD/YYYY format.
*********************************************************************************************/

#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{

    public:

        Date();                                                             // default constructor; sets m = 01, d = 01, y = 0001
        Date(unsigned m, unsigned d, unsigned y);                           // explicit-value constructor to set date equal to today's date. Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should print a message if a leap year.
        void display();                                                     // output Date object to the screen
        int getMonth();                                                     // accessor to output the month
        int getDay();                                                       // accessor to output the day
        int getYear();                                                      // accessor to output the year
        void setMonth(unsigned m);                                          // mutator to change the month
        void setDay(unsigned d);                                            // mutator to change the day
        void setYear(unsigned y);                                           // mutator to change the year
        friend ostream& operator<<(ostream& out, Date& dateObj);            // overloaded operator<< as a friend function with chaining
        void check_date();                                                  // function which checks for valid dates
        void make_space();                                                  // function that inserts a space in the output as needed

    private:

        int myMonth, myDay, myYear;                                         // month, day, and year of a Date obj respectively

};

#endif // DATE_H