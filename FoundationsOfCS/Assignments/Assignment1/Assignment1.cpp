/**
 * Joel Brigida
 * COP 3014-003
 * Dr. Sareh Taebi
 * Assignment #1
*/

#include <iostream>

using namespace std;

int main()
{

    // Part a) Integer type input variable declarations
    int num_quarters, num_nickels, num_dimes;

    //Program Inputs: number of quarters (num_quarters), number of dimes (num_dimes), and number of nickels (num_nickels

    // Purpose of program and informative user messages
    cout << "=> Pocket Change Counter for Quarters, Dimes, and Nickels <=\n\n";

    // Part b) proper prompting to user
    cout << "At each one of the 3 prompts, please input an integer quantity for the number of coins.\n\n";

    // 1st output meesage to user
    cout << "How many quarters are in your pocket? ";

    // Part b) 1st program input / user prompt - the number of quarters
    cin >> num_quarters;

    // 2nd output message to user
    cout << "\nHow many dimes are in your pocket? ";

    /// Part b) 2nd program input - the number of dimes
    cin >> num_dimes;
    
    // 3rd output meesage to user
    cout << "\nHow many nickels are in your pocket? ";

    // Part b) 3rd program input - the number of nickels
    cin >> num_nickels;                                                                

    // Part c) Integer type output variable declaration Expected output = total value of the of coins in cents
    int total_cents;

    /** Part d) "How do you relate the inputs to the output?"

    The inputs are the integer quantity of individual nickels, dimes, and quarters in the users pocket. The desired output is a total value
    of all the coins in cents. Since the inputs are numbers of individual coins (num_quarters, num_dimes, num_nickels), each separate coin quantity
    must be multiplied by its value in cents. These 3 separate total quantities (denominated in cents) must be calculated 1st (which is why they
    are in parenthesis), then all added together to get the total value in cents output. The 3 individual values of quarters, nickels, and
    dimes are all added up and the stored into the variable "total_cents" 
    */

    // Also Part d) This is the algorithm to solve the problem
    total_cents = (num_quarters * 25) + (num_dimes * 10) + (num_nickels * 5);

    // Part e) Informative output statement to user indicating total value of coins in cents
    cout << "\n\nThe coins in your pocket are worth a total of " << total_cents << " cents.\n\n";
    
    return 0;
}