/************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * Implementation File for Modelling Student Financial Aid Records.
 * This is the implementation file of the class library for the StudentAidRecord 
 * Class that models student financial aid records. 
************************************************************************/

#include <iostream>     // cout
#include <cassert>      // assert

using namespace std;

#include "StudentAidRecord.h"

/************************************************************************
Function Name: StudntAidRecord()
Description: Default constructor
Precondition: None.
Postcondition: StudentAidRecord object has been constructed with id = 0, 
name is an empty string, and finAid is default.
FinancialAidAward object (source = "", amount = 0).
************************************************************************/
StudentAidRecord::StudentAidRecord() : id(0), name(""), numAwards(0) { }

/************************************************************************
Function Name: getId()
Description: Accessor Function for ID #
Postcondition: Value stored in id is returned.
************************************************************************/
int StudentAidRecord::getId() const
{
    return id;
}

/************************************************************************
Function Name: getName()
Description: Accessor Function for Name.
Postcondition: Value stored in name is returned.
************************************************************************/
string StudentAidRecord::getName() const
{
    return name;
}

/************************************************************************
Function Name: getNumAwards()
Description: Accessor Function for NumAwards
Postcondition: Value stored in numAwards is returned.
************************************************************************/
int StudentAidRecord::getNumAwards() const
{
    return numAwards;
}

/************************************************************************
Function Name: getFinancialAid()
Description: Accessor Function for FinancialAid
Precondition:  0 <= i < numAwards
Postcondition: Value stored in finAid[i] is returned.
************************************************************************/
FinancialAidAward StudentAidRecord::getFinancialAid(int i) const
{
    assert(0 <= i && i < numAwards);
    return finAid[i]; 
}

/************************************************************************
Function Name: setId()
Description: Mutator Function for ID #
Precondition: newId > 0
Postcondition: id is been changed to newId.
*************************************************************************/
void StudentAidRecord::setId(int newId)
{ 
    assert(newId > 0);
    id = newId;
}

/************************************************************************
Function Name: setName()
Description: Mutator Function for Name
Precondition:  None. 
Postcondition: name has been changed to newName.
*************************************************************************/
void StudentAidRecord::setName(string newName)
{
    name = newName;
}

/************************************************************************
Function Name: setNumAwards()
Description: Mutator Function for NumAwards
Precondition:  0 < newNumAwards < MAX_NUMBER_FINAID_AWARDS
Postcondition: numAwards has been changed to newNumAwards.
************************************************************************/
void StudentAidRecord::setNumAwards(int newNumAwards)
{ 
    assert(0 <= newNumAwards && newNumAwards < MAX_NUMBER_FINAID_AWARDS);;
    numAwards = newNumAwards;
}

/************************************************************************
Function Name: setFinancialAid()
Description: Mutator Function for finAid
Precondition: 0 <= i < numAwards
Postcondition: finAid[i] has been changed to newAid.
************************************************************************/
void StudentAidRecord::setFinancialAid(int i, FinancialAidAward newAid)
{
    assert(0 <= i && i < numAwards);
    finAid[i] = newAid;
}

/************************************************************************
Function Name: display()
Description: Accessor Function to display ID, Name, and FinAid
Precondition: None.
Postcondition: StudentAidRecord object has been output to cout.
************************************************************************/
void StudentAidRecord::display() const
{
    cout << id << "  " << name << endl;
    for (int i = 0; i < numAwards; i++)
        {
            finAid[i].display();
            cout << endl;
        }
}