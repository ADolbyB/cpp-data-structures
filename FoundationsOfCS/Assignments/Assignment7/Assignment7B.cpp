/**
 * Joel Brigida
 * Assignment 7 - Grading Program with Classes
 * COP 3014-003
 * Dr. Sareh Taebi
*/

#include <iostream>                                                                             // directive for cin, cout, >> & <<
#include <iomanip>                                                                              // directive for setw()
#include <fstream>                                                                              // directive for stream classes
#include <cstdlib>                                                                              // directive for "exit" function

const int NUM_TESTS = 4;                                                                        // total number of tests during the semester
const double QUIZ1_WEIGHT = 20.0;
const double QUIZ2_WEIGHT = 20.0;                                                               // weight of each test as constants
const double MIDTERM_WEIGHT = 25.0;
const double FINALEXAM_WEIGHT = 35.0;

using namespace std;

class StudentRecord
{
    public:

        StudentRecord(void);                                                                    // Default Constructor
        StudentRecord(int student_num);                                                         // Constructor to initialize values to user input
        void set_grades(int test_num);                                                          // mutator function to manually override grades.
        void calc_weighted_numeric(void);                                                       // calculates student's overall numeric grade based on the quizzes and exams.
        void calc_final_letter(void);                                                           // calculates students's final letter grade based on the overall weighted average.
        void print_grades(int student_num, ostream& file_out);                                  // prints the grades to an output stream
        double get_grades(int test_num);                                                        // accessor function to retrieve individual test scores.
        char get_letter_grade(void);                                                            // accessor function to retrieve 'letter_grade'
        void compare_students(const StudentRecord& studentA, const StudentRecord& studentB, ostream& file_out);    // compares 2 student records

    private:

        char letter_grade;
        double overall_grade;
        double class_grades[NUM_TESTS];
};

void banner(void);
void assignment7(void);                                                                         // "main" function that carries out function calls
void format_output(ostream& file_out);                                                          // ordinary function to format printed results.

int main()
{

    banner();

    return 0;
}

void banner(void)
{

    char word_banner[] = "# =>> Assignment 7: Grading with Classes <<= #";
    int i;

    for (i = 0; i < 46; i++)
        cout << "#";
    cout << endl;
    for (i = 0; i < 46; i++)
        cout << word_banner[i];
    cout << endl;
    for (i = 0; i < 46; i++)
        cout << "#";

    cout << endl << endl;

    assignment7();

}

void assignment7()
{
    StudentRecord Student1(1);                                                                  // 2 students declared as objects which call the constructor.
    StudentRecord Student2(2);                                                                  // constructor takes user input of 4 test scores.

    Student1.calc_weighted_numeric();                                                           // calculates 'overall_grade' based on test scores.
    Student2.calc_weighted_numeric();

    Student1.calc_final_letter();                                                               // uses 'overall_grade' to determine proper letter grade
    Student2.calc_final_letter();

    format_output(cout);                                                                        // ordinary function to format stream output

    Student1.print_grades(1, cout);                                                             // output grades to any output stream
    Student2.print_grades(2, cout);

    Student1.compare_students(Student1, Student2, cout);                                        // comparison of both students grades output to a stream
}

void format_output(ostream& file_out)                                                           // formats the output to a specified output stream
{
    file_out.setf(ios::fixed);
    file_out.setf(ios::showpoint);
    file_out.precision(1);
}

StudentRecord::StudentRecord(void) : letter_grade('F'), overall_grade(0.0)                      // default initialization for private variables
{
    for (int i = 0; i < NUM_TESTS; i++)
        {
            class_grades[i] = 0.0;                                                              // initializes 'class_grades[]' array to default values.
        }
}

