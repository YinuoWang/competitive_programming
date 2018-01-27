#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int m, output;
    double n,k,ans;
    cin >> m >> k >> n;
    ans = n*0.595;
    output = ceil(ans-k);
    if (output>m){
        cout << "have mercy snew" << endl;
    }
    else {
        if (output<0){
            cout << 0 << endl;
        }
        else{
            cout << output << endl;
        }
    }
    return 0;
}