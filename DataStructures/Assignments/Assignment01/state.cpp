/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Joel Brigida             Email: j*******9@f**.edu                    TOTAL POINTS:  25                DUE DATE: Friday 01/22/2021
COURSE: Data Structures COP 3530-001                                       Professor:  Dr. Bullard
Assignment Name:  Assignment #1
Description:  This program manages a dynamic array of records.
******************************************************************************************************************************************************/

#include "state.h"                                                                  // include the header with our class definition
#include <iomanip>                                                                  // directive for "setw" formatting
#include <cstdlib>                                                                  // directive for "exit" function
#include <fstream>                                                                  // directive for file i/o
#include <string>                                                                   // directive for string class
#include <iostream>                                                                 // directive for cin, cout, << and >>

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  
The function initializes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
double_size is called, which doubles the capacity of pop_DB.
**********************************************************************************************************************************************************/
state_class::state_class()
{

    cout << "=>> Default Constructor Called <<=" << endl << endl;                   // Shows that the default constructor has been called.

	count = 0;                                                                      // intially count, capacity, and pop_DB are initialized with the following values:
	capacity = 5;
	pop_DB = new population_record[capacity];                                       // declares a dynamic array

    ifstream file_in;                                                               // declare fstream object to read data from file.

    file_in.open("census2020_data.txt");                                            // opens the file "census2020_data.txt" for the program to take values out.

    if(file_in.fail())
        {
            cout << "Input file failed to open...exiting" << endl;
            exit(1);
        }

    string the_line;                                                                // string object used to read in the file data from "census2020_data.txt"
    string the_population;                                                          // string used to store the population data part of "the_line"
    string the_place;                                                               // string used to store the loation data part of "the_line"

    while (!file_in.eof())
    {

        double_size();                                                              // checks the size of the array and doubles it if too small to fit all values

        getline(file_in, the_line);                                                 // reads and outputs one line at a time from the input file stream

        //cout << "the_line = " << the_line << endl;                                // debug - prints the file names so i know it is reading the file properly

        int location = 0;                                                           // location of the last space of the particular line read from the file.
        int digit_length = 0;                                                       // amount of integers in the population size

        for (int i = (the_line.length() - 1); i >= 0; i--)
            {
                if (isdigit(the_line[i]))
                    {
                        location = i;                                               // this finds the 1st space from the end of the string
                    }
            }

        //cout << "location = " << location << endl;                                // debug to show the value of "location"

        for (int k = location; k < int(the_line.length()); k++)
            {
                digit_length++;                                                     // counts how many digits are in the population part of the string
            }

        //cout << "digit_length = " << digit_length << endl;                        // debug to show value of "digit length"

        the_place = the_line.substr(0, (location - 1));                             // puts the location part of the string into a separate string variable
        the_population = the_line.substr(location, digit_length);                   // puts the numeric part of the string into a separate string variable

        //cout << "the place = [" << the_place << "]" << endl;                      // debug to show parsed string values.
        //cout << "the population = [" << the_population << "]" << endl;            // debug

        cout.setf(ios::fixed);                                                      // display values as fixed decimal notation (not e-notation)
        cout.precision(0);                                                          // display values with 0 decimal places.

        pop_DB[count].state_name = the_place;
        pop_DB[count].population = stod(the_population);

        //cout << "pop_DB[" << count << "] = [" << pop_DB[count].state_name << "]" << endl;   // debug to print values stored in the array
        //cout << "pop_DB[" << count << "] = [" << pop_DB[count].population << "]" << endl;   // debug

        count++;                                                                    // increase the array index count by one
    }

    //cout << "=>> Default constructor ended <<=" << endl;                          // debug to know when the loop ends

    file_in.close();                                                                // close file when finished to avoid file corruption.

}

/******************************************************************************************************************************************************
Name: state_class
Pre-Condition: must already have called the default constructor.
Post-Condition the contents of pop_DB will have been copied onto a new array.
Description: copy constructor: performs a deep copy of an object.
******************************************************************************************************************************************************/
state_class::state_class(const state_class & org)
{

    cout << "=>> Copy Constructor Called <<=" << endl;                              // Shows that the copy constructor has been called.

    count = org.count;                                                              // both statements make the copied object the same size as the original
    capacity = org.capacity;

    pop_DB = new population_record[capacity];                                       // creates a new deep copy array.

    for(int i = 0; i < count; i++)                                                  // for-loop that sets each of the indicies equal to each other.
        {
            pop_DB[i] = org.pop_DB[i];                                              // copies array values to the new dynamic array
        }

}

