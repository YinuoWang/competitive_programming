#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    vector<long long>ans_list;
    scanf("%d", &cases);

    for (int c = 0; c < cases; ++c){
        int n, m;
        scanf("%d %d", &n, &m);
        vector<int>arr_k(n);
        for (int i = 0; i < n; ++i){
            int cur;
            scanf("%d", &cur);
            arr_k[i] = cur;
        }
        vector<long long>costs(m);
        for (int j = 0; j < m; ++j){
            long long cur_input;
            scanf("%lld", &cur_input);
            costs[j] = cur_input;
        }
        sort(arr_k.begin(), arr_k.end());
        reverse(arr_k.begin(), arr_k.end());
        int arr_k_i = 0; 
        int costs_i = 0;
        long long ans = 0;
        while (arr_k_i < arr_k.size()){
            if (costs_i < costs.size() && costs[costs_i] < costs[arr_k[arr_k_i]-1]){
                ans += costs[costs_i];
                costs_i += 1;
            }
            else {
                ans += costs[arr_k[arr_k_i]-1];
            }
            arr_k_i += 1;
        }
        ans_list.push_back(ans);
    }
    for (auto val : ans_list){
        printf("%lld\n", val);
    }
    return 0;
}