/**
 * Joel Brigida
 * COP 3014-003
 * Dr. Sareh Taebi
 * September 28, 2020
 * Assignment 3: A Function which lists all prime numbers based on user entry
*/

#include <iostream>
#include <cmath>                                                                        // library used for sqrt() function

void Q1(void);                                                                          // void function for Prime Number Finder
void Q2(void);                                                                          // Alpha program with "break" statement (not allowed)

using namespace std;

int main()
{

    Q1();                                                                               // Function call for Prime Number Finder
    //Q2();

    return 0;
}

void Q1(void)
{

    char exit_status;                                                                   // do-while loop condition variable.

    cout << "\t=> Prime Number Finder <=" << endl << endl;
    cout << "=> Lists all prime numbers up to the user entered value <=" << endl << endl;

    do {

        int user_entry;
        int prime_suspect, divisor;                                                     // outer loop (prime_suspect) and inner loop (divisor) control variables.
        int number_of_primes = 0;                                                       // counter variable for # of prime numbers printed on the list.
        bool prime = true;                                                              // "prime" begins as true and remains true if "prime_suspect" integer is evaluated as having no zero-remainder quotients.

        cout << "Enter an integer of at least 2 to evaluate: ";
        cin >> user_entry;
        cout << endl;

        if (user_entry >= 2)                                                            /** 2 is a prime number, so I included it in the list of primes as a "bonus" **/
            {
                cout << "List of primes between 2 and " << user_entry << ":" << endl << endl;
                for (prime_suspect = 2; prime_suspect <= user_entry; prime_suspect++)   // outer loop "prime_suspect" counts every integer from 2 <= user_entry to check each one if they are prime.
                    {
                        prime = true;                                                   // value of prime must be reset after each outer loop cycle, in case a non-prime was found on the previous inner loop cycle.

                        for (divisor = 2; divisor <= sqrt(prime_suspect); divisor++)    // Inner loop cycles through all integers from 2 <= sqrt(user_entry) to search for a quotient with no remainder.
                            {
                                if (prime_suspect % divisor == 0)
                                    {
                                        prime = false;                                  // a zero-remainder quotient means the number is not prime, so it must be excluded from the printed list of primes.
                                    }
                            }
                        if (prime == true)
                            {
                                cout << prime_suspect << "  ";                          // only prints after the inner loop completes a full cycle without finding a zero-remainder quotient.

                                number_of_primes++;                                     // counts # of primes determined by the algorithm. This # is printed after the list of numbers.
                            }
                    }

                cout << endl << endl;
                cout << "Amount of prime numbers from 2 to " << user_entry << ": " << number_of_primes << endl;
            }

        else
            {
                cout << "Invalid Entry!!";                                              // Error statement if user enters a value < 2.
                cout << endl;
            }

        cout << endl;
        cout << "Would you like to evaluate another number?" << endl;
        cout << "Enter Y for yes, any other key to exit: ";
        cin >> exit_status;
        cout << endl;

    } while (exit_status == 'Y' || exit_status == 'y');                                // Loop condition for do-while

    cout << endl;

    cout << "See you next time!!" << endl << endl;

}

void Q2(void)
{                         /** This is the original Alpha Program - NO break statements allowed **/

    char exit_status;                                                                   // do-while loop condition variable.

    cout << "\t=> Prime Number Finder <=" << endl << endl;
    cout << "=> Calculates and lists all primes up to user entered value <=" << endl << endl;

    do {                                                                                // do-while loop for repeatable calculations.

        int user_entry;
        int prime_suspect, divisor;                                                     // outer loop (prime_suspect) and inner loop (divisor) control variables.
        bool prime;                                                                     // "prime" is true if "prime_suspect" integer is found to be a prime number.

        cout << "Enter an integer greater than 2 to evaluate: ";
        cin >> user_entry;
        cout << endl;

        if (user_entry >= 3)                                                            // The prime calculation only works for integers >= 3 because 2 is an even number.
            {
                cout << "2 is prime" << endl;                                           // 2 is prime, so I added this line just for list accuracy.
                for (prime_suspect = 3; prime_suspect <= user_entry; prime_suspect++)   // outer loop "prime_suspect" counts up from 3 (start point) to the user entered value. Each of these integers are checked one by one if they are prime.
                    {
                        for (divisor = 2; divisor <= sqrt(prime_suspect) ; divisor++)   // The inner loop cycles through all integers less than the user entry to use as a divisor for "prime_suspect" to determine if the quotient has a remainder.
                            {
                                if (prime_suspect % divisor == 0)                       // the inner loop must keep cycling until 1) either a non-prime is found (prime_suspect % divisor == 0), or 2) (divisor < prime_suspect)
                                    {                                                   // to make verify if our "prime_suspect" is prime.
                                        prime = false;
                                    }
                                else
                                    {
                                        prime = true;
                                    }
                                if (prime == false)                                     // as soon as a non-prime is found (prime_suspect % divisor == 0) results in (prime == false) we must jump out of the inner loop with a "break" to advance to the next
                                    break;                                              // "prime_suspect" value immediately to so the value of "prime" for this "prime_suspect" value doesn't change to "true" on the next inner loop cycle
                            }
                        if (prime == true)
                            cout << prime_suspect << " is prime" << endl;               // only prints if the "prime_suspect" is found to be prime, which happens when the inner loop completes a cycle without finding (prime_suspect % divisor == 0)
                    }
                cout << endl;
            }
        else
            {
                cout << "Invalid Entry!!";                                              // Error statement if user enters a value < 3.
                cout << endl;
            }

        cout << endl;
        cout << "Would you like to evaluate another number?" << endl;
        cout << "Enter Y for yes, any other key to exit: ";
        cin >> exit_status;                                                             // user entry at end of calculations to repeat the Prime Number Finder function again.

        cout << endl;

    }
    while (exit_status == 'Y' || exit_status == 'y');                                   // Loop condition for do-while

    cout << endl;
    cout << "See you next time!!" << endl << endl;

}