StudentRecord::StudentRecord(int student_num) : letter_grade('F'), overall_grade(0.0)           // letter_grade and overall_grade are calculated later.
{
    cout << "Enter grades for Student #" << student_num << endl;
    for (int i = 0; i < NUM_TESTS; i++)
        {
            double user_entry;
            if (i == 0)
                {
                    cout << "Enter Quiz #1 Grade (out of 20 pts): ";
                    cin >> user_entry;
                    if (user_entry < 0)
                        {
                            cout << endl << "Score cannot be negative...exiting" << endl;
                            exit(1);
                        }
                    else
                        {
                            class_grades[0] = (user_entry / 0.2);                               // stores Quiz 1 grade as % in 'class_grades[]' array
                        }
                }
            else if (i == 1)
                {
                    cout << "Enter Quiz #2 Grade (out of 20 pts): ";
                    cin >> user_entry;
                    if (user_entry < 0)
                        {
                            cout << endl << "Score cannot be negative...exiting" << endl;
                            exit(1);
                        }
                    else
                        {
                            class_grades[1] = (user_entry / 0.2);                               // stores Quiz 2 grade as % in 'class_grades[]' array
                        }
                }
            else if (i == 2)
                {
                    cout << "Enter Midterm Grade (out of 100 pts): ";
                    cin >> user_entry;
                    if (user_entry < 0)
                        {
                            cout << endl << "Score cannot be negative...exiting" << endl;
                            exit(1);
                        }
                    else
                        {
                            class_grades[2] = user_entry;                                       // stores Midterm grade as % in 'class_grades[]' array
                        }
                }
            else
                {
                    cout << "Enter Final Exam Grade (out of 100 pts): ";
                    cin >> user_entry;
                    if (user_entry < 0)
                        {
                            cout << endl << "Score cannot be negative...exiting" << endl;
                            exit(1);
                        }
                    else
                        {
                            class_grades[3] = user_entry;                                       // stores Final Exam grade as % in 'class_grades[]' array
                        }
                }
        }
    cout << endl;
}

double StudentRecord::get_grades(int test_num)                                                  // accessor function to retrieve any test grade in the 'class_grades[]' array
{                                                                                               // or the 'overall_grade' private variable

    if (test_num >= 1 && test_num <= 4)
        {
            return (class_grades[test_num - 1]);
        }
    else if (test_num == 5)
        {
            return (overall_grade);
        }
    else
        {
            cout << endl << "Invalid argument...returning 0" << endl;
            return(0.0);
        }
}

char StudentRecord::get_letter_grade(void)                                                      // accessor function to retrieve private char variable 'letter_grade'
{
    return (letter_grade);
}

