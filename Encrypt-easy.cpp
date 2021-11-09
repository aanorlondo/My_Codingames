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

char getAlpha(int c) {
    return alpha[c]; //not found
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
    cerr << "Encoding : "<< code << endl;
    /*CESAR phase*/
    for (int i = 0; i < code.length(); i++) {
        //cerr << "\t\tChar : "<< code[i] ;
        code[i] = shift(degres+i,code[i]);
        //cerr << " becomes : " << code[i] << endl;
    }
    /*ROTORS 1 to 3*/
    cerr << "\tAfter Cesar : "<< code << endl;
    code = rotor(code,rotors[0]);
    cerr << "\tAfter rotor 1 : "<< code << endl;
    code = rotor(code,rotors[1]);
    cerr << "\tAfter rotor 2 : "<< code << endl;
    code = rotor(code,rotors[2]);
    cerr << "\tAfter rotor 3 : "<< code << endl;
    cerr << "**FINAL ENCRYPTION :" << endl;
    return code;
}

int main() {
    string OP; getline(cin, OP); //operator (ENCODE / DECODE)
    int SHIFT; cin >> SHIFT; cin.ignore(); // initial shift degree
    string rotors[3]; // the 3 rotors to be used
    for (int i = 0; i < 3; i++) {
        getline(cin, rotors[i]); //storing the rotors
    }
    string message; getline(cin, message);
    // the encode sequence
    if (OP == "ENCODE") cout << encode(message,rotors,SHIFT) << endl;
    else {
        // the decode sequence
        if (OP == "DECODE") cout << "NOT IMPLEMENTED YET" << endl;
    }
}
