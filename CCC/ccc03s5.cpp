#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <functional>
#include <algorithm>

using namespace std;

vector<pair<int, int>>adj[10001];
int minWeight[10001];

void prims() {
	priority_queue <pair<int,int>> pq;
	memset(minWeight, 0, sizeof(minWeight));
	pq.push(make_pair(1000000000, 1));
	minWeight[1] = 10000000;
	while (!pq.empty()) {
		pair<int, int> u = pq.top();
		pq.pop();
		if (u.first < minWeight[u.second]) {
			continue;
		}
		for (auto it = adj[u.second].begin(); it != adj[u.second].end(); ++it) {
			int w = min(minWeight[u.second], (*it).first);
			if (minWeight[(*it).second] < w) {
				minWeight[(*it).second] = w;
				pq.push(make_pair(w, (*it).second));
			}
		}
	}
}

int main() {
	int c, r, d;
	scanf("%d%d%d", &c, &r, &d);
	for (int i = 0, x, y, w; i<r; ++i) {
		scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back(make_pair(w, y));
		adj[y].push_back(make_pair(w, x));
	}
	prims();
	int answer = 100000000;
	for (int i = 0, input; i<d; ++i) {
		scanf("%d", &input);
		answer = min(answer, minWeight[input]);
	}
	printf("%d", answer);
	return 0;
}