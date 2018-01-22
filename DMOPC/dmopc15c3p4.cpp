#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

int nodes;
long long dist[3001];
bool vis[3001];
vector<pair<long long, long long>> coords;
long long weights[3001][3001];

int minDistance(){
    long long minValue = LLONG_MAX;
    int min_index;
    for (int i=1; i<=nodes; ++i){
        if (vis[i]==false && dist[i]<=minValue){
            minValue = dist[i];
            min_index =i;
        }
    }
    return min_index;
}

void dijkstra(int src){
    for (int i=1; i<=nodes; ++i){
        dist[i] = LLONG_MAX;
        vis[i] = false;
    }
    dist[src]=0;
    for (int i=1; i<=nodes-1; ++i){
        int u = minDistance();
        vis[u]=true;
        for (int k=1; k<=nodes; ++k){
            if (vis[k]==false && dist[u]+weights[u][k]<dist[k]){
                dist[k]= dist[u]+weights[u][k];
            }
        }
    }
}

int main(){
    scanf("%d", &nodes);
    for (int i=0; i<nodes; ++i){
        long long x,y;
        scanf("%lli%lli",&x,&y);
        coords.push_back(make_pair(x,y));
    }
    for (int i=0; i<coords.size(); ++i){
        for (int k=i; k<coords.size(); ++k){
            weights[i+1][k+1]=pow(coords[i].first-coords[k].first,2) + pow(coords[i].second-coords[k].second,2);
            weights[k+1][i+1]=pow(coords[i].first-coords[k].first,2) + pow(coords[i].second-coords[k].second,2);

        }
    }
    int start;
    scanf("%d",&start);
    dijkstra(start);
    vector<long long> sortedVec;
    for (int i=1; i<=nodes; ++i){
        sortedVec.push_back(dist[i]);
    }
    sort(sortedVec.begin(), sortedVec.end());
    long long q;
    scanf("%lli", &q);
    while(q--){
        long long query;
        scanf("%lli", &query);
        printf("%d\n", upper_bound(sortedVec.begin(), sortedVec.end(), query)-sortedVec.begin());
    }
    return 0;
}
