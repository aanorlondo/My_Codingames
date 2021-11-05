#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string s; getline(cin, s);
    string mirror; getline(cin, mirror);

    if (mirror == "|") {
        for (int i = s.length()-1 ; i >= 0 ; i--)
        {
            cout << s[i] ;
        }
        cout << endl;
    }
    else
        if (mirror == "/") {
            for (int i = s.length()-1 ; i >=0 ; i--)
            {
                for (int j = 0 ; j < s.length(); j++)
                {  
                    if (j < i) cout << ".";
                    else if (j == i) cout << s[i] << endl;
                }
            }
            cout << endl;
        }
        else
            if (mirror == "\\") {
                for (int i = s.length()-1 ; i >=0 ; i--)
                { 
                    for (int j = s.length()-1 ; j >= 0 ; j--)
                    {
                        if (j == i) cout << s[i] << endl;
                        else if (j > i) cout < "." ;
                    }
                }
                cout << endl;
            }
}