/******************************************************************************************************************************************************
Name: ~state_class
Pre-Condition: must have a dynamic array containing values.
Post-Condition: all memory allocated to the dynamic pop_DB will have been deleted.
Description: Destructor which de-allocates all memory allocated to the dynamic pop_DB using the new funciton.
******************************************************************************************************************************************************/
state_class::~state_class()
{

    cout << "=>> Destructor has been called <<=" << endl;                           // Shows that the destructor has been called

    delete [] pop_DB;                                                               // deletes the array pop_DB[]
    pop_DB = 0;                                                                     // zeros out the pointer so its not "dangling"
    count = 0;                                                                      // set count to zero since there are no items in the array now

}

/******************************************************************************************************************************************************
Name: double_size()
Pre-Condition: There must already be records held in pop_DB
Post-Condition: the dynamic aray at pop_DB will now be twice its original size
Description: Mutator function. Doubles the capacity (size) of the memory allocate to the dynamic array pop_DB.
******************************************************************************************************************************************************/
void state_class::double_size()
{
    if (Is_Full())
        {

            capacity *= 2;                                                          // Multiply the allocated capacity of the dynamic aray by 2.

            population_record *temp = new population_record[capacity];              // Declare a population_record pointer and use new to allocate an array with "size" elements.

            for (int i = 0; i < count; i++)                                         // the loop copies all the records in the list to the new temp[] array
                {
                    temp[i] = pop_DB[i];
                }

            delete [] pop_DB;                                                       // delete the old pop_DB
            pop_DB = temp;                                                          // assign temp to pop_DB

        }

}

