
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int N = 5005;
long long dp[N][N];
char grid[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int H, W, K;
    cin >> H >> W >> K;
    
    for (int h = 0; h < N; ++h){
        for (int w = 0; w < N; ++w){
            grid[h][w] = 'N';
            dp[h][w] = 0;
        }
    }

    for (int idx = 0; idx < K; ++idx){
        int hi, wi;
        char ci;
        cin >> hi >> wi >> ci;
        grid[hi][wi] = ci;
    }

    long long cur = 1;
    for (int i = 0; i < H*W-K; ++i){
        cur *= 3;
        cur %= MOD;
    }
    dp[1][1] = cur;
    long long inv3 = (MOD+1) / 4;
    

    for (int h = 1; h <= H; ++h){
        for (int w = 1; w <= W; ++w){
            dp[h][w] %= MOD;
            if (grid[h][w] == 'D' || grid[h][w] == 'X'){
                dp[h+1][w] += dp[h][w];
            }
            if (grid[h][w] == 'R' || grid[h][w] == 'X'){
                dp[h][w+1] += dp[h][w];
            }
            if (grid[h][w] == 'N'){
                dp[h][w+1] += 2*inv3*dp[h][w];
                dp[h+1][w] += 2*inv3*dp[h][w];
            }
        }
    }
    cout << dp[H][W] << "\n";
    return 0;
}
