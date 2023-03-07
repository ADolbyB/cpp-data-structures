/*************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the driver file for testing a Binary Search Tree ADT.
 * This program validates computer user-ids and passwords. A list of valid
 * ids and passwords is read from UsersFile and is stored in a BST. When
 * user-ids and passwords are entered during execution, the BST is
 * searched to determine whether they exist or not.
 * Input (file): UserInfo records for valid users
 * Input (keyboard): Ids and passwords of users logging in
 * Output (screen): Messages indicating whether user-ids and passwords
 * are valid.
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

class UserInfo  // Class for User Information
{
    public:

        // Inline Function Implementations
        string id() const { return myId; };             // Access User ID
        void read(istream& in)                          // Function to Read INput from File
        { in >> myId >> myPassword; };
        bool operator==(const UserInfo & user) const    // Overloaded Equality Operator
        { return myId == user.myId && myPassword == user.myPassword; };
        bool operator<(const UserInfo & user) const     // Overloaded Less-Than Operator
        { return myId < user.myId || myId == user.myId && myPassword < user.myPassword; };

    private:

        string myId;                                    // User ID
        string myPassword;                              // User Password
};

// Non-Class Function Definition that overloads the >> Input Operator.
istream& operator>>(istream& in, UserInfo& user)
{
    user.read(in);
}

// Main Driver
int main()
{
    string userFile;

    cout << "Enter name of user-info file: (userid.txt): ";
    getline(cin, userFile);

    ifstream inStream(userFile.data());                 // Open stream to read file data
    if (!inStream.is_open())                            // Check If Stream is Open.
        {
            cerr << "Cannot open " << userFile << " Exiting Function..." << endl;
            exit(1);
        }

    BST<UserInfo> userTree;                             // BST of user records
    UserInfo user;                                      // a user record

    for(;;)
        {
            inStream >> user;
            if (inStream.eof())                         // Stop at end of file
                {
                    break;
                }
            userTree.insert(user);
        }

    cout << "Enter Q to Quit Processing:" << endl;
    for (;;)
        {
            cout << endl << "User id & password: ";
            cin >> user;

            if (user.id() == "Q")
                {
                    break;
                }
            if (userTree.search(user))
                {
                    cout << "Valid user" << endl;
                }
            else
                {
                    cout << "Not a Valid User" << endl;
                }
        }
}