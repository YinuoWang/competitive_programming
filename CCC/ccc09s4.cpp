#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
#include <string.h>

using namespace std;

int n, t, k, d, adj[5001][5001];
long long dist[5001], minPrice = LLONG_MAX;
bool vis[5001];

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int minDistance() {
	long long minValue = LLONG_MAX;
	int minIndex;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] <= minValue && vis[i] == false) {
			minValue = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void dijkstra(int src) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = LLONG_MAX;
	}
	dist[src] = 0;
	for (int i = 1; i <= n; ++i) {
		int u = minDistance();
		vis[u] = true;
		for (int k = 1; k <= n; ++k) {
			if (dist[k] > dist[u] + adj[u][k] && vis[k]==false) {
				dist[k] = dist[u] + adj[u][k];
			}
		}
	}
}

int main() {
	memset(vis, false, sizeof(vis));
	scan(n);
	scan(t);
	for (int i = 0; i <= n; ++i) {
		for (int k = 0; k <= n; ++k) {
			adj[i][k] = INT_MAX;
		}
	}
	for (int i = 0; i < t; ++i) {
		int a, b, weight;
		scan(a);
		scan(b);
		scan(weight);
		adj[a][b] = min(adj[a][b], weight);
		adj[b][a] = adj[a][b];
	}
	scan(k);
	vector<pair<int, int>>pens;
	for (int i = 0; i < k; ++i) {
		int a, price;
		scan(a);
		scan(price);
		pens.push_back(make_pair(a, price));
	}
	scan(d);
	dijkstra(d);
	for (auto it = pens.begin(); it != pens.end(); ++it) {
		minPrice = min(minPrice, dist[(*it).first] + (*it).second);
	}
	printf("%lli\n", minPrice);
	return 0;
}