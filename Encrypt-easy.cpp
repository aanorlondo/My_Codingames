//https://www.codingame.com/ide/puzzle/encryptiondecryption-of-enigma-machine
#include <iostream>
#include <string>
using namespace std;

extern const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//get alphabetical position of a char
int getAlphaPos(char c) {
    for (int i=0; i<alpha.length(); i++) {
        if (c==alpha[i]) return i;
    }
    return -1;
}

//get position of a char in a given string
int getPos(char c, string s) {
        for (int i=0; i<s.length(); i++) {
        if (c==s[i]) return i;
    }
    return -1;
}

//get letter by position from alphabetical sequence
char getAlpha(int c) {
    return alpha[c]; //not found
}


//filter a string by a given rotor
string rotor(string m, string rotor) {
    string code = "";
    for (int i = 0; i < m.length() ; i++) {
        code += rotor[getAlphaPos(m[i])];
    }
    return code;
}

string reverserotor(string m, string rotor) {
    string code = "";
    for (int i = 0; i < m.length() ; i++) {
        code += getAlpha(getPos(m[i],rotor));
    }
    return code;
}

//cesar with a given degre
char shift(int degres, char c) {
    int d = getAlphaPos(c) + degres; 
    while ( d <= -26 ) d += 26;
    if (d<0) return getAlpha(d%26+26);
             return getAlpha(d%26);
}

string cesar(string m, int degres) {
    string str = m;
    for (int i = 0; i < m.length(); i++) {
        str[i] = shift(degres+i,str[i]);
    }
    return str;
}

string reversecesar(string m, int degres) {
    string str = m;
    for (int i = 0; i < str.length(); i++) {
        str[i] = shift(-degres-i,str[i]);
    }
    return str;
}

//the encode sequence
string encode(string m, string rotors[], int degres) {
    cerr << "Encoding : "<< m << endl;
    /*CESAR phase*/
    string code = cesar(m,degres);
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

//the decode sequence
string decode(string m, string rotors[], int degres) {
    cerr << "Decoding : "<< m << endl;
    /*Reverse ROTORS 3 to 1*/
    string clear = reverserotor(m,rotors[2]);
    cerr << "\tAfter reverse rotor 3 : "<< clear << endl;
    clear = reverserotor(clear,rotors[1]);
    cerr << "\tAfter reverse rotor 2 : "<< clear << endl;
    clear = reverserotor(clear,rotors[0]);
    cerr << "\tAfter reverse rotor 1 : "<< clear << endl;
    /*Reverse CESAR phase*/
    clear = reversecesar(clear, degres);
    cerr << "\tAfter reverse Cesar : "<< clear << endl;
    /*for (int i = 0 ; i < clear.length() ; i++) {
        cerr << getAlphaPos(clear[i]) << " ";
    }
    cerr << endl;*/
    cerr << "**FINAL DECRYPTION :" << endl;
    return clear;
}

int main() {
    string OP; getline(cin, OP); //operator (ENCODE / DECODE)
    int SHIFT; cin >> SHIFT; cin.ignore(); // initial shift degree
    string rotors[3]; // the 3 rotors to be used
    for (int i = 0; i < 3; i++) {
        getline(cin, rotors[i]); //storing the rotors
    }
    string message; getline(cin, message);
    cerr << "**INPUTS**" << endl;
    cerr << "SHIFT = " << SHIFT << " | OP = " << OP << " | STR = " << message.length() << endl;
    cerr << "Rotor 1 = " << rotors[0] << endl;
    cerr << "Rotor 2 = " << rotors[1] << endl;
    cerr << "Rotor 3 = " << rotors[2] << endl;
    cerr << "************************************" << endl;

    // the encode sequence
    if (OP == "ENCODE") cout << encode(message,rotors,SHIFT) << endl;
    else
     // the decode sequence
    if (OP == "DECODE") cout << decode(message,rotors,SHIFT) << endl;
}
