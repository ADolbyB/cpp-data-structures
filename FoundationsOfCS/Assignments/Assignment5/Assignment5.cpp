/**
 * Joel Brigida
 * COP 3014-003
 * Assignment #5 - Random Number File Generator
 * Dr. Sareh Taebi
*/

#include <iostream>                                                                                 // directive for cin, cout, >> & <<
#include <fstream>                                                                                  // directive for ifstream & ofstream classes
#include <cstdlib>                                                                                  // directive for srand(), rand(), and exit()
#include <ctime>                                                                                    // directive for time() function
#include <cmath>                                                                                    // directive for sqrt() function
#include <iomanip>                                                                                  // directive for setw() and precision() manipulators.

using namespace std;

const int FIELD_WIDTH = 10;                                                                         // Field width value for "Results.txt"

void banner(void);                                                                                  // welcome banner for assignment 5
void assignment5(void);                                                                             // "main" function for assignment 5
void random_input(ofstream& outfile);                                                               // generates an unorganized file of random decimal numbers
void make_neat(ifstream& file_in, ofstream& neat_out, int& number_of_entries);                      // generates an organized file from the random numbers and counts the amount of numbers in the list.
double Averages(ifstream& infile, ofstream& outfile, int file_size);                                // calculates average of the random number list
void StdDeviation(ifstream& input, ofstream& output, double average, int file_size);                // calculates standard deviation of the random numbers

int main()
{

    banner();

    return 0;
}

void banner(void)
{

    char word_banner[47] = "#    =>> Random Number File Generator <<=    #";
    int i;

    for (i = 1; i <= 46; i++)
        cout << "#";
    cout << endl;
    for (i = 0; i < 46; i++)
        cout << word_banner[i];
    cout << endl;
    for (i = 1; i <= 46; i++)
        cout << "#";

    cout << endl;

    assignment5();

}

void assignment5(void)
{

    int number_of_entries = 0;                                                                      // total number of list entries generated from "random_input() function"
    double avg_of_entries;                                                                          // calculated average from "averages()" function

    ifstream fin;                                                                                   // declare input stream object
    ofstream fout;                                                                                  // declare output stream object

    random_input(fout);                                                                             // generates "Random_list.txt" - a random number of random decimal numbers.

    make_neat(fin, fout, number_of_entries);                                                        // generates "Results.txt" - an organized list of the random decimal numbers.

    avg_of_entries = Averages(fin, fout, number_of_entries);                                        // calculates and returns average of all the random numbers, then appends the value to "Results.txt".

    StdDeviation(fin, fout, avg_of_entries, number_of_entries);                                     // calculates the std deviation, then appends the value to "Results.txt'

}

void random_input (ofstream& outfile)
{

    int i, number_of_entries;                                                                       // 'number_of_entries' = amount of random decimals that will be generated in "Random_list.txt"
    double random_generated;                                                                        // each 'random_generated' is written to "Random_list.txt"

    srand(time(NULL));                                                                              // generates random number seed

    outfile.open("Random_list.txt");                                                                // function creates this file to print random numbers to.
    if(outfile.fail())                                                                              // if file fails to open, program exits.
        {
            cout << "Function \'random_input\' failed to open output file...exiting program" << endl;
            exit(1);
        }

    number_of_entries = (rand() % 899) + 101;                                                       // generates a random integer from 101 to 999 which determines how many random decimals to generate for "Random_list.txt"
    //number_of_entries = (rand() % 12) + 20;                                                       // DEBUG - algorithm test
    //cout << endl << "\'number_of_entries\' = " << number_of_entries << endl;                      // DEBUG - variable check

    cout.setf(ios::fixed);                                                                          // proper decimal number formatting for files and screen.
    cout.precision(6);
    outfile.setf(ios::fixed);
    outfile.precision(6);

    for (i = 1; i <= number_of_entries; i++)
        {
            random_generated = (50.0 * ((double)rand() / RAND_MAX));                                // generates decimal numbers: 0 < random_generated < 50
            outfile << random_generated << " ";                                                     // writes the random numbers to file "Random_list.txt"
        }

    cout << endl << "Generated file \"Random_list.txt\" of " << number_of_entries << " random numbers." << endl;

    outfile.close();                                                                                // close files before function ends to avoid data corruption

}

