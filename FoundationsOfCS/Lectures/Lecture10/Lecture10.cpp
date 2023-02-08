/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 10
 * Functions: Call by reference
*/

#include <iostream>

using namespace std;

void part1(void);
void get_numbers(int& input1, int& input2);                                     // call by reference function (uses '&' address operator)
void swap_values(int& var1, int& var2);                                         // call by reference function
void show_results(int output1, int ouput2);                                     // call by value function
void part2(void);
void do_stuff(int par1_value, int& par2_ref);
void figure_me_out(int& x, int y, int& z);

int main()
{

    //part1();
    part2();

    return 0;
}

void part1(void)
{
    int first_number, second_number;

    get_numbers(first_number, second_number);
    swap_values(first_number, second_number);
    show_results(first_number, second_number);
}

void get_numbers(int& input1, int& input2)
{
    cout << "Enter two integers: ";
    cin >> input1                                                               // note the way the input is formatted out.
        >> input2;

    cout << endl << "The first number is: " << input1 << endl
         << "The second number is: " << input2 << endl;
}

void swap_values(int& var1, int& var2)
{
    int temp;

    temp = var1;
    var1 = var2;
    var2 = temp;
}

void show_results(int output1, int output2)
{
    cout << endl << "The new value for the 1st number is: " << output1 << endl
         << "The new value for the 2nd number is: " << output2 << endl;
}

void part2(void)
{
    int n1 = 1;
    int n2 = 2;

    cout << "Before function call \"do_stuff\", \'n1\' = " << n1 << " \'n2\' = " << n2 << endl << endl;

    do_stuff(n1, n2);

    cout << "\'n1\' after function call by value: " << n1 << endl
         << "\'n2\' after function call by reference: " << n2 << endl << endl;

    for (int i = 0; i < 55; i++)
        cout << "*";
    cout << endl << endl;

    int a = 10;
    int b = 20;
    int c = 30;

    cout << "Before function call \"figure_me_out\", \'a\' = " << a << " \'b\' = " << b << " \'c\' = " << c << endl << endl;

    figure_me_out(a, b, c);

    cout << "After function call \"figure_me_out\", \'a\' = " << a << " \'b\' = " << b << " \'c\' = " << c << endl;
}

void do_stuff(int par1_value, int& par2_ref)
{
    par1_value = 111;
    par2_ref = 222;

    cout << "\'par1_value\' inside function call \"do_stuff\" : " << par1_value << endl;
    cout << "\'par2_ref\' inside function call \"do_stuff\" : " << par2_ref << endl << endl;
}

void figure_me_out(int& x, int y, int& z)
{
    cout << "Inside function call \"figure_me_out\", \'x\' = " << x << " \'y\' = " << y << " \'z\' = " << z << endl;

    x = 1;
    y = 2;
    z = 3;

    cout << "After variable value changes inside function call \"figure_me_out\": " << endl
         << "\'x\' = " << x << " \'y\' = " << y << " \'z\' = " << z << endl << endl;
}