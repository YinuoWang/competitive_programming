#include <iostream>
#include <algorithm>

using namespace std;

int arrayA[1000], arrayB[1000], dp[1001][1001];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i){
        cin >> arrayA[i];
    }
    for (int i=0; i<m; ++i){
        cin >> arrayB[i];
    }
    for (int i=0; i<=n; ++i){
        for (int k=0; k<=m; ++k){
            if (i==0 || k==0){
                dp[i][k]=0;
            }
            else if (arrayA[i-1]==arrayB[k-1]){
                dp[i][k]=dp[i-1][k-1] + 1;
            }
            else{
                dp[i][k]=max(dp[i-1][k],dp[i][k-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}