void make_neat(ifstream& file_in, ofstream& neat_out, int& number_of_entries)
{

    double next_value;                                                                              // local variable for reading decimals in "Random_list.txt"

    file_in.open("Random_list.txt");                                                                // opening newly created "Random_list.txt" to read data for input.
    if(file_in.fail())
        {
            cout << "Function \'make_neat\' failed to open input file...exiting program" << endl;
            exit(1);
        }

    neat_out.open("Results.txt");                                                                   // creating "Results.txt" to be an organized list.
    if(neat_out.fail())
        {
            cout << "Function \'make_neat\' failed to open output file...exiting program" << endl;
            exit(1);
        }

    neat_out.unsetf(ios::left);                                                                     // proper formatting for "Results.txt"
    neat_out.setf(ios::right);
    neat_out.setf(ios::showpos);

    while (file_in >> next_value)
        {
            neat_out << setw(FIELD_WIDTH) << next_value << endl;                                    // generates a neat file "Results.txt" based on input from "Random_list.txt"
            number_of_entries++;                                                                    // 'number_of_entries' is call by reference used to calculate average in 'Averages' function.
        }

    file_in.close();                                                                                // close files before function ends to avoid data corruption
    neat_out.close();

    neat_out.unsetf(ios::showpos);                                                                  // unset "showpos" flag so it doesn't affect appended output later.

    cout << endl << "\"Random_list.txt\" has now been organized into \"Results.txt\"" << endl;
    cout << endl << "\"Results.txt\" contains " << number_of_entries << " random numbers." << endl;

}

double Averages(ifstream& infile, ofstream& outfile, int file_size)
{

    double sum_of_randoms = 0;
    double avg_of_randoms, data_next;

    infile.open("Random_list.txt");                                                                 // opens "Random_list.txt" to run calculation
    if(infile.fail())
        {
            cout << "Function \'Averages\' failed to open input file...exiting program" << endl;
            exit(1);
        }
    outfile.open("Results.txt", ios::app);                                                          // appending to "Results.txt"
    if(outfile.fail())
        {
            cout << "Function \'Averages\' failed to open output file...exiting program" << endl;
            exit(1);
        }
    while (infile >> data_next)
        {
            sum_of_randoms += data_next;                                                            // sums all random numbers for the average calculation
        }

    avg_of_randoms = sum_of_randoms / file_size;                                                    // calculation of the average of all random numbers.

    cout << endl << "The average of all " << file_size << " random numbers = " << avg_of_randoms << endl;

    outfile << endl << "The average of all " << file_size << " random numbers = "                   // This statement is appended to file "Results.txt"
            << avg_of_randoms << endl;

    infile.close();
    outfile.close();

    return (avg_of_randoms);

}

void StdDeviation(ifstream& input, ofstream& output, double average, int number_of_entries)
{

    double diff_squared, difference, next_data, std_deviation;                                      // local variables for standard deviation calculation.
    double variance = 0;

    input.open("Random_list.txt");                                                                  // opens "Random_list.txt" to run calculation
    if (input.fail())
        {
            cout << "Function \'StdDeviation\' failed to open input file...exiting program" << endl;
            exit(1);
        }

    output.open("Results.txt", ios::app);                                                           // appending to "Results.txt"
    if (output.fail())
        {
            cout << "Function \'StdDeviation\' failed to open output file...exiting program" << endl;
            exit(1);
        }

    while (input >> next_data)
        {
            difference = average - next_data;                                                       // algorithm for calculating variance (used for std deviation)
            diff_squared = difference * difference;
            variance += diff_squared;
        }

    std_deviation = sqrt(variance / number_of_entries);                                             // algorithm for calculating std deviation

    output << endl << "The standard deviation for all "                                             // This statement is appended to file "Results.txt"
           << number_of_entries << " random numbers = " << std_deviation << endl;

    cout << endl << "The standard deviation for all " << number_of_entries << " random numbers = " << std_deviation << endl;

    input.close();
    output.close();

}