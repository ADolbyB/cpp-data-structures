/*********************************************************************
 * Drill-and-Practice Program that generates random drill-and-practice
 * addition problems.  Problems that are answered incorrectly are
 * queued and asked again until all are answered correctly or maximum
 * number of tries is reached.
 * Inputs: # of problems to generate & student's answers to problems
 * Output: Messages, problems, correct answers, number of problems
 * answered correctly
 * Requires use of a Queue Class Header and Implementation.
**********************************************************************/

#include <iostream>                  // cin, cout, >>, <<
#include "Queue.h"                   // A queue class for AdditionProblems
#include "AdditionProblem.h"         // AdditionProblem, initialize()

using namespace std;

int main()
{

    int numProblems;                 // number of problems asked
    int maxAddend;                   // maximum addend in a problem
    const int MAX_ROUNDS = 3;        // maximum number of rounds in which to try the problems
    
    initialize();                    // initialize random number generator

    cout << "*** Addition Practice Problems ***" << endl << endl
         << "How many problems would you like? ";
    cin >> numProblems;

    cout << "What's the largest addend you would like? ";
    cin >> maxAddend;

    Queue problemQueue;              // generate a queue of addition problems

    for (int i = 1; i <= numProblems; i++)
        {
            AdditionProblem problem(maxAddend);
            problemQueue.enqueue(problem);
        }

    AdditionProblem problem;         // Generate next addition problem
    int userAnswer;                  // user's answer to a problem
    int numberMissed;                // number of problems incorrect

    for (int round = 1; round <= MAX_ROUNDS; round++)
        {    // One round of problems
            numberMissed = 0;

            for (int count = 1; count <= numProblems; count++)
                {
                    problem = problemQueue.front();
                    problemQueue.dequeue();
                    cout << problem;
                    cin >> userAnswer;

                    if (userAnswer == problem.answer())
                        {
                            cout << "Correct!" << endl << endl;
                        }
                    else
                        {
                            cout << "Incorrect: Try again next time" << endl << endl;
                            problemQueue.enqueue(problem);
                            numberMissed++;
                        }
                } // End of Practice Problems
            if (numberMissed == 0)
                {
                    cout << "Congrats! You correctly answered every problem in Round #" << round << endl;
                    break;
                }
            else
                {
                    cout << endl << "You missed " << numberMissed << " problems in Round #" << round << "." << endl;

                    if (round < MAX_ROUNDS)
                        {
                            cout << "You may now try them again.  Good luck!" << endl;
                        }
                    numProblems = numberMissed;
                } // end of evaluation
        }
    if (numberMissed == 0)
        {
            cout << "You have finished & correctly answered all problems. Congrats!" << endl;
        }
    else
        {
            cout << endl << "You have finished all the practice problems." << endl;
            cout << "Here are the problems you missed:" << endl << endl;
            while (!problemQueue.empty())
                {
                    problem = problemQueue.front();
                    problemQueue.dequeue();
                    cout << problem << " Answer: " << problem.answer() << endl << endl;
                }
            cout << "Perhaps it would be a good idea to practice some more." << endl;
        }
    return 0;
}