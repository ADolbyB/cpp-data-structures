/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 07
 * Enum data types and switch statements
*/

#include <iostream>

enum day_t {monday, tuesday, wednesday, thursday, friday, saturday, sunday};    // default values: monday = 0, tuesday = 1, wed = 2, thurs = 3, fri = 4, sat = 5, sun = 6
enum expense_t {entertainment = 500, rent = 1250, utilities = 125, food = 65, clothing = 75, automobile = 360, insurance = 175, misc};

// enums act like integers. "misc" takes default value 176
enum class direction {N, S, E, W};                                              // strong enums don't act like integers.
enum class NS {S, E};                                                           // strong enum names are local to the enum
enum class Days {Sun, Mon, Tue, Wed, Thur, Fri, Sat};                           // strong enums DO NOT implicitly convert to other types (like int or another enum)
enum class Weather {Rain, Sunny};

using namespace std;

void Q1(void);
void Q2(void);
void show_assignment(void);
void show_grade(void);
void give_hints(void);

int main()
{

    //Q1();
    Q2();

    return 0;
}

void Q1(void)
{
    day_t days = tuesday;                                                       // Declares variable "days" as enum type "day_t" from line 10
    expense_t cost = utilities;                                                 // Declares variable "cost" as enum type "expense_t"

    direction myHouse = direction::S;                                           // Qualifying a strong enum value w/ scope resolution operator ::
    NS yourHouse = NS::S;                                                       // Qualifying a strong enum value
    Days d = Days::Tue;
    Weather w = Weather::Sunny;

    //if (d == 0)                                                               // syntax error - d is part of strong enum - not treated like an int.
        //cout << "d == 0 is True" << endl;

    if (d == Days::Fri)                                                         // regular enums this is valid
        cout << "\"d == Days::Fri\" is true" << endl;
    else
        cout << "\"d == Days::Fri\" is False" << endl;

    cout << "days are: " << days << endl;                                       // enums print like integers
    cout << "cost is: $" << cost << endl;                                       // cost = utilities = 125 from line 11 enum expense_t

    int x = (int) direction::S;                                                 // Typecast for workaround in line 58 "Direction of myHouse: "

    //cout << "Direction of myHouse: " << myHouse << endl;                      // Syntax error for string enums
    cout << "Direction of myHouse: " << x << endl;                              // This is a workaround to print myHouse

    switch (days)                                                               // Controlling expression can be type char, bool, int, enum.
    {                                                                           // day_t days = tuesday in line 41
        case 0:
            cout << "Monday" << endl;
            break;
        case 1:
            cout << "Tuesday" << endl;
            break;
        case 2:
            cout << "Wednesday" << endl;
            break;
        case 3:
            cout << "Thursday" << endl;
            break;
        case 4:
            cout << "Friday" << endl;
            break;
        case 5:
            cout << "Saturday" << endl;
            break;
        case 6:
            cout << "Sunday" << endl;
            break;
        default:
            cout << "NOT VALID" << endl;
    }
}

void Q2(void)
{
    cout << "\t=> Sample Teacher/Student Software <=" << endl << endl;

    int choice;

    do {
        cout << "Choose 1 to see your next homework assignment.\n"
             << "Choose 2 to see your grade for sample assignment.\n"
             << "Choose 3 for assignment hints.\n"
             << "Choose 4 to exit this program.\n\n"
             << "Enter your choice and press return: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << endl;
                show_assignment();
                break;
            case 2:
                cout << endl;
                show_grade();
                break;
            case 3:
                cout << endl;
                give_hints();
                break;
            case 4:
                cout << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << endl;
                cout << "Invalid choice" << endl
                     << "Choose again" << endl << endl;
        }
    } while (choice != 4);
}

void show_assignment(void)
{
    cout << "This is a sample assignment to test the switch menus" << endl << endl;
}

void show_grade(void)
{
    cout << "Your current sample grade is an A" << endl << endl;
}

void give_hints(void)
{
    cout << "Here's a hint to your assignment:\n"
         << "Wash your hands, brush your teeth \n"
         << "and GO THE FUCK TO BED!! haha" << endl << endl;
}