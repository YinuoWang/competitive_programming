#include <iostream>

using namespace std;

int main(){
    int finalAnswer=0, n;
    cin >> n;
    for (int i=0,a; i<n; ++i){
        cin >> a;
        if (a%2 == i%2){
            finalAnswer++;
        }
    }
    cout << finalAnswer << endl;
    return 0;
}