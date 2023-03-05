/************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * Implementation file of the class library for the FinancialAidAward
 * class that models student financial aid awards.
************************************************************************/

#include <iostream>     // cout
#include <string>       // string
#include <cassert>      // assert

using namespace std;

#include "FinancialAidAward.h"

/************************************************************************
Function Name: FinancialAidAward()
Description: Default constructor
Precondition: None.
Postcondition: FinancialAidAward object has been constructed in which
idNumber is 0, name and source are empty strings and amount is 0. 
************************************************************************/
FinancialAidAward::FinancialAidAward() : source(""), amount(0) { }

/************************************************************************
Function Name: FinancialAidAward()
Description: Explicit-value constructor
Precondition: id > 0 and amt >= 0
Postcondition: FinancialAidAward object has been constructed with 
idNumber = id, sourced = src, amount = amt.
************************************************************************/
FinancialAidAward::FinancialAidAward(string src, double amt)
{
   assert(amt >= 0);  // check preconditions
   amount = amt;
   source = src;
}

/************************************************************************
Function Name: getAmount()
Description: Accessor Function
Postcondition: Value stored in amount is returned.
************************************************************************/
double FinancialAidAward::getAmount() const
{
   return amount; 
}
 
/************************************************************************
Function Name: getSource()
Description: Accessor Function
Postcondition: Value stored in source is returned.
************************************************************************/
string FinancialAidAward::getSource() const
{
   return source;
}

/************************************************************************
Function Name: setAmount()
Description: Mutator Function
Precondition:  newAmount >= 0
Postcondition: amount has been changed to newAmount.
************************************************************************/
void FinancialAidAward::setAmount(double newAmount)
{ 
   assert(amount >= 0);
   amount = newAmount;
}

/***********************************************************************
Function Name: setSource()
Description: Mutator Function
Precondition: None. 
Postcondition: source has been changed to newSource.
************************************************************************/
void FinancialAidAward::setSource(string newSource)
{
   source = newSource;   
}

/************************************************************************
Function Name: display()
Description: Output function.
Precondition: None.
Postcondition: FinancialAidAward object has been output to cout.
************************************************************************/
void FinancialAidAward::display() const
{
   cout << source << ": $" << amount; 
}