void StudentRecord::set_grades(int test_num)                                                    // mutator function for manual override of any grades
{
    double user_entry;
    char letter;

    if (test_num == 1)
        {
            cout << "Enter Quiz #1 Grade (out of 20 pts): ";
            cin >> user_entry;
            if (user_entry < 0)
                {
                    cout << endl << "Score cannot be negative..." << endl;
                    return;
                }
            else
                {
                    class_grades[0] = (user_entry / 0.2);                                       // stores Quiz 1 grade % in 'class_grades[]' array
                }
        }
    else if (test_num == 2)
        {
            cout << "Enter Quiz #2 Grade (out of 20 pts): ";
            cin >> user_entry;
            if (user_entry < 0)
                {
                    cout << endl << "Score cannot be negative..." << endl;
                    return;
                }
            else
                {
                    class_grades[1] = (user_entry / 0.2);                                       // stores Quiz 2 grade % in 'class_grades[]' array
                }
        }
    else if (test_num == 3)
        {
            cout << "Enter Midterm Grade (out of 100 pts): ";
            cin >> user_entry;
            if (user_entry < 0)
                {
                    cout << endl << "Score cannot be negative..." << endl;
                    return;
                }
            else
                {
                    class_grades[2] = user_entry;                                               // stores Mideterm grade % in 'class_grades[]' array
                }
        }
    else if (test_num == 4)
        {
            cout << "Enter Final Exam Grade (out of 100 pts): ";
            cin >> user_entry;
            if (user_entry < 0)
                {
                    cout << endl << "Score cannot be negative..." << endl;
                    return;
                }
            else
                {
                    class_grades[3] = user_entry;                                               // stores Final Exam grade % in 'class_grades[]' array
                }
        }
    else if (test_num == 5)
        {
            cout << "Enter Overall Semester Average (out of 100%): ";
            cin >> user_entry;
            if (user_entry < 0)
                {
                    cout << endl << "Score cannot be negative..." << endl;
                    return;
                }
            else
                {
                    overall_grade = user_entry;                                                 // stores Semester Average grade % in 'overall_grade' private variable
                }
        }
    else if (test_num == 6)
        {
            cout << "Enter Final Semester Letter Grade (A - F): ";
            cin >> letter;
            if (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D' && letter != 'F')
                {
                    cout << endl << "Invalid Letter Grade...Valid Entries are:" << endl
                         << "\'A\', \'B\', \'C\', \'D\', or \'F\'" << endl;

                    return;
                }
            else
                {
                    letter_grade = letter;                                                      // stores Final Letter grade in 'letter_grade' private variable
                }
        }
    else
        {
            cout << endl << "Improper argument for test input" << endl;
            return;
        }
}

void StudentRecord::calc_weighted_numeric(void)
{
    overall_grade = ((QUIZ1_WEIGHT * class_grades[0]) +                                         // algorithm to calculate weighted grade average
    (QUIZ2_WEIGHT * class_grades[1]) +                                                          // based on user entered array value test scores
    (MIDTERM_WEIGHT * class_grades[2]) +
    (FINALEXAM_WEIGHT * class_grades[3])) /
    (QUIZ1_WEIGHT + QUIZ2_WEIGHT + MIDTERM_WEIGHT + FINALEXAM_WEIGHT);
}

void StudentRecord::calc_final_letter(void)                                                     // calculates final letter grade based on 'overall_grade'
{
    if (overall_grade >= 90.0)
        {
            letter_grade = 'A';
        }
    else if (overall_grade >= 80.0)
        {
            letter_grade = 'B';
        }
    else if (overall_grade >= 70.0)
        {
            letter_grade = 'C';
        }
    else if (overall_grade >= 60.0)
        {
            letter_grade = 'D';
        }
    else if (overall_grade < 60.0 && overall_grade >= 0.0)
        {
            letter_grade = 'F';
        }
    else
        {
            cout << "Error in grade input...exiting";
            exit(1);
        }
}

void StudentRecord::print_grades(int student_num, ostream& file_out)
{
    file_out << endl << "Semester Grades for Student #" << student_num << ":" << endl << endl;

    file_out << " " << setw(8) << "Quiz 1" << setw(9) << "Quiz 2" << setw(10) << "Midterm"
             << setw(13) << "Final Exam" << setw(10) << "Overall" << setw(8) << "Grade" << endl;

    file_out << setw(8) << get_grades(1) << "\%" << setw(8) << get_grades(2) << "\%" << setw(9)
             << get_grades(3) << "\%" << setw(12) << get_grades(4) << "\%" << setw(9)
             << get_grades(5) << "\%" << setw(8) << get_letter_grade() << endl;
}

void StudentRecord::compare_students(const StudentRecord& studentA, const StudentRecord& studentB, ostream& file_out)
{
    if (studentA.overall_grade > studentB.overall_grade)
        {
            file_out << endl << "Student #1 is performing better with an overall average of: "
                     << studentA.overall_grade << "\%" << endl;
        }
    else if (studentA.overall_grade < studentB.overall_grade)
        {
            file_out << endl << "Student #2 is performing better with an overall average of: "
                     << studentB.overall_grade << "\%" << endl;
        }
    else // if (studentA.overall_grade == studentB.overall_grade)
        {
            file_out << endl << "Both students are performing equally well with an overall average of: "
                     << studentA.overall_grade << "\%" << endl;
        }
}