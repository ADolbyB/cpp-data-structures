/********************************************************************************************
Name: Joel Brigida                      Z#: Z***************
Course: Data Structures COP3530-001     Professor: Dr. Lofton Bullard
Due Date: 03/26/2021                    Due Time: 11:59pm
Total Points: 25 pts                    Assignment 8B: Recursion
Description: This function uses a class called 'node' and creates a linked list using functions
    that are not class functions. The nodes are created and added to a linked list using the
    "insert" function, and then prints the data stored in the nodes using recursive calls to
    the function "fun", which is a recursive print function.
*********************************************************************************************/

#include <iostream>

using namespace std;

void fun(class node* start);                        // Recursive function that prints out the created linked.
void insert(class node*& front, class node*& back, int the_data); // creates/adds nodes to a linked list

class node                                          // class declaration for a linked list
{
    public:

        int data;                                   // data inside the node (integer)
        node* next;                                 // points to the next node

};

int main()
{

    node* front = 0;                                // intialize front pointer to NULL since there is no list yet
    node* back = 0;                                 // intialize back pointer to NULL since there is no list yet

    for (int i = 1; i <= 6; i++)                    // for loop generates 6 new nodes in the list
        {
            //cout << "i = " << i << endl;          // debug
            insert(front, back, i);                 // creates and adds nodes to a linked list
        }

    //cout << "Before \'Fun\'" << endl;             // debug

    fun(front);                                     // function "fun" prints the linked list

    //cout << "DONE with \'Fun\'" << endl;          // debug

    return 0;
}

/**************************************************************************************
> Function Name: fun(class node* start);
> Precondition: The list to be printed has been populated with nodes.
> Postcondition: The data stored in all nodes is printed to the screen.
> Description: This function iterates a linked list of nodes and prints the contents
    of each node. If there are no nodes in the list, the function just returns and does
    nothing.
***************************************************************************************/
void fun(class node* start)
{
    //cout << "CALL TO FUN" << endl;

    if(start == NULL)                               // if the input argument pointer is NULL, then there is no list to print
        {
            //cout << "Inside 1st IF" << endl;      // debug
            return;
        }

    //cout << "(1) Print start->data" << endl;      // debug
    cout << start->data;                            // prints the data in the node passed as an argument 1st.

    if(start->next != NULL)
        {
            //cout << "Inside 2nd IF" << endl;      // debug
            fun(start->next->next);                 // recursive call to function "fun"
        }

    //cout << "(2) Print start->data" << endl;      // debug
    cout << start->data;                            // prints the data in the node passed as an argument 1st.

}

/*************************************************************************************
Function Name: insert(node*& front, node*& back, int the_data);
Precondition: Front and Back pointers have been declared and initialized in the main,
    and a function call to the function has been executed with pointers and an integer
    in the argument.
Postcondition: A new node is created, data is inserted to the node, and the pointers are
    moved to accomodate the new node to the linked list.
Description: This function allocates dynamic memory to create linked list nodes
    without using class functions.
*************************************************************************************/
void insert(node*& front, node*& back, int the_data)
{
    if(front == 0 && back == 0)
        {
            //cout << "add_back IF" << endl;        // debug
            front = new node;                       // declare new node at the front
            front->data = the_data;                 // dump data into the node
            back = front;                           // make the back the same as the front since there is only one node.
        }
    else
        {
            //cout << "add_back ELSE" << endl;      // debug
            node *p = new node;                     // declare new node at p
            p->next = 0;                            // dump data into new node
            p->data = the_data;                     // p will be in the back, so p->next will be NULL
            back->next = p;                         // tie p to back of the list
            back = p;                               // move back pointer to p, which is the new back node
        }
}
