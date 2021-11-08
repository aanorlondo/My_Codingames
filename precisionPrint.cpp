#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string s; getline(cin, s);
    double count = 0;
    for (int i = 0; i < s.length(); i++) count += double(s[i]);
    cout.precision(1); cout <<fixed << (double)count/s.length() << endl;
}
