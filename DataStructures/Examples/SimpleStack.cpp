/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is a simple stack class program to demonstrate how a stack ADT works
*/

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

        stack();
        ~stack();
        stack(const stack& );
        stack_element top();
        void pop();
        void push(const stack_element& );
        void print();

    private:

        stack_node *s_top;

};

int main()
{
	stack S;

	S.push("a");                            // 1st string gets pushed to the bottom of the stack
	S.push("b");
	S.push("c");
	S.push("d");
	S.push("e");
	S.push("f");
	S.push("g");                            // Last string gets pushed and is on the top of the stack

	S.print();                              // prints stack from top to bottom "g f e d c b a"

	cout << endl << endl;

	stack Y = S;                            // calls copy constructor and makes a new object

	Y.print();                              // prints copied object from top of stack to bottom of stack

	return 0;                               // destructor called at program termination 2 times - 1 for each object.

}

stack::stack()
{
    cout << "* Default Constructor Called *" << endl;

    this->s_top = 0;                    // sets top of the new stack to NULL (since there are no elements in it the new object
}

stack::stack(const stack& original)
{
	cout << "* Copy Constructor Called *" << endl;

	(*this).s_top = 0;                                      // set pointer to the new stack node to zero, since the new stack is empty.

	stack temp;                                             // declare temporary stack object (will have a reversed stack)
	stack_node *p = original.s_top;                         // declare a pointer and start it at the original object that needs to be copied

	while(p != 0)
        {
            temp.push(p->data);                             // push the data from orig list to the stack of the new temp stack
            p = p->next;                                    // iterate through the list
        }                                                   /// this results in a copy stack that is reversed.

	p = temp.s_top;                                         // move pointer to the top of the temporary copy stack with reversed stack nodes.

	while (p != 0)
        {
            (*this).push(p->data);                          // now, push the stack data from the temp (reversed) stack, to the copy object
            p = p->next;                                    // iterate through the list
        }

    //temp.~stack();                                        // The destructor is called implicitly to deallocate the memory from the local temp stack, so this call is unnecessary
}

stack::~stack()
{
    cout << "* Destructor Called *" << endl;

	while(s_top != 0)
        {
            pop();
        }
}

void stack::push(const stack_element& item)
{
	cout << "\'Push\' Called" << endl;          // works for an empty or non-empty stack

	stack_node *p = new stack_node;         // allocate a new stack node with pointer

	p->data = item;                         // assign the input item to the data field
	p->next = s_top;                        // assign the next field to the current *s_top pointer
	s_top = p;                              // move the *s_top pointer up a node to *p (the new top of stack)

}

void stack::pop()
{

    cout << "\'Pop\' Called" << endl;

	stack_node *p;                          // declare stack_node pointer

	if (s_top != 0)                         // pop until the stack is empty
        {
            p = s_top;                      // point *p at the top of the stack
            s_top = s_top->next;            // move *s_top to the next one down the list
            delete p;                       // delete the top node in the stack.
        }

}

void stack::print()
{
	cout << "\'Print Called\'" << endl;

	stack_node *p;                              // declare a stack node pointer to iterate through the stack

	for(p = s_top; p != 0; p = p->next)         // point stack_node pointer at top of stack and iterate through the stack to print
        {
            cout << p->data << endl;            // iterates through and prints the stack from top to bottom
        }
}

stack_element stack::top()
{
	cout << "\'Top\' Called" << endl;

	if (s_top == 0)
        {
            exit(1);                                        // if the stack is empty, then the function exits
        }
	else
        {
            return s_top->data;                             // otherwise returns the top value of the stack
        }
}