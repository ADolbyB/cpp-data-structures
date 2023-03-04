/**
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file to test a single linked queue.
*/

#include <iostream>
#include <string>
#include "s_queue.h"

using namespace std;

int main()
{
	QUEUE Q;

	Q.deQueue();

	Q.enQueue("hello world");
	Q.enQueue("good_bye_world");

	cout << Q.Front() <<endl;

	Q.deQueue();

	cout << Q.Front() << endl;

	Q.deQueue();
	Q.deQueue();

	return 0;
}