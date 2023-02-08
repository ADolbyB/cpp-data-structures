/**
 * Joel Brigida
 * COP3014: Foundations of CS
 * Test funtion
 * Prints all ASCII characters inside a loop
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char c;

    for (int x = 0; x <= 255; x++ )
        {
            c = char(x);

            cout << x << " = " << c << endl;

        }

    return 0;
}