/******************************************************************************************************************************************************
Name: operator+
Pre-Condition: A new object to be added to the array has values already assigned to it.
Post-Condition: Both values of the object 'r' passed to the function are appended to the array pop_DB
Description: Mutator Function. Overloads the '+' operator so that the "r" object with 2 values (declared in the main) can be added to the array
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	if(Is_Full())
        {
            double_size();
        }

    pop_DB[count].population = r.population;                                        // appends the population value to the list of array values
    pop_DB[count].state_name = r.state_name;                                        // appends the state name value to the list of array values

    count++;

}

/******************************************************************************************************************************************************
Name: Search
Pre-Condition: pop_DB must be populated with values.
Post-Condition: pop_DB will have been searched for the state, and the location will have been revealed.
Description: Accessor Function: searches pop_DB for a state in pop_DB. If the state is in pop_DB the location of the record is return; otherwise a -1 is returned.
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{

    for (int i = 0; i < count; i++)                                                 // loop cycles through the array indices
    {
        if(state == pop_DB[i].state_name)                                           // compare the value we want to match to the array values
            {
                return i;                                                           // return the index value with the matched string value
            }

    }
	return -1;                                                                      // if loop ends, then string was not found and (-1) is returned

}

/******************************************************************************************************************************************************
Name: Remove
Pre-Condition:  pop_DB must be declared and populated.
Post-Condition: a population record will have been deleted from pop_DB
Description: Mutator Function: Deletes a population record from pop_DB if the key field matches the state name.
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{

    int goal;
    goal = Search(state);               // stores the index location of the state that we want to be removed by invoking the search function.

    //cout << "Remove state name: [" << state << "]" << endl;                       // debug statement to print out the string value

    if(Is_Empty())
        {
            cout << "pop_DB is EMPTY" << endl;
        }
    else if (goal != -1)
        {
            for(int i = goal; i < count - 1; i++)
                {
                    pop_DB[i] = pop_DB[i + 1];
                }

            count--;

        }

}

/******************************************************************************************************************************************************
Name: Print_ALL_To_File
Pre-Condition: pop_DB must be populated with values to print.
Post-Condition: the population records stored in pop_DB will have been printed onto the filename specified in the function call.
Description: Accessor Function: Prints all the fields of all the population records stored in pop_DB to the filename passed as a string object to this function.
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{

    ofstream fileout;                                                           // declare a local ofstream object to write to file
    fileout.open(filename);                                                     // open the file with the filename of the string object passed as a call-by-refernce

    if(fileout.fail())                                                          // if there is a problem opening the file, then the program exits.
        {
            cout << "Output file opening failed...";
            exit(1);
        }

    fileout.setf(ios::left);                                                    // format the list as left justified
    fileout.setf(ios::fixed);                                                   // fixed decimal notation (not e-notation)
    fileout.precision(0);                                                       // show no decimal points

    for (int i = 0; i < count; i++)                                             // For loop goes through every index of pop_DB through the use of variable count.
        {
            // outputs both state_name and population into a file.
            fileout << setw(12) << "State Name: " << setw(25) << pop_DB[i].state_name << "Population: " << pop_DB[i].population << endl;
        }

    fileout.close();                                                            // close file when done to avoid data corruption

}


/******************************************************************************************************************************************************
Name: Print_All
Pre-Condition: There must be non-blank values store in the array in order to print out to the screen,
Post-Condition: The values stored in the array are displayed on the screen in the order they are read.
Description: Accessor Function: Prints the "State Name: " and "Population: " fields stored in pop_DB array to the screen.
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{

    cout.setf(ios::left);                                                       // format the list as left justified
    cout.setf(ios::fixed);                                                      // fixed decimal notation (not e-notation)
    cout.precision(0);                                                          // show no decimal points

    for (int i = 0; i < count; i++)                                             // For loop goes through every index of pop_DB through the use of variable count
        {
            // outputs both state_name and population to the screen.
            cout << setw(12) << "State Name: " << setw(25) << pop_DB[i].state_name << "Population: " << pop_DB[i].population << endl;
        }

}


/******************************************************************************************************************************************************
Name: Print_Range
Pre-Condition: pop_DB must be populated with non-blank values that can be printed to the screen.
Post-Condition: The population records stored in pop_DB between the values of min and max (inclusive) are printed to the screen.
Description: Accessor Function: Prints all fields of all population records stored in pop_DB with a population between min and max to the screen;
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
    cout.setf(ios::left);                                                       // format the list as left justified
    cout.setf(ios::fixed);                                                      // fixed decimal notation (not e-notation)
    cout.precision(0);                                                          // show no decimal points

    for (int i = 0; i < count; i++)                                             // For loop goes through every index of pop_DB through the use of variable count
        {
            //cout << "DEBUG: population = " << i << "[" << pop_DB[i].population << "]" << endl;        // debug to see what value is being compared
            if(pop_DB[i].population >= min && pop_DB[i].population <= max)
                {
                    // outputs both state_name and population to the screen.
                    cout << setw(12) << "State Name: " << setw(25) << pop_DB[i].state_name << "Population: " << pop_DB[i].population << endl;
                }

        }

}


/******************************************************************************************************************************************************
Name: State_Count
Pre-Condition: pop_DB must be declared and populated.
Post-Condition: total number of states with a population between min and max, inclusive, will have been printed as an integer value.
Description: Accessor Function: returns the total number of states as an integer with a population between min and max, inclusive.
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{

    int state_count = 0;                                                        // initializes a number for the count of states

    for (int i = 0; i < count; i++)                                             // for-loop that goes through and adds to the count if the states population fits between the two parameters.
    {

        if (pop_DB[i].population >= min && pop_DB[i].population <= max)
            {
                state_count++;                                                  // adds to the count if the states population fits between the two parameters.
            }

    }

	return state_count;
}

/******************************************************************************************************************************************************
Name: Sort
Pre-Condition: pop_DB array must be populated with string values at a minimum
Post-Condition: pop_DB will have been sorted in alphabetical order by state name.
Description: Mutator Function: Sorts the array pop_DB in alphabetical order based on state_name field using insertion sort algorithm
******************************************************************************************************************************************************/
void state_class::Sort()
{

    for (int i = 1; i < count; i++)
        {
            population_record key = pop_DB[i];                          // declare an object "key" of class "population_record" and assign to it the current array values stored in pop_DB[i]
                                                                        // key is the item to be inserted into the array
            int j = (i - 1);
            while ((j >= 0) && (pop_DB[j].state_name > key.state_name))
                {
                    pop_DB[j + 1] = pop_DB[j];                          // move the array value up one if
                    j -= 1;
                }
            pop_DB[j + 1] = key;
        }
}