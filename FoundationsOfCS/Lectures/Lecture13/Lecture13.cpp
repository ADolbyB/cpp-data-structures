/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 13
 * get() and put() functions
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;
void test_get_func(void);
void test_get_func2(void);
void test_get_func3(void);
void new_line(void);
void get_int(int& num1);
void main2(void);
void new_line2(istream& in_stream);
void main3(void);
void add_plus_plus(ifstream& fin, ofstream& fout);
void cctype(void);

int main()
{

    //test_get_func();
    //test_get_func2();
    test_get_func3();
    //new_line();
    //main2();
    //main3();
    //cctype();

    return 0;
}

void test_get_func(void)
{
    char next_symbol;

    cout << "Enter a char: ";
    cin.get(next_symbol);
    cout << "You entered: ";
    cout.put(next_symbol);
}

void test_get_func2(void)
{
    char c1;                                                            // takes an unlimited amount of characters input and then echos them back to user.

    cout << "Enter a line of text to echo: " << endl;

    do {                                                                // add a break point here and watch how the loop functions
        cin.get(c1);
        cout.put(c1);
        //cout << c1;                                                   // works the same with cout

    } while (c1 != '\n');

    cout << "The \'\\n\' is read from cin.get and echoed..." << endl;   // '\n' is read at the end of text line and echoed so that each line of text is on a new line.
}

void test_get_func3(void)
{
    ifstream fin;
    ofstream fout;
    char next_symbol;

    cout << "Opening File: infile.txt" << endl;
    fin.open("infile.txt");
    if (fin.fail())
        {
            cout << "Failed to open infile" << endl;
            exit(1);
        }
    fout.open("outfile.txt");
    cout << "Opening File: outfile.txt" << endl;
    if (fout.fail())
        {
            cout << "Failed to open infile" << endl;
            exit(1);
        }

    cout << "Generating Output:" << endl;
    while (!(fin.eof()))
        {
            fin.get(next_symbol);       // gets each character one by one
            fout.put(next_symbol);      // prints each character to file "outfile.txt"
            cout.put(next_symbol);      // prints to screen
        }

    fin.close();
    fout.close();
}

void main2(void)
{
    int number;
    get_int(number);
    cout << "final value read = " << number << endl
         << "end of demonstration" << endl;
}

void get_int(int& num1)
{
    char ans;
    do {
        cout << "enter input number: " ;
        cin >> num1;
        cout << "You entered: " << num1 << " is this correct?" << endl;
        cin >> ans;
        new_line2(cin);

    } while ((ans != 'Y') && (ans != 'y'));
}

void new_line(void)
{
    char symbol;
    do
    {
        cin.get(symbol);

    } while (symbol != '\n');
}

void new_line2(istream& in_stream)
{
    char symbol;

    do {

        in_stream.get(symbol);

    } while (symbol != '\n');
}

void main3(void)
{
    ifstream fin;
    ofstream fout;

    cout << "Begin editing files" << endl;

    fin.open("cad.txt");
    if (fin.fail())
        {
            cout << "Input file opening failed" << endl;
            exit(1);
        }

    fout.open("cplusplusad.txt");
    if (fout.fail())
        {
            cout << "output file opening failed" << endl;
            exit(1);
        }

    add_plus_plus(fin, fout);

    fin.close();
    fout.close();

    cout << "Finished editing files" << endl;
}

void add_plus_plus(ifstream& fin, ofstream& fout)
{
    char next_char;

    fin.get(next_char);                                                          // use fin.get(next_char) instead of a while (cin >> next_char)
    while (!(fin.eof()))                                                         // the .get function will preserve text spaces in the original file.
        {
            if (next_char == 'C')
                {
                    fout << "C++";
                }
            else
                {
                    fout << next_char;
                }
            fin.get(next_char);

        }
}

void cctype(void)
{
    char var1, var2, var3, var4, var5, var6;
    bool check1, check2;
    var1 = 'a';
    var2 = 'b';
    var3 = 'C';
    var4 = '$';
    var5 = '0';

    cout << "toupper('a') returns: " << toupper('a') << endl;
    cout << "toupper(var1) returns: " << toupper(var1) << endl;
    cout << "static_cast<char>(toupper('a')) = " << static_cast<char>(toupper('a')) << endl;

    var2 = toupper(var2);
    cout << "var2 is now: " << var2 << endl;

    var3 = tolower(var3);
    cout << "var3 is now: "<< var3 << endl;

    if (isalpha(var4))
        {
            check1 = true;
        }
    else
        {
            check1 = false;
        }
    cout << "isalpha(var4) is: " << check1 << endl;

    if (isdigit(var5))
        {
            check2 = true;
        }
    else
        {
            check2 = false;
        }
    cout << "isdigit(var5) is: " << check2 << endl;

    cout << endl << "Enter a line of text to echo without spaces:" << endl;

    do {
        cin.get(var6);
        if (isspace(var6))                                                          // proper boolean usage of the isspace() function
            {
                cout.put('_');                                                      // prints '_' in case of a space, tab, or newline
            }
        else
            {
                cout.put(var6);
            }

    } while (var6 != '\n');
}