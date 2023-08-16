#include <iostream>
#include <string>
using namespace std;

int main()
{
    string l1,l2,l3;
    l1 = " /\\ "; l2 = "<  >"; l3 =" \\/ ";
    int sides;
    cin >> sides; cin.ignore();

    for (int i=0; i < sides-1; i++) {
        cout << l1;
    }
    cout << " /\\" << endl;

    for (int i=0; i < sides; i++) {
        cout << l2;
    }
    cout << endl;

    for (int i=0; i < sides-1; i++) {
        cout << l3;
    }
    cout << " \\/" << endl;
}
