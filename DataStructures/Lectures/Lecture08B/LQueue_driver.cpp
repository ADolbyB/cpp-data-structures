/*********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This file implements A simple Queue Data Structure
*********************************************************************/

#include <iostream>
#include "LQueue.h"

using namespace std;

// Function Declaration & inline implementation
void print(Queue q) { q.display(cout); } // inline implementation

int main()
{
    Queue q1;

    cout << "Queue created. Empty? " << boolalpha << q1.empty() << endl;

    cout << "How many elements to add to the queue? ";
    int numItems;
    cin >> numItems;

    for (int i = 1; i <= numItems; i++)
        {
            q1.enqueue(100 * i);
        }

    cout << "Contents of queue q1 (via print):" << endl;
    print(q1);
    cout << endl;

    Queue q2;
    q2 = q1;

    cout << "Contents of queue Q2 after Q2 = Q1 (via print): " << endl;
    print(q2);
    cout << endl;

    cout << "Queue Q2 empty? " << q2.empty() << endl;

    cout << "Front value in Q2: " << q2.front() << endl;

    while (!q2.empty())
        {
            cout << "Remove front: Queue contents: ";
            q2.dequeue();
            q2.display(cout);
        }

    cout << "Queue Q2 empty? " << q2.empty() << endl;
    cout << "Front value in Q2?" << endl << q2.front() << endl;
    cout << "Trying to remove front of Q2: " << endl;

    q2.dequeue();
}