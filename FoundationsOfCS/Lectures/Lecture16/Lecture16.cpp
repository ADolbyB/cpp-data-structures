/**
 * Joel Brigida
 * COP 3024: Foundations of CS
 * Lecture 16
 * Classes, Constructors, and Member initializer
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class BankAccount
{
    public:

        BankAccount(int dollars, int cents, double rate);                                       // Constructor member function must be PUBLIC with NO RETURN TYPE
        BankAccount(int dollars, double rate);                                                  // Constructors initialize member variables according to arguments
        BankAccount(void);                                                                      // Default constructor: sets acct balance to $0 and rate to 0.0%
        void update(void);                                                                      // adds one year simple interest to balance
        double get_balance(void);                                                               // returns the current account balance
        double get_rate(void);                                                                  // returns current interest rate as a percentage.
        void output(ostream& fout);                                                             // outputs data to a stream

    private:

        double balance;
        double interest_rate;
        double fraction(double percent);                                                        // converts a percentage to a fraction.
};

void AcctMgr(void);

int main()
{

    AcctMgr();

    return 0;
}

void AcctMgr(void)
{
    BankAccount account1(1000, 3.5);                                                            // declares object and calls 2nd constructor member function
    BankAccount account2;                                                                       // declares object and implicitly calls default constructor

    cout << "Account #1 initialized as follows:" << endl;
    account1.output(cout);

    cout << endl << "Update Account #1 with 1 year simple interest at "
         << account1.get_rate() << "\% is:" << endl;
    account1.update();                                                                          // updates account to add 1 year simple interest.
    account1.output(cout);                                                                      // outputs new balance to the screen.

    cout << endl << "Account #2 initialized as follows:" << endl;
    account2.output(cout);

    account1 = BankAccount(999, 99, 5.5);                                                       // explicit call to constructor BankAccount::BankAccount to initialize object

    cout << endl << "Now Account #1 is reset to the following:" << endl;
    account1.output(cout);
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
// Another option: intialize values in the function definition header instead:
// BankAccount::BankAccount(int dollars, int cents, double rate): balance (dollars + (0.01 * cents)), interest_rate (rate)

    if (dollars < 0 || cents < 0 || rate < 0)
        {
            cout << "Error in balance or rate...exiting..." << endl;
            exit(1);
        }

    balance = dollars + (0.01 * cents);
    interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
        {
            cout << "Error in balance or rate...exiting..." << endl;
            exit(1);
        }

    balance = dollars;                                                                          // Initializing values in the function definition instead of the header
    interest_rate = rate;
}

BankAccount::BankAccount(): balance(0), interest_rate(0.0)                                      // This is the default constructor.
{
    // Uses optional intialization values in the function definition as arguments.
    // In this case, the function body is left empty.
}

void BankAccount::update(void)
{
    balance = balance + (fraction(interest_rate) * balance);                                    // calls function "fraction()" inside statement
}

double BankAccount::fraction(double percent)
{
    return (percent / 100.0);
}

double BankAccount::get_balance(void)
{
    return balance;
}

double BankAccount::get_rate(void)
{
    return interest_rate;
}

void BankAccount::output(ostream& fout)
{
    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(2);
    fout << "Account Balance = $" << balance << endl;
    fout << "Interest Rate = " << interest_rate << "\%" << endl;
}