/***********************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the implentation file for the TextEditor class. 
***********************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "TextEditor.h"

/***********************************************************************
Function Name: eatBlanks()
Description: Non Class Utility function Called from to eat spaces from cin
Precondition: Text Entered using cin
Postcondition: removes spaces from cin
***********************************************************************/
void eatBlanks()                                                                   
{
    char blank;

    while (cin.peek() == ' ')
        {
            cin.get(blank);
        }
}

/***********************************************************************
Function Name: TextEditor()
Description: Construct a text editor for files named inputFile and
outputFile.
Precondition: inputFile is the file to be edited.
Postcondition: outputFile contains the edited text.
***********************************************************************/
TextEditor::TextEditor(string inputFile, string outputFile)
{

    myInstream.open(inputFile.data());
    myOutstream.open(outputFile.data());

    if (!myInstream.is_open() || !myOutstream.is_open())
        {
            cerr << "Error in opening files.";
            exit(-1);
        }
}

/***********************************************************************
Function Name: run()
Description: Runs the text editor program.
Precondition: None.
Postcondition: Text from inputFile has been edited and output to
outputFile.
***********************************************************************/
void TextEditor::run()
{

    showMenu();

    cout << "Enter an editing command following each prompt: " << endl << endl;

    getline(myInstream, myLine);           // ifstream object "myInstream" writes user input to private variable myLine

    cout << "TEXT: " << myLine << endl;    // echo user text stored in myLine

    char command;

    string str1, str2;

    for (;;) // infinite loop
        {

            if (myInstream.eof())
                {
                    break;
                }

            cout << '>';
            cin >> command;
            cin.ignore(1, '\n');

            switch(toupper(command))
            {

                case 'I' :

                    eatBlanks();
                    getline(cin, str1);
                    cout << "Insert before what string? ";
                    getline(cin, str2);
                    insert(str1, str2);
                    break;

                case 'D' :

                    eatBlanks();
                    getline(cin, str1);
                    erase(str1);
                    break;

                case 'R' :

                    eatBlanks();
                    getline(cin, str1);
                    cout << "With what? ";
                    getline(cin, str2);
                    replace(str1, str2);
                    break;

                case 'N' : next();
                    break;

                case 'Q' : quit();
                    break;

                default :  cout << endl << "*** Illegal command ***" << endl;
                    showMenu();
                    cout << "TEXT:" << myLine << endl;
            }

            if (!myInstream.eof())
                {
                    cout << "TEXT: " << myLine << endl;
                }
        }
    cout << endl << "*** Editing complete ***" << endl;
}

/***********************************************************************
Function Name: showMenu()
Description: Displays menu of editing commands.
Precondition: None.
Postcondition: Menu has been output to cout.
***********************************************************************/
void TextEditor::showMenu()
{

    cout << "Editing commands are: " << endl
         << "I str: Insert string str before another string" << endl
         << "D str: Delete string str" << endl
         << "R str: Replace string str with another string" << endl
         << "N: Get next line of text" << endl
         << "Q: Quit editing" << endl;

}

/***********************************************************************
Function Name: insert()
Description: Insert a string into a line of text.
Precondition: None.
Postcondition: str1 has been inserted before str2 in myLine if
str2 is found in myLine; otherwise, myLine is unchanged.
***********************************************************************/
void TextEditor::insert(string str1, string str2)
{
    int position = myLine.find(str2);

    if (position != int(string::npos))
        {
             myLine.insert(position, str1);
        }

    else
        cout << str2 << " not found" << endl;
}

/***********************************************************************
Function Name: erase()
Description: Removes a string from a line of text.
Preconditions: None.
Postcondition: str has been removed from myLine if str is found
in myLine; otherwise, myLine is unchanged.
***********************************************************************/
void TextEditor::erase(string str)
{
    int position = myLine.find(str);

    if (position != int(string::npos))
        {
            myLine.erase(position, str.length());
        }
    else
        cout << str << " not found" << endl;
}

/***********************************************************************
Function Name: replace()
Description: Replaces one string with another in a line of text.
Precondition: None.
Postcondition: str1 has been replaced with str2 in myLine if str1
is found in myLine; otherwise, myLine is unchanged.
***********************************************************************/
void TextEditor::replace(string str1, string str2)
{

    int position = myLine.find(str1);

    if (position != int(string::npos))
        {
            myLine.replace(position, str1.length(), str2);
        }
    else
        cout << str1 << " not found" << endl;
}

/***********************************************************************
Function Name: next()
Description: Move on to next line of text to edit.
Precondition: None.
Postcondition: String that was in myLine has been output to
myOutstream and a new line read from myInstream into myLine.
***********************************************************************/
void TextEditor::next()
{

    myOutstream << myLine << endl;

    getline(myInstream, myLine);

    cout << endl << "Next line:" << endl << endl;
}

/***********************************************************************
Function Name: quit()
Description: Quits the Text Editor.
Precondition: None.
Postcondition: String that was in myLine has been output to
outputFile and any lines remaining in inputFile have been
copied to outputFile.
***********************************************************************/
void TextEditor::quit()
{

    myOutstream << myLine << endl;

    for (;;)
        {
            getline(myInstream, myLine);

            if (myInstream.eof())
                {
                    break;
                }
            myOutstream << myLine << endl;
        }
}