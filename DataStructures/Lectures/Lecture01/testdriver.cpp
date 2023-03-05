/************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * Test driver for updateFinancialAid() function
 * This Function implements 2 classes: One for Student Aid Records,
 * And a 2nd for Financial Aid Awards.
*************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
#include "FinancialAidAward.h"  // Financial aid awards
#include "StudentAidRecord.h"   // Student financial-aid records

using namespace std;

/* Non-Class Function Prototype Declaration */
void updateFinancialAid(int numRecords, StudentAidRecord studentRecord[], double percent);

int main()
{
    const int NUMBER_OF_RECORDS = 3;
    
    StudentAidRecord arr[NUMBER_OF_RECORDS];
    
    double percent = .10;
    int id, awards;
    string name, source;
    double amount;

    for (int i = 0; i < NUMBER_OF_RECORDS; i++)
        {
            cout << endl << "Enter student's id, name: ";
            cin >> id;
            getline(cin, name);
            
            arr[i].setId(id);
            arr[i].setName(name);
            
            cout << "Enter number of awards for " << id << ": ";
            cin >> awards;
            
            arr[i].setNumAwards(awards);
            
            for (int a = 0; a < awards; a++)
                {
                    cout << "Award " << a + 1 << "'s amount and source: ";
                    cin >> amount;

                    getline(cin, source);

                    FinancialAidAward finaid(source, amount);

                    arr[i].setFinancialAid(a, finaid);
                }
        }
    updateFinancialAid(NUMBER_OF_RECORDS, arr, percent);

    cout << endl << "Updated Financial Aid Records:" << endl << "==============================" << endl;
    
    for (int i = 0; i < NUMBER_OF_RECORDS; ++i)
        {
            arr[i].display();
            cout << endl;
        }
}

/*************************************************************************
Function Name: updateFinancialAid()
Description: Non-Class Function to Increase the amount of all financial
aid awards in an array of student financial aid records by a specified percentage.
Precondition: numRecords > 0 and percent > 0 is a expressed as a decimal. 
Postcondition: Each record in finAidArray has been modified by increasing
the amount of each financial aid award in each record by the specified percentage.
*************************************************************************/
void updateFinancialAid(int numRecords, StudentAidRecord studentRecord[], double percent)
{
    assert (numRecords > 0 && percent > 0);
    for (int record = 0; record < numRecords; record++)
        {
            int awardCount = studentRecord[record].getNumAwards();
            for (int count = 0; count < awardCount; count++)
                {
                    FinancialAidAward aid = studentRecord[record].getFinancialAid(count);
                    double newAmount = aid.getAmount();
                    
                    newAmount += percent * newAmount;
                    aid.setAmount(newAmount);
                    
                    studentRecord[record].setFinancialAid(count, aid);
                }
        }
}