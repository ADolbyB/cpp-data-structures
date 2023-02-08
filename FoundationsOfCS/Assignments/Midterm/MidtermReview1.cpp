/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Midterm Review #2
 * 10/25/2020
**/

#include <iostream>
#include <string>

const double PI = 3.14;

using namespace std;

void nested_loop(void);
void circle(void);
void Calculations(double radius, double& circumference, double& area);
void even_calculator(void);
void args(void);
void default_args(int arg1, int arg2, int arg3 = -3, int arg4 = -4);
void two_12(void);
void test_string(void);
void tester(void);

int main()
{
    //nested_loop();
    //circle();
    //even_calculator();
    //args();
    //two_12();
    //test_string();
    tester();

    return 0;
}

void nested_loop(void)
{
    int x, y;

    cout << "Enter two integers in the range 1 - 20: ";
    cin >> x >> y;
    for (int i = 1; i <= y; i++)                            // outer loop up and down rows (y value)
    {
        cout << "Row #" << i << ": ";
        for (int j = 1; j <= x; j++)                       // inner loop is columns across left/right (x value)
            {
                cout << j << " ";
            }
        cout << endl;
    }
}

void circle(void)
{
	double radius, circumference, area;
	cout << "Enter Radius: ";
	cin >> radius;

	Calculations(radius, circumference, area);

	cout << "The circumference = " << circumference << endl;
	cout << "The area = " << area << endl;
}

void Calculations(double radius, double& circumference, double& area)
{
	circumference = 2.0 * PI * radius;
	area = PI * radius * radius;
}

void even_calculator(void)
{
    int total = 0;
    int input;

    cout << "Enter an even number to calculate sum of all evens," << endl
         << "or an odd number to exit: ";
    cin >> input;

    while (input % 2 == 0)
        {
            total += input;
            cout << "Enter another number: ";
            cin >> input;
        }
    cout << "The sum of all evens entered by user = " << total;
}

void args(void)
{
    default_args(5, 6);
    //default_args(6, 7, 8);
    //default_args(5, 6, 7, 8);
}

void default_args(int arg1, int arg2, int arg3, int arg4)
{
    cout << arg1 << " " << arg2 << " " << arg3 << " " << arg4 << endl;
}

void two_12(void)
{
    double one = 1.0;
    double two = 1.414;
    double three = 1.732;
    double four = 2.0;
    double five = 2.236;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << "\tN\tSquare Root" << endl;
    cout << "\t1\t" << one << endl;
    cout << "\t2\t" << two << endl;
    cout << "\t3\t" << three << endl;
    cout << "\t4\t" << four << endl;
    cout << "\t5\t" << five << endl;
}

void test_string(void)
{
    string one, two, three;

    one = "1234567890";
    two = "abcdefghi";

    cout << one << " " << two << endl;

    three = one + " " + two;

    cout << three << endl;
}

void tester(void)
{
    int i, j;

    if (i = 0)  // assignment operator in place of equality operator
        {
            cout << "i is true" << endl;
            cout << "i = " << i << endl << endl;
        }
    else
        {
            cout << "i is false" << endl;
            cout << "i = " << i << endl << endl;
        }

    if (j = 1)  // assignment operator in place of equality operator
        {
            cout << "j is true" << endl;
            cout << "j = " << j << endl << endl;
        }
    else
        {
            cout << "j is false" << endl;
            cout << "j = " << j << endl << endl;
        }

    if (0)  // 0 is false
        cout << "0 is true" << endl;
    else
        cout << "0 is false" << endl;

    if (1)  // 1 is true
        cout << "1 is true" << endl;
    else
        cout << "1 is false" << endl;

    if (-1) // any non-zero integer is considered "true"
        cout << "-1 is true" << endl;
    else
        cout << "-1 is false" << endl;
}