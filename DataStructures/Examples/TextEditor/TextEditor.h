/**-- TextEditor.h ---------------------------------------------------------
 * Joel Brigida
 * COP3530: Data Structures
 * This header file defines the data type TextEditor for editing text files.
 * Basic operations:
 * Constructor: Construct a TextEditor object for given files
 * run(): Run the editor
 * showMenu(): Display the menu of editing "hot keys"
 * insert(): Insert a string in a line of text
 * erase(): Remove a string from a line of text
 * replace(): Replace a string by another string in a line of text
 * next(): Output edited line and get next line to edit
 * quit(): Terminate editing
 --------------------------------------------------------------------------*/

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class TextEditor
{
    public:     /******** Function Members ********/

        TextEditor(string inputFile, string outputFile);
        void run();
        void showMenu();
        void insert(string str1, string str2);
        void erase(string str);
        void replace(string str1, string str2);
        void next();
        void quit();

    private:    /******** Data Members ********/

        ifstream myInstream;
        ofstream myOutstream;
        string myLine;
};

#endif // TEXTEDITOR_H