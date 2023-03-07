/*********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This function uses recursive function calls to search
 * Recursively sub(list) a[first], ..., a[last]
 * for item using a binary search.
 * Precondition: Elements of 'a' are in ascending order;
 * item has the same type as the array elements
 * Postcondition: found = true and loc = position of item
 * if search is successful; otherwise, found is false.
 ********************************************************************/

#include <iostream>
#include <string>

typedef double ElementType;
typedef double ArrayType;

int Print_recursions;
int Fib_recursions;
int Fact_recursions;

using namespace std;

void recBinarySearch (ArrayType a, int first, int last, ElementType item, bool& found, int& loc);
void print(string );                                // recursive char by char string parsing
int fibonacci(int );                                // recursive function that prints the fibonacci sequence. INEFFICIENT!!
int factorial(int );                                // function which calculates the factorial recursively
int power_func(int b, int e);                       // function which calculates powers using recursion

int main()
{
    // int loc_index;
    // bool found_it;
    // ElementType some_value = 2.5;

    // ArrayType test[] = {1.0, 2.0, 2.5, 3.0, 4.5, 6.0, 7.5, 8.0};

    // recBinarySearch(test, 0, 7, some_value, found_it, loc_index);

    // cout << "Did you find item = 2.5?" << boolalpha << found_it << endl;

    string test_string = "ABC-123-DEF-456";

    Print_recursions = 0;
    Fib_recursions = 0;
    Fact_recursions = 0;
    int base, exponent, output;

    print(test_string);

    cout << endl << "# of Print recursions: " << Print_recursions << endl;
    cout << endl << "The Fibonacci of 28 = " << fibonacci(28) << endl;                  // works but is terribly inefficient
    cout << endl << "# of Fibonacci recursions: " << Fib_recursions << endl;            // way too many function calls
    cout << endl << "The Factorial of 7 = " << factorial(7) << endl;                    // factorial calculation using recursion
    cout << endl << "# of Factorial recursions: " << Fact_recursions << endl;

    cout << endl << "Enter a base: ";
    cin >> base;
    cin.ignore();                                                                       // ignore the '\n'
    cout << "Enter an exponent: ";
    cin >> exponent;
    cin.ignore();                                                                       // ignore the '\n'
    output = power_func(base, exponent);
    cout << endl << base << " to the " << exponent << "th power = " << output << endl;

    return 0;
}

void print(string any_string)
{
    if(any_string.length() != 0)
        {
            cout << any_string[0] << "  ";

            //cout << "any_string.substr(1, any_string.length() - 1) = " << any_string.substr(1, any_string.length() - 1) << endl; // debug

            cout << "any_string = " << any_string << endl; // debug

            print(any_string.substr(1, any_string.length() - 1)); // recursive function call: the argument parses string & sends back to this function

            //cout << "any_string.substr(1, any_string.length() - 1) = " << any_string.substr(1, any_string.length() - 1) << endl; // debug
            
            Print_recursions++;
        }
    else
        {
            cout << endl << "String is empty" << endl << endl;
        }
}

int fibonacci(int number)
{
    if(number <= 1)
        {
            return number;                              // base / inductive / anchor case
        }
    else
        {
            Fib_recursions++;
            return (fibonacci(number - 2) + fibonacci(number - 1)); // recursive function call 
        }
}

int factorial(int input)
{
    if(input < 0)
        {
            cout << "Entry must be positive" << endl;
            return 0;
        }
    else if(input == 0 || input == 1)
        {
            return 1;                                   // base / inductive / anchor case
        }
    else
        {
            Fact_recursions++;
            return (input * factorial(input - 1));      // recursive function call 
        }
}

int power_func(int b, int e)
{

    if(e == 0)
        {
            return 1;                                   // inductive / anchor case
        }
    else
        {
            return (b * power_func(b, e - 1));          // recursive function call
        }
}

// void recBinarySearch (ArrayType a, int first, int last, ElementType item, bool& found, int& loc)
// {
//    if (first > last)     	                        // anchor 1: empty sublist
//        {
//            found = false;
//        }
//    else                                              // inductive case
//        {                                             // recursively search
//            loc = (first + last) / 2;
//            if (item < a[loc])                        // the first half
//                {
//                    recBinarySearch( a, first, loc-1, found loc);
//                }
//            else if (item > a[loc])	                // the second half
//                {
//                    recBinarySearch (a, loc + 1, last, found, loc);
//                }
//            else
//                {
//                    found = true;	                    // anchor 2: found item
//                }
//        }
// }