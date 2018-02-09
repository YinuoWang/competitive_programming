#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <utility>
#include <string.h>
#include <climits>

using namespace std;

int n, m, baller1, baller2, start1, start2;
vector<int>graph1[3001], graph2[3001], levels1(3001), levels2(3001);
tuple<int, int, int>team1[3001], team2[3001];

double distance(int x1, int x2, int y1, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void bfs(int src, vector<int>*graph, vector<int>& levels) {
	bool vis[3001];
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < levels.size(); ++i) {
		levels[i] = INT_MAX;
	}
	queue<int> q;
	vis[src] = true;
	levels[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
			if (vis[*it] == false) {
				vis[*it] = true;
				q.push(*it);
				levels[*it] = levels[u] + 1;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int maxY = -1;
	for (int i = 0, x, y, r; i<n; ++i) {
		scanf("%d%d%d", &x, &y, &r);
		if (r == 9001) {
			baller1 = i;
		}
		if (maxY < y) {
			maxY = y;
			start1 = i;
		}
		team1[i] = make_tuple(x, y, r);
	}
	maxY = -1;
	for (int i = 0, x, y, r; i<m; ++i) {
		scanf("%d%d%d", &x, &y, &r);
		if (r == 9001) {
			baller2 = i;
		}
		if (maxY < y) {
			start2 = i;
			maxY = y;
		}
		team2[i] = make_tuple(x, y, r);
	}
	for (int a = 0; a<n; ++a) {
		for (int b = 0; b<n; ++b) {
			if (a == b) {
				continue;
			}
			if (distance(get<0>(team1[a]), get<0>(team1[b]), get<1>(team1[a]), get<1>(team1[b])) <= get<2>(team1[a])) {
				graph1[a].push_back(b);
			}
		}
	}
	for (int a = 0; a<m; ++a) {
		for (int b = 0; b<m; ++b) {
			if (a == b) {
				continue;
			}
			if (distance(get<0>(team2[a]), get<0>(team2[b]), get<1>(team2[a]), get<1>(team2[b])) <= get<2>(team2[a])) {
				graph2[a].push_back(b);
			}
		}
	}
	bfs(start1, graph1, levels1);
	bfs(start2, graph2, levels2);
	if (levels1[baller1]<levels2[baller2]) {
		printf("%s\n", "We are the champions!");
	}
	else if (levels1[baller1] == levels2[baller2]) {
		printf("%s\n", "SUDDEN DEATH");
	}
	else {
		printf("%s\n", ":'(");
	}
	return 0;
}