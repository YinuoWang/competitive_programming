#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int flooring, x, y, counting;
int navx[4] = { 1,-1,0,0 };
int navy[4] = { 0,0,-1,1 };
bool vis[26][26];
char map[26][26];
vector<pair<int, int>> adj[26][26];
vector<int> areas;

void dfs(int sx, int sy) {
	vis[sx][sy] = true;
	counting++;
	for (int i = 0; i<adj[sx][sy].size(); ++i) {
		int ix = adj[sx][sy][i].first, iy = adj[sx][sy][i].second;
		if (vis[ix][iy] == false) {
			vis[ix][iy] = true;
			dfs(ix, iy);
		}
	}
}

int main() {
	memset(vis, false, sizeof(vis));
	cin >> flooring >> y >> x;
	for (int k = 0; k<y; ++k) {
		string line;
		cin >> line;
		for (int i = 0; i<x; ++i) {
			map[i][k] = line[i];
		}
	}
	for (int i = 0; i<x; ++i) {
		for (int k = 0; k<y; ++k) {
			if (map[i][k] == '.') {
				for (int p = 0; p<4; ++p) {
					int px = i + navx[p], py = k + navy[p];
					if (px<0 || px >= x || py<0 || py >= y) {
						continue;
					}
					if (map[px][py] != '.') {
						continue;
					}
					adj[i][k].push_back(make_pair(px, py));
					adj[px][py].push_back(make_pair(i, k));
				}
			}
		}
	}
	for (int i = 0; i<x; ++i) {
		for (int k = 0; k<y; ++k) {
			if (vis[i][k] == false && map[i][k]=='.') {
				dfs(i, k);
				areas.push_back(counting);
				counting = 0;
			}
		}
	}
	sort(areas.begin(), areas.end());
	reverse(areas.begin(), areas.end());
	int rooms = 0;
	for (auto it = areas.begin(); it != areas.end(); ++it) {
		if (flooring - *it<0) {
			break;
		}
		rooms++;
		flooring -= *it;
	}
	if (rooms == 1) {
		cout << rooms << " room, " << flooring << " square metre(s) left over" << endl;
	}
	else {
		cout << rooms << " rooms, " << flooring << " square metre(s) left over" << endl;
	}
	return 0;
}