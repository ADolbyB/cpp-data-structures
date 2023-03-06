/******************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This program is another example of declaring and using generic function 
 * templates which work on multiple data types.
******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 5;

/*******************************************************************************
Class declaraton for Generic Template Array_Class
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

int main()
{
    Array_Class<string> S;

    S.Add("hello");
    S.Add("Zebra");
    S.Add("House");
    S.Print();

    Array_Class<double> D;

    D.Add(2.9876);
    D.Add(1.3450);
    D.Add(4.999);
    D.Print();

    return 0;
}

/**********************************************************************
Function Name: Array_Class()
Description: Default Constructor. Constructs an empty object based on
the data type declared in the main function.
**********************************************************************/
template <class New_Type>
Array_Class<New_Type>::Array_Class()
{
    cout << "Default Constructor Called" << endl;
    cout << "New_Type has a size of " << sizeof(New_Type) << " bytes" << endl;

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
    cout << endl << "Destructor Called" << endl;
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
            cout << "A[" << i << "] = " << A[i] << endl;
        }
}