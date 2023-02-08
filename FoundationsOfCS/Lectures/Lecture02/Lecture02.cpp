/**
 * Joel Brigida
 * COP3014-007
 * Lecture 02 - Write a program that requests # of students and # of books per student
 * and calculates the total number of books.
 * Goal: Familiarize yourself with CPP format and debugging.
*/

#include <iostream>

using namespace std;

void Q1(void);
void Q2(void);

int main()
{

    Q1();
    Q2();

    return 0;

}

void Q1(void)
{
    int books, students, total_books;

    cout << "How many students in this class? ";
    cin >> students;

    cout << "How many books per student for this semester? ";
    cin >> books;

    total_books = books * students;

    cout << "The total number of books is: ";
    cout << total_books << endl << endl;

    ///Alternate way to do it:

    cout << "The total number of books is: " << total_books << " for " << students << " students" << endl << endl;
}

void Q2(void)
{
    int number_of_pods, peas_per_pod, total_peas;

    cout << "Press return after entering a number\n";
    cout << "Enter the number of pods:\n";
    cin >> number_of_pods;
    cout << "Enter the number of peas in a pod:\n";
    cin >> peas_per_pod;

    total_peas = number_of_pods * peas_per_pod;

    cout << "If you have ";                         /// Alternate way to print statements as opposed to all in one line like Q1()
    cout << number_of_pods;
    cout << " pea pods\n";
    cout << "and ";
    cout << peas_per_pod;
    cout << " peas in each pod, then\n";
    cout << "you have ";
    cout << total_peas;
    cout << " peas in all the pods.\n";
}