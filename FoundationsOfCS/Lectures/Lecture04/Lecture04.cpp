/**
 * Joel Brigida
 * Lecture 4
 * If-Else Practice
 * Practice flow of control for logical and relational operators
*/

#include <iostream>

using namespace std;

void Q1(void);
void Q2(void);
void Q3(void);

int main()
{

    Q1();
    //Q2();
    //Q3();

    return 0;
}

void Q1(void)
{
    int number1, number2;
    number1 = (1 / 3) * 3;                                      // (1/3) is an int/int which = 0
    number2 = (1.0 / 3.0) * 3;
    cout << "(1 / 3) * 3 = " << number1 << endl << endl;        // Output is 0 because (int 1) / (int 3) = 0
    cout << "(1.0 / 3.0) * 3 = " << number2 << endl << endl;    // Correct output of 1

    double c = 20.0;
    double f1, f2;
    f1 = (9 / 5) * c + 32.0;                                    // (9/5) is an int/int which = 1
    f2 = (9.0 / 5.0) * c + 32.0;

    cout << "(9 / 5) * c + 32.0 = " << f1 << endl;              // output is: (1 * c) + 32 = 52 because (int 9) / (int 5) = 1
    cout << "(9.0 / 5.0) * c + 32.0 = " << f2 << endl;          // Correct output of 68
    cout << endl;


    int score;
    cout << "Please enter a score: ";
    cin >> score;
    cout << endl;

    if (score > 100)                                            // Basic if / else statement.
        cout << "High" << endl;
    else
        cout << "Low" << endl;

    cout << endl;
}

void Q2(void)
{
    int pressure, temperature;

    cout << "Please enter the temperature in Degrees: ";
    cin >> temperature;
    cout << endl;
    cout << "Please enter the pressure in PSI: ";
    cin >> pressure;
    cout << endl;

    if (temperature >= 100 || pressure >= 200)
        cout << "WARNING!!";
    else
        cout << "Normal";

    cout << endl << endl;
}

void Q3(void)
{
    double hours, hourly_rate, gross_pay, overtime_hours, overtime_rate, overtime_pay;

    cout << "Enter the number of hours worked: ";
    cin >> hours;
    hours = double(hours);                                  /// Typecast in case int value is entered for # of hours. (Avoid possible logic errors)

    cout << endl;

    cout << "Enter your pay rate per hour: ";
    cin >> hourly_rate;
    hourly_rate = double(hourly_rate);                      /// Typecast in case int value is entered for hourly rate. (Avoid possible logic errors)

    cout << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (hours > 40.0)
        {
            gross_pay = (hourly_rate * 40.0) + (((hours - 40.0) * 1.5) * hourly_rate);  /// Use parenthesis to avoid possible logic errors.
            overtime_pay = (((hours - 40.0) * 1.5) * hourly_rate);
            overtime_rate = hourly_rate * 1.5;
            overtime_hours = hours - 40.0;

            cout << "Your hours worked = " << hours << endl;
            cout << "You worked " << overtime_hours << " hours overtime." << endl;
            cout << "Your hourly pay rate = $" << hourly_rate << endl;
            cout << "Your overtime rate = $" << overtime_rate << endl;
            cout << "Your gross pay this week is: $" << gross_pay << endl;
            cout << "Your pay includes $" << overtime_pay << " of overtime pay" << endl << endl;

        }

    else
        {
            gross_pay = hours * hourly_rate;

            cout << "Your hours worked = " << hours << endl;
            cout << "Your hourly pay rate = $" << hourly_rate << endl;
            cout << "Your gross pay this week is: $" << gross_pay << endl << endl;
        }
    cout << "Thanks for showing up!" << endl << endl;
}