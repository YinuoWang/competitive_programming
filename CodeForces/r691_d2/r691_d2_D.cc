#include <bits/stdc++.h>

using namespace std;

const int MX = 10001;
int dp[101][MX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int total_water = 0;
    vector<int> a, b;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int cur_a, cur_b;
        cin >> cur_a >> cur_b;
        a.push_back(cur_a);
        b.push_back(cur_b);
        total_water += cur_b;
    }
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j < MX; ++j){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        int cur_cap = a[i-1];
        int cur_water = b[i-1];

        for (int j = i; j > 0; --j){
            for (int c = cur_cap; c < MX; ++c){
                if (dp[j-1][c-cur_cap] != -1){
                    dp[j][c] = max(dp[j][c], dp[j-1][c-cur_cap] + cur_water);
                }
            }
        }
    }
    for (int cup_count = 1; cup_count <= n; ++cup_count){
        double cur_ans = 0;
        for (int cap = 1; cap < MX; ++cap){
            if (dp[cup_count][cap] != -1){
                double extra_water = ((double)total_water - dp[cup_count][cap])/2;
                double new_ans = min((double)cap, dp[cup_count][cap] + extra_water);
                cur_ans = max(cur_ans, new_ans);
            }
        }
        cout << cur_ans;
        if (cup_count == n){
            cout << '\n';
        }
        else { 
            cout << ' ';
        }
    }
    return 0;
}