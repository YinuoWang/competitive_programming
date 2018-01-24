#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

long long n, m;

vector<long long> bigger[1000001];
bool vis[1000001];

bool isBigger(long long a, long long b){
    queue<long long>bfs;
    memset(vis, false, sizeof(vis));
    bfs.push(a);
    while(!bfs.empty()){
        long long k = bfs.front();
        vis[k] = true;
        bfs.pop();
        for (long long i=0; i<bigger[k].size(); ++i){
            if (vis[bigger[k][i]]==false){
                vis[bigger[k][i]] = true;
                bfs.push(bigger[k][i]);
            }
        }
        if (vis[b]==true){
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%lli%lli",&n, &m);
    for (int i=0; i<m; ++i){
        long long x,y;
        scanf("%lli%lli",&x, &y);
        bigger[x].push_back(y);
    }
    long long p,q;
    scanf("%lli%lli", &p, &q);

    if (isBigger(p,q)){
        printf("%s\n", "yes");
    }
    else if (isBigger(q,p)){
       printf("%s\n", "no"); 
    }
    else{
        printf("%s\n", "unknown");
    }
    return 0;
}