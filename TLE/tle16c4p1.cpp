#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long n, input, count=0, sum=0;
    vector<long long>presents;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> input;
        presents.push_back(input);
    }
    sort(presents.begin(), presents.end());
    for (vector<long long>::iterator it = presents.begin(); it!=presents.end(); ++it){
        if (*it>=sum){
            count++;
            sum+=*it;
        }
    }
    cout << count << endl;
    return 0;
}