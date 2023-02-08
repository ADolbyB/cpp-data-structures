/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 17
 * Inheritance: Derived or Child Classes
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
        void set(int dollars, int cents, double rate);                                          // set functions for
        void set(int dollars, double rate);
        void update(void);                                                                      // adds one year simple interest to balance
        double get_balance(void);                                                               // returns the current account balance
        double get_rate(void);                                                                  // returns current interest rate as a percentage.
        void output(ostream& fout);                                                             // outputs data to a stream

    private:

        double balance;
        double interest_rate;
        double fraction(double percent);                                                        // converts a percentage to a fraction.
};

class SavingsAccount : public BankAccount                                                      // Derived or Child class of Parent/Base/Super Class "BankAccount
{
    public:

        SavingsAccount(int dollars, int cents, double rate);                                   // Constructor for Child Class "Savings account"
        void deposit(int dollars, int cents);                                                  // Only need to declare new functions specific to this class
        void withdraw(int dollars, int cents);                                                 // this class also inherits functions from "BankAccount"

    private:
};

class CDAccount : public SavingsAccount                                                         // Derived / Child Class of SavingsAccount. Inherits functions from BankAccount and SavingsAccount
{
    public:

        CDAccount(int dollars, int cents, double rate, int days);
        int get_days_to_maturity(void);
        void decrement_days_to_maturity(void);

    private:

        int days_to_maturity;
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

    cout << endl << "Create New Savings Account3" << endl;
    SavingsAccount account3(100, 50, 6.5);
    account3.output(cout);

    cout << endl << "Depositing $10.25 to Account3" << endl;
    account3.deposit(10, 25);
    account3.output(cout);

    cout << endl << "Withdrawing $11.80 to Account3" << endl;
    account3.withdraw(11, 80);
    account3.output(cout);

    cout << endl << "Create new CD Account4" << endl;
    CDAccount account4(1000, 0, 7.5, 180);
    account4.output(cout);
    cout << "Days to maturity = " << account4.get_days_to_maturity() << endl;

    cout << endl << "Deposit $100.50 to Account4:" << endl;
    account4.deposit(100, 50);
    account4.output(cout);
    cout << "Days to maturity = " << account4.get_days_to_maturity() << endl;
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
        {
            cout << "Improper entry for money or interest rate...exiting" << endl;
            return;
        }

    balance = dollars + (0.01 * cents);
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
        {
            cout << "Improper entry for money or interest rate...exiting" << endl;
            return;
        }

    balance = dollars;
    interest_rate = rate;
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

SavingsAccount::SavingsAccount(int dollars, int cents, double rate) : BankAccount(dollars, cents, rate)
{
    // The SavingsAccount constructor calls the BankAccount constructor to set the initial values.
}

void SavingsAccount::deposit(int dollars, int cents)                                            // function specific of child class "SavingsAccount"
{
    double balance = get_balance();                                                             // calls the "get_balance()" function from "BankAccount" to retrieve the current balance

    balance += dollars;
    balance += (static_cast<double>(cents) / 100);

    int new_dollars = static_cast<int>(balance);
    int new_cents = static_cast<int>((balance - new_dollars) * 100);

    set(new_dollars, new_cents, get_rate());                                                    // member of Parent BankAccount class to change member variables.
}

void SavingsAccount::withdraw(int dollars, int cents)
{
    double balance = get_balance();

    balance -= dollars;
    balance -= (static_cast<double>(cents) / 100);

    int new_dollars = static_cast<int>(balance);
    int new_cents = static_cast<int>((balance - new_dollars) * 100);

    set(new_dollars, new_cents, get_rate());
}

CDAccount::CDAccount(int dollars, int cents, double rate, int days): SavingsAccount(dollars, cents, rate)
{
    // CDAccount constructor calls Savings Account Constructor, which calls BankAccount Constructor to initialize the variables "dollars", "cents", "rate"
    // Since The CDAccount class does not have access to those private variables in the BankAccount Class.
    days_to_maturity = days;
}

int CDAccount::get_days_to_maturity(void)
{
    return (days_to_maturity);
}