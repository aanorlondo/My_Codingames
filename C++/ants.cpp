#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    string s[n];
    for (int i=0;i<n;i++)
        cin>>s[i];cin.ignore();
    int x=0; int y=0;
    for (int i=0;i<n;i++)
    {   if(s[i]=="F")y++;
        if(s[i]=="B")y--;
        if(s[i]=="R")x++;
        if(s[i]=="L")x--; }
    cout<<sqrt(pow(x,2)+pow(y,2))<<endl;
}
