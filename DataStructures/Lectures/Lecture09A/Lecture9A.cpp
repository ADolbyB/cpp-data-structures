/**********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a program to demonstrate the use of vector data structures.
**********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**********************************************************************
Function Name: search()
Description: Declares an iterator to iterate through the vector to
search for a string match in a vector of strings.
**********************************************************************/
vector<string>::iterator search(vector<string>& s)
{
    vector<string>::iterator i = s.begin();

    return i;
}

int main()
{

    vector<string> s(10,"hello"); // declare string type vector

    for(vector<string>::iterator i = s.begin(); i != s.end(); i++)
        {
            cout << "[x] = " << (*i) << endl;
        }

    vector<int> I; // declare int type vector;

    cout << endl << "(1) I.size() = " << I.size() << endl;

    for (int i = 0; i < 10; i++)
        {
            I.push_back(i);
            cout << "push_back(" << i << ") = " << I.size() << endl;
        }

    cout << "(2) I.size() = " << I.size() << endl << endl;

    for (int i = 0; i < 10; i++)
        {
            cout << "(1) I[" << i << "] = " << I[i] << endl;
        }

    cout << endl << endl;

    cout << "I.erase(I.begin());" << endl;
    I.erase(I.begin());

    for (int i = 0; i < 9; i++)
        {
            cout << "(2) I[" << i << "] = " << I[i] << endl;
        }

    I.insert(I.begin() + 3, 222);

    cout << endl << endl;

    for (int i = 0; i < 10; i++)
        {
            cout << "(3) I[i] = " << I[i] << endl;
        }

    cout << endl << endl << (*(search(s))) << endl;

    return 0;
}