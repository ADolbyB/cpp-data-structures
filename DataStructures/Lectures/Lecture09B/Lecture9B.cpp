/******************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This program os an example of declaring and using generic function templates
 * which work on multiple data types.
******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***********************************************************
Function Name: xswap()
Description: Generic Function Template for performing
swapping of 2 variables of type 'new_type'
***********************************************************/
template <class new_type>
void xswap(new_type& x, new_type& y)
{
    new_type temp = x;
    x = y;
    y = temp;
}

/***********************************************************
Function Name: Is_Equal()
Description: Generic Function Template for checking if 2
variables are the same.
***********************************************************/
template <class a_type>
bool Is_Equal(a_type a, a_type b)
{
    return a == b;
}

int main()
{
    string s = "hello";
    string c = "goodbye";
    int x = 10;
    int y = 10;
    char ch = 'k';
    char sh = 'X';

    cout << "Is_Equal for strings: " << boolalpha << Is_Equal(s, c) << endl;
    cout << "Is_Equal for integers: " << boolalpha << Is_Equal(x, y) << endl;
    cout << "Is_Equal for chars: " << boolalpha << Is_Equal(ch, sh) << endl << endl;

    int i = 10;
    int j = 20;
    string a = "hello";
    string b = "goodbye";

    cout << "i and j before call " << "i = " << i << " and j = " << j << endl;

    xswap(i, j); // swap 2 integers

    cout << "i and j after call " << "i = " << i << " and j = " << j << endl << endl;

    cout << "a and b before call " << "a = " << a << " and b = " << b << endl;

    xswap(a, b); // swap 2 strings

    cout << "a and b after call " << "a = " << a << " and b = " << b << endl << endl;

    return 0;
}