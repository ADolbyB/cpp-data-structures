/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the Driver file for a double linked queue.
*/

#include <iostream>
#include <string>
#include "d_queue.h"

using namespace std;

int main()
{

	DQUEUE Q;                           // Test Default Constructor

	Q.deQueue();                        // attmept to dequeue an empty queue

	Q.enQueue("1 hello world");         // Test ENQUEUE function
	Q.enQueue("2 good_bye_world");
	Q.enQueue("3 jurrasic_world");
	Q.enQueue("4 fish_world");
	Q.enQueue("5 water_world");

	Q.Print();                          // test PRINT function

	cout << Q.Front() << endl;          // test FRONT function

	Q.deQueue();                        // test DEQUEUE function

	cout << Q.Front() << endl;          // test FRONT function

	Q.deQueue();                        // test DEQUEUE function
	Q.deQueue();                        // destructor tested at the end

	return 0;
}