/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Joel Brigida             Email: j*******9@f**.edu                    TOTAL POINTS:  25                DUE DATE: Friday 01/22/2021
COURSE: Data Structures COP 3530-001                                       Professor:  Dr. Bullard
Assignment Name:  Assignment #1
Description:  This program manages a dynamic array of records.
******************************************************************************************************************************************************/

#pragma once                                                    // only include this header once if called by multiple files.
#include <iostream>                                             // directive for cin, cout, << and >>
#include <fstream>                                              // directive for file i/o file stream objects
#include <string>                                               // directive for string class

using namespace std;

class population_record
{
    public:

        population_record() {state_name = ' '; population = 0;};// default constructor which initializes the object "r" in state_pop_statistics.cpp
        string state_name;                                      // Name of the state as a string value
        double population;                                      // Population of each state stored as an integer

};

class state_class
{
    public:

        state_class();                                          // default constructor which initializes the state (private data) of the class.
        state_class(const state_class&);                        // copy constructor
        ~state_class();                                         // destructor which de-allocates all memory allocated to the dynamic pop_DB using the new funciton.
        void double_size();                                     // double the capacity (size) of the memory allocate to the dynamic array pop_DB.
        void operator+(const population_record &);              // overload operator+ without chaining. The function inserts a population record into the population dynamic array (pop_DB).
        bool Is_Full() { return count == capacity; };           // inline implementation...returns true if pop_DB is full; otherwise false is returned
        bool Is_Empty() { return count == 0; };                 // inline implementation...returns ture if pop_DB is empty; otherwise false is returned
        int Search(const string&);                              // search pop_DB for a state in pop_DB. If the state is in pop_DB the location of the record is return; otherwise a -1 is returned.
        void Remove(const string&);                             // deletes a population record from pop_DB if the key field matches the state name.
        void Print_ALL_To_File(const string& datafile);         // prints all the fields of all the population records stored in pop_DB to the filename stored in datafile.
        void Print_ALL();                                       // prints all the fields of all the population records stored in pop_DB to the screen.
        void Print_Range(const int min, const int max);         // prints all the fields of all the population records stored in pop_DB with a population between min and max to the screen;
        int State_Count(const int min, const int max);          // returns the total number of states with a population between min and max, inclusive.
        void Sort();                                            // sorts the array pop_DB in alphabetical order based on state_name field using insertion sort algorithm

    private:

        int count;                                              // total number of population records stored in pop_DB
        int capacity;                                           // total memory allocated to the dynamic array pop_DB
        population_record *pop_DB;                              // dynamic array

};