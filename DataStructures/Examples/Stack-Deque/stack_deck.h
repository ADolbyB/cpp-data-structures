/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file to test a single linked queue.
*/

#ifndef STACK_DECK_H_INCLUDED
#define STACK_DECK_H_INCLUDED

#include <iostream>
#include <deque>

template<typename StackElement>
class Stack
{
    public:      /***** Function Members *****/

        Stack();
        bool empty() const;
        void push(const StackElement & value);
        void display(ostream & out) const;
        StackElement top() const;
        void pop();

    private:     /***** Data Members *****/

        deque<StackElement> myDeque;  // deque to store elements

}; // end of class declaration


template <typename StackElement>
inline Stack<StackElement>::Stack()
{  
    // deque has its own constructor 
}

template <typename StackElement>
inline bool Stack<StackElement>::empty() const
{
    return myDeque.empty();
}

template <typename StackElement>
void Stack<StackElement>::push(const StackElement & value)
{
    // push value to the back of the deque
    myDeque.push_back(value);
}

template <typename StackElement>
void Stack<StackElement>::display(ostream & out) const
{
    for (int pos = myDeque.size() - 1; pos >= 0; pos--)
        {
             out << myDeque[pos] << endl;
        }
}

template <typename StackElement>
StackElement Stack<StackElement>:: top() const
{
    if (!myDeque.empty())
        {
            return myDeque.back();
        }

    else
        {
            cout << "*** Stack is empty ***\n";
            return 0;
        }
}

template <typename StackElement>
void Stack<StackElement>:: pop()
{
    if (!myDeque.empty())
        {
            myDeque.pop_back();
        }
    else
        {
            cout << "*** Stack empty: can't remove a value ***" << endl;
        }
}

#endif // STACK_DECK_H_INCLUDED