/**
 * Joel Brigida
 * COP 3014-003
 * October 10, 2020
 * Dr. Sareh Taebi
 * Assignment #4: Coin Change Calculator
*/

#include <iostream>
#include <limits>                                                                               // needed for "cin.ignore(numeric_limits<streamsize>::max(), '\n')" (Line 102)

using namespace std;

void banner(void);                                                                              // banner for start of program
void assignment4(void);                                                                         // "main" function for assignment 4
void read_input(int& cents);                                                                    // handles input parameter
void input_confirmation(int& cents);                                                            // handles input confirmation
void compute_coins(int coin_value, int& num, int& amount_left);                                 // computes # of coins as per user entry
void print_output(int total_change, int quarters, int dimes, int nickels, int pennies);         // displays the calculated output
void run_again(bool& repeat);                                                                   // prompts for repeating the calculation again.

int main()
{

    banner();

    return 0;
}

void banner(void)
{
    int i;

    for (i = 1; i <= 46; i++)
        {
            cout << "#";
        }

    cout << endl << "#        => Coin Change Calculator <=        #" << endl;                   // a cool banner design "just for fun"

    for (i = 1; i <= 46; i++)
        {
            cout << "#";
        }

    cout << endl;

    assignment4();
}

void assignment4(void)
{
    int spare_change;                                                                           // begins as user entered value, then used for the leftover remainder from each coin calculation
    int total_change;                                                                           // stores the original user entered value for printing during output function
    int num_coins;                                                                              // interim output calculated from function "compute_coins()" as the number of a coin type
    int quarters, dimes, nickels, pennies;                                                      // stores the computed number of coins from "compute_coins()"
    bool repeat = false;                                                                        // boolean value of whether user wants to repeat the calculations process.

    do {

        read_input(spare_change);                                                               // prompts user for input parameter

        total_change = spare_change;                                                            // Saves user entered value separately for output function

        compute_coins(25, num_coins, spare_change);                                             // determines number of quarters
        quarters = num_coins;                                                                   // stores output as number of quarters

        compute_coins(10, num_coins, spare_change);                                             // determines number of dimes
        dimes = num_coins;                                                                      // stores output as number of dimes

        compute_coins(5, num_coins, spare_change);                                              // determines number of nickels
        nickels = num_coins;                                                                    // stores output as number of nickels

        compute_coins(1, num_coins, spare_change);                                              // determines number of pennies
        pennies = num_coins;                                                                    // stores output as number of pennies

        print_output(total_change, quarters, dimes, nickels, pennies);                          // prints output values

        run_again(repeat);                                                                      // prompts user if they want to do another calculation.

    } while (repeat == true);

    cout << endl << "See you next time!" << endl;

}

void read_input(int& cents)
{
    cout << endl << "Enter the change amount in cents between 1 and 99: ";
    cin >> cents;

    if (!(cents))                                                                               // infinite loop fix if user enters characters into input stream (see line 102)
        {
            cout << endl << "Invalid entry, Try again..." << endl;                              // source: https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
            cin.clear();                                                                        // clears input stream error flag if user enters non-numeric data
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                // removes <streamsize> characters up to "numeric_limits" and stops at '\n' to purge input stream
            read_input(cents);                                                                  // restart input function after bad data entry
        }                                                                                       // programmer note: still not a 100% fix: still produces partial bad output if user enters 2 numbers and characters
    else if (cents < 1 || cents > 99)
        {
            cout << endl << "Invalid entry, Try again..." << endl;
            read_input(cents);                                                                  // restart input function after bad data entry
        }
    else // (if cents >= 1 && cents <= 99)
        {
            input_confirmation(cents);                                                          // function call to confirm if user entered the proper input.
        }                                                                                       // programmer note: if this step is commented out and user entered 2 numbers and characters, then the entire program terminates with no output

}

void input_confirmation(int& cents)
{
    char choice;

    cout << endl << "You entered: " << cents << " cents. Is this correct\?" << endl;
    cout << endl << "Enter Y to continue, or N to try again: ";                                 // Verifies user entered the correct data and offers a retry
    cin >> choice;

    if (!(choice == 'Y' || choice == 'y'))
        {
            read_input(cents);
        }
}

void compute_coins(int coin_value, int& num, int& amount_left)                                  // algorithm for computing the number of coins to make proper change.
{
    if (coin_value == 1)
        {
            num = amount_left;                                                                  // pennies are "leftover" at the end, so no need to perform computation.
        }
    else // if (coin_value == 5 || coin_value == 10 || coin_value == 25)
        {
            num = amount_left / coin_value;                                                     // num = amount of coins necessary which is the whole number calculated from (amount_left / coin_value)
            amount_left = amount_left % coin_value;                                             // the remainder "amount_left" is the extra change left over that needs to go to the next lowest coin denomination when this function is called again.
        }
}

void print_output(int total_change, int quarters, int dimes, int nickels, int pennies)          // prints the output of calculations
{
    cout << endl << total_change << " cents is given as:" << endl;

    if (quarters == 1)                                                                          // prints proper singular or plural form nouns
        cout << quarters << " quarter" << endl;
    else
        cout << quarters << " quarters" << endl;
    if (dimes == 1)
        cout << dimes << " dime" << endl;
    else
        cout << dimes << " dimes" << endl;
    if (nickels == 1)
        cout << nickels << " nickel" << endl;
    else
        cout << nickels << " nickels" << endl;
    if (pennies == 1)
        cout << pennies << " penny" << endl << endl;
    else
        cout << pennies << " pennies" << endl << endl;
}

void run_again(bool& repeat)
{
    char choice;

    cout << "Would you like to perform another calculation\?" << endl;                          // prompts user to repeat calculations again
    cout << "Enter Y or N: ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        {
            repeat = true;                                                                      // boolean value for "assignment4()" as loop condition
            return;
        }
    else // if (any other choice)
        {
            repeat = false;
            return;
        }
}