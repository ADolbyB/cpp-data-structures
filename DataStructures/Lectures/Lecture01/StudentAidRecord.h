/************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * Header file for the StudentAidRecord Class that 
 * models student financial aid records.   
************************************************************************/

#ifndef STUDENTAIDREC
#define STUDENTAIDREC

#include <string> 
#include "FinancialAidAward.h"

const int MAX_NUMBER_FINAID_AWARDS = 10;
typedef FinancialAidAward FinAidAwardArray[MAX_NUMBER_FINAID_AWARDS];

class StudentAidRecord
{
    public: // Function members

        StudentAidRecord();
        int getId() const;
        string getName() const;
        int getNumAwards() const;
        FinancialAidAward getFinancialAid(int i) const;
        void setId(int newId);
        void setName(string newName);
        void setNumAwards(int newNumAwards);
        void setFinancialAid(int i, FinancialAidAward newAid);
        void display() const;

    private: // Data members

        int id;                    // student's id number
        string name;               // student's name
        int numAwards;             // number of financial aid awards
        FinAidAwardArray finAid;   // array of financial aid awards

}; // end of class 

#endif