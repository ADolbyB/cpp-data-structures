/******************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines a LoginLog class template for a
 * computer log simulation of user information recorded during logins.
 * The type parameter Info represents the login information recorded for a user.
 * Basic operations:
 * build:    Builds the log of information for distinct users
 * search:   Searches the computer log for a particular user
 * display:  Displays the contents of the log
 * Note:  >>, <<, and == must be defined for type Info.
******************************************************************************/

#ifndef LOGINLOG_H_INCLUDED
#define LOGINLOG_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

template<typename Info>
class LoginLog
{
    public:

        // No Constructor Because We Are Using A Vector
        // Vector Has Its Own Constructor.
        void build(string fileName);
        int search(Info item) const;
        void display(ostream & out) const;

    private:

        vector<Info> myUserLog;

}; // End Class Definition

/******************************************************************************
Function Name: build()
Description: Builds the log of usernames.
Precondition: None.
Postcondition: Log has been built using input via a stream connected
to fileName.
******************************************************************************/
template<typename Info>
void LoginLog<Info>::build(string fileName)
{
    ifstream fin(fileName.data());                  // Declare input stream
    assert (fin.is_open());                         // Check that input stream is open

    Info userInfo;                                  // Declare generic object

    for(;;)                                         // infinite loop
        {
            fin >> userInfo;
            if ( fin.eof() )
                {
                    break;                          // break at End of File
                }
            int pos = search(userInfo);
            if (pos == myUserLog.size())            // New User
                {
                    myUserLog.push_back(userInfo);
                }
        }
}

/*******************************************************************************
Function Name: search()
Description: Searches user log for a given Info object.
Precondition: None.
Postcondition: The index in myUserLog where item is found is returned,
returns i = myUserLog.size() if not found.
*******************************************************************************/
template<typename Info>
int LoginLog<Info>::search(Info item) const
{
    int i;
    for (i = 0; i < myUserLog.size(); i++)
        {
            if (item == myUserLog[i])
                {
                    break;
                }
        }
    return i;
}

/*****************************************************************************
Function Name: display()
Description: Outputs the log to an output stream.
Precondition:  ostream out is a reference parameter.
Postcondition: Log has been output to out.
******************************************************************************/
template<typename Info>
inline void LoginLog<Info>::display(ostream& out) const
{
    for (int i = 0; i < myUserLog.size(); i++)
        {
            out << myUserLog[i] << endl;
        }
}

#endif // LOGINLOG_H_INCLUDED