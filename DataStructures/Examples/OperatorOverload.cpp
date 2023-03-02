/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is some test code using a class for overloaded Operator<<
*/

#include <iostream>

using namespace std;

class Date
{

    public:

        Date();
        Date(int m, int d, int y);
        friend ostream& operator<<(ostream& os, const Date& dt);

    private:

        int mo, da, yr;

};

ostream& operator<<(ostream& os, const Date& dt)
{

    os << dt.mo << '/' << dt.da << '/' << dt.yr;

    return os;

}

int main()
{

    Date dt(5, 6, 92);

    cout << dt;

}
Date::Date()
{

    mo = 1, da = 1, yr = 2001;

}

Date::Date(int m, int d, int y)
{

    mo = m; da = d; yr = y;

}