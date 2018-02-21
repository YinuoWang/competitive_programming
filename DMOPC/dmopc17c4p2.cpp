#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

vector<int>traversed, temp;
vector<int> adj[1001];
int nodes[1001], n, q;
bool vis[1001];

void traverse(int src, int dest, vector<int>tempVec) {
	tempVec.push_back(src);
	vis[src] = true;
	if (src == dest) {
		for (auto it = tempVec.begin(); it != tempVec.end(); ++it) {
			traversed.push_back(*it);
		}
	}
	else {
		for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
			if (vis[*it] == false) {
				traverse(*it, dest, tempVec);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1, input; i <= n; ++i) {
		scanf("%d", &input);
		nodes[i] = input;
	}
	for (int i = 1, a, b; i<n; ++i) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0, a, b, c; i<q; ++i) {
		memset(vis, false, sizeof(vis));
		traversed.clear();
		scanf("%d%d%d", &a, &b, &c);
		traverse(b, c, temp);
		if (a == 1) {
			double average = 0, tSize = traversed.size();
			for (auto it = traversed.begin(); it != traversed.end(); ++it) {
				average += nodes[*it];
			}
			long long answer = round(average / tSize);
			printf("%lli\n", answer);
		}
		else if (a == 2) {
			vector<double>medianVec;
			for (auto it = traversed.begin(); it != traversed.end(); ++it) {
				medianVec.push_back(nodes[*it]);
			}
			sort(medianVec.begin(), medianVec.end());
			int theSize = medianVec.size(), answer;
			if (theSize % 2 == 1) {
				answer = medianVec[theSize / 2];
			}
			else {
				answer = round((medianVec[theSize / 2] + medianVec[(theSize / 2) - 1]) / 2);
			}
			printf("%d\n", answer);
		}
		else {
			int frequency[100001], maxCount = 0, maxIndex;
			memset(frequency, 0, sizeof(frequency));
			for (auto it = traversed.begin(); it != traversed.end(); ++it) {
				frequency[nodes[*it]]++;
				if (frequency[nodes[*it]]>maxCount) {
					maxCount++;
					maxIndex = nodes[*it];
				}
				else if (frequency[nodes[*it]] == maxCount) {
					maxIndex = min(maxIndex, nodes[*it]);
				}
			}
			printf("%d\n", maxIndex);
		}
	}
	return 0;
}
