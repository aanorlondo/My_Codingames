#include <iostream>
#include <string>

using namespace std;

bool find(string line, string str) {
    return (line.find(str) != string::npos);
}

int val(string o) { //extract the right answer
    string v = "";
    for (int i = 0 ; i < o.length() && o[i] != ' ' ; i++ )
        v += o[i];
    return stoi(v);
}

int main() {
    int r; // nmbr of rounds
    cin >> r; cin.ignore();
    string lines[r]; // rounds strings
    for (int i = 0; i < r; i++) {
        getline(cin, lines[i]);
            cerr << "Round " << i+1 << ": " << lines[i] << endl;
    }
    int solution = val(lines[r-1]); //fetching the solution
            cerr << "Solution = " << solution << endl;
    for (int i = 0; i < r; i++) {
        if ( ( find(lines[i],"too high") && val(lines[i]) <= solution ) ||
            ( find(lines[i],"too low") && val(lines[i]) >= solution )) {
                    cout << "Alice cheated in round "+ to_string(i+1) << endl;
                    exit(-1);
                    // by retrospection, anything incoherent with the final result is cheating
            }
    }
    cout << "No evidence of cheating"; //owise...
}
