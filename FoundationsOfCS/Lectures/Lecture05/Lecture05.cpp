/**
 * Joel Brigida
 * Lecture 05: Loops
 * September 16, 2020
*/

#include <iostream>
#include <string>

using namespace std;

void Q1();
void Q2();
void Q3();

int main()
{

    Q1();                   // Simple while loop example
    Q2();                   // Simple do-while loop example
    Q3();

    return 0;
}

void Q1()
{
    int count_down;

    cout << "How many greetings do you want? ";
    cin >> count_down;

    while (count_down > 0)
        {
            cout << "Good Day to you!!" << endl;
            count_down--;
        }
    cout << endl;
    cout << "Goodbye!" << endl << endl;
}

void Q2()
{
    char answer;

    do {

        cout << endl;
        cout << "Hello!" << endl << endl;
        cout << "Would you like me to say hello again?" << endl;
        cout << "Enter Y for yes, N for no: ";
        cin >> answer;

        }

    while (answer == 'Y' || answer == 'y');

    cout << endl;
}

void Q3()
{
    double current_balance, end_balance, interest_rate, total_dollars;
    int counter = 0;

    cout << "\t=> Account Balance Calculator <=" << endl << endl;

    cout << "This program will tell you how many months it takes to accumulate\n"
            << "a user specified account balance of a specific value\n"
            << "starting with a user specified initial balance, based\n"
            << "on a user specified monthly interest rate.\n" << endl << endl;

    cout << "Enter your current account balance: $";
    cin >> current_balance;

    cout << "Enter the monthly interest rate: %";
    cin >> interest_rate;

    cout << "Enter the desired balance after interest accrues: $";
    cin >> end_balance;

    total_dollars = current_balance;

    while (total_dollars < end_balance)
        {
            total_dollars = (total_dollars * (interest_rate * 0.01)) + total_dollars;
            counter++;
        }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << endl;
    cout << "After " << counter << " months, your current balance of $" << current_balance << " will\n"
            << "exceed $" << end_balance << " and have a total balance of $" << total_dollars << endl << endl;
}