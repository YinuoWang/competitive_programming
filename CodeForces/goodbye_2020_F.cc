#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;
const int MX = 1e9 + 7;

int uf[N];
int sz[N];

int find(int x){
    if (uf[x] != x){
       uf[x] = find(uf[x]);
    }
    return uf[x];
}

bool _union(int x, int y){
    int xr = find(x);
    int yr = find(y);

    if (xr == yr){
        return false;
    }
    if (sz[xr] < sz[yr]){
        xr, yr = yr, xr;
    }
    uf[yr] = xr;
    sz[xr] += sz[yr];
    return true;
}

int main(){
    int n,m;
    int ans = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m+1; ++i){
        uf[i] = i;
        sz[i] = 1;
    }
    vector<int> cur_lst;
    for (int i = 1; i <= n; ++i){
        int bit_lst_size, bit1, bit2;
        bit1 = bit2 = m+1;
        scanf("%d", &bit_lst_size);
        scanf("%d", &bit1);
        if (bit_lst_size == 2){
            scanf("%d", &bit2);
        }
        if (_union(bit1, bit2)){
            cur_lst.push_back(i);
            ans *= 2;
            ans %= MX;
        }
    }
    printf("%d %d\n", ans, cur_lst.size());
    for (auto v: cur_lst){
        printf("%d ", v);
    }
    return 0;
}