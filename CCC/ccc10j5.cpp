#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int navx[8] = {1,1,-1,-1,2,2,-2,-2};
int naxy[8] = {2,-2,2,-2,1,-1,-1,1};
vector<pair<int, int>>adj[8][8];
bool vis[8][8];
int levels[8][8];

void createGraph() {
	for (int a = 0; a<8; ++a) {
		for (int b = 0; b<8; ++b) {
			for (int c = 0; c<8; ++c) {
                int nx = a + navx[c], ny = b + naxy[c];
                if (nx<0 || nx >= 8 || ny<0 || ny >= 8) {
                    continue;
                }
                if (find(adj[a][b].begin(), adj[a][b].end(), make_pair(nx, ny)) == adj[a][b].end()) {
                    adj[a][b].push_back(make_pair(nx, ny));
                    adj[nx][ny].push_back(make_pair(a, b));
                }

			}
		}
	}
}

int main() {
	int startx, starty, endx, endy;
	createGraph();
	memset(vis, false, sizeof(vis));
	cin >> startx >> starty >> endx >> endy;
	startx--;
	starty--;
	endx--;
	endy--;
	queue<pair<int, int>> q;

	q.push(make_pair(startx, starty));
	vis[startx][starty] = true;
	levels[startx][starty] = 0;
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		for (int i = 0; i<adj[px][py].size(); ++i) {
			int ix = adj[px][py][i].first;
			int iy = adj[px][py][i].second;
			if (vis[ix][iy] == false) {
				levels[ix][iy] = levels[px][py] + 1;
				vis[ix][iy] = true;
				q.push(make_pair(ix, iy));
			}
		}
	}
	cout << levels[endx][endy] << endl;
	return 0;
}
