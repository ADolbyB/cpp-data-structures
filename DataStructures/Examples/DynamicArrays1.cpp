/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is a program to practice dynamic arrays in classes, Copy Constructors and Destructors
 * This example uses the class StringVar whose values are strings.
*/

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>

using namespace std;

class StringVar
{
    public:

        StringVar(int size);            // initializes object so it can accept string values up to "size" in length. Sets value of object to an empty string
        StringVar();                    // initializes the object so it can accept string values of length 100 or less. Sets the value of object to an empty string
        StringVar(const char a[]);      // initializes the object so its value is the string stored in a[] and so that it can later be set to string values up to strlen(a) in length
        StringVar(const StringVar& stringObject);   // copy constructor
        ~StringVar();                   // destructor: returns all the dynamic memory used by the object to the heap/freestore
        int length() const;             // returns the length of the current string value
        void inputLine(istream& ins);   // text in input stream is copied to the calling object, up to as much that is allowed to fit.
        friend ostream& operator <<(ostream& outs, const StringVar& theString); // overloads the "<<" operator so it can be used to outputvalues of type StringVar

    private:

        char *value;                    // pointer to the dynamic array that holds the string value
        int maxLength;                  // declared max length of any string value

};

void conversation(int maxNameSize);     // has a conversation with the user.

int main()
{

    conversation(30);                   // memory returned to the heap/freestore when the function call ends via the destructor.

    cout << "End of demonstration" << endl;


    return 0;
}

void conversation(int maxNameSize)      // demonstration function
{

    StringVar yourName(maxNameSize), ourName("Johnny Blaze");

    cout << "What is your first and last name?" << endl;
    yourName.inputLine(cin);
    cout << "My name is " << ourName << endl;
    cout << "We will meet again " << yourName << endl;

}

StringVar::StringVar(int size) : maxLength(size)
{

    value = new char[maxLength + 1];         // the +1 is for the NULL character '\0'
    value[0] = '\0';

}

StringVar::StringVar() : maxLength(100)
{

    value = new char[maxLength + 1];         // the +1 is for the NULL character '\0'
    value[0] = '\0';

}

StringVar::StringVar(const char a[]) : maxLength(strlen(a))
{

    value = new char[maxLength + 1];        // the +1 is for the NULL character '\0'
    strcpy(value, a);

}

StringVar::StringVar(const StringVar& stringObject) : maxLength(stringObject.length())      // COPY CONSTRUCTOR
{

    value = new char[maxLength + 1];        // the +1 is for the NULL character '\0'
    strcpy(value, stringObject.value);

}

StringVar::~StringVar()                     // DESTRUCTOR
{

    delete [] value;

}

int StringVar::length() const
{

    return strlen(value);

}

void StringVar::inputLine(istream& ins)
{

    ins.getline(value, maxLength + 1);

}

ostream& operator <<(ostream& outs, const StringVar& theString)
{

    outs << theString.value;
    return outs;

}