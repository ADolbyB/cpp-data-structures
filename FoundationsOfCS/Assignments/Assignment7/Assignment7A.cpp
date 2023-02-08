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
        StudentRecord(int student_num);                                                         // Constructor to set values to user input
        void set_grades(int test_num);                                                          // mutator function to change grades.
        void calc_weighted_numeric(void);                                                       // calculates student's overall numeric grade.
        void calc_final_letter(void);                                                           // calculates students's final letter grade.
        void print_grades(int student_num, ostream& file_out);                                  // prints the grades to an output stream
        double get_grades(int test_num);                                                        // accessor function to retrieve individual test scores.
        char get_letter_grade(void);                                                            // accessor function to retrieve 'letter_grade'
        void compare_students(const StudentRecord& studentA, const StudentRecord& studentB, ostream& file_out);    // compares 2 student records

    private:

        char letter_grade;                                                                      // stores student letter grade
        double overall_grade;                                                                   // student's weighted overall percent average
        double class_grades[NUM_TESTS];                                                         // array holds students individual quiz / exam grades
};

void banner(void);                                                                              // decorative banner for this assignment
void assignment7A(void);                                                                        // "official release" - performs
void assignment7B(void);                                                                        // "Beta" test to check code as part of a larger program
void format_output(ostream& file_out);                                                          // ordinary function to format printed results.
void menu(StudentRecord& studentA, StudentRecord& studentB, char input);                        // switch case based menu used for assignment7B

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

    char version;

    cout << "Which version of assignment #7 do you want to run?" << endl;
    RETRY:cout << endl << "Version A (Official Release), or Version B (Beta Test)" << endl;

    cout << endl << "Enter \'A\' or \'B\': ";
    cin >> version;

    if (version == 'a' || version == 'A')
        {
            assignment7A();
        }
    else if (version == 'b' || version == 'B')
        {
            assignment7B();
        }
    else
        {
            cout << "Invalid entry...try again..." << endl;
            goto RETRY;
        }
}

