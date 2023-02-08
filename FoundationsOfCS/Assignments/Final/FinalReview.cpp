/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Review for final exam
*/

#include <iostream>
#include <cmath>

using namespace std;

void f1(double array1[], int size1);
int digit_to_int(char c);
int digit_to_int2(char c);

int main()
{

    double size1, volume = 16.0;
    size1 = sqrt(sqrt(volume)) / 3;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << size1;

    cout << endl << endl;

    int arr[] = {1, 2, 3};
    for (int element : arr)
        element += 10;
    for (int element : arr)
        cout << element << endl;

    cout << endl << endl;

    double array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    f1(array2, 10);

    int test_char;
    test_char = digit_to_int('55');

    cout << "First test:" << endl;
    cout << test_char;

    int test_char2;
    test_char2 = digit_to_int2('7');

    cout << endl << endl << "Second Test:" << endl;
    cout << test_char2 << endl;

    return 0;
}

int digit_to_int(char c)
{
    return (int(c) - int('0'));
}

int digit_to_int2(char c)
{
    return (int(c));
}

void f1(double array1[], int size1)
{
   int i = 0;
   while (i < size1)
       {
           array1[i] += 2;
           cout << array1[i] << " ";
           i++;
       }
}