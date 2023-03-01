/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is example code for working with and converting integers
 * to 8 bit binary strings using the <bitset> directive.
*/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{

    bitset<8> x = 255;

    cout << "x = " << x << endl;

    bitset<8> left;
    bitset<8> right;
    left = right = x;

    //cout << "(1) left = " << left << endl;
    //cout << "(1) right = " << right << endl;

    cout << "right = " << right << endl;
    for(int i = 0; i <= 64; i++)
        {
            right = right >> 1;
            if(right == 0)
                {
                    cout << "right = " << right << endl;
                    right = 255;
                }
            cout << "right = " << right << endl;
        }

    cout << endl;

    cout << "left = " << left << endl;
    for(int i = 0; i <= 64; i++)
        {
            left = left << 1;
            if(left == 0)
                {
                    cout << "left = " << left << endl;
                    left = 255;
                }
            cout << "left = " << left << endl;
        }

    cout << endl;

    bitset<8> L1 = 0;
    bitset<8> R7 = 0;
    bitset<8> output = 0x38;

    cout << "Before FOR: L1 = " << L1 << endl;
    cout << "Before FOR: R7 = " << R7 << endl;

    for(int j = 0; j <= 64; j++)
        {
            cout << "Output = " << output << endl;
            L1 = output << 1;
            cout << "L1 = " << L1 << endl;
            R7 = output >> 7;
            cout << "R7 = " << R7 << endl;
            output = (L1 | R7);
        }

    cout << endl;

    bitset<8> L7 = 0;
    bitset<8> R1 = 0;
    bitset<8> output2 = 0x38;

    cout << "Before FOR: L1 = " << L7 << endl;
    cout << "Before FOR: R7 = " << R1 << endl;

    for(int j = 0; j <= 64; j++)
        {
            cout << "Output2 = " << output2 << endl;
            L7 = output2 >> 7;
            cout << "L7 = " << L7 << endl;
            R1 = output2 << 1;
            cout << "R1 = " << R1 << endl;
            output2 = (L7 | R1);
        }

    cout << endl;

    bitset<8> output3 = 0x00;

    int counter = 0;

    //cout << "Before FOR: L1_L = " << L1_L << endl;
    //cout << "Before FOR: R1_R = " << R1_R << endl;

    for(int j = 0; j <= 20; j++)
        {
            //cout << "counter = " << counter << endl;
            if(counter % 5 == 0)
                {
                    cout << "output3 = " << output3 << endl;
                    output3 = 0x18;
                }
            else if(counter % 5 == 1)
                {
                    cout << "output3 = " << output3 << endl;
                    output3 = 0x24;
                }
            else if(counter % 5 == 2)
                {
                    cout << "output3 = " << output3 << endl;
                    output3 = 0x42;
                }
            else if(counter % 5 == 3)
                {
                    cout << "output3 = " << output3 << endl;
                    output3 = 0x81;
                }
            else if(counter % 5 == 4)
                {
                    cout << "output3 = " << output3 << endl;
                    output3 = 0x00;
                }
            counter++;
            if(counter == 5)
                {
                    counter = 0;
                }
        }

    bitset<8> L1_L = 0;
    bitset<8> R1_R = 0;
    bitset<8> output4 = 0x18;

    for(int k = 0; k <= 25; k++)
        {
            L1_L = output4 << 1;
            L1_L = (output4 ^ L1_L);

        }

    return 0;
}