/**
 * Compiled & Modified by Joel Brigida
 * Adapted into C++ training program from user "Morfidon"
 * https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
*/

#include <iostream>
#include <string>

using namespace std;

void newline(istream& input_stream);
void iostream_fail(void);
void part_2(void);
void part_3(void);
void part_4(void);
void part_5(void);

int main()
{

    //iostream_fail();
    //part_2();
    part_3();
    //part_4();
    //part_5();

    return 0;
}

void newline(istream& input_stream)                                                               // discards unwanted characters in any input stream
{
    char symbol;

    do {

        input_stream.get(symbol);

    } while (symbol != '\n');
}

void iostream_fail(void)
{
    int age;

    string name;

    cout << "Give me your name and surname (2 words):"<< endl;
    cin >> name;
    cout << endl << "You entered: " << name << endl;
    cout << "Notice the 2nd word did not print to the screen..." << endl;

    cout << endl << "Give me your age:" << endl;
    cin >> age;
    cout << endl << "You Entered: " << age << endl;

    cout << endl << "Wait...What happened?" << endl;
    cout << "cin.rdstate() = " << cin.rdstate() << endl;        // new line is here: cin state 0 is goodbit, cin state 4 is fail state
}

void part_2(void)
{
    string name;

    cout << "Give me your name and surname (2 words):"<< endl;
    cin >> name;
    cout << "You entered: " << name << endl;

    int age;
    cout << "Give me your age:" <<endl;
    cin >> age;                         // newline is here now - causing input type mismatch and input stream failure

    cout << endl << "cin.rdstate() = " << cin.rdstate() << endl;
    cin.clear();                        // clears input stream error flag
    cout << endl << "After clearing error flag: cin.rdstate() = " << cin.rdstate() << endl;

    cout << endl << "Error Flag cleared. Give me your age: " << endl;
    cin >> age;                         // newline is still here clogging up the input stream
    cout << endl << "Notice the user prompt for \'age\' is still skipped" << endl;
}

void part_3(void)
{
    string name;

    cout << "Give me your name and surname (2 words):" << endl;
    cin >> name;
    cout << "You entered: " << name << endl;
    cout << endl << "Your last name was skipped because \'cin >>\' ignored the space..." << endl;
    cout << "The 2nd word is now stuck in the input stream...time to clear the stream..." << endl;

    cout << endl << "Not an input type mismatch, so cin.rdstate() = " << cin.rdstate() << endl;

    //cin.ignore(10000, '\n');                 // removes the 1st 10000 characters until it sees a '\n', which is the 2nd word that is "stuck" in the input stream
    newline(cin);                              // alternate way to do discard characters in input stream

    cout << "...Stream cleared" << endl;

    int age;                            // now there is no type mismatch that causes the input stream to fail
    cout << endl << "Give me your age:" << endl;
    cin >> age;                         // not a problem unless user types a character response for 'age'
    cout << "You entered: " << age << endl;
    cout << endl << "cin.rdstate() = " << cin.rdstate() << endl;
}

void part_4(void)
{
    int age;

    cout << "Enter age as a number or word: ";
    if (cin >> age)                     // will return false if input types don't match
        {
            cout << "You entered: " << age << endl;
            cout << endl << "cin.rdstate() = " << cin.rdstate() << endl;
        }
    else
        {
            cout << "Input failure due to type mismatch" << endl;
            cout << endl << "cin.rdstate() = " << cin.rdstate() << endl;
        }
}

void part_5(void)
{
    string name;
    cout << "Enter your name and surname:" << endl;
    cin >> name;
    cout << "You entered: " << name << endl;
    cout << "Clearing input stream..." << endl;
    cin.ignore(10000, '\n');            // removes the 2nd word that is "stuck" in the input stream

    int age;
    cout << endl << "Enter your age (test integer or character): ";

    if (cin >> age)
        {
            cout << "cin.rdstate() = " << cin.rdstate() << endl;
            cout << "You entered: " << age << endl;
        }
    else
        {
            cout << endl << "Before clearing error flag: cin.rdstate() = " << cin.rdstate() << endl;
            cin.clear();                // clears input stream error flag
            cin.ignore(10000, '\n');    // removes the characters clogging the input stream
            cout << "After clearing error flag: cin.rdstate() = " << cin.rdstate() << endl;
            cout << endl << "Enter your age as an integer only: ";
            cin >> age;
            cout << "You entered: " << age << endl;
        }
}