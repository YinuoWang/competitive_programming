#include <iostream>

using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    for (int t = 0; t<testCases; ++t){
        int a, possible, counter;
        cin >> a;
        cout << 2 << ' ' << 2 << endl;
        while(true){
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0){
                break;
            }
            cout << 2 << ' ' << 2 + counter << endl;
            counter++;
            if (counter>4){
                counter = 0;
            }
        }
    }
    return 0;
}