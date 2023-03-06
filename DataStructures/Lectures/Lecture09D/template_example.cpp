/******************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This program is another example of declaring and using generic function 
 * templates which work on multiple data types.
******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5;

/*******************************************************************************
Class declaraton and definition for Generic Template Array_Class
*******************************************************************************/
template <class New_Type>
class Array_Class
{
    public:

        Array_Class();
        ~Array_Class();
        void Add(New_Type item);
        int Search(New_Type item);
        void Print();

    private:

        New_Type *A;
        int count;
};

/**********************************************************************
Function Name: Array_Class()
Description: Default Constructor. Constructs an empty object based on
the data type declared in the main function.
**********************************************************************/
template <class New_Type>
Array_Class<New_Type>::Array_Class()
{
    cout << "You are inside the default constructor" << endl;
    cout << "New_Type has a size of " << sizeof(New_Type) << " bytes" << endl << endl;

    count = 0;
    A = new New_Type[SIZE];
}

/**********************************************************************
Function Name: ~Array_Class()
Description: Class Destructor. Deallocates all memory from the 
data type.
**********************************************************************/
template <class New_Type>
Array_Class<New_Type>::~Array_Class()
{
    cout << "The Destructor has been called" << endl << endl;

    delete[] A;
    count = 0;
    A = 0;
}

/**********************************************************************
Function Name: Add()
Description: Adds a new item to an index to the data type.
**********************************************************************/
template <class New_Type>
void Array_Class<New_Type>::Add(New_Type item)
{
    if (count < SIZE)
        {
            A[count++] = item;
        }
    else
        {
            cout << "Array is Full" << endl;
        }
}

/**********************************************************************
Function Name: Search()
Description: Searches the vector for 'item' given in the argument.
**********************************************************************/
template <class New_Type>
int Array_Class<New_Type>::Search(New_Type item)
{
    int i;

    for (i = 0; i < count; i++)
        {
            if (item == A[i])
                {
                    return i;
                }
        }
    return -1;
}

/**********************************************************************
Function Name: Print()
Description: Prints all items contained in the Array_Class object.
**********************************************************************/
template <class New_Type>
void Array_Class<New_Type>::Print()
{
    int i;
    for (i = 0; i < count; i++)
        {
            cout << "A[i" << i << "] = " << A[i] << endl;
        }
}

// Main Driver
int main()
{
    Array_Class<int> I; // class template type is integer in this case declaration of an object I

    I.Add(15);
    I.Add(20);
    I.Add(0);
    I.Print();

    cout << endl;

    Array_Class<string> S; // class template type is string here, declaration of an object S

    S.Add("hello");
    S.Add("goodbye");
    S.Print();

    cout << endl;

    Array_Class<double> D; // class template type is double here declaration of an object D

    D.Add(.66666);
    D.Add(99.99999);
    D.Print();

    return 0;
}