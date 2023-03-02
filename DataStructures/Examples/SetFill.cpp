/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is a small demonstration of the setfill() function.
 * The "setfill()" function fills any open space with any character
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int day = 1, month = 2, year = 3, epoch = 4;

	cout << setfill('0') << setw(5) << day << endl;
	cout << setfill('X') << setw(5) << month << endl;
	cout << setfill('_') << setw(10) << year << endl;
	cout << setfill('-') << setw(10) << epoch << endl;

	return 0;
}