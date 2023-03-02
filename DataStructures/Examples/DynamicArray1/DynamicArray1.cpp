/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is an example of a Dynamic Array implementation in C++
 * Class and implementation are all in the same file.
*/

#include <iostream>
#include <fstream>

using namespace::std;

class ARRAY
{
    public:

        ARRAY();
        ~ARRAY();
        void Insert(int);
        void double_size();
        bool Is_Full() { return count == capacity; };
        bool Is_Empty() { return count == 0; };
        void Print();
        int Search(int);
        void Remove(int);

    private:

        int count;
        int capacity;
        int* Array;                 // pointer to the 1st element of the dynamic array
};

int main()
{
	ARRAY yourArray;                // object declaration - calls default constructor

	yourArray.Print();              // call to member function "Print"

	yourArray.Insert(500);          // call to member function "Insert"

	yourArray.Print();              // call to member function "Print" again

	yourArray.Remove(500);          // call to member function "Remove"

	yourArray.Print();              // call to member function "Print"

	return 0;
}

/* Default Constructor */
ARRAY::ARRAY()
{
	cout << "default constructor has been invoked \n";

	count = 0;
	capacity = 2;                   // capacity = # of elements in the array

	Array = new int[capacity];      // declare a dynamic array and assign pointer "Array" to point to the 1st element
	int i;
	ifstream in;
	in.open("myData.txt");          // Reads data from text file

	while (!in.eof())
        {
            if (Is_Full())
                double_size();
            in >> i;
            Insert(i);
        }
	in.close();
}

/* Destructor */
ARRAY::~ARRAY()
{
	cout << "destructor has been invoked" << endl;
	delete[] Array;
}

/* Inserts integer at the last array index */
void ARRAY::Insert(int i)
{
	cout << "Insert has been invoked" << endl;
	if (!Is_Full())
        {
            Array[count] = i;
            count++;
        }
}

/* creates a new array with 2x the # of indices */
void ARRAY::double_size()
{
	capacity = capacity * 2;
	int * temp = new int[capacity];

	for (int i = 0; i < count; i++)
        {
            temp[i] = Array[i];
        }

	delete[] Array;
	Array = temp;
}

/* Prints all values in the array */
void ARRAY::Print()
{
	cout << "Print has been Invoked" << endl;
	for (int i = 0; i < count; i++)
        {
            cout << "Array[" << i << "] = " << Array[i] << endl;
        }
}

/* Searches entire array for value 'key' */
int ARRAY::Search(int key)
{
	cout << "Search has been invoked" << endl;
	for (int i = 0; i < count; i++)
        {
            if (Array[i] == key)
                {
                    return i;
                }
        }
	return -1;
}

/* Searches array for a match, if match, then it is deleted */
void ARRAY::Remove(int key)
{
	cout << "Remove has been invoked" << endl;
	int i = Search(key);

	if (i != -1)
        {
            for (int j = i; j < count - 1; j++) // shift array down
                {
                    Array[j] = Array[j + 1];
                }
            count--;
        }
}