void assignment7A()                                                                             // This is my original Assignment7 solution before attempting a full menu based program.
{                                                                                               // "Assignmnent7A" is the same functionality as 'Case A' in "Assignment 7B'
    StudentRecord Student1(1);                                                                  // object declarations for 2 students.
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

void assignment7B(void)                                                                         // "Beta" version used to test functionality of my original code fragment 'Assignment 7A'
{                                                                                               // This is a full menu-based program
    char exit, option;

    StudentRecord Student1, Student2;                                                           // declare objects - uses default constructor to initialize.

    do {
        cout << "=>> Grading Options <<=" << endl;                                              // This is the "main menu"
        cout << "Please make a selection" << endl;

        cout << endl << "Option A: Enter semester grades for all students, perform" << endl
             << "average calculations and student comparison" << endl;

        cout << endl << "Option B: Retrieve any student grade" << endl;

        cout << endl << "Option C: Manually override any grade" << endl;

        cout << endl << "Option D: Run new overall average calculations after grade edits" << endl;

        cout << endl << "Option E: Perform new student comparison" << endl;

        RETRY:cout << endl << "Enter an option letter: ";
        cin >> option;

        if ( (option < 'a' ||  option > 'e' ) && (option < 'A' || option > 'E') )
            {
                cout << "Invalid entry...try again" << endl;
                goto RETRY;                                                                     // the "goto" cycles back to accept user input in case of invalid entry
            }

        menu(Student1, Student2, option);                                                       // calls 'menu' function that accepts call by reference objects and the menu option

        cout << endl << "Would you like to perform another operation? Y or N: ";
        cin >> exit;                                                                            // this ends the entire program when answering 'N'

        cout << endl;

    } while (exit == 'Y' || exit == 'y');

    cout << "See You Next Time!!" << endl;
}

void menu(StudentRecord& studentA, StudentRecord& studentB, char input)                         // The switch case forms the basis of menu options
{
    switch(input)
        {
            case 'A':                                                                           // Case 'A' performs the same operation as the original program "assignment 7A"
            case 'a':
                {
                    //StudentRecord studentA(1);                                                // doesn't work in this case since the objects are being re-declared
                    //StudentRecord studentB(2);                                                // this worked in Assignment 7A but will not work here

                    cout << endl << "Enter Grades for Student #1:" << endl;                     // workaround - use the "set_grades" mutator function.
                    for (int i = 1; i <= 4; i++)
                        {
                             studentA.set_grades(i);
                        }
                    cout << endl << "Enter Grades for Student #2:" << endl;
                    for (int i = 1; i <= 4; i++)
                        {
                             studentB.set_grades(i);
                        }

                    studentA.calc_weighted_numeric();                                           // these function calls remain the same as "assignment 7A" program
                    studentB.calc_weighted_numeric();

                    studentA.calc_final_letter();
                    studentB.calc_final_letter();

                    format_output(cout);

                    studentA.print_grades(1, cout);
                    studentB.print_grades(2, cout);

                    studentA.compare_students(studentA, studentB, cout);

                    break;
                }
            case 'B':                                                                           // Case 'B' retrieves any stored grade and prints to the screen
            case 'b':
                {

                    int student_number, user_entry;                                             // local variables to this block for user input

                    REDO1:cout << "Enter Student #: ";
                    cin >> student_number;

                    if (student_number != 1 && student_number != 2)
                        {
                            cout << endl << "Invalid Entry...try again..." << endl;
                            goto REDO1;                                                         // 'goto' cycles back for re-rentry of student number in case of invalid input
                        }

                    cout << endl << "Student #" << student_number << endl;

                    cout << endl << "Which grade to retrieve?" << endl;

                    cout << "Enter 1 for Quiz 1" << endl
                         << "Enter 2 for Quiz 2" << endl
                         << "Enter 3 for Midterm" << endl
                         << "Enter 4 for Final Exam" << endl
                         << "Enter 5 for Semester Average" << endl
                         << "Enter 6 for Course Letter Grade" << endl;

                    cout << endl << "Enter a number choice: ";
                    cin >> user_entry;

                    if (student_number == 1)
                        {
                            if (user_entry >= 1 && user_entry <= 6)
                                {
                                    cout << "The grade for ";

                                        if (user_entry == 1)
                                            cout << "Quiz 1 = ";
                                        else if (user_entry == 2)
                                            cout << "Quiz 2 = ";
                                        else if (user_entry == 3)
                                            cout << "Midterm = ";
                                        else if (user_entry == 4)
                                            cout << "Final Exam = ";
                                        else if (user_entry == 5)
                                            cout << "Semester Weighted Average = ";
                                        else if (user_entry == 6)
                                            cout << "Entire Course = ";

                                        if (user_entry >= 1 && user_entry <= 5)
                                                cout << studentA.get_grades(user_entry) << "\%" << endl;
                                        else // if (user_entry == 6)
                                                cout << studentA.get_letter_grade() << endl;    // calls to the "get/accessor" function
                                }
                            else
                                {
                                    cout << "Invalid Entry" << endl;
                                    return;
                                }
                        }
                    else if (student_number == 2)
                        {
                            if (user_entry >= 1 && user_entry <= 6)
                                {
                                    cout << "The grade for ";

                                        if (user_entry == 1)
                                            cout << "Quiz 1 = ";
                                        else if (user_entry == 2)
                                            cout << "Quiz 2 = ";
                                        else if (user_entry == 3)
                                            cout << "Midterm = ";
                                        else if (user_entry == 4)
                                            cout << "Final Exam = ";
                                        else if (user_entry == 5)
                                            cout << "Semester Weighted Average = ";
                                        else if (user_entry == 6)
                                            cout << "Entire Course = ";

                                        if (user_entry >= 1 && user_entry <= 5)
                                                cout << studentB.get_grades(user_entry) << "\%" << endl;
                                        else // if (user_entry == 6)
                                                cout << studentB.get_letter_grade() << endl;    // calls to the "get/accessor" function
                                }
                            else
                                {
                                    cout << endl << "Invalid Entry" << endl;
                                    return;
                                }
                        }
                    break;
                }
            case 'C':                                                                           // Case 'C' manually overrides any grade input
            case 'c':
                {
                    int student_number, user_entry;                                             // local variables to this block for user entry

                    REDO2:cout << "Enter Student #: ";
                    cin >> student_number;

                    if (student_number != 1 && student_number != 2)
                        {
                            cout << endl << "Invalid Entry...try again..." << endl;
                            goto REDO2;                                                         // goto cycles back to user input in case of invalid input
                        }

                    cout << endl << "Student #" << student_number << endl;

                    cout << endl << "Which grade to override?" << endl;

                    cout << "Enter 1 for Quiz 1" << endl
                         << "Enter 2 for Quiz 2" << endl
                         << "Enter 3 for Midterm" << endl
                         << "Enter 4 for Final Exam" << endl
                         << "Enter 5 for Semester Average" << endl
                         << "Enter 6 for Course Letter Grade" << endl;

                    cout << endl << "Enter a number choice: ";
                    cin >> user_entry;

                    if (student_number == 1)
                        {
                            if (user_entry >= 1 && user_entry <= 6)
                                {
                                    studentA.set_grades(user_entry);                            // call to the "set/mutator" function
                                }
                            else
                                {
                                    cout << endl << "Invalid Entry" << endl;
                                    return;
                                }
                        }
                    else if (student_number == 2)
                        {
                            if (user_entry >= 1 && user_entry <= 6)
                                {
                                    studentB.set_grades(user_entry);                            // call to the "set/mutator" function
                                }
                            else
                                {
                                    cout << endl << "Invalid Entry" << endl;
                                    return;
                                }
                        }
                    break;
                }
            case 'D':                                                                           // Case 'D' is for recalculating the overall grades
            case 'd':                                                                           // used after a manual override
                {
                    cout << endl << "Recalculating grades..." << endl;

                    studentA.calc_weighted_numeric();
                    studentB.calc_weighted_numeric();

                    studentA.calc_final_letter();
                    studentB.calc_final_letter();

                    cout << endl << "...Done" << endl;

                    break;
                }
            case 'E':                                                                           // case 'E' reprints the student grades and performs new student comparison
            case 'e':                                                                           // used after a manual override and recalculating
                {
                    format_output(cout);

                    studentA.print_grades(1, cout);
                    studentB.print_grades(2, cout);

                    studentA.compare_students(studentA, studentB, cout);

                    break;
                }
            default:
                {
                cout << endl << "Invalid entry, Try again" << endl;
                return;
                }


        }

}

void format_output(ostream& file_out)                                                           // formats output to any stream argument
{

    file_out.setf(ios::fixed);
    file_out.setf(ios::showpoint);
    file_out.precision(1);

}

StudentRecord::StudentRecord(void) : letter_grade('F'), overall_grade(0.0)                      // default constructor: default initialization for private variables
{
    for (int i = 0; i < NUM_TESTS; i++)
        {
            class_grades[i] = 0.0;                                                              // initializes 'class_grades[]' array to default values.
        }
}

StudentRecord::StudentRecord(int student_num) : letter_grade('F'), overall_grade(0.0)           // This constructor initializes quiz/exam grades to user-set values.
{                                                                                               // letter_grade and overall_grade are calculated later.
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

double StudentRecord::get_grades(int test_num)                                                  // this function returns the numerical grades for
{                                                                                               // quizzes, exams, and overall semester average

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
            return(0.0);
        }

}

char StudentRecord::get_letter_grade(void)                                                      // this function returns the course letter grade
{

    return (letter_grade);

}

void StudentRecord::set_grades(int test_num)                                                    // mutator function for manual override of any grade
{
    double user_entry;                                                                          // local variables to accept user input for setting grades.
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
                    class_grades[2] = user_entry;                                               // stores Midterm grade % in 'class_grades[]' array
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

void StudentRecord::calc_weighted_numeric(void)                                                 // calculates overall student weighted semester average
{
    overall_grade = ((QUIZ1_WEIGHT * class_grades[0]) +                                         // algorithm to calculate weighted grade average
    (QUIZ2_WEIGHT * class_grades[1]) +
    (MIDTERM_WEIGHT * class_grades[2]) +
    (FINALEXAM_WEIGHT * class_grades[3])) /
    (QUIZ1_WEIGHT + QUIZ2_WEIGHT + MIDTERM_WEIGHT + FINALEXAM_WEIGHT);

}

void StudentRecord::calc_final_letter(void)                                                     // uses the "overall_grade" private variable percentage to determine the correct letter grade
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

void StudentRecord::print_grades(int student_num, ostream& file_out)                            // prints out student semester report card to any output stream
{
    file_out << endl << "Semester Grades for Student #" << student_num << ":" << endl << endl;

    file_out << " " << setw(8) << "Quiz 1" << setw(9) << "Quiz 2" << setw(10) << "Midterm"
             << setw(13) << "Final Exam" << setw(10) << "Overall" << setw(8) << "Grade" << endl;

    file_out << setw(8) << get_grades(1) << "\%" << setw(8) << get_grades(2) << "\%" << setw(9)
             << get_grades(3) << "\%" << setw(12) << get_grades(4) << "\%" << setw(9)
             << get_grades(5) << "\%" << setw(8) << get_letter_grade() << endl;
}

void StudentRecord::compare_students(const StudentRecord& studentA, const StudentRecord& studentB, ostream& file_out)
{                                                                                               // student comparison is based on the overall weighted average
    if (studentA.overall_grade > studentB.overall_grade)
        {
            file_out << endl << "Student #1 is performing better with an overall average of: "
                     << studentA.overall_grade << "\%" << endl;                                 // accesses private variable directly, rather than using an accessor
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