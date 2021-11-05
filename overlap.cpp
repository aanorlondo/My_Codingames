#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Abs(int x)
{
    if (x < 0) return -x; return x;
}
int main()
{
    int begin_1; int end_1; int begin_2; int end_2;
    cin >> begin_1 >> end_1; cin.ignore(); cin >> begin_2 >> end_2; cin.ignore();
    int len_1 = Abs(end_1 - begin_1); int path_1[len_1];
    int len_2 = Abs(end_2 - begin_2);

    cerr << "line 1 : "<< begin_1 << " " << end_1 << endl;
    cerr << "line 2 : "<< begin_2 << " " << end_2 << endl;

    for (int i = 0 ; i < len_1 ; i++)
    {
        path_1[i] = begin_1 + i;
    }
    for (int i = 0 ; i < len_2 ; i++)
    {
        for (int j = 0; j < len_1 ; j++)
        {
            if (begin_2 + i == path_1[j]) 
            {
                cout << "Overlap" << endl;
                exit(0);
            }
        }
    }
    cout << "Not overlap" << endl;
}
