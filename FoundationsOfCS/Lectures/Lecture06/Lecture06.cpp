/**
 * Joel Brigida
 * COP 3104: Foundations of CS
 * Lecture 6: Nested If-Else statements
**/

#include <iostream>

using namespace std;

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

int main()
{

    //Q1();
    //Q2();
    //Q3();
    //Q4();
    Q5();

    return 0;
}

void Q1(void)
{
    // Demonstrates Local variables declared inside blocks

    int x = 1;
    cout << "Outer block: x = " << x << endl;
    {
        cout << "Inner block 1: x = " << x << endl;
        int x = 2;
        cout << "Inner block 1: x = " << x << endl;
        {
            cout << "Inner Block 2: x = " << x << endl;
            int x = 3;
            cout << "Inner Block 2: x = "<< x << endl;
        }
        cout << "Inner block 1: x = " << x << endl;
    }
    cout << "Outer block: x = " << x << endl;
}

void Q2(void)
{
    // Demonstrates increment and decrement pre- and postfix operators.

    cout << "Count down 1:" << endl << endl;
    int count1 = 5;
    
    while (count1-- > 0)
        cout << count1 << ", ";
    
    cout << endl << endl;
    cout << "Count down 2:" << endl << endl;
    
    int count2 = 5;
    while (--count2 > 0)
        cout << count2 << ", ";
    
    cout << endl << endl;
    cout << "Count up 1:" << endl << endl;
    int n = 1;
    
    do {
        cout << n << ", ";
    } while (n++ <= 5);

    cout << endl << endl;
    cout << "Count up 2:" << endl << endl;
    int m = 1;
    
    do {
        cout << m << ", ";
    } while (++m <= 5);

    cout << endl << endl;
}

void Q3()
{
    int n = 1024;
    int log = 1;
    for (int i = 1; i < n; i = i * 2)
        {
            log++;
            cout << "i = " << i << endl;
        }
    cout << n << " " << log << endl;
}

void Q4()
{
    // "break" vs "exit" statements
    int n = 10;
    int m = 10;

    while (--n > 0)
        {
            if (n == 2)
                break;
            cout << n << " ";
        }
    cout << "End of loop." << endl << endl;


    while (--m > 0)
        {
            if (m == 2)
                exit(99);           // Note the 99 at the program end.
            cout << m << " ";
        }
    cout << "End of loop." << endl << endl;
}

void Q5()
{
    // Example to compute progressive sales tax
    // 0% tax up to $15,000, 5% tax $15,001 <= x <= $25,000, 10% tax anything over $25,000

    int gross_income;
    double tax_bill;
    double five_pc_tax, ten_pc_tax;

    cout << "Enter gross year income rounded to whole dollars: $";
    cin >> gross_income;

    if (gross_income < 15000)
        {
            tax_bill = 0;                                           // no tax collected on the 1st $15,000
        }
    else if (gross_income <= 25000)
        {
            tax_bill = (0.05 * (gross_income - 15000));             // 5% tax collected on income $15,001 to $25,000
        }
    else                                                            // Income > $25000
        {
            five_pc_tax = 10000 * 0.05;                             // 5% tax between $15,001 and $25,000
            ten_pc_tax = 0.1 * (gross_income - 25000);              // 10% tax on everything over $25,000
            tax_bill = five_pc_tax + ten_pc_tax;                    // total bill is both added up.
        }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Gross income: $" << gross_income << endl;
    cout << "Tax Bill: $" << tax_bill << endl;
}