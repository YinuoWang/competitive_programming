#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    vector<long long>ans_list;
    scanf("%d", &cases);

    for (int i = 0; i < cases; ++i){
        int n;
        long long x;
        scanf("%d %lld", &n, &x);
        long long ans = 0;
        long long extra = 0;
        long long mult = 1;
        vector<long long>arr(n);
        for (int j = 0; j < n; ++j){
            scanf("%lld", &arr[j]);
        }
        bool success = true; 
        while (success) {
            for (int j = 0; j < n; ++j){
                ans += arr[j] * mult;
                if (arr[j] % x != 0){
                    success = false;
                }
                if (success){
                    arr[j] = arr[j] / x;
                    extra += arr[j] * mult * x;
                }
            }
            if (success) {
                extra = 0;
            }
            else {
                ans += extra;
            }
            mult *= x;
        }
        ans_list.push_back(ans);
    }
    for (auto val : ans_list){
        printf("%lld\n", val);
    }
    return 0;
}