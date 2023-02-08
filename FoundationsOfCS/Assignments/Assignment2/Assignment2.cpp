/**
 * Joel Brigida
 * COP 3014-003
 * Dr. Sareh Taebi
 * September 18, 2020
 * Assignment 2: Sum and Average calculator
*/

#include <iostream>

using namespace std;

void Q1(); // Void function for calculator
void Q2(); // Alternate way of doing it with input while loop


int main()
{

    //Q1();
    Q2();

    return 0;

}

void Q1()
{

    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10; // user input variables.
    char exit_status;                                                // Variable for repeating calculator do-while loop

    do {

        int pos_counter = 0;       // counters to keep track of the # of positive and non-positive integers.
        int non_pos_counter = 0;   // We assume Zero is not a Positive Integer as in Discrete Math set theory.
        int sum_positive = 0;      // sum variables for sum calculations.
        int sum_non_pos = 0;
        int sum_all_nums = 0;
        double avg_positive = 0;   // average variables for average calculations.
        double avg_non_pos = 0;
        double avg_all_nums = 0;

        cout << "\t=> Sum and Average Calculator <=" << endl << endl;

        cout << "Please enter any 10 integers each separated by a space: " << endl;
        cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10;       // User Entry of variables all at once.

        cout << endl;

        // 10 if-else conditions, one for each user entered variable,
        // which classifies each user input into the proper category.
        if (num1 > 0) 
            {
                sum_positive = sum_positive + num1;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num1;
                non_pos_counter++;
            }

        if (num2 > 0)
            {
                sum_positive = sum_positive + num2;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num2;
                non_pos_counter++;
            }

        if (num3 > 0)
            {
                sum_positive = sum_positive + num3;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num3;
                non_pos_counter++;
            }

        if (num4 > 0)
            {
                sum_positive = sum_positive + num4;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num4;
                non_pos_counter++;
            }

        if (num5 > 0)
            {
                sum_positive = sum_positive + num5;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num5;
                non_pos_counter++;
            }

        if (num6 > 0)
            {
                sum_positive = sum_positive + num6;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num6;
                non_pos_counter++;
            }

        if (num7 > 0)
            {
                sum_positive = sum_positive + num7;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num7;
                non_pos_counter++;
            }

        if (num8 > 0)
            {
                sum_positive = sum_positive + num8;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num8;
                non_pos_counter++;
            }

        if (num9 > 0)
            {
                sum_positive = sum_positive + num9;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num9;
                non_pos_counter++;
            }

        if (num10 > 0)
            {
                sum_positive = sum_positive + num10;
                pos_counter++;
            }
        else
            {
                sum_non_pos = sum_non_pos + num10;
                non_pos_counter++;
            }

        sum_all_nums = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10;                    // sum of all numbers calculation
        avg_all_nums = (num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10) / 10.0;           // average of all numbers calculation

        if (pos_counter > 0)                                                                                    // run-time error prevention
            {
                avg_positive = static_cast <double> (sum_positive) / pos_counter;                               // positive average calculation
            }
        else avg_positive = 0.0;

        if (non_pos_counter > 0)                                                                                // run-time error prevention
            {
                avg_non_pos = static_cast <double> (sum_non_pos) / non_pos_counter;                             // negative average calculation
            }
        else avg_non_pos = 0.0;

        cout << "The number of positive integers entered is: " << pos_counter << endl;
        cout << "The number of non-positive integers entered is: " << non_pos_counter << endl << endl;

        cout << "The sum of all positive integers is: " << sum_positive << endl;                                // Part A
        cout << "The average of all positive integers is: " << avg_positive << endl << endl;                    // Part B

        cout << "The sum of all non-positive integers is: " << sum_non_pos << endl;                             // Part C
        cout << "The average of all non-positive numbers is: " << avg_non_pos << endl << endl;                  // Part D

        cout << "The sum of all entered integers is: " << sum_all_nums << endl;                                 // Part E
        cout << "The average of all entered integers is: " << avg_all_nums << endl << endl;                     // Part F

        cout << "Would you like to perform another calculation?\n"
             << "Enter Y to continue, or any other key to quit: ";
        cin >> exit_status;

        cout << endl;

    } while (exit_status == 'Y' || exit_status == 'y');                                                       // Loop condition to perform add'l calculations

    cout << "See you next time!!" << endl << endl;

}

void Q2()
{

    char exit_status;             // variable to continue or terminate loop

    do {

        int entry_counter = 0;    // Counts how many inputs user has entered.
        int pos_counter = 0;      // counters to keep track of the # of positive and non-positive integers.
        int non_pos_counter = 0;  // We assume Zero is not a Positive Integer as in Discrete Math set theory.
        int sum_positive = 0;     // sum variables for sum calculations.
        int sum_non_pos = 0;
        int sum_all_nums = 0;
        double avg_positive = 0;  // average variables for average calculations.
        double avg_non_pos = 0;
        double avg_all_nums = 0;
        int input_number;

        cout << "\t=> Sum and Average Calculator <=" << endl << endl;

        cout << "Please enter 10 integers, each followed by Enter: " << endl;

        while (entry_counter < 10)
            {
                cin >> input_number;
                entry_counter++;

                    if (input_number > 0)
                        {
                            sum_positive = sum_positive + input_number;
                            pos_counter++;
                        }
                    else
                        {
                            sum_non_pos = sum_non_pos + input_number;
                            non_pos_counter++;
                        }
            }

        sum_all_nums = sum_positive + sum_non_pos;                                                              // sum of all numbers calculation
        avg_all_nums = (sum_positive + sum_non_pos) / 10.0;                                                     // average of all numbers calculation

        if (pos_counter > 0)                                                                                    // run-time error prevention
            {
                avg_positive = static_cast <double> (sum_positive) / pos_counter;                               // positive average calculation
            }
        else avg_positive = 0.0;

        if (non_pos_counter > 0)                                                                                // run-time error prevention
            {
                avg_non_pos = static_cast <double> (sum_non_pos) / non_pos_counter;                             // negative average calculation
            }
        else avg_non_pos = 0.0;

        cout << endl << endl;

        cout << "The number of positive integers entered is: " << pos_counter << endl;
        cout << "The number of non-positive integers entered is: " << non_pos_counter << endl << endl;

        cout << "The sum of all positive integers is: " << sum_positive << endl;                                // Part A
        cout << "The average of all positive integers is: " << avg_positive << endl << endl;                    // Part B

        cout << "The sum of all non-positive integers is: " << sum_non_pos << endl;                             // Part C
        cout << "The average of all non-positive numbers is: " << avg_non_pos << endl << endl;                  // Part D

        cout << "The sum of all entered integers is: " << sum_all_nums << endl;                                 // Part E
        cout << "The average of all entered integers is: " << avg_all_nums << endl << endl;                     // Part F

        cout << "Would you like to perform another calculation?\n"
             << "Enter Y to continue, or any other key to quit: ";

        cin >> exit_status;

    } while (exit_status == 'Y' || exit_status == 'y');

    cout << endl << endl;
    cout << "See you next time!!" << endl << endl;
}