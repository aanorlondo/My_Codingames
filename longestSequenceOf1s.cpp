#include <iostream>
#include <string>
using namespace std;


int longest(string s) {
    int max = 0;
    int l = 0;
    for (int i = 0; i < s.length() ; i++) {
        if (s[i] == '1') {
            cerr << "Reading : " << s[i] << endl; 
            l++;
            if (l > max) max = l;
        }
        if (s[i] == '0') l=0;
    }
    return max;
}

int longestBis(string s) {
    int max = 0;
    int l = 0;
    int zeros = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            zeros++;
            if (zeros == 2) {
                l--;
                zeros = 1;
            }
            else l++;
        }
        else {
            l++;
        }
        if (l > max) max = l;
    }
    return max;
}

int main() {
    string b; getline(cin, b);
    cerr << "Sequence is " << b << endl;
    //int answer = longest(b);
    int answer2 = longestBis(b);
    cout << answer2 << endl;
}
