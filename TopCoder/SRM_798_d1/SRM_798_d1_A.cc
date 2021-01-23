#include <bits/stdc++.h>
using namespace std;

class SuperSubset{
    public:
        int solve(vector<int> A, int Y){
            long long MOD = 1e9 + 7;
            vector<long long>d(Y+1);
            d[0] = 1;
            for (int val : A){
                vector<long long>next(Y+1);
                for (int i = 0; i <= Y; ++i){
                    next[i] = d[i]*2 % MOD;
                }
                for (int k = 0; k <= Y; ++k){
                    if (k + val <= Y){
                        next[k+val] += d[k];
                        next[k+val] %= MOD;
                    }
                }
                d = next;
            }
            return d[Y] % MOD; 
        }
};

// int main(){
//     SuperSubset t = SuperSubset();
//     vector<int>arr;
//     for (int i = 0; i < 200; ++i){
//         int num;
//         cin >> num;
//         arr.push_back(num);
//     }
//     cout << t.solve(arr, 3000) << endl;
//     return 0;
// }