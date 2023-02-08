/**
 * Joel Brigida
 * 12-03-2020
 * COP 3014-003
 * Lab 3 - Arrays: Sorting algorithms and search techniques
 * Dr. Sareh Taebi
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int SIZE = 25;                                                                            // size of the array declared as a constant

void banner(void);
void lab3(void);                                                                                // "main" function
void sort_type(int any_array[]);                                                                // menu to choose which algoithm to run
int get_min_index(int any_array[], int begin_index);                                            // finds array index location with the lowest value
int get_max_index(int any_array[], int begin_index);                                            // finds array index with the largest value
void swap_values(int& value1, int& value2);                                                     // performs swapping of 2 variables - used in the 'selection_sort' algorithm
void selection_sort_ascending(int any_array[]);                                                 // sorts array in ascending order
void selection_sort_ascending2(int any_array[]);                                                // alternate way to above
void selection_sort_descending(int any_array[]);                                                // sorts array in descending order
void selection_sort_descending2(int any_array[]);                                               // alternate way to above
void bubble_sort_ascending(int any_array[]);                                                    // another method to sort in ascending order
void bubble_sort_descending(int any_array[]);                                                   // another method to sort in descending order

int main()
{

    banner();

    return 0;
}

void banner(void)
{
    char word_banner[46] = "#  =>> Lab 3: Array Sorting Algorithms <<=  #";
    int i;

    for (i = 0; i < 45; i++)
        cout << "#";
    cout << endl;
    for (i = 0; i < 45; i++)
        cout << word_banner[i];
    cout << endl;
    for (i = 0; i < 45; i++)
        cout << "#";

    cout << endl << endl;

    lab3();
}

void lab3(void)
{
    srand(time(NULL));
    int random_generated;

    char choice;

    do {

        int min_index;
        int max_index;

        int array1[SIZE];

        for (int i = 0; i < SIZE; i++)
            {
                random_generated = ((rand() % 2599) + 1) * int(pow(-1, i));                     // generates a list of alternating +/- integers and writes them to array1[]
                array1[i] = random_generated;
            }

        min_index = get_min_index(array1, 0);
        max_index = get_max_index(array1, 0);

        cout << "The minimum index for 'array1[]' is: [" << min_index << "]" << endl;
        cout << "The maximum index for 'array1[]' is: [" << max_index << "]" << endl << endl;

        cout << "Initial list of RANDOM array values and their indices:" << endl << endl;

        for (int x = 0; x < SIZE; x++)
            {
                cout << "[" << x << "]" << " = " << array1[x];

                if (min_index == x)
                    {
                        cout << "   <--- Minimum Value";
                    }
                if (max_index == x)
                    {
                        cout << "   <--- Maximum value";
                    }

                cout << endl;
            }

        sort_type(array1);

        min_index = get_min_index(array1, 0);
        max_index = get_max_index(array1, 0);

        cout << "The NEW minimum index for 'array1[]' is: [" << min_index << "]" << endl;
        cout << "The NEW maximum index for 'array1[]' is: [" << max_index << "]" << endl << endl;

        cout << "After running algorithm: The new array values and their indices:" << endl << endl;

        for (int x = 0; x < SIZE; x++)
            {
                cout << "[" << x << "]" << " = " << array1[x];

                if (min_index == x)
                    {
                        cout << "   <--- Minimum Value";
                    }
                if (max_index == x)
                    {
                        cout << "   <--- Maximum value";
                    }

                cout << endl;
            }

            cout << endl << "Run again? Y or N: ";
            cin >> choice;

    } while (choice != 'n' && choice != 'N');
}

void sort_type(int any_array[])
{
    int user_entry;

    cout << endl << "Which sort algoritm to run?" << endl << endl;
    cout << "Choose 1 for \'Selection Sort Ascending\'" << endl;
    cout << "Choose 2 for \'Selection Sort Ascending #2\'" << endl;
    cout << "Choose 3 for \'Selection Sort Descending\'" << endl;
    cout << "Choose 4 for \'Selection Sort Descending #2\'" << endl;
    cout << "Choose 5 for \'Bubble Sort Ascending\'" << endl;
    cout << "Choose 6 for \'Bubble Sort Descending\'" << endl;
    cout << endl << "Make a selection: ";
    cin >> user_entry;

    if (user_entry == 1)
        {
            cout << endl << "Running \'selection_sort_ascending\' algorithm" << endl << endl;
            selection_sort_ascending(any_array);
        }
    else if (user_entry == 2)
        {
            cout << endl << "Running \'selection_sort_ascending2\' algorthm" << endl << endl;
            selection_sort_ascending2(any_array);
        }
    else if (user_entry == 3)
        {
            cout << endl << "Running \'selection_sort_descending\' algorthm" << endl << endl;
            selection_sort_descending(any_array);
        }
    else if (user_entry == 4)
        {
            cout << endl << "Running \'selection_sort_descending2\' algorthm" << endl << endl;
            selection_sort_descending2(any_array);
        }
    else if (user_entry == 5)
        {
            cout << endl << "Running \'bubble_sort_ascending\' algorthm" << endl << endl;
            bubble_sort_ascending(any_array);
        }
    else if (user_entry == 6)
        {
            cout << endl << "Running \'bubble_sort_descending\' algorthm" << endl << endl;
            bubble_sort_descending(any_array);
        }
    else
        {
            cout << endl << "Invalid Entry..." << endl;
            sort_type(any_array);
        }
}

int get_min_index(int any_array[], int begin_index)                                             // finds the array index with the lowest value.
{

    int min_value;                                                                              // local variable to contain the minimum value of the array.
    int min_index;                                                                              // local variable that identifies the array index holding the min_value.

    min_value = any_array[begin_index];                                                         // start lowest value at 1st array index for comparison purposes.
    min_index = begin_index;                                                                    // start minimum index as the start index for comparison purposes

    for (int i = begin_index; i < SIZE; i++)
        {
            if (any_array[i] < min_value)
                {
                    min_value = any_array[i];                                                   // loops through the array locating the lowest integer
                    min_index = i;                                                              // updates the location of the lowest integer
                }
        }
    return (min_index);                                                                         // returns integer location index in array
}

int get_max_index(int any_array[], int begin_index)                                             // finds array index with the largest integer value
{                                                                                               // this is a mirror image of the 'get_min_index' function
    int max_value;
    int max_index;

    max_value = any_array[begin_index];
    max_index = begin_index;
    for (int i = begin_index; i < SIZE; i++)
        {
            if (any_array[i] > max_value)
                {
                    max_value = any_array[i];
                    max_index = i;
                }
        }
    return (max_index);
}

void swap_values(int& value1, int& value2)                                                      // performs swap of 2 variables with call-by-reference
{
    int temp;

    temp = value1;
    value1 = value2;
    value2 = temp;
}

void selection_sort_ascending(int any_array[])                                                  // sorts array in ascending order from lowest index to the highest
{
    int min_index;                                                                              // local variable for locating array index with lowest value

    for (int i = 0; i < SIZE; i++)
        {
            min_index = get_min_index(any_array, i);                                            // loops through function starting at the next highest index each time (array index search gets smaller each time)

            if (i > min_index)
                {
                    swap_values(any_array[i], any_array[min_index]);                            // moves the larger value towards the beginning of the array
                }
            else if (i < min_index)
                {
                    swap_values(any_array[min_index], any_array[i]);                            // moves the smaller value towards the end of the array
                }
        }
}

void selection_sort_ascending2(int any_array[])
{
    int min_index;                                                                              // local variable for locating array index with lowest value

    for (int i = 0; i < SIZE; i++)
        {
            min_index = get_min_index(any_array, i);                                            // loops through function starting at the next highest index each time (array index search gets smaller each time)

            if (i != min_index)
                {
                    swap_values(any_array[i], any_array[min_index]);                            // continually swaps the lowest value into the lowest array index of the current loop
                    //swap_values(any_array[min_index], any_array[i]);                            // this also works the same.
                }
        }
}

void selection_sort_descending(int any_array[])                                                 // sorts array in decending order from lowest index to the highest
{
    int max_index;

    for (int i = 0; i < SIZE; i++)
        {
            max_index = get_max_index(any_array, i);                                            // finds the index in array1[] with the maximum value

            if (i < max_index)
                {
                    swap_values(any_array[i], any_array[max_index]);                            // moves the larger value towards the beginning of the array
                }
            else if (i > max_index)
                {
                    swap_values(any_array[max_index], any_array[i]);                            // moves the smaller value towards the end of the array
                }
        }
}

void selection_sort_descending2(int any_array[])
{
    int max_index;

    for (int i = 0; i < SIZE; i++)
        {
            max_index = get_max_index(any_array, i);                                            // finds the index in array1[] with the maximum value

           if (i != max_index)
                {
                    //swap_values(any_array[i], any_array[max_index]);                            // continually swaps the largest value into the lowest array index of the current loop
                    swap_values(any_array[max_index], any_array[i]);                            // this also works the same.
                }
        }
}

void bubble_sort_ascending(int any_array[])                                                     // sorts array in ascending order with "bubble" method
{
    for (int i = SIZE; i > 0; i--)                                                              // this shrinks the array search in increments from largest array index downward
        {
            for (int j = 0; j < i; j++)                                                         // iterates the array indices
                {
                    if (any_array[j] > any_array [j + 1])
                        {
                            swap_values(any_array[j], any_array[j + 1]);                        // this pushes or "bubbles" the largest value to the end
                        }
                }
        }
}

void bubble_sort_descending(int any_array[])                                                    // sorts array in descending order with "bubble" method
{

    for (int i = (SIZE - 1); i >= 0; i--)                                                       // this shrinks the array search in increments from largest array index downward
        {
            for (int j = 0; j < i; j++)
                {
                    if (any_array[j] < any_array [j + 1])
                        {
                            swap_values(any_array[j], any_array[j + 1]);                        // this pushes or "bubbles" the smallest value to the end
                        }
                }
        }
}