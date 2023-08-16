#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getPos(char c) {
    for (int i=0; i<alpha.length(); i++)
        if (alpha[i] == c) return i;
    return -1;
}

bool isAlpha(char c) {
    return ( getPos(c) > -1); 
}

char shift(char c) {
    int d = getPos(c) + 1; 
    return alpha[d%26];
}

string cesar(string m) {
    string str = m;
    for (int i = 0; i < m.length(); i++) {
        if (str[i] != ' ')
            str[i] = shift(str[i]);
    }
    return str;
}

int countWords(string m) {
    int count = 1;
    for (int i=0; i<m.length(); i++) {
        if (m[i] == ' ') count++;
    }
    return count;
}

bool find(string m, string *arr, int n) {
    for (int i=0; i<n ; i++) {
        if (m == arr[i]) return true;
    }
    return false;
}

int main() {
    string message;
    getline(cin, message);
    cerr << message << endl;

    bool legit = false; //we first assume the message is not legit
    int count = 0; //to count times we shifted the letters one position
    string decode = message; //string to remember states after multiple shifts

    while (!legit and count<26) {
        decode = cesar(decode); //shift one position
        int n = countWords(decode);
        
        //array of words after shifting
        string words[countWords(decode)]; 
        int i = 0;
        stringstream ssin(decode);
        while (ssin.good() && i < n){
            ssin >> words[i];
            ++i;
        }
        //looking for "CHIEF" in the words after shifting
        if (find("CHIEF",words,n)) 
            legit = true;

        count++; //we shifted one more time (max 25 times)
    }
    
    if (legit) cout << decode << endl;
    else cout << "WRONG MESSAGE" << endl;
}
