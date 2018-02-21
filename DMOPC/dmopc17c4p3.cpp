#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <climits>
#include <utility>

using namespace std;

long long levels[100001], longest, secondLongest;
int n;
bool vis[100001];
vector<pair<int, int>>adj[100001];

void bfs(int src) {
	memset(vis, false, sizeof(vis));
	memset(levels, -1, sizeof(levels));
	queue<int> q;
	vis[src] = true;
	levels[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
			if (vis[(*it).first] == false) {
				vis[(*it).first] = true;
				q.push((*it).first);
				levels[(*it).first] = levels[u] + (*it).second;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0, a, b, c; i<n - 1; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	bfs(1);
	long long maxDist = -1, maxIndex, prevIndex;
	for (int i = 2; i<=n; ++i) {
		if (levels[i]>maxDist) {
			maxDist = levels[i];
			maxIndex = i;
		}
	}
	bfs(maxIndex);
	prevIndex = maxIndex;
	longest = -1, secondLongest = -1;
	for (int i = 1; i <= n; ++i) {
		if (levels[i] >= longest) {
			secondLongest = longest;
			longest = levels[i];
			maxIndex = i;
		}
		else if (levels[i]>secondLongest) {
			secondLongest = levels[i];
		}
	}
	bfs(maxIndex);
	for (int i = 1; i <= n; ++i) {
		if (levels[i] >= longest && i!=prevIndex) {
			secondLongest = longest;
			longest = levels[i];
			maxIndex = i;
		}
		else if (levels[i]>secondLongest && i!=prevIndex) {
			secondLongest = levels[i];
		}
	}
	printf("%lli", secondLongest);
	return 0;
}