/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 9: Functions
*/

#include <iostream>
#include <cmath>

const double PI = 3.14159;                                                              // global named const variable declaration
const double GLOBAL_CONST = 1.0;                                                        // scope is global
double GENERIC = 12345.6789;                                                            // global defined variable (not good practice - can be harder to deal with)

using namespace std;                                                                    // doesnt have to be global. Can be local as needed.

void part1(void);
double est_total(int min_peas, int max_peas, int pod_count);
void part2(void);
double area(double radius);
double volume(double radius);
void part3(void);
long long n_factorial(int n);                                                           // need to find a "bigint" library
void part4(void);
double ave(double n1, double n2);
double ave(double n1, double n2, double n3);                                            // example of overloading function names

int main()
{

    //part1();
    //part2();
    //part3();
    part4();

    return 0;
}


void part1(void)                                                                        // this is the "function header"
{                                                                                       // the "function body" is between the curly braces
    //using namespace std;                                                              // can be declared local to a block.

    int min_count, max_count, pod_count;
    double avg_pea, yield;

    cout << "Enter minimum and maximum number of peas in a pod: ";
    cin >> min_count >> max_count;
    cout << "Enter number of pods: ";
    cin >> pod_count;
    cout << "Enter the weight of an average pea (in ounces): ";
    cin >> avg_pea;

    yield = est_total(min_count, max_count, pod_count) * avg_pea;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << "Minimum number of peas in a pod = " << min_count << endl                   // note the formatted text w/o ";"
         << "Maximum number of peas in a pod = " << max_count << endl
         << "Pod count = " << pod_count << endl
         << "Average pea weight = "
         << avg_pea << " ounces" << endl
         << "estimated average yield = " << yield << " ounces."
         << endl;
}

double est_total(int min_peas, int max_peas, int pod_count)                             // formal parameters inside argument are local to the function
{
    double avg_pea;                                                                     // this avg_pea variable is local to this function.

    avg_pea = (max_peas + min_peas) / 2.0;
    return (pod_count * avg_pea);
}

void part2(void)
{
    double radius, area_of_circle, volume_of_sphere;

    cout << "Enter the radius of a circle in inches: ";
    cin >> radius;

    area_of_circle = area(radius);
    volume_of_sphere = volume(radius);

    cout << "Radius = " << radius << " inches." << endl
         << "Area of circle = " << area_of_circle << " square inches." << endl
         << "Volume of sphere = " << volume_of_sphere << " cubic inches." << endl;
}

double area(double radius)
{
    return (PI * pow(radius, 2));
}

double volume(double radius)
{
    return ((4.0 / 3.0 * PI * pow(radius, 3)));
}

void part3(void)
{
    char choice;

    do {

        int user_input;
        long long int result;

        cout << "Enter a number \'n\' for factorial calculation: ";
        cin >> user_input;

        result = n_factorial(user_input);

        cout << endl << "The result of " << user_input << "! (factorial) = " << result << endl << endl;

        cout << "Would you like to perform another calculation\?" << endl
             << "Enter Y to continue, N to exit: ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');
}

long long n_factorial(int n)
{
    long long product = 1;
    int counter = 1;

    if (n < 1)
        {
            cout << "Error: Please enter a positive integer" << endl;
            return (0);
        }
    else
        {
            while (counter <= n)
            {
                product = counter * product;
                counter++;
            }
        }
    return (product);
}

void part4(void)
{
    cout << "The average of 15 and 29 = " << ave(15.65, 29) << endl;                    // compiler decides function to call based on # of arguments.
                                                                                        // must have different # of parameters in argument AND/OR
    cout << "The average of 15, 18, and 39 = " << ave(15, 18, 39.227) << endl;          // different variable type parameters
                                                                                        // note that the integers in the argument are automatically converted to type double.
}

double ave(double n1, double n2)                                                        // NOT A GOOD IDEA to use the same function names for unrelated functions
{
    return ((n1 + n2) / 2);
}

double ave(double n1, double n2, double n3)
{
    return ((n1 + n2 + n3) / 3);
}