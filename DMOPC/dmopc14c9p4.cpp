#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

vector<pair<double, int>>adj[1001];
double dist[1001];
int minEdge[1001];

void dijkstra() {
	priority_queue<pair<double, int>> pq;
	for (int i = 0; i <= 1000; ++i) {
		dist[i] = 100000000;
		minEdge[i] = 1001;
	}
	dist[1] = 0;
	minEdge[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
			double weight = (*it).first;
			int v = (*it).second;
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
				minEdge[v] = minEdge[u] + 1;
			}
			else if (dist[v]==dist[u] + weight) {
				minEdge[v] = min(minEdge[v], minEdge[u] + 1);
			}
		}
	}
}

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	for (int i = 0; i<edges; ++i) {
		int n1, n2;
		double dist, speed;
		scanf("%d%d%lf%lf", &n1, &n2, &dist, &speed);
		adj[n1].push_back(make_pair(60*dist / speed, n2));
		adj[n2].push_back(make_pair(60*dist / speed, n1));
	}
	dijkstra();
	cout << minEdge[nodes] << endl;
	cout << round(dist[nodes] / 0.75 - dist[nodes]) << endl;
	return 0;
}