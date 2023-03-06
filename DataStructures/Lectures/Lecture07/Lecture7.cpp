/****************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a driver, header and implementation file for a single linked stack
 * This program demonstrates use of the overloaded = operator for Linked
 * Lists. Makes one list the same as the other (similar to copy constructor)
****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

typedef string stack_element;

class stack_node
{
    public:

        stack_element data;
        stack_node *next;
};

class stack
{
    public:

        stack();                            // default constructor
        ~stack();                           // destructor
        stack(const stack& );               // copy constructor
        stack_element top();                // checks if stack is full
        void pop();
        void push(const stack_element& );
        void print();

    private:

        stack_node *s_top;
};

int main()
{
    stack S;

    S.push("Hello World!");
    S.push("We Hope You Are Well");
    S.push("Sooner Or Later...");
    S.push("Goodbye, World!");

    S.print();

    cout << endl << endl;
    S.print();

    cout << endl << endl;
    S.pop();
    S.print();

    cout << endl << endl;

    stack E = S;    // Using Overloaded Assignment operator=

    E.print();
    cout << endl << endl;
    S.print();

    return 0;
}

stack::stack()
{
    cout << "Inside Default Constructor" << endl;
    s_top = 0;
}

stack::~stack()
{
    cout << "Inside !~stack" << endl;
    while(s_top != 0)
        {
            pop();
        }
}

void stack::pop()
{
    cout << "Inside pop" << endl;
    stack_node *p;

    if (s_top != 0)
        {
            p = s_top;
            s_top = s_top->next;
            delete p;
        }
}

void stack::push(const stack_element& item)
{
    cout << "Inside push" << endl;
    stack_node *p = new stack_node;

    p->data = item;
    p->next = s_top;
    s_top = p;
}

void stack::print()
{
    cout << "Call to print" << endl;
    for(stack_node *p = s_top; p != 0; p = p->next)
        {
            cout << p->data << endl;
        }

    cout << "Done Printing" << endl;
}

stack_element stack::top()
{
    cout << "Inside top" << endl;
    if (s_top == 0)
        {
            cout << "WARNING: STACK FULL. Exiting..." << endl;
            exit(1);
        }
    else
        {
            return s_top->data;
        }
}

stack::stack(const stack& orig_obj)
{
    cout << "Inside the Copy Constructor" << endl;
    stack_node *p = orig_obj.s_top;
    (*this).s_top = 0;

    while(p != 0)
        {
            (*this).push(p->data); // stack is copied and stored in reverse order
            p = p->next;
        }
}