/**
 * Joel Brigida
 * Oct 14, 2020
 * Lecture 11:
 * An intro to classes and file stream
*/

#include <iostream>                                                                 // cin and cout streams
#include <fstream>                                                                  // allows use of ifstream and ofstream
#include <cstdlib>                                                                  // library for exit() function.
#include <string>
#include <iomanip>                                                                  // library for manipulators "setw" amd "setprecision" used after "<<"

using namespace std;

void part1(void);
void part2(void);
void part3(void);
void make_neat(ifstream& messy_file, ofstream& neat_file, int dec_places, int field_width);
void make_neat2(ifstream& messy_file, ofstream& neat_file, int dec_places, int field_width);
void test_output(void);

int main()
{

    //part1();
    //part2();
    part3();
    //test_output();

    return 0;
}

void part1(void)
{
    char file_name [20];                                                            // could also use a string instead
    cout << "What file would you like to open\? Write file name:" << endl;
    cin >> file_name;

    // declared objects
    ifstream read_input;                                                            // declared "variable" - they are actually objects.
    ofstream write_output;                                                          // define object "write_output" of class "ofstream"

    // initialized objects
    read_input.open(file_name);                                                     // uses user input char array to get file. (can also use a string)
    //read_input.open("infile.txt");                                                // object function "read_input" and
    write_output.open("outfile.txt");                                               // file will be created if it does not exist.

    if (read_input.fail())                                                          // member function using the dot operator (.) to inform which object is calling it.
        {
            cout << "No such file, read failed!!" << endl;
            exit(1);                                                                // terminates program with exit status "1"
        }
    if (write_output.fail())
        {
            cout << "Fail! Write output was not generated." << endl;
            exit(1);                                                                // part of #include <cstdlib>
        }

    int var1, var2, var3, var4;

    read_input >> var1 >> var2 >> var3 >> var4;                                     // read_input now associated with "infile"

    cout << var1 << " " << var2 << " " << var3 << " " << var4;                      // echos back the input read from "infile"

    int sum = var1 + var2 + var3 + var4;

    write_output << "The sum of values in the input file are: " << sum << endl;     // writes to file using object "write_output"
    write_output << "Yay, I got this to work!!" << endl;

    // Don't leave your files open!! They may get corrupted!!
    read_input.close();                                                             // member function "close" of the object "read_input" of class "ifstream"
    write_output.close();                                                           // member function "close" of the object "write_output" of class "ofstream"

    // good practice to close the files and then reopen them when needed.
    write_output.open("outfile.txt", ios::app);                                     // appends the file instead of starting from scratch.

    write_output << "Lets append this!! The sum of the variables is: " << sum << endl;

    write_output.close();
}

void part2(void)
{
    ifstream read_in;                                                               // use infile2.txt
    ofstream write_out;                                                             // define object "write_out" of class "ofstream"

    write_out.setf(ios::fixed);                                                     // formats output to the file as fixed decimal notation using "write_output"
    write_out.setf(ios::showpoint);                                                 // denotes that the decimal always be shown
    write_out.setf(ios::showpos);
    write_out.precision(2);                                                         // denotes 2 decimal places in this case.
    //write_out.width(5);                                                             // set field with of 5 spaces

    cout.setf(ios::fixed);                                                          // formats output to the file as fixed decimal notation using "write_output"
    cout.setf(ios::showpoint);                                                      // denotes that the decimal always be shown
    cout.setf(ios::showpos);                                                        // sets "show positive" flag
    cout.precision(2);                                                              // denotes 2 decimal places in this case.
    //cout.width(5);                                                                  // set field width to 5 spaces

    string file_name;                                                               // could also use a char array;
    cout << "What file would you like to open\? Write file name:" << endl;
    cin >> file_name;

    // initialized objects
    read_in.open(file_name);                                                        // uses user input char array to get file. (can also use a string)

    //read_input.open("infile.txt");                                                // object function "read_input" and
    write_out.open("outfile2.txt");                                                 // file will be created if it does not exist.

    if (read_in.fail())                                                             // member function using the dot operator (.) to inform which object is calling it.
        {
            cout << "No such file, read failed!!" << endl;
            exit(1);                                                                // terminates program with exit status "1"
        }
    if (write_out.fail())
        {
            cout << "Fail! Write output was not generated." << endl;
            exit(1);                                                                // part of #include <cstdlib>
        }

    int var1, var2, var3, var4;

    read_in >> var1 >> var2 >> var3 >> var4;                                        // reads variables from file as typecasted doubles

    int sum = var1 + var2 + var3 + var4;

    cout << var1 << " " << var2 << " " << var3 << " " << var4 << endl;              // echoes back declared variable values.

    write_out << "The sum of values in \"infile2.txt\" are: " << (double)sum << endl;
    write_out << "Yay, I got this to work!!" << endl;

    cout << "The sum of values in \"infile2.txt\" are: " << (double)sum << endl;

    // Don't leave your files open!! They may get corrupted!!
    read_in.close();                                                                // member function of the ifstream
    write_out.close();                                                              // member function of the ofstream

    cout << endl << "Setting field width with manipulator: " << setw(7) << 12 << setw(10) << setprecision(5) << (double)24 << setw(7) << 36 << endl;
                                                                                    // "setprecision()" stays in effect until change, but not "setw()"
    cout << endl << "\"setprecision()\" is still working on this line: " << 24.0 << " " << 23 << " " << 68.24 << endl;
}

