#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, m, diff = -1, answer;
bool isPalindrome(int n){
    string numString = to_string(n);
    int lengthy = numString.length();
    for (int i=0; i<lengthy/2; ++i){
        if (numString[i]!=numString[lengthy-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i=n; i<=m; ++i){
        if (isPalindrome(i)){
            if (diff<=min(abs(n-i), (m-i))){
                diff = min(abs(n-i), (m-i));
                answer = i;
            }
            else{
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}