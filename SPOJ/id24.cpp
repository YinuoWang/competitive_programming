#include <iostream>
#include <vector>

using namespace std;

int t;

int main(){
    cin >> t;
    int n;
    long long ans;
    vector<long long> output;
    for (int i=0; i<t; ++i){
        ans=1;
        cin >> n;
        for (int k=2; k<=n; ++k){
            ans*=k;
        }
        output.push_back(ans);
    }
    for (vector<long long>::iterator it=output.begin(); it!=output.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}