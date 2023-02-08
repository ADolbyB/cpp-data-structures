/**
 * Joel Brigida
 * COP 3014: Foundations of CS
 * Banner Headline for assignments and testing cin functions
*/

#include <iostream>
#include <string>

void banner(void);

using namespace std;

int main()
{
    //banner();

    return 0;
}

void banner(void)
{
    char word_banner[46] = "        => Coin Change Calculator <=         ";
    int i;

    for (i = 1; i <= 45; i++)
        cout << "#";
    cout << endl;
    for (i = 1; i <= 45; i++)
        cout << word_banner[i];
    cout << endl;
    for (i = 1; i <= 45; i++)
        cout << "#";
}