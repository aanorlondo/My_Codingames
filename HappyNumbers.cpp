#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

bool found(string x, set<string> set) {
    return set.find(x) != set.end();
}

long long sqrtSum(string x) {
    int sum = 0;
    for (int j = 0; j < x.length(); j++) {
        sum += sqrt(x[j]-'0');
    }
    return sum;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    set<string> unhappy;
    for (int i = 0; i < n; i++) {
        set<string> numbers;
        string x;
        getline(cin, x);
        string x_transform = x;
        cerr << "Number " << i+1 << " is " << x << " :" << endl;
        int k = 0; //to erase
        long long num = 0;
        while(!found(x_transform,numbers) && !found(x_transform,unhappy) && num!=1) {
            numbers.insert(x_transform);
            num = sqrtSum(x_transform);
            x_transform = to_string(num);
            k++; //to erase
            cerr <<"\tSum of squares (pass n°" << k <<") = " << x_transform << endl;
        }
        if(num!=1) unhappy.insert(x);
        cout << (x+" :"+( (num==1) ? ")" : "(")) << endl;
    }
}
