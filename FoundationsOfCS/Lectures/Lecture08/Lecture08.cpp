/**
 * Joel Brigida
 * Lecture 08
 * Random Number Generators
 * Create a random number generator that gives a number between 0 and 1
*/

#include <ctime>                                        // required for time() function
#include <cstdlib>                                      // required for rand() and srand() functions
#include <cmath>
#include <iostream>

using namespace std;

void Q1(void);
void Q2(void);
void Q3(void);
void Q4(void);
void Q5(void);

int main()
{

    //Q1();
    //Q2();
    //Q3();                                             /** Q3 = INFINITE LOOP TEST ENVIRONMENT **/
    //Q4();
    Q5();                                               /** Q5 = INFINITE LOOP TEST ENVIRONMENT **/

    return 0;
}

void Q1(void)
{
    char exit_status;
    
    // Random number seed is based on the UNIX Epoch Time, which is continuously changing.
    //srand(time(0));                                   // If you don't change the seed srand(), then the rand() generated will always be the same sequence.
    srand(time(NULL));                                  // Alternate way to generate a random seed.

    do {
        int zero_one = rand() / RAND_MAX;               // both are type int, so it generates a 0 or 1

        int die1 = (rand() % 6) + 1;                    // Generates a number from 1 to six simulating rolling a die.
        int die2 = (rand() % 6) + 1;                    // The remainder can be 0 to 5 with "% 6" so we add one to make the set = [1, 6]

        int ten_to_21 = (rand() % 12) + 10;             // generate a random integer 10 <= ten_to_21 <= 21


        double norm_rand = (double)rand() / RAND_MAX;

        cout << "ten_to_21 = " << ten_to_21 << endl << endl;
        cout << "die roll 1 = " << die1 << " & die roll 2 = " << die2 << endl;
        cout << "You rolled a " << die1 + die2 << endl << endl;
        cout << "zero_one = " << zero_one << endl;
        cout << "norm_rand = " << norm_rand << endl;
        cout << "RAND_MAX = " << RAND_MAX << endl << endl;

        // For integers 10 < x < 21
        // (rand() % 10) generates integers 0 to 9
        // then adding 11 changes the bounds to: 11 <= x <= 20 (10 < x < 21).

        int eleven_to_20 = (rand() % 10) + 11;
        cout << "ten_to_21 = " << eleven_to_20 << endl;

        // for decimals 10.0 < x < 21.0
        // (11.0 * ((double)rand() / RAND_MAX)) generates decimals 0.0 < x < 11.0
        // adding 10 to this entire expression changes the bounds to 10.0 < x < 21.0

        double decimal_ten_to_21 = 10.0 + (11.0 * ((double)rand() / RAND_MAX));
        cout << "decimal_ten_to_21 = " << decimal_ten_to_21 << endl;

        // A different way to generate integers by rounding:
        // (9.0 * ((double)rand() / RAND_MAX)) generates decimals 0.0 < x < 9.0
        // round() makes the decimals whole numbers from 0 <= x <= 9
        // adding 11 changes the bounds to 11 <= x <= 20 (10 < x < 21)
        // typecast the output with (int) and now the output is integers 10 < x < 21

        double int_11_to_20 = 11.0 + round(9.0 * ((double)rand() / RAND_MAX));
        cout << "int_11_to_20 = " << (int)int_11_to_20 << endl << endl;

        cout << "Run again? Y or N: ";
        cin >> exit_status;
        cout << endl << endl;

    } while(exit_status == 'Y' || exit_status == 'y');
}

void Q2(void)
{
    char exit_status;

    //srand(time(0));
    srand(time(NULL));                                  // Another option - NULL sets to the current time.

    do {
        int loop_control;
        int counter = 1;
        cout << "How may random integers to generate? ";
        cin >> loop_control;
        cout << endl << endl;

        while (counter <= loop_control)
            {
                int ten_to_21 = (rand() % 10) + 11;     // Generates integers between 10 and 21 (10 < x < 21)

                cout << "#" << counter << " = " << ten_to_21 << endl;

                counter++;
            }

        cout << endl;
        cout << "Run again? Y or N: ";
        cin >> exit_status;
        cout << endl << endl;

    } while(exit_status == 'Y' || exit_status == 'y');
}

void Q3(void)
{
    /** INFINITE LOOP INTEGER TEST ENVIRONMENT **/
    char exit_status;

    //srand(time(0));
    srand(time(NULL));                                  // Another option - NULL sets to the current time.

    do {
        int counter = 1;

        cout << endl << endl;

        int ten_to_21 = (rand() % 899) + 101;

        while(ten_to_21 > 100 && ten_to_21 < 1000)
            {
                ten_to_21 = (rand() % 899) + 101;       // generates integers from 101 to 999

                cout << "#" << counter << " = " << ten_to_21 << endl;

                counter++;
            }
        cout << endl;
        cout << "Run again? Y or N: ";
        cin >> exit_status;
        cout << endl << endl;

    } while(exit_status == 'Y' || exit_status == 'y');
}

void Q4(void)
{
    char exit_status;

    //srand(time(0));
    srand(time(NULL));                                  // Another option - NULL sets to the current time.

    do {
        double decimal_11_to_20;
        int loop_control;
        int counter = 1;
        cout << "How may random decimals to generate? ";
        cin >> loop_control;
        cout << endl << endl;

        while(counter <= loop_control)
            {                                                                       // (11.0 * ((double)rand() / RAND_MAX)) generates decimals 0.0 < x < 11.0
                decimal_11_to_20 = 10.0 + (11.0 * ((double)rand() / RAND_MAX));     // Adding 10 changes the bounds to 10.0 < x < 21.0
                
                // (9.0 * ((double)rand() / RAND_MAX)) generates decimals 0.0 < x < 9.0
                cout << "#" << counter << " = " << decimal_11_to_20 << endl;        // round() and a typecast (int) on the output makes the decimals integers from 0 <= x <= 9
                
                // adding 11 changes the bounds to 11 <= x <= 20
                counter++;
            }
        cout << endl;
        cout << "Run again? Y or N: ";
        cin >> exit_status;
        cout << endl << endl;

    } while(exit_status == 'Y' || exit_status == 'y');
}

void Q5(void)
{
    char exit_status;

    //srand(time(0));
    srand(time(NULL));                      /** INFINITE LOOP TEST ENVIRONMENT **/
    
    /** PRINTS DECIMALS 10 < x < 21 **/

    do {
        double decimal_11_to_20;
        int counter = 1;
        decimal_11_to_20 = (50.0 * ((double)rand() / RAND_MAX));

        cout << "decimal number = " << decimal_11_to_20 << endl;

        while(decimal_11_to_20 > 0.01 && decimal_11_to_20 < 49.99)
            {
                decimal_11_to_20 = (50.0 * ((double)rand() / RAND_MAX));

                cout << "#" << counter << " = " << decimal_11_to_20 << endl;

                counter++;
            }
        cout << endl;
        cout << "Run again? Y or N: ";
        cin >> exit_status;
        cout << endl << endl;

    } while(exit_status == 'Y' || exit_status == 'y');
}