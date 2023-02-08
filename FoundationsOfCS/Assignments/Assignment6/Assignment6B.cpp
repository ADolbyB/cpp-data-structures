/**
 * Joel Brigida
 * COP 3014-003
 * Assignment #6 - Counting with Classes
 * Dr. Sareh Taebi
*/

#include <iostream>                                                                             // directive for cin, cout, >> & <<
#include <fstream>                                                                              // directive for stream classes

using namespace std;

class LetsCount                                                                                 // Class declaration
{
    public:

        void set_counter(int counter_value);                                                    // mutator member function to set counter values.
        void increase_counter(void);                                                            // member function which increments counter value by 1
        void decrease_counter(void);                                                            // member function which decrements counter value by 1
        int get_count(void);                                                                    // accessor member function which retrieves the counter value.
        void print_count(ostream& output_file);                                                 // function which prints the counter value to any output stream.

    private:

        int counter;                                                                            // private member variable accessible only by class member functions.

};

void banner(void);
void assignment6(void);

int main()
{

    banner();

    return 0;
}

void banner(void)
{

    char word_banner[48] = "# =>> Assignment 6: Counting with Classes <<= #";
    int i;

    for (i = 0; i < 47; i++)
        cout << "#";
    cout << endl;
    for (i = 0; i < 47; i++)
        cout << word_banner[i];
    cout << endl;
    for (i = 0; i < 47; i++)
        cout << "#";

    cout << endl;

    assignment6();

}

void assignment6(void)
{
    char choice;                                                                                // do-while loop control variable.

    LetsCount countUp, countDown;                                                               // object declarations of class LetsCount.

    do {

        int num_entries;                                                                        // user entered variable for total number of integers.
        int input_number;                                                                       // variable that represents each individual integer entry by user.

        cout << endl << "Enter the amount of integers you will be inputting: ";
        cin >> num_entries;

        countUp.set_counter(0);                                                                 // object "countUp" calls mutator function "set_counter" to set 1st counter to zero which counts up
        countDown.set_counter(num_entries);                                                     // object "countDown" calls mutator function "set_counter" to set 2nd counter to "num_entries" which counts down

        cout << endl << "Enter an integer and press enter after each input: " << endl;
        for (int i = 0; i < num_entries; i++)                                                   // for loop accepts user entry until "num_entries" is reached.
            {
                cin >> input_number;

                if (input_number >= 0)                                                          // if the input value is negative, we don't move any counters.
                    {
                        countUp.increase_counter();                                             // increment 1st counter when positive value is input
                        countDown.decrease_counter();                                           // decrement 2nd counter when positive value is input.
                    }
            }

        cout << endl << "The number of positive integers entered (including zero) = ";
        countUp.print_count(cout);                                                              // call "countUp" member function "print_count" to send counter output to the screen.

        cout << endl << "The number of non-positive integers entered = ";
        countDown.print_count(cout);                                                            // call "countDown" member function "print_count" to send counter output to the screen.

        cout << endl << "The total number of integers entered = "                               // calls accessor member function "get_count" for both objects, adds both counters together and displays total # of integers to the screen.
             << countUp.get_count() + countDown.get_count() << endl;

        cout << endl << "Would you like to repeat the program? Y or N: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << endl << "Goodbye!" << endl;

}

void LetsCount::set_counter(int counter_value)                                                  // Class "LetsCount" member function "set_counter" is a mutator function.
{
    counter = counter_value;                                                                    // takes the integer argument and sets private member variable "counter" to that integer.
}

void LetsCount::increase_counter(void)                                                          // Class member function to increase the counter.
{
    counter++;
}

void LetsCount::decrease_counter(void)                                                          // Class member function to decrease the counter.
{
    counter--;
}

int LetsCount::get_count(void)                                                                  // Class member function "get_count" is an accessor function.
{
    return (counter);                                                                           // returns counter value as an integer.
}

void LetsCount::print_count(ostream& output_file)                                               // member function that can output data to any stream type.
{
    output_file << counter << endl;                                                             // takes a stream type argument and outputs data to that stream type
}