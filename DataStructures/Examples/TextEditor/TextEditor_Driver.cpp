/***************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is the Driver program for TextEditor class. 
 * User Enters the name of a file to be edited.
 * TextEditor appends ".out" for the output file, constructs
 * a TextEditor object for editing these files, an& sends it the run() 
 * Function.
***************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#include "TextEditor.h"

int main()
{

    string inFileName, outFileName;

    cout << "Enter the name of the input file: ";

    getline(cin, inFileName);

    outFileName = inFileName + ".out";

    cout << "The output file is " << outFileName << "\n\n";

    TextEditor editor(inFileName, outFileName);

    editor.run();

    return 0;

}