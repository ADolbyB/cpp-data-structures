/**
 * Joel Brigida
 * October 8, 2020
 * COP 3014-003
 * Dr. Sareh Taebi
 * Lab #2 Bonus: A weight conversion calculator
*/

#include <iostream>

using namespace std;

const double LBS_PER_KG = 2.2046;
const double OZ_PER_LB = 16.0;                                                          // const variables used for conversion constants
const double GMS_PER_KG = 1e3;

void lab2(void);                                                                        // Void function called in main for the calculator function
void input(int input_type, int& weight1, int& weight2);                                 // Reads user input
double convert_kg_to_lbs(int& kilos, int& grams);                                       // Performs conversion from kg to lbs
double convert_lbs_to_kg(int& pounds, int& ounces);                                     // Performs conversion from lbs to kg
void output(int output_type, double output_value);                                      // Prints converted value as output with proper format
void run_again(void);                                                                   // Asks for user input and runs the calculator program again

int main()
{

    lab2();                                                                             // function call to start lab2();

    return 0;
}

void lab2(void)
{
    int conversion_type = 0;
    int weight_large;                                                                   // unit of pounds or kilos
    int weight_small;                                                                   // unit of ounces or grams
    double converted_value;                                                             // returned value from either conversion calculation

    cout << "\t=> Metric and Imperial weight calculator <=" << endl << endl;

    do {

        cout << "What type of conversion do you need\?" << endl;
        cout << "For kg to lb enter \'1\'" << endl;
        cout << "For lb to kg enter \'2\'" << endl;
        cin >> conversion_type;

        if (!(conversion_type))                                                         // infinite loop fix: if the input type is not correct...
            {
                cout << "Improper input, try again..." << endl << endl;                 // ...output this error message...
                cin.clear();                                                            // ...clear the input stream error flag...
                cin.ignore(10000,'\n');                                                 // ...ignore/remove up to 10000 characters in the input stream up to the '\n'
            }
        else if (conversion_type == 1)
            {
                input(1, weight_large, weight_small);                                   // Function call to take user input
                converted_value = convert_kg_to_lbs(weight_large, weight_small);        // Function call for kg -> lbs conversion
                cout << endl << endl;
                output(1, converted_value);                                             // Function call for outputting converted value
                cout << endl << endl;
                run_again();                                                            // Function call to run calculator again
            }
        else if (conversion_type == 2)
            {
                input(2, weight_large, weight_small);                                   // Function call to take user input
                converted_value = convert_lbs_to_kg(weight_large, weight_small);        // Function call for lbs -> kg conversion
                cout << endl << endl;
                output(2, converted_value);                                             // Function call for outputting converted value
                cout << endl << endl;
                run_again();                                                            // Function call to run calculator again
            }
        else
            cout << "Improper input, try again..." << endl << endl;

    } while ( !(conversion_type == 1 || conversion_type == 2) );                          // Allows a retry on improper input
}

void input(int input_type, int& weight1, int& weight2)
{
    if (input_type == 1)
        {
            cout << endl << "\t=> Weight entry in kg and grams <=" << endl << endl;
            cout << "First, input kg as an integer: ";
            cin >> weight1;                                                             // accepts units of kg
            cout << "Now input grams as an integer: ";
            cin >> weight2;                                                             // accepts units of grams
        }
    else // if(input_type == 2)
        {
            cout << endl << "\t=> Weight entry in pounds and ounces <=" << endl << endl;
            cout << "First, input lbs as an integer: ";
            cin >> weight1;                                                             // accepts units of pounds
            cout << "Now input ounces as an integer: ";
            cin >> weight2;                                                             // accepts units of ounces
        }
}

double convert_kg_to_lbs(int& kilos, int& grams)
{
    return((kilos * LBS_PER_KG) + ((grams / GMS_PER_KG) * LBS_PER_KG));                 // algorithm for kilos to lbs conversion
}

double convert_lbs_to_kg(int& pounds, int& ounces)
{
    return((pounds / LBS_PER_KG) + ((ounces / OZ_PER_LB) / LBS_PER_KG));                // algorithm for lbs to kilos conversion
}

void output(int output_type, double output_value)
{
    cout.setf(ios::fixed);                                                              // set fixed decimal point
    cout.setf(ios::showpoint);                                                          // set always show decimal point
    cout.precision(3);                                                                  // set 3 decimal place precision

    if (output_type == 1)
        {
            cout << "This converted value is: " << output_value << " pounds";           // output in pounds as a decimal
        }
    else // if (output_type == 2)
        {
            cout << "This converted value is: " << output_value << " kilograms";        // output in kilos as a decimal
        }
}

void run_again(void)
{
    char choice;

    cout << "Would you like to perform another calculation\?" << endl;
    cout << "Enter Y or N: ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        {
            cout << endl << endl;
            lab2();                                                                     // calls lab2() function in main() again if user wants another calculation
        }
    else
        {
            cout << endl << "See you next time!!" << endl;
            return;
        }
}