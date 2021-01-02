#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    scanf("%d", &N);
    vector<long long> ans(N+1, 0);
    vector<vector<int>>adj(N+1);
    vector<pair<int, int>>edges;
    edges.push_back(make_pair(-1,-1));

    for (int i = 1; i <= N-1; ++i){
        int a,b;
        scanf("%d %d", &a, &b);
        edges.push_back(make_pair(a,b));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    long long root_ans = 0;
    vector<unordered_map<int,long long>>filter(N+1); 
    vector<unordered_map<int,long long>>filter2(N+1); 
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i){
        int t,e,target,dest;
        long long x;
        scanf("%d %d %lld", &t, &e, &x);
        if (t == 1){
            target = edges[e].second;
            dest = edges[e].first;
        }
        else {
            target = edges[e].first;
            dest = edges[e].second;
        }

        if (filter[target].find(dest) == filter[target].end()){
            filter[target][dest] = x;
        }
        else {
            filter[target][dest] += x;
        }

        if (filter2[dest].find(target) == filter2[dest].end()){
            filter2[dest][target] = x;
        }
        else {
            filter2[dest][target] += x;
        }
        root_ans += x;
    }
    vector<pair<int, int>>stk;
    stk.push_back(make_pair(1, -1));
    while (stk.size() > 0){
        int cur = stk.back().first;
        int parent = stk.back().second;
        stk.pop_back();
        for (auto edge : adj[cur]){
            if (edge != parent){
                stk.push_back(make_pair(edge, cur));
                if (filter[cur].find(edge) != filter[cur].end()){
                    root_ans -= filter[cur][edge];
                }
            }
        }
    }
    vector<tuple<int,long long, int>> stk2;
    stk2.push_back(make_tuple(1, root_ans, -1));
    while (stk2.size() > 0){
        int cur = get<0>(stk2.back());
        int parent = get<2>(stk2.back());
        long long cur_ans = get<1>(stk2.back());
        ans[cur] = cur_ans;
        stk2.pop_back();

        for (auto edge : adj[cur]){
            if (edge != parent){
                long long new_ans = cur_ans;
                if (filter[cur].find(edge) != filter[cur].end()){
                    new_ans += filter[cur][edge];
                }
                if (filter2[cur].find(edge) != filter2[cur].end()){
                    new_ans -= filter2[cur][edge];
                }
                stk2.push_back(make_tuple(edge, new_ans, cur));
            }
        }
    }
    for (int i = 1; i < ans.size(); ++i){
        printf("%lld\n", ans[i]);
    }

    return 0;
}