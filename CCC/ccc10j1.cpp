#include <iostream>

using namespace std;

int main(){
    int n, count=0;
    cin >> n;
    for (int a=0; a<=5; ++a){
        for (int b=1; b<=5; ++b){
            if (b>=a){
                if (a+b==n){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}