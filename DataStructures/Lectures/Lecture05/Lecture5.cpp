/*****************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * This is the test driver for File Reading and Writing.
 * This reads numeric data stored in a file, computes the minimum, maximum,
 * average of the numbers, then write these statistics to an output file.
 * Input(keyboard): names of the input and output files
 * Input(file): a sequence of numeric values
 * Output(file): a count of the values, the minimum value, the maximum value,
 * and the average value
----------------------------------------------------------------------------*/

#include <iostream>                                 // cin, cout
#include <fstream>                                  // ifstream, ofstream
#include <string>                                   // string, getline()
#include <cassert>                                  // assert()
#include <cfloat>                                   // DBL_MIN and DBL_MAX
#include <iomanip>
#include <sstream>

using namespace std;

void file_io_review(void);

int main()
{

    file_io_review();

    return 0;

}

void file_io_review(void)
{

    cout << "This program computes the number, maximum, minimum, and" << endl
         << "average of an input list of numbers in one file," << endl
         << "and places its results in another file." << endl << endl;

    // User Input

    cout << "Enter the name of the input file: ";
    string inputFileName;                       // get name of input file

    getline(cin, inputFileName);                // open an input stream
    ifstream fin;                               // to the input file,

    fin.open(inputFileName.data());             // establish a connection,
    assert( fin.is_open() );                    // and check for success

    int count = 0;                              // number of values
    double reading,                             // value being processed
    maximum = DBL_MIN,                          // largest seen so far
    minimum = DBL_MAX,                          // smallest seen so far
    sum = 0.0;                                  // running total

    for (;;)                                    // infinite loop
        {
            fin >> reading;                     // read a value from file
            if ( fin.eof() ) break;             // if eof, quit

            count++;                            // update count
            sum += reading;

            if (reading < minimum)
                minimum = reading;              // minimum
            if (reading > maximum)
                maximum = reading;              // maximum
        }                                       // end loop

    fin.close();                                // close the connection

    // Output Section

    cout << "Enter the name of the output file: ";
    string outputFileName;
    
    getline(cin, outputFileName);               // open an output stream
    ofstream fout(outputFileName.data());       // establish connection
    assert( fout.is_open() );                   // check if successful

    fout << endl << "There were " << count << " values"; // write results to file

    if (count > 0)
        fout << endl << "    ranging from " << minimum << " to " << maximum
             << endl << "    and their average is " << sum / count << endl;

    fout.close(); // close output stream

    cout << "Processing complete." << endl;
}