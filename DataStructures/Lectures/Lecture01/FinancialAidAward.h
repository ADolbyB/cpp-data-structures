/*************************************************************************
 * Joel Brigida
 * COP 3530: Data Structures
 * Header file for the FinancialAidAward Class which
 * models student financial aid records.
*************************************************************************/

#ifndef FINAIDAWARD
#define FINAIDAWARD

#include <string> 

class FinancialAidAward
{
    public: // Function members

        FinancialAidAward();
        FinancialAidAward(string src, double amt);
        double getAmount() const;
        string getSource() const;
        void setAmount(double newAmount);
        void setSource(string newSource);
        void display() const;

    private: // Data members

        string source;     // source of financial aid
        double amount;     // amount of financial aid

}; // end of class declaration

#endif