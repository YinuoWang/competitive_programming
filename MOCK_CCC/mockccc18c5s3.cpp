#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[51];
bool vis[51], flag;

void dfs(int src) {
	if (src == n) {
		flag = true;
	}
	vis[src] = true;
	for (int i = 0; i<adj[src].size(); ++i) {
		if (vis[adj[src][i]] == false) {
			dfs(adj[src][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	vector<pair<int, int>> mList;
	for (int i = 0, a, b; i<m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		mList.push_back(make_pair(a, b));
	}
	for (int i = 0; i<m; ++i) {
		auto it = find(adj[mList[i].first].begin(), adj[mList[i].first].end(), mList[i].second);
		adj[mList[i].first].erase(it);
		memset(vis, false, sizeof(vis));
		flag = false;
		dfs(1);
		if (flag) {
			cout << "YES" << endl;
			flag = false;
		}
		else {
			cout << "NO" << endl;
		}
		adj[mList[i].first].push_back(mList[i].second);
	}
	return 0;
}