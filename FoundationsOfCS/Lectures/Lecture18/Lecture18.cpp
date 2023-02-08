/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 18
 * Friend Functions
 * Rewrite of Lecture 15 Code with "DayOfYear" code example.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class DayOfYear3                                                                                // Improved version with private members
{
    public:                                                                                     // DEFAULT VALUE is PRIVATE if no specification exists

        friend bool equal2(DayOfYear3 date1, DayOfYear3 date2);                                 // friend is NOT A MEMBER FUNCTION but can access private class variables
        DayOfYear3(int theMonth, int theDay, int theYear);
        DayOfYear3(void);                                                                       // default constructor
        void input(void);                                                                       // accepts user input of date
        void output(void);                                                                      // prints output dates to the screen
        void set_date(int new_month, int new_day, int new_year);                                // date gets reset according to argument
        int get_month(void);                                                                    // Returns month as an int: 1 for Jan, 2 for Feb, etc
        int get_day(void);                                                                      // returns day of month as integer

    private:                                                                                    // private members can be accessed only by member functions of the class within the definitions of member functions
                                                                                                // private can be variables or functions
        void check_date(void);
        int month;                                                                              // NORMAL PRACTICE to make member variables PRIVATE
        int day;                                                                                // requires member functions to perform all changing and retrieving of values
        int year;

    private:

        void test(void);

};

void testday3(void);
bool equal(DayOfYear3 date1, DayOfYear3 date2);                                                 // NOT a class member function, NOT a friend function

int main()
{

    testday3();

    return 0;
}

void testday3(void)
{
    DayOfYear3 today, my_bday;
    DayOfYear3 due_date, tomorrow;

    cout << "See default initialization of today:" << endl;
    today.output();

    cout << endl << "Enter today\'s date (MM DD YYYY): " << endl;
    today.input();

    cout << endl << "Today\'s date is: ";
    today.output();

    my_bday.set_date(2, 3, 1983);
    cout << endl << "Joel\'s Birthday is: ";
    my_bday.output();

    if (equal(today, my_bday))
        cout << endl << "Happy Birthday to You!!" << endl;
    else
        cout << endl << "Well, it\'s just another day in paradise..." << endl;

    cout << endl << "Alternate way to check the dates directly: Function call is the same" << endl;

    if (equal2(today, my_bday))
        cout << endl << "Happy Birthday to You!!" << endl;
    else
        cout << endl << "Well, it\'s just another day in paradise..." << endl;

    tomorrow.set_date(11, 10, 2020);

    due_date = tomorrow;                                                                        // objects 'due_date' and 'tomorrow' can be assigned values w/ assignment operator ( = )

    cout << endl << "Tomorrow\'s date is: ";
    tomorrow.output();

    cout << endl << "The due date is: ";
    due_date.output();
}

bool equal(DayOfYear3 date1, DayOfYear3 date2)                                                  // uses member function calls to obtain private data values
{
    return (date1.get_month() == date2.get_month() && date1.get_day() == date2.get_day());      // not efficient since it does not directly access variables.
}

bool equal2(DayOfYear3 date1, DayOfYear3 date2)                                                 // THIS IS A FRIEND FUNCTION
{
    return (date1.month == date2.month && date1.day == date2.day);                              // HAS DIRECT ACCESS TO THE MEMBER VARIABLES
}

DayOfYear3::DayOfYear3(int theMonth, int theDay, int theYear)
{
    month = theMonth;
    day = theDay;
    year = theYear;
}

DayOfYear3::DayOfYear3(void): month(1), day(1), year(2001)
{
    // default constructor initializes date to 1/1/2001
}

void DayOfYear3::input(void)
{
    cout << "Enter the month as a number: ";
    cin >> month;                                                                               // PRIVATE MEMBER can only be used in member function definition

    cout << "Enter the day of the month: ";
    cin >> day;                                                                                 // Private member variable

    cout << "Enter the current year: ";
    cin >> year;                                                                                // Private member variable

    check_date();                                                                               // Private member function
}

void DayOfYear3::output(void)
{
    cout << month << " / " << day << " / " << year << endl;
}

void DayOfYear3::set_date(int new_month, int new_day, int new_year)                             // This is a MUTATOR FUNCTION
{
    month = new_month;
    day = new_day;
    year = new_year;
    check_date();
}

void DayOfYear3::check_date(void)
{
    if ( (month < 1) || (month > 12) || (day < 1) || (day > 31) )
        {
            cout << "Incorrect date...try again..." << endl;
            exit(1);
        }
}

int DayOfYear3::get_month(void)                                                                 // This is an ACCESSOR FUNCTION
{
    return (month);
}

int DayOfYear3::get_day(void)                                                                   // This is an ACCESSOR FUNCTION
{
    return (day);
}