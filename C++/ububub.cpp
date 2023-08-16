#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isvowel(char c) {
    string vowels = "aeio";
    for (int i = 0; i < vowels.length() ; i++)
    {
        if ( c == vowels[i]) return true;
    }
    return false;
}

int main()
{
    string input;

    getline(cin, input);
    string output = "";
    for (int i = 0; i < input.length() ; i++)
    {
        if (isvowel(input[i])) {
            output = output + "ub" + input[i];
        }
        else output = output + input[i];
    }
    cout << output << endl;
}
