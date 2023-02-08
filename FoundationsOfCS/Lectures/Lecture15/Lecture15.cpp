/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 15: Classes
 * Classes, like Structures, can have member variables
 * Classes can also have member FUNCTIONS
 * Class members are PRIVATE by default
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class DayOfYear
{
    public:                                                                                 // public members can be accessed from outside the class.
        void output(void);                                                                  // member function declaration / prototype
        int month;
        int day;
        int year;
};                                                                                          // DON'T FORGET THE SEMI-COLON!!

class DayOfYear2                                                                            // Improved version with private members
{
    public:                                                                                 // DEFAULT VALUE is PRIVATE if no specification exists

        void input(void);                                                                   // accepts user input of date
        void output(void);                                                                  // prints output dates to the screen
        void set_date(int new_month, int new_day, int new_year);                            // date gets reset according to argument
        int get_month(void);                                                                // Returns month as an int: 1 for Jan, 2 for Feb, etc
        int get_day(void);                                                                  // returns day of month as integer

    private:                                                                                // private members can be accessed only by member functions of the class within the definitions of member functions
                                                                                            // private can be variables or functions
        void check_date(void);
        int month;                                                                          // NORMAL PRACTICE to make member variables PRIVATE
        int day;                                                                            // requires member functions to perform all changing and retrieving of values
        int year;
};

class BankAccount
{
    public:

        void set(int dollars, int cents, double rate);
        void set(int dollars, double rate);
        void update(void);                                                                  // adds 1 year simple interest to the acct balance.
        double get_balance(void);                                                           // returns current account balance
        double get_rate(void);                                                              // returns current 'interest_rate' as a percentage
        void output(ostream& outs);                                                         // can output to screen or a file

    private:

        double balance;
        double interest_rate;
        double fraction(double percent);                                                    // converts precentage to fraction: fraction(5.2) returns 0.052
};

void testday(void);
void testday2(void);
void acct_info(void);

int main()
{

    //testday();
    //testday2();
    acct_info();

    return 0;
}

void testday(void)
{
    DayOfYear today, birthday;

    cout << "Enter your Birth Year: ";
    cin >> birthday.year;

    cout << "Enter your Birth Month: ";
    cin >> birthday.month;

    cout << "Enter your Birth Day: ";
    cin >> birthday.day;
    cout << endl;

    birthday.output();                                                                      // calling DayOfYear member function 'output()'

    cout << endl << "Enter todays date in the format MM DD YYYY: ";
    cin >> today.month >> today.day >> today.year;
    cout << endl;

    today.output();                                                                         // calling DayOfYear member function 'output()'
    cout << endl;
}

void DayOfYear::output(void)                                                                // member function definition identifies the class in which the function is a member
{
    cout << month << " / " << day << " / " << year << endl;
}

void testday2(void)
{
    DayOfYear2 today, my_bday;
    DayOfYear2 due_date, tomorrow;

    cout << "Enter today\'s date (MM DD YYYY): " << endl;
    today.input();

    cout << endl << "Today\'s date is: ";
    today.output();

    my_bday.set_date(2, 3, 1983);
    cout << endl << "Joel\'s Birthday is: ";
    my_bday.output();

    if ( today.get_month() == my_bday.get_month() && today.get_day() == my_bday.get_day() )
        cout << endl << "Happy Birthday to You!!" << endl;
    else
        cout << endl << "Well, it\'s just another day in paradise..." << endl;

    tomorrow.set_date(11, 10, 2020);

    due_date = tomorrow;                                                                    // objects 'due_date' and 'tomorrow' can be assigned values w/ assignment operator ( = )

    cout << endl << "tomorrow\'s date is: ";
    tomorrow.output();

    cout << endl << "The due date is: ";
    due_date.output();
}

void DayOfYear2::input(void)
{
    cout << "Enter the month as a number: ";
    cin >> month;                                                                           // PRIVATE MEMBER can only be used in member function definition

    cout << "Enter the day of the month: ";
    cin >> day;                                                                             // Private member variable

    cout << "Enter the current year: ";
    cin >> year;                                                                            // Private member variable

    check_date();                                                                           // Private member function
}

void DayOfYear2::output(void)
{
    cout << month << " / " << day << " / " << year << endl;
}

void DayOfYear2::set_date(int new_month, int new_day, int new_year)                         // This is a MUTATOR FUNCTION
{
    month = new_month;
    day = new_day;
    year = new_year;
    check_date();
}

void DayOfYear2::check_date(void)
{
    if ( (month < 1) || (month > 12) || (day < 1) || (day > 31) )
        {
            cout << "Incorrect date...try again..." << endl;
            exit(1);
        }
}

int DayOfYear2::get_month(void)                                                             // This is an ACCESSOR FUNCTION
{
    return (month);
}

int DayOfYear2::get_day(void)                                                               // This is an ACCESSOR FUNCTION
{
    return (day);
}

void acct_info(void)
{
    BankAccount account1, account2;

    cout << "Start of test: " << endl;

    account1.set(123, 99, 3.0);
    cout << endl << "account1 initial statement: " << endl;
    account1.output(cout);

    account1.set(100, 5.0);
    cout << endl << "account1 new setup: " << endl;
    account1.output(cout);

    account1.update();
    cout << endl << "account1 after update: " << endl;
    account1.output(cout);

    account2 = account1;
    cout << endl << "account2: " << endl;
    account2.output(cout);
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ( (dollars < 0) || (cents < 0) || (rate < 0) )
        {
            cout << "Illegal values for money or interest rate." << endl;
            exit(1);
        }

    balance = dollars;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if ( (dollars < 0) || (rate < 0) )
        {
            cout << "Illegal values for money or interest rate." << endl;
            exit(1);
        }

    balance = dollars;
    interest_rate = rate;
}

void BankAccount::update(void)
{
    // member function call inside a member function definition.
    balance = balance + (fraction(interest_rate) * balance);                                // 'fraction' called by member function 'update'
}

double BankAccount::fraction(double percent_value)                                          // private member of the BankAccount class
{
    return (percent_value / 100.0);
}

double BankAccount::get_balance(void)
{
    return (balance);
}

double BankAccount::get_rate(void)
{
    return (interest_rate);
}

void BankAccount::output(ostream& outs)                                                     // 'ostream' can be used with COUT or an output file system_error
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);

    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "\%" << endl;
}