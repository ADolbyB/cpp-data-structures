/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * This is a compilation of methods to produce segmentation faults.
 * For research purposes
*/

#include <iostream>
#include <cstdlib>                              // malloc, rand, free, etc

using namespace std;

const int TEST_VAR = 1234;
void test_array(void);

int main()
{

    //test_array();
    //char *p1 = NULL;                            // Null pointer
    //char *p2;                                   // Wild pointer: not initialized at all.
    //char *p3 = malloc(10 * sizeof(char));       // Initialized pointer to allocated memory
                                                // (assuming malloc did not fail)
    //free(p3);                                   // p3 is now a dangling pointer, as memory has been freed


    //TEST_VAR++;                               // syntax error

    //char *s = "hello world";
    //*s = 'H';

    //int *ptr = NULL;
    //printf("%d", *ptr);

    //int *ptr = NULL;
    //*ptr = 1;

    //main();

    return 0;
}

void test_array(void)
{
    int num;
    int array1[10];

    cout << "Enter number of array elements needed: ";
    cin >> num;                                                                                 // problem: input is not validated to meet criteria of array index limit.

    for (int i = 0; i < num; i++)                                                               // program crashes if 'num' > 10
        {
            array1[i] = i;
            cout << "array1[" << i << "] = " << i << endl;
        }
}