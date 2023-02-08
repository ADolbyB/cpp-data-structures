/**
 * Joel Brigida
 * COP 3014-003
 * Assignment #6
 * Dr. Sareh Taebi
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class LetsCount
{
    public:

        void set_counter(int counter_value);
        void increase_counter(void);
        void decrease_counter(void);
        int get_count(void);
        void print_count(ostream& output_file);

    private:

        int counter;
};

void assignment6(void);

int main()
{

    assignment6();

    return 0;
}

void assignment6(void)
{

    int i, num_entries, input_number;
    int pos_count, nonpos_count;

    LetsCount pos_countup, nonpos_countdown;

    cout << "Enter the amount of integers you will be inputting: ";
    cin >> num_entries;

    pos_countup.set_counter(0);
    nonpos_countdown.set_counter(num_entries);

    cout << "positive counter value:" << pos_countup.get_count() << endl;  //debug
    cout << "negative counter value" << nonpos_countdown.get_count() << endl;  //debug

    cout << endl << "Enter an integer and press enter after each input: " << endl;
    for (i = 0; i < num_entries; i++)
        {
            cin >> input_number;

            if (input_number >= 0)
                {

                    pos_countup.increase_counter();
                    nonpos_countdown.decrease_counter();
                }
                    cout << "up counter is now: " << pos_countup.get_count() << endl;       //debug
                    cout << "down counter is now: " << nonpos_countdown.get_count() << endl;  //debug
        }

    pos_count = pos_countup.get_count();
    nonpos_count = nonpos_countdown.get_count();

    cout << "number of positives and zero: " << pos_count << endl;   //DEBUG
    cout << "number of non-positives: " << nonpos_count << endl;     //DEBUG

    //pos_countup.print_count(cout);

    //cout << endl << "The number of positive integers entered (including zero) = " << pos_countup.get_count() << endl;
    //cout << "The number of non-positive integers entered = " << nonpos_countdown.get_count() << endl;

}

void LetsCount::set_counter(int counter_value)
{
    counter = counter_value;
}

void LetsCount::increase_counter(void)
{
    counter++;
}

void LetsCount::decrease_counter(void)
{
    counter--;
}

int LetsCount::get_count(void)
{
    return (counter);
}

void LetsCount::print_count(ostream& output_file)
{
    output_file << counter << endl;
}