#include <iostream>

using namespace std;

int main(){
    int n;
    long count=0;
    cin >> n;
    for (int a=1; a<=n-3; ++a){
        for (int b=a+1; b<=n-2; ++b){
            for (int c=b+1; c<=n-1; ++c){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}