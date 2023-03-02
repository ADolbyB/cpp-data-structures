/**
 * Joel Brigida
 * COP3530: Data Structures
 * This function uses a class to test dynamic arrays.
**/

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

class XLIST
{
    public:

        XLIST();
        ~XLIST();
        void fill_array(int the_size);      //(int any_array[], int the_size);
        int get_min_index(int any_array[], int begin_index);
        void swap_values(int& value1, int& value2);
        void selection_sort_ascending();    //(int any_array[], int the_size);
        int search_array(const int& the_number);
        void insert_number(const int& the_number);
        void remove_number(const int& the_number);
        void print_array();                 //(int any_array[], int the_size);

    private:

        int *IntArray;
        int index_count;
        int capacity;

};

using namespace std;

int main()
{

//    double *DPtr = new double[55];
//
//    XLIST some_array;
//    int test1 = 0;
//    int test2 = 1;
//
//    some_array.fill_array(20);
//
//    cout << "The unsorted array elements are: " << endl;
//    some_array.print_array();
//
//    some_array.selection_sort_ascending();
//
//    cout << "The sorted array elements are: " << endl;
//    some_array.print_array();
//
//    some_array.insert_number(test1);
//    some_array.insert_number(test2);
//
//    cout << "After inserting 2 numbers: " << endl;
//    some_array.print_array();
//
//    some_array.selection_sort_ascending();
//
//    cout << "After sorting: " << endl;
//    some_array.print_array();

    string *test_array2 = new string[99] { "0", "1-Time", "2Pac", "3-Peat", "4", "5", "What is this?", "Does it work?", "Abracadabra" };

    int i = 0;
    while(test_array2[i] != "")
        {
            cout << "test_array2[" << i << "] = " << test_array2[i] << endl;
            i++;
        }

    string my_string = "What the hell happened to me in this crazy world?";
    string copy_string = my_string;                                                         // make a copy since the string stream will pull it apart.
    int num_characters;
    num_characters = (int)my_string.length();                                               // stores the number of characters into a variable

    cout << endl << "Length of String: num_characters = " << num_characters << endl;        // debug
    cout << "my_string = " << my_string << endl << endl;

    string *test_array = new string[num_characters];                                        // array to store parsed string values - should always have ample space

    int total_count = 0;
    string each_word;                                                                       // A string to store the word on each iteration.
    stringstream the_string_stream(my_string);

    while (the_string_stream >> my_string)
        {
            test_array[total_count++] = my_string;                                          // iterates through the string and parses each word
        }

    cout << "my_string = " << my_string << endl;
    cout << "copy_string = " << copy_string << endl << endl;

    int j = 0;
    while(test_array[j] != "")
        {
            cout << "test_array[" << j << "] = " << test_array[j] << endl;
            j++;
        }


    string temp_string = "";                                                                // temporary string to parse words of 'copy_string' into
    string *another_array = new string[num_characters];                                     // new array to parse the string words into
    int str_array_pos = 0;                                                                  // variable to keep track of occupied array indices

    int k;
    if((int)copy_string.length() != 0)                                                      // if the string length is not zero
        {
            for(k = 0; k < (int)copy_string.length(); k++)                                  // declare a loop to iterate through the string
                {
                    if(copy_string[k] != ' ')                                               // if the current character of the string is not a space
                        {
                            temp_string += copy_string[k];                                  // add that character to the 'temp_string'
                        }
                    if(copy_string[k] == ' ')                                               // when a space is found
                        {
                            another_array[str_array_pos++] = temp_string;                   // drop the whole word from 'temp_string' and drop it into the next string array index
                            another_array[str_array_pos++] = ' ';                           // then add a space to the next index and increment the counter again.
                            temp_string = "";                                               // clear the content of the 'temp_string'
                        }
                    if(k == (int)copy_string.length() - 1)                                  // at the end of the string
                        {
                            another_array[str_array_pos++] = temp_string;                   // drop the current word into the next index of 'another_array'
                            temp_string = "";                                               // clear contents of 'temp_string'
                        }
                }
        }

    cout << endl << endl;

    int n = 0;
    while(another_array[n] != "")
        {
            cout << "another_array[" << n << "] = " << another_array[n] << endl;
            n++;
        }

    return 0;
}

XLIST::XLIST()
{

    index_count = 0;
    capacity = 25;
    IntArray = new int[capacity];

}

XLIST::~XLIST()
{

    delete [] IntArray;

}

void XLIST::swap_values(int& value1, int& value2)                                                      // performs swap of 2 variables with call-by-reference
{

    int temp;

    temp = value1;
    value1 = value2;
    value2 = temp;

}

int XLIST::get_min_index(int any_array[], int begin_index)                                      // finds the array index with the lowest value.
{

    int min_value;                                                                              // local variable to contain the minimum value of the array.
    int min_index;                                                                              // local variable that identifies the array index holding the min_value.

    min_value = any_array[begin_index];                                                         // start lowest value at 1st array index for comparison purposes.
    min_index = begin_index;                                                                    // start minimum index as the start index for comparison purposes

    for (int i = begin_index; i < index_count; i++)
        {
            if (any_array[i] < min_value)
                {
                    min_value = any_array[i];                                                   // loops through the array locating the lowest integer
                    min_index = i;                                                              // updates the location of the lowest integer
                }
        }

    return (min_index);                                                                         // returns integer location index in array

}

void XLIST::selection_sort_ascending()                                                  // sorts array in ascending order from lowest index to the highest
{

    int min_index;                                                                              // local variable for locating array index with lowest value

    for (int i = 0; i < index_count; i++)
        {
            min_index = get_min_index(IntArray, i);                                            // loops through function starting at the next highest index each time (array index search gets smaller each time)

            if (i > min_index)
                {
                    swap_values(IntArray[i], IntArray[min_index]);                            // moves the larger value towards the beginning of the array
                }
            else if (i < min_index)
                {
                    swap_values(IntArray[min_index], IntArray[i]);                            // moves the smaller value towards the end of the array
                }
        }
}

void XLIST::print_array()
{

    for (int j = 0; j < index_count; j++)
        {
            cout << "[" << j << "] = " << IntArray[j] << endl;                        // prints out the random numbered array values.
        }

    cout << endl;

}

void XLIST::insert_number(const int& the_number)
{

    int i;
    for(i = 0; i < index_count; i++)
        {
            if(the_number <= IntArray[i])
                {
                    break;
                }

        }
    if(i < index_count)
        {
            for(int j = index_count; j > i; j--)
                {
                    IntArray[j] = IntArray[j - 1];
                }
            IntArray[i] = the_number;
            index_count++;
        }
}

void XLIST::remove_number(const int& the_number)
{

    int i;
    for(i = 0; i < index_count; i++)
        {
            if(IntArray[i] == the_number)
                {
                    for(int j = i; j < (index_count - 1); j++)
                        {
                            IntArray[j] = IntArray[j + 1];
                        }
                    index_count--;
                    return;
                }
        }
    cout << "This number was not found" << endl;
}

void XLIST::fill_array(int the_size)                                        // fills array elements
{
    srand(time(NULL));

    int i;
    int random_generated;

    for (i = 0; i < the_size; i++)
        {
            random_generated = ((rand() % 99) + 1) * int(pow(-1, i));       // generates a list of alternating +/- integers and writes them to the array
            IntArray[i] = random_generated;
        }

    index_count = the_size;

}