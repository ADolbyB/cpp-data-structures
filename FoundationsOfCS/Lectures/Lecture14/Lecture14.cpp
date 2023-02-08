/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 14
 * Structures
 * Structure members are PUBLIC by default (can be made private)
*/

#include <iostream>

using namespace std;

struct CDAccount                                                                                // must be ABOVE function prototypes / declarations
{
    double balance;
    double interest_rate;
    int term; //months to maturity
};                                                                                              // DON'T FORGET THE SEMI-COLON HERE

struct FertilizerStock
{
    double quantity;                                                                            // having multiple variables named "quantity" in different structs is OK.
    double nitrogen_content;
};

struct CropYield
{
    int quantity;                                                                               // multiple variables "quantity" not a problem.
    double crop_size;
};

struct Date                                                                                     // MUST BE ON TOP TO USE INSIDE ANOTHER STRUCT
{
    int month;
    int day;
    int year;
};

struct PersonInfo
{
    int height_feet, height_inches;
    int weight;
    Date birthday;                                                                              // heirarchical structure inside a structure
};

struct EmployeeRecord
{
    double hourly_rate, yearly_salary;
    int vacation_days;
    char hourly_salary_status;
};

void example(void);
void test_acct(void);
void get_data(CDAccount& the_acct);
CDAccount shrink_wrap(double the_balance, double the_rate, int the_term);                       // using a structure as a function return type
void test_acct2(void);
void personnel_test(void);
void employer_payroll(void);

int main()
{

    example();
    //test_acct();
    //test_acct2();
    //personnel_test();
    //employer_payroll();


    return 0;
}

void example(void)
{
    CDAccount my_acct;                                                          // "my_acct" and "your_acct" have member variables "balance", "interest_rate", "term"
    CDAccount your_acct;                                                        // value of object CDAccount consists of the values of the member variables.
    double interest = 35.0;

    my_acct.balance = 1000;                                                     // use dot operator to specify a member variable
    your_acct.balance = 2500;                                                   // "my_acct.balance" and "your_acct.balance" are different member variables

    my_acct.balance = my_acct.balance + interest;
    your_acct.balance = your_acct.balance + interest;

    cout << "my_acct.balance is now " << my_acct.balance << endl;
    cout << "your_acct.balance is now " << your_acct.balance << endl << endl;

    //my_acct = your_acct;                                                      // will set all variable values of "your_acct" into "my_acct"

    FertilizerStock super_grow;
    CropYield apples;

    super_grow.quantity = 15.5;
    super_grow.nitrogen_content = 25.0;

    apples.quantity = 1500;
    apples.crop_size = 23.0;

    cout << "super_grow.quantity = " << super_grow.quantity << " lbs" << endl;
    cout << "super_grow.nitrogen_content = " << super_grow.nitrogen_content << "\%" << endl << endl;

    cout << "With an apple crop harvest of " << apples.crop_size << " bushels, " << endl
         << "The net amount of apples picked is " << apples.quantity << endl;
}

void test_acct(void)
{
    CDAccount account;
    get_data(account);

    double rate_fraction, interest;

    rate_fraction = account.interest_rate / 100.0;
    interest = account.balance * rate_fraction * (account.term / 12.0);
    account.balance = account.balance + interest;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "When your CD matures in " << account.term << " months, " << endl
         << "you will have earned $" << interest << ", and your account" << endl
         << "will have a balance of $" << account.balance << endl;
}

void get_data(CDAccount& the_acct)                                              // this function takes the structure type "CDAccount" as a call-by-reference input
{
    cout << "Enter the account balance: $";
    cin >> the_acct.balance;
    cout << endl;

    cout << "Enter account interest rate: \%";
    cin >> the_acct.interest_rate;
    cout << endl;

    cout << "Enter the number of months until maturity: ";
    cin >> the_acct.term;
    cout << endl;
}

void test_acct2(void)                                                           // Function that runs "shrink_wrap" function
{
    CDAccount new_account;

    new_account = shrink_wrap(1000.00, 5.1, 11);

    cout << "Returned values from function \'shrink_wrap\': " << endl;
    cout << "new_account.balance = " << new_account.balance << endl;
    cout << "new_account.interest_rate = " << new_account.interest_rate << endl;
    cout << "new_account.term = " << new_account.term << endl << endl;
}

CDAccount shrink_wrap(double the_balance, double the_rate, int the_term)
{
    CDAccount temp;

    temp.balance = the_balance;
    temp.interest_rate = the_rate;
    temp.term = the_term;

    return (temp);
}

void personnel_test(void)
{
    PersonInfo person1;                                                         // declare variables for structure PersonInfo
    Date due_date = {12, 31, 2021};                                             // use curly braces to initialize values for variable due_date inside struct Date

    cout << "Enter your Birth Year: ";
    cin >> person1.birthday.year;

    cout << "Enter your Birth Month: ";
    cin >> person1.birthday.month;

    cout << "Enter your Birth Day: ";
    cin >> person1.birthday.day;

    cout << "Enter your height in feet and inches: ";
    cin >> person1.height_feet >> person1.height_inches;

    cout << "Enter your weight in lbs: ";
    cin >> person1.weight;

    cout << "You entered a birthday of: " << person1.birthday.month << " - " << person1.birthday.day << " - " << person1.birthday.year << ", " << endl;
    cout << "A height of " << person1.height_feet << " feet and " << person1.height_inches << " inches." << endl << endl;

    cout << "The due date is: " << due_date.month << " - " << due_date.day << " - " << due_date.year << endl;
}

void employer_payroll(void)
{
    EmployeeRecord employee1;
    double vacation_pay;

    cout << "Employee1: H for hourly, S for salary: ";
    cin >> employee1.hourly_salary_status;

    if (employee1.hourly_salary_status == 'h' || employee1.hourly_salary_status == 'H')
        {
            cout << "Enter employee1 hourly wage: $";
            cin >> employee1.hourly_rate;
        }
    else if (employee1.hourly_salary_status == 's' || employee1.hourly_salary_status == 'S')
        {
            cout << "Enter employee1 yearly salary: $";
            cin >> employee1.yearly_salary;
        }
    else
        {
            cout << "Invalid entry, try again..." << endl << endl;
            employer_payroll();
        }

    cout << "Enter how many vacation days are you requesting: ";
    cin >> employee1.vacation_days;

    if (employee1.hourly_salary_status == 'h' || employee1.hourly_salary_status == 'H')
        {
            vacation_pay = (employee1.hourly_rate * 8.0) * employee1.vacation_days;
        }
    else if (employee1.hourly_salary_status == 's' || employee1.hourly_salary_status == 'S')
        {
            vacation_pay = (employee1.yearly_salary / 365.0) * employee1.vacation_days;
        }

    cout << "You requested " << employee1.vacation_days << " vacation days for a total value of $" << vacation_pay << endl << endl;
}