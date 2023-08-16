#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

bool found(string x, set<string> set) {
    return set.find(x) != set.end();
}

int squareSum(string x) {
    int sum = 0;
    for (int j = 0; j < x.length(); j++) {
        sum += pow(x[j]-'0',2);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    set<string> unhappy;
    for (int i = 0; i < n; i++) {
        set<string> cache;
        string x;
        getline(cin, x);
        string x_transform = x;
        cerr << "Number " << i+1 << " is " << x << " :" << endl;
        int k = 0; //to erase
        int sum = 0;
        while(!found(x_transform,cache) && !found(x_transform,unhappy) && sum!=1) {
            cache.insert(x_transform);
            sum = squareSum(x_transform);
            k++; //to erase
            cerr <<"\tSum of squares of " << x_transform 
                 <<" (pass n°" << k <<") = " << sum 
                 << ((found(to_string(sum),cache))? " [cycle detected :(]" : "") << endl;
            x_transform = to_string(sum);
        }
        if(sum!=1) unhappy.insert(x);
        cout << (x+" :"+( (sum==1) ? ")" : "(")) << endl;
    }
}
