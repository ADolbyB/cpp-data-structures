/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * This is the Midterm I compiled into a working program
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void findproduct(void);
void Num_Product(ifstream& fin, int& product);
void noUpper(void);
void output_data1(void);
void output_data2(ofstream& fout);
void output_data3(ostream& outfile);

int main()
{

    //findproduct();
    //noUpper();
    //output_data1();

    return 0;
}

void findproduct(void)
{
    int product;
    ifstream fin;

    fin.open("input.txt");
    if(fin.fail())
        {
            cout << "error" << endl;
            exit(1);
        }

    Num_Product(fin, product);

    cout << "The product of all positive integers = " << product << endl;

    fin.close();
}

void Num_Product(ifstream& fin, int& product)
{
    int next;
    int total = 1;

    while(fin >> next)
        {
            if (next > 0)
                {
                    total = next * total;
                }
        }
    product = total;
}

void noUpper(void)
{
    char next_symbol;
    ifstream fin;

    fin.open("infile.txt");
    if (fin.fail())
        {
            cout << "error" << endl;
            exit(1);
        }

    while (!(fin.eof()))                                                                        // can use a do-while loop also
        {
            fin.get(next_symbol);
            //if (next_symbol >= 'a' && next_symbol <= 'z')                                     // doesn't work properly (skips spaces)
            if (!isupper(next_symbol))                                                          // properly deletes the Upper Case Letters.
                {
                    cout.put(next_symbol);
                }
        }
    fin.close();
}

void output_data1(void)
{
    ofstream file_out;

    file_out.open("output.txt");
    if(file_out.fail())
        {
            cout << "error" << endl;
            exit(1);
        }

    //cout << "write a string to output to \'outfile.txt\' (no spaces): " << endl;
    //output_data2(file_out);

    cout << "cin.get outputs to the screen:" << endl;
    output_data3(cout);

    cout << "cin.get outputs to \'outfile.txt\':" << endl;
    output_data3(file_out);

    file_out.close();
}

void output_data2(ofstream& fout)
{
    string line_of_text2;

    cout << "enter a line of text: " << endl;                                                   // strings can't have spaces :-(
    cin >> line_of_text2;

    fout << line_of_text2 << endl;
}

void output_data3(ostream& outfile)
{
    char data;

    do {                                                                                        // could be a while loop

        cin.get(data);

        outfile << data;

    } while (data != '\n');                                                                     // could be (!outfile.eof ()) or (data != '\n') it’s ok.

    outfile << endl;                                                                            // eof is ctrl + z (windows) or ctrl + d (mac os, linux)
}