#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 5005;
ll end_arr[N][N], val_arr[N], total_arr[N], n, k, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> q;

    for (int i = 0; i < n; ++i){
        end_arr[0][i] = 1;
        total_arr[i] = 0;
        cin >> val_arr[i];
    }
    for (int i = 1; i <= k; ++i){
        for (int j = 0; j < n; ++j){
            ll add1 = 0;
            ll add2 = 0;
            if (j > 0){
                add1 = end_arr[i-1][j-1];
            }
            if (j < n - 1){
                add2 = end_arr[i-1][j+1];
            }
            end_arr[i][j] = (add1+add2) % MOD;
        }
    }

    ll cur_ans = 0;
    for (int i = 0; i <= k; ++i){
        for (int j = 0; j < n; ++j){
            total_arr[j] += (end_arr[i][j] * end_arr[k-i][j]);
            total_arr[j] %= MOD;
        }
    }
    for (int j = 0; j < n; ++j){
        cur_ans += val_arr[j] * total_arr[j];
        cur_ans %= MOD;
    }

    vector<ll> ans_list;
    while (q--){
        ll index, new_val;
        cin >> index >> new_val;
        index -= 1;
        cur_ans -= (val_arr[index] * total_arr[index]) % MOD;
        cur_ans %= MOD;
        val_arr[index] = new_val;
        cur_ans += (val_arr[index] * total_arr[index]) % MOD;
        cur_ans += MOD;
        cur_ans %= MOD;
        ans_list.push_back(cur_ans);
    }
    for (auto val : ans_list){
        cout << val << endl;
    }
}