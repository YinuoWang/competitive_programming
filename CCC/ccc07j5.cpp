#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    vector<int>motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for (int i=0; i<n; ++i){
        int input;
        cin >> input;
        motels.push_back(input);
    }
    sort(motels.begin(), motels.end());
    int dp[motels.size()];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i=0; i<motels.size(); ++i){
        int count = i+1;
        while(true){
            if (motels[count]>motels[i]+b){
                break;
            }
            else if (motels[count]>=motels[i]+a){
                dp[count]+=dp[i];
            }
            count++;
        }
    }
    cout << dp[motels.size()-1] << endl;
    return 0;
}