void part3(void)
{
    ifstream filein;
    ofstream fileout;

    string file_name;                                                               // could also use a char array;
    cout << "What file would you like to open\? Write file name:" << endl;
    cin >> file_name;                                                               // use "rawdata.txt"

    filein.open(file_name);
    fileout.open("neat_data.txt");

    if (filein.fail())                                                             // member function using the dot operator (.) to inform which object is calling it.
        {
            cout << "No such file, read failed!!" << endl;
            exit(1);                                                                // terminates program with exit status "1"
        }
    if (fileout.fail())
        {
            cout << "Fail! Write output was not generated." << endl;
            exit(1);                                                                // part of #include <cstdlib>
        }

    make_neat(filein, fileout, 5, 12);

    filein.close();
    fileout.close();

    filein.open(file_name);
    fileout.open("neat_data.txt", ios::app);

    if (filein.fail())                                                              // member function using the dot operator (.) to inform which object is calling it.
        {
            cout << "No such file, read failed!!" << endl;
            exit(1);                                                                // terminates program with exit status "1"
        }
    if (fileout.fail())
        {
            cout << "Fail! Write output was not generated." << endl;
            exit(1);                                                                // part of #include <cstdlib>
        }

    fileout << endl << "Appended data from make_neat2: " << endl << endl;

    cout << endl << "Appended data from make_neat2: " << endl << endl;

    make_neat2(filein, fileout, 5, 12);

    filein.close();
    fileout.close();

    cout << endl << "End of program." << endl;
}

void make_neat(ifstream& messy_file, ofstream& neat_file, int dec_places, int field_width)
{
    neat_file.setf(ios::fixed);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(dec_places);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(dec_places);

    double data_next;

    //while (!(messy_file.eof()))                                                     // Also valid for end of file (not working right now)
    while (messy_file >> data_next)                                                 // only true if there is more data to read from file.
        {
            cout << setw(field_width) << data_next << endl;
            neat_file << setw(field_width) << data_next << endl;
        }

    neat_file.unsetf(ios::fixed);                                                   // MUST UNSET FLAGS IF YOU WANT A DIFFERENT OUTPUT LATER
    cout.unsetf(ios::fixed);                                                        // IN THIS CASE FOR THE NEXT FUNCTION TO PRODUCE OUTPUT IN SCIENTIFIC NOTATION
}

void make_neat2(ifstream& messy_file, ofstream& neat_file, int dec_places, int field_width)
{
    neat_file.setf(ios::scientific);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(dec_places);
    cout.setf(ios::scientific);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(dec_places);

    double data_next;

    //while (!(messy_file.eof()))                                                     // Also valid for end of file (not working right now)
    while (messy_file >> data_next)                                                 // only true if there is more data to read from file.
        {
            cout << setw(field_width) << data_next << endl;
            neat_file << setw(field_width) << data_next << endl;
        }
}

void test_output(void)
{
    double test_value1, test_value2, test_value3;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(5);

    cout << "Input 3 double numbers: ";
    cin >> test_value1 >> test_value2 >> test_value3;

    cout << endl << "The entered values are: " << test_value1 << " " << test_value2 << " " << test_value3 << endl;

    cout.unsetf(ios::fixed);                                                        // if you dont "unset" the fixed flag...
    cout.setf(ios::scientific);                                                     // ...the scientific notation is outputted incorrectly as "hexfloat"
    cout.precision(2);

    cout << "Now in scientific notation: " << endl;
    cout << endl << "The entered values are: " << test_value1 << " " << test_value2 << " " << test_value3 << endl;
}