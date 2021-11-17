//Graffiti on the fence 
//https://www.codingame.com/ide/puzzle/graffiti-on-the-fence
#include <iostream>
#include <string>
using namespace std;

 void print(int* field, long long L) {
     //print the field to vizualise (0)1 == (un)painted
     for (int i = 0; i < L; i++) {
         cerr << field[i] << " " ;
     }
     cerr << endl;
 }

 void set(int* field, long long L) {
     //to set all segments to 0 (unpainted)
     for (int i = 0; i < L; i++) {
         field[i] = 0;
     }
 }

int main()
{
    long long L; cin >> L; cin.ignore(); 
    long long N; cin >> N; cin.ignore();
    int* field = new int[L]; set(field,L); //set all segments in field at 0
    print(field,L);
    for (int i = 0; i < N; i++) {
        int start; int end; cin >> start >> end; cin.ignore();
        for (int j = start; j< end; j++) {
            field[j] = 1; //for every interval, set segments at 1
        }
    }
    print(field,L);
    // we assume it's all painted
    int start = -1; int end = -1; 
    bool painted = true;
    for (int i = 0; i < L; i++) {
        if (field[i] == 0 && painted) {
            //if a segment is not painted
            start = i; //remember the start
            painted = false; //switch the "painted" assumption to false
            cout << i << " "; //print the known start
        }
        if (field[i] == 1 && !painted)  {
            //if after finding a not painted segment we find one that is 
            end = i; //remember where the non painted segment ends
            painted = true; //switch the sequence the painted
            cout << i << endl; //remember the end of the non painted segment
        }
    }
    if (!painted && start != -1) {
        //if the field ends without finding an end to an unpainted segment, then it's the end of the field
        cout << L << endl; //print the field length (last segment)
    }
    print(field,L);
    if (start == -1 && end == -1) {
        //if we get through the field without finding any unpainted segment, it's all painted !
       cout << "All painted" << endl;
    }
}
