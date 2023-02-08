/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Lecture 19 - Arrays
 * Implementing arrays with functions
*/

#include <iostream>
#include <iomanip>

const int NUMBER_STUDENTS = 4;
const int NUMBER_QUIZZES = 3;

using namespace std;

void test_arrays(void);
void maximum_score(void);
void arrays_in_functions(void);
void fill_up(int a[], int size);                                                                // size is the declared size of array a[]
void show_the_world(const int a[], int size);                                                   // function to display values of the array
void multi_dimensional(void);
void grading_criteria(void);
void compute_student_avg(const int grade[][NUMBER_QUIZZES], double student_avg[]);
void compute_quiz_avg(const int grade[][NUMBER_QUIZZES], double quiz_avg[]);
void display(const int grade[][NUMBER_QUIZZES], const double student_avg[], const double quiz_avg[]);

int main()
{

    //test_arrays();
    //maximum_score();
    //arrays_in_functions();
    multi_dimensional();
    //grading_criteria();

    return 0;
}

void test_arrays(void)
{
    int test[3];                                                                                // array declaration
    test[0] = 12;                                                                               // manual initialization of index #0
    test[1] = 15;                                                                               // manual initialization of index #1
    test[2] = 24;                                                                               // manual initialization of index #2

    int test2[10] = {13, 15};                                                                   // NOT A GOOD IDEA - "supposed to" initalize all other values to zero, but don't depend on it.

    for (int x : test2)                                                                         // RANGE BASED LOOP: C++ 11 added feature
        {
            cout << x << " ";                                                                   // prints values of array indices
        }
    cout << endl << endl;

    for (int& x : test2)                                                                        // call by reference to access array index addresses directly
        {
            x++;                                                                                // increments all values of the array with range-based loop.
        }

    for (auto x : test2)                                                                        // "auto" automatically determines variable datatype
        {
            cout << x << " ";                                                                   // prints the incremented values set by previous loop
        }
    cout << endl << endl;

    char symbol[5] = {'a', 'B', 'c', 'D', 'e'};
    for (int index = 0; index < 5; index++)
        {
            cout << symbol[index] << " ";
        }

    cout << endl;

    int children[3] = {2, 3, 14};                                                               // one way to initialize values in an array
    int kids[] = {2, 3, 15};                                                                    // initializes array to # of entries in curly braces

}

void maximum_score(void)
{
    int i, max_score, num_scores;

    cout << "How many test scores do you want to compare? ";
    cin >> num_scores;

    int score[num_scores];                                                                      // first index is score[0], last is score[num_scores - 1]

    cout << "Enter " << num_scores << " test scores:" << endl;
    cin >> score[0];
    max_score = score[0];

    for (i = 1; i < num_scores; i++)
        {
            cin >> score[i];
            if (score[i] > max_score)
                {
                    max_score = score[i];
                }
        }

    cout << endl << "The highest score is: " << max_score << endl;
    cout << endl << "Each score and the offset from the max:" << endl;

    for (i = 0; i < num_scores; i++)
        {
            cout << setw(5) << score[i] << " differs by " << setw(5) << (max_score - score[i]);

            if (max_score - score[i] == 0)
                {
                    cout << "   <-- Highest Score" << endl;
                }
            else
                {
                    cout << endl;
                }
        }
}

void arrays_in_functions(void)
{
    int array_size;

    cout << "How many indices are needed in this array?" << endl;
    cin >> array_size;

    int random_scores[array_size];

    cout << endl << "Call to \"fill_up\":" << endl;

    fill_up(random_scores, array_size);                                                          // function call to 'fill_up' using array and integer arguments

    cout << endl << "Call to \"show_the_world\":" << endl;

    show_the_world(random_scores, array_size);
}

void fill_up(int a[], int size)
{
    cout << endl << "Enter " << size << " numbers:" << endl;

    for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }

    size--;

    cout << endl << "The last array index entered was: [" << size << "]" << endl;
}

void show_the_world(const int a[], int size)                                                    // "const" prevents changing of array values
{
    cout << endl << "The intialized array values are:" << endl << endl;

    for (int i = 0; i < size; i++)                                                              // loop to display array values.
        {
            cout << a[i] << " ";
        }

    cout << endl;
}

void multi_dimensional(void)
{
    char page [5][10];                                                                          // char array with 5 rows (up/down) and 10 columns (left right)
                                                                                                // "page" is array of size 5 and base type of 10
    for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j++)
                {
                    page[i][j] = 'X';                                                           // sets array values to 'X'
                }
        }

    for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j++)
                {
                    cout << "page [" << i << "]" << "[" << j << "] = " << page[i][j] << endl;   // displays all array values
                }
        }
}

void grading_criteria(void)
{
    int grade[NUMBER_STUDENTS][NUMBER_QUIZZES];                                                 // 4 students, 3 quizzes
    double student_avg[NUMBER_STUDENTS];
    double quiz_avg[NUMBER_QUIZZES];

    for (int i = 0; i < NUMBER_STUDENTS; i++)
        {
            cout << "Enter data for Student #" << i + 1 << endl;
            for (int j = 0; j < NUMBER_QUIZZES; j++)
                {
                    cout << "Quiz #" << j + 1 << " score: ";
                    cin >> grade[i][j];
                }
        }

    cout << endl << endl;

    for (int i = 0; i < NUMBER_STUDENTS; i++)
        {
            cout << "Student #" << i + 1 << "scores: " << endl;
            for (int j = 0; j < NUMBER_QUIZZES; j++)
                {
                    cout << "Quiz #" << j + 1 << " score: ";
                    cout << grade[i][j] << endl;
                }
            cout << endl;
        }

    cout << "Computing student average..." << endl;

    compute_student_avg(grade, student_avg);

    cout << endl << "Computing quiz average..." << endl;

    compute_quiz_avg(grade, quiz_avg);

    cout << endl << "Displaying results:" << endl;

    display(grade, student_avg, quiz_avg);
}

void compute_student_avg(const int grade[][NUMBER_QUIZZES], double student_avg[])
{
    for (int stud_num = 1; stud_num <= NUMBER_STUDENTS; stud_num++)
        {
            double sum = 0;

            for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
                {
                    sum = sum + grade[stud_num - 1][quiz_num - 1];
                }

            student_avg[stud_num - 1] = (sum / NUMBER_QUIZZES);
        }
}

void compute_quiz_avg(const int grade[][NUMBER_QUIZZES], double quiz_avg[])
{
    for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
        {
            double sum = 0;

            for (int stud_num = 1; stud_num <= NUMBER_STUDENTS; stud_num++)
                {
                    sum = sum + grade[stud_num - 1][quiz_num - 1];
                }
            quiz_avg[quiz_num - 1] = (sum / NUMBER_STUDENTS);
        }
}

void display(const int grade[][NUMBER_QUIZZES], const double student_avg[], const double quiz_avg[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << setw(8) << "Student" << setw(5) << "Avg" << setw(15) << "Quizzes" << endl;

    for (int stud_num = 1; stud_num <= NUMBER_STUDENTS; stud_num++)
        {
            cout << setw(8) << stud_num << setw(5) << student_avg[stud_num - 1] << " ";

            for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
                {
                    cout << setw(5) << grade[stud_num - 1][quiz_num - 1];
                }
            cout << endl;
        }

    cout << endl << "Quiz Averages: ";
    for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
        {
            cout << setw(5) << quiz_avg[quiz_num - 1];
        }
    cout << endl;
}