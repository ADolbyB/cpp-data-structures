/**
 * Joel Brigida
 * COP3530: Data Structured
 * Test Program For Copy Constructor
 * This test program shows the difference between
 * a "deep copy" (using a copy constructor) and a "shallow copy"
 * A copy constructor is used to make a deep copy of an object in dynamic memory
*/

#include <iostream>

using namespace std;

void shallow_copy(void);
void deep_copy(void);
void copy_deallocate(void);

const int SIZE = 5;

class ARRAY_CLASS                                           // Array class for shallow copy function
{
    public:

        ARRAY_CLASS();                                      // default constructor
        void Add(int);                                      // mutator
        void Print();                                       // accessor
        int* Get_Address();                                 // accessor

    private:

        int *A;                                             // declares int pointer A
        int count;

};

class ARRAY_CLASS2                                          // Array class for deep copy function
{
    public:

        ARRAY_CLASS2();                                     // default constructor
        ARRAY_CLASS2(const ARRAY_CLASS2&);                  // copy constructor
        ~ARRAY_CLASS2();                                    // destructor
        void Add(int);                                      // mutator
        void Print();                                       // accessor
        int* Get_Address();                                 // accessor

    private:

        int *A;                                             // declares int pointer A
        int count;

};

class ARRAY_CLASS3                                          // Array class for deep copy and deallocate function
{
    public:

        ARRAY_CLASS3();                                     // default constructor
        ARRAY_CLASS3(const ARRAY_CLASS3&);                  // copy constructor - needed or the program will crash.
        ~ARRAY_CLASS3();                                    // destructor
        void Add(int);                                      // mutator
        void Print();                                       // accessor
        int* Get_Address();                                 // accessor
        void DeAllocate();                                  // mutator

    private:

        int *A;
        int count;

};

int main()
{

    //shallow_copy();
    deep_copy();
    //copy_deallocate();                                      /// CRASHES W/O A COPY CONSTRUCTOR FUNCTION

	return 0;
}

void shallow_copy(void)
{

    ARRAY_CLASS Bravo;                                      // declares an object Bravo, calls default constructor which adds a dynamic array to the object

	Bravo.Add(1);
	Bravo.Add(2);
	Bravo.Add(3);
	Bravo.Add(4);
	Bravo.Add(5);

	Bravo.Print();

	cout << endl << endl;

	ARRAY_CLASS Alpha = Bravo;

	Alpha.Print();

	cout << endl << "Alpha holds address location = " << Alpha.Get_Address() << endl;
	cout << "Bravo holds address location = " << Bravo.Get_Address() << endl;

}

ARRAY_CLASS::ARRAY_CLASS(void)
{

	cout << "Default Constructor has been Called!" << endl;

	A = new int[SIZE];                                      // int pointer A becomes a dynamic array with 5 blank elements.

	count = 0;                                              // initializes count to 0

}

void ARRAY_CLASS::Add(int item)                             // mutator function
{

	if (count < SIZE)                                       // SIZE is a const == 5
        {
            A[count++] = item;                              // sets array element A[count] == the argument sent from the function call in the "main"
        }
	else
        {
            cout << "Array Full" << endl;
        }

}

void ARRAY_CLASS::Print(void)
{

	for(int i = 0; i < count; i++)
        {
            cout << "A[" << i << "] = " << A[i] << endl;    // prints out the Array Element values in order
        }

}

int* ARRAY_CLASS::Get_Address(void)
{

	return A;                                               // returns pointer A as an int pointer, which is the address of the 1st element of the array

}

void deep_copy(void)
{

    ARRAY_CLASS2 Bravo2;                                    // creates an object called "B" and calls default constructor, count = 0

	Bravo2.Add(1);                                          // calls add function, places the value '1' into the array
	Bravo2.Add(2);
	Bravo2.Add(3);
	Bravo2.Add(4);
	Bravo2.Add(5);

	Bravo2.Print();                                         // prints out the entire array

	cout << endl << endl;

	ARRAY_CLASS2 Alpha2 = Bravo2;                           // declares a new object "A" that takes the value of "B"

	Alpha2.Print();

	cout << endl << "Alpha2 holds address location = " << Alpha2.Get_Address() << endl;
    cout << "Bravo2 holds address location = "<< Bravo2.Get_Address() << endl;

}

ARRAY_CLASS2::ARRAY_CLASS2(void)
{

	cout << "The Default Constructor 2 has been Called!" << endl;

	A = new int[SIZE];                                      // Pointer A becomes a blank 5 element array (SIZE = 5)

	count = 0;

}

ARRAY_CLASS2::ARRAY_CLASS2(const ARRAY_CLASS2& Org)
{

	cout << "The Copy Constructor has been Called!" << endl;

	count = Org.count;

	A = new int[SIZE];

	for(int i = 0; i < count; i++)
        {
            A[i] = Org.A[i];
        }

}

ARRAY_CLASS2::~ARRAY_CLASS2(void)
{

	cout << "The Destructor has been Called!" << endl;

	delete [] A;                                            // deletes the array and de-allocates the heap memory for the array
	A = 0;
	count = 0;

}

void ARRAY_CLASS2::Add(int item)
{
	if (count < SIZE)
        {
            A[count++] = item;
        }
	else
        {
            cout << "Array Full" << endl;
        }

}

void ARRAY_CLASS2::Print(void)
{

	for(int i = 0; i < count; i++)
        {
            cout << "A[" << i << "] = " << A[i] << endl;
        }

}

int* ARRAY_CLASS2::Get_Address(void)
{

	return A;

}

void copy_deallocate(void)
{

    ARRAY_CLASS3 Bravo;

	Bravo.Add(1);
	Bravo.Add(2);
	Bravo.Add(3);
	Bravo.Add(4);
	Bravo.Add(5);

	Bravo.Print();

	cout << endl << endl;

	ARRAY_CLASS3 Alpha = Bravo;

	cout << endl << "A holds address location = " << Alpha.Get_Address() << endl;
    cout << "B holds address location = " << Bravo.Get_Address() << endl;

	Bravo.DeAllocate();
    Alpha.Print();

}

ARRAY_CLASS3::ARRAY_CLASS3()
{

    cout << "Default constructor has been called" << endl;

	A = new int[SIZE];

	count = 0;

}

ARRAY_CLASS3::ARRAY_CLASS3(const ARRAY_CLASS3& Org)
{

	cout << "The Copy Constructor has been Called!" << endl;

	count = Org.count;

	A = new int[SIZE];

	for(int i = 0; i < count; i++)
        {
            A[i] = Org.A[i];
        }

}

ARRAY_CLASS3::~ARRAY_CLASS3()
{

	cout << "The Destructor has been Called!" << endl;

    delete [] A;
	A = 0;
	count = 0;

}

void ARRAY_CLASS3::Add(int item)
{

	if (count < SIZE)
        {
            A[count++] = item;
        }
	else
		cout << "Array Full" << endl;

}
void ARRAY_CLASS3::Print()
{

	for(int i = 0; i < count; i++)
        {
            cout << "A[" << i << "] = " << A[i] << endl;
        }

}

int* ARRAY_CLASS3::Get_Address()
{

	return A;

}

void ARRAY_CLASS3::DeAllocate()
{

	delete [] A;
	A = 0;
	count = 0;

}