#include <iostream>
using namespace std;
int main() {
    int a; int b; int c;
    cin >> a; cin.ignore(); cin >> b; cin.ignore(); cin >> c; cin.ignore();
    int budget = (a*6*5*4) - c;
    if (budget > b) cout << "true" << endl; 
    else cout << "false" << endl; 
}
