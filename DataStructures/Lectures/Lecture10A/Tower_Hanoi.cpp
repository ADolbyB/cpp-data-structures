/*************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This program solves the Towers of Hanoi puzzle using recursion.
 * Input: numDisks, the number of disks to be moved
 * Output: The sequence of moves that solve the puzzle
 ************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void move(unsigned n, unsigned& moveNumber, char source, char destination, char spare);

int main()
{
    const char PEG1 = 'A';                              // Three Pegs of the Game
    const char PEG2 = 'B';
    const char PEG3 = 'C';

    unsigned moveNumber = 0;                            // Count # of Moves

    cout << "This program solves the Hanoi Towers puzzle." << endl << endl;
    cout << "Enter the number of disks: ";
    
    int numDisks;                                       // Number of Disks that need to be moved.
    cin >> numDisks;
    
    cout << endl;

    move(numDisks, moveNumber, PEG1, PEG3, PEG2);       // Determines Solution

    return 0;
}

/***********************************************************************
Function Name: move()
Description: Recursively called function that solves the Towers of Hanoi
puzzle with 'n' number of disks.
Precondition: None.
Postcondition: A message describing the move is output to cout.
 ***********************************************************************/
void move(unsigned n, unsigned& moveNumber, char source, char destination, char spare)
{
    if (n == 1)                                         // Anchor Case
        {
            moveNumber++;
            cout << setw(3) << moveNumber <<  ". Move the top disk from " << source << " to " << destination << endl;
        }
    else
        {                                               // Inductive Case
            move(n - 1, moveNumber, source, spare, destination);
            move(1, moveNumber, source, destination, spare);
            move(n - 1, moveNumber, spare, destination, source);
        }
}