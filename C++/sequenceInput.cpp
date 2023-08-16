#include <iostream>
#include <string>
using namespace std;
int main() {
    string alpha = ".abcdefghijklmnopqrstuvwxyz";
    int n; cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int chars; 
        cin >> chars; cin.ignore();
        int max = chars - n + 1; if (max <= 0) max = 1; 
        for (int j = 0; j < max; j++) {
            cout << alpha[chars];
        }
        cout << endl;
    }
}
