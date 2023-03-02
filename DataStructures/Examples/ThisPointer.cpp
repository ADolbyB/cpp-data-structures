/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is a small test function to demostrate the "this ->" pointer function
*/

#include <iostream>

using namespace std;

class Container
{
    public:

        Container(double l = 2.0, double b = 2.0, double h = 2.0);  // Constructor definition with default arguments
        double Volume(void);
        int compare(Container any_box);

    private:

        double length;                                              // Length of a box
        double depth;                                               // depth of a box
        double height;                                              // Height of a box
};

int main()
{
    Container Box1(3.3, 1.2, 1.5);                                  // Declare box1
    Container Box2(8.5, 6.0, 2.0);                                  // Declare box2

    if(Box1.compare(Box2))
        {
            cout << "Box2 is smaller than Box1" <<endl;
        }
    else
        {
            cout << "Box2 is equal to or larger than Box1" <<endl;
        }

   return 0;
}

Container::Container(double l, double b, double h)
{

    cout << "The Constructor has been called." << endl;

    length = l;
    depth = b;
    height = h;

}

double Container::Volume(void)
{

    return (length * depth * height);

}

int Container::compare(Container any_box)
{

    return (this->Volume() > any_box.Volume());                   // only member functions have a "this" pointer.

}