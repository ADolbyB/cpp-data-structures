/**
Joel Brigida
Lecture 3
Data Types
*/


#include <iostream>
#include <string>                                                           /// Must be included to use variable type "string"

using namespace std;                                                        /// Allows ommission of "std::" before i/o commands
                                                                            /// Ex: "cout" is actually "std::cout" and "cin" is actually "std::cin"
                                                                            /// the "::" is called the "scope resolution operator"
int main()
{
    double price1, price2;
    price1 = 31.35813, price2 = 3.89123;

    string your_name = "\t==> Joel Brigida <==";                            /// Variable declaration of type "string"
    string message = "\t==> Coding Czar <==";

    cout << your_name << endl << message << endl << endl;                   /// Prints string "your_name", line break, then "message"

    bool boolean_var1, boolean_var2, boolean_var3, boolean_var4;            /// Variable declaration of type "boolean"
    boolean_var1 = true, boolean_var2 = false;
    boolean_var3 = 1, boolean_var4 = 0;

    cout << "bool variable \'boolean_var1\' has value: " << boolean_var1 << endl;
    cout << "bool variable \'boolean_var2\' has value: " << boolean_var2 << endl;
    cout << "bool variable \'boolean_var3\' has value: " << boolean_var3 << endl;
    cout << "bool variable \'boolean_var4\' has value: " << boolean_var4 << endl << endl;

    cout.setf(ios::fixed);                                                  /// Specifies fixed decimal point notation
    cout.setf(ios::showpoint);                                              /// Specifies that decimal point will always be shown
    cout.precision(2);                                                      /// Specifies that 2 decimal places will always be shown

    cout << "The 1st price is: $" << price1 << endl;                        /// Note that 1st price gets rounded up to 31.36
    cout << "The 2nd price is: $" << price2 << endl << endl;

    cout << "Short Integers occupy this many bytes: " << sizeof(short) << endl;
    cout << "Integers occupy this many bytes: " << sizeof(int) << endl;
    cout << "Long Integers occupy this many bytes: " << sizeof(long int) << endl;
    cout << "Doubles occupy this many bytes: " << sizeof(double) << endl;
    cout << "Long Doubles occupy this many bytes: " << sizeof(long double) << endl;
    cout << "Floats occupy this many bytes: " << sizeof(float) << endl;
    cout << "Chars occupy this many bytes: " << sizeof(char) << endl;
    cout << "Strings occupy this many bytes: " << sizeof(string) << endl << endl;

    char letter1, letter2, letter3;                                         /// Variables can be declared at any place in the function

    cout << "Enter 2 letters of your initials: ";
    cin >> letter1 >> letter2;

    cout << endl;                                                           /// Prints a new line

    cout << "Your 2 initals are: " << letter1 << letter2 << endl << endl;
    cout << "How about with a space?" << endl << endl;

    letter3 = ' ';

    cout << letter1 << letter3 << letter2 << endl << endl;

    cout << "Bye Bye!!" << endl << endl;

    string pet_name, middle_name, alter_ego;

    cout << "Enter the name of your pet: ";
    cin >> pet_name;
    cout << endl;
    cout << "Enter your Middle Name: ";
    cin >> middle_name;
    cout << endl << endl;

    alter_ego = pet_name + " " + middle_name;

    cout << "The name of your alter-ego is: " << alter_ego << "." << endl;



    return 0;
}
