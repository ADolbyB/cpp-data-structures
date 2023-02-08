/**
 * Joel Brigida
 * COP 3014-003
 * Dr. Sareh Taebi
 * September 18, 2020
 * Assignment: Lab 1
 * 1) Convert Miles per hour to Minutes and Seconds per Mile.
 * 2) Construct a custom Mad Lib game.
**/

#include <iostream>
#include <string>

using namespace std;

void Q1(void); // Function for the MPH conversion.
void Q2(void); // Function for the Mad Lib game.

int main()
{

    Q1();
    Q2();

    return 0;
}

void Q1(void)
{
    double miles_per_hr, min_per_mile, sec_per_mile, display_seconds;
    int display_minutes;
    char exit_value;

    cout << "\t=> Treadmill Speed to Runner Pace Conversion Tool <=" << endl << endl;

    do {

    cout << "Enter your treadmill speed in miles per hour: ";
    cin >> miles_per_hr;
    cout << endl;


    sec_per_mile = 3600 / miles_per_hr;                      // conversion of user input to seconds per mile
    min_per_mile = sec_per_mile / 60;                        // converts seconds per mile to minutes per mile

    display_minutes = static_cast <int> (min_per_mile);      // typecast total_minutes to new variable as whole number

    display_seconds = (min_per_mile - display_minutes) * 60; // recalculates the dropped remainder minutes and converts to seconds

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << "Your treadmill speed of " << miles_per_hr << " mph is equivalent to: " << endl << endl;
    cout << display_minutes << " minutes and " << display_seconds << " seconds per mile.";
    cout << endl << endl;

    cout << "Would you like to convert another value?" << endl;
    cout << "Enter Y to continue, any other key to exit: " << endl;
    cin >> exit_value;
    cout << endl;

    } while (exit_value == 'Y' || exit_value == 'y');        // do-while loop condition
}

void Q2(void)
{
    string instructor, food, color, adjective, animal, first_name, last_name, faking_it;
    int temperature;
    bool lies;

    cout << "\t=> The C++ Mad Lib Game <=" << endl << endl;

    cout << "Enter your Instructor's Last name: ";
    cin >> instructor;
    cout << "Enter your First name: ";
    cin >> first_name;                                      // Entering first and last name as one string variable with a space results
    cout << "Enter your Last Name: ";                       // in incorrect output so I split the name into 2 separate string variables.
    cin >> last_name;
    cout << "Enter your favorite food: ";
    cin >> food;
    cout << "Enter your favorite color: ";
    cin >> color;
    cout << "Enter a number from 100 - 120: ";
    cin >> temperature;
    cout << "Enter an adjective: ";
    cin >> adjective;
    cout << "Enter your favorite animal: ";
    cin >> animal;
    cout << "Enter the number 0 or 1: ";
    cin >> lies;

    if (lies == 0)
        faking_it = "telling the truth";
    else
        faking_it = "lying to you";

    cout << "\n\nDear Professor " << instructor << "," << endl << endl;
    cout << "\tI am sorry that I am unable to turn in my homework\n"
         << "at this time. First, I ate a rotten " << food << ", which made me turn\n"
         << color << " and made me extremely ill. I came down with a fever of " << temperature << ".\n"
         << "Next, my " << adjective << " pet " << animal << " must have smelled the leftover\n"
         << food << " on my homework because he ate it, too. I am currently\n"
         << "rewriting my homework and hope you will accept it late.\n"
         << "I swear I am " << faking_it << "!!" << endl << endl << endl;

    cout << "Sincerely," << endl << endl;
    cout << "\t" << first_name << " " << last_name << endl;
}