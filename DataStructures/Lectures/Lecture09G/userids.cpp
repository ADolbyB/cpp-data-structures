/***********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a small Driver Program that determines which users were 
 * logged into a computer system for a given period of time.
 * Input (keyboard): Name of the user-id file
 * Input (file): User ids
 * Output (screen): A list of distinct user-ids
***********************************************************************/

#include <iostream>
#include <string>
#include "LoginLog.h"

using namespace std;

int main()
{
    string userInfoFile;                        // Declare object to read file
    cout << "Enter name of login-info file: ";  // Step 1: Get file of logins
    getline(cin, userInfoFile);                 // use 'login.txt' and place a file in the project folder

    LoginLog<string> userIdLog;                    
    userIdLog.build(userInfoFile);              // Read the log from the file


    cout << endl << "List of Users who logged in:" << endl;
    userIdLog.display(cout);                    // Display the log
}