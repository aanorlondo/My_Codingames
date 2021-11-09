//https://www.codingame.com/ide/puzzle/encryptiondecryption-of-enigma-machine
#include <iostream>
#include <string>
using namespace std;

extern const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getAlphaPos(char c) {
    for (int i=0; i<alpha.length(); i++) {
        if (c==alpha[i]) return i;
    }
    return -1;
}

int getPos(char c, string s) {
        for (int i=0; i<s.length(); i++) {
        if (c==s[i]) return i;
    }
    return -1;
}

char getAlpha(char c) {
    return alpha[getAlphaPos(c)]; //not found
}

char shift(int degres, char c) {
    return getAlpha((getAlphaPos(c)+degres)%26);
}

string rotor(string m, string rotor) {
    string code = "";
    for (int i = 0; i < m.length() ; i++) {
        code += rotor[getAlphaPos(m[i])];
    }
    return code;
}

string encode(string m, string rotors[], int degres) {
    string code = m;
    cerr << "Encoding : "<< m << endl;
    for (int i = 0; i < m.length(); i++) {
        code[i] = shift(degres+i,code[i]);
    }
    cerr << "\tAfter Cesar : "<< code << endl;
    code = rotor(code,rotors[0]);
    cerr << "\tAfter rotor 1 : "<< code << endl;
    code = rotor(code,rotors[1]);
    cerr << "\tAfter rotor 2 : "<< code << endl;
    code = rotor(code,rotors[2]);
    cerr << "\tAfter rotor 3 : "<< code << endl;
    return code;
}

int main() {
    string OP; getline(cin, OP);
    int SHIFT; cin >> SHIFT; cin.ignore();
    string rotors[3];
    for (int i = 0; i < 3; i++) {
        getline(cin, rotors[i]);
    }
    string message; getline(cin, message);
    cerr << message << endl;
    cout << encode(message,rotors,SHIFT) << endl;
}
