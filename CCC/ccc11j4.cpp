#include <iostream>
#include <utility>
#include <string.h>

using namespace std;

pair<int, int> grid[401][200];
bool vis[401][200];

int main() {
	int x = 0, y = 0;
	for (int a = -200; a <= 199; ++a) {
		x++;
		for (int i = -1; i >= -200; --i) {
			grid[x][y] = make_pair(a, i);
			y++;
		}
		y = 0;
	}
	memset(vis, false, sizeof(vis));
	vis[201][0] = true;
	vis[201][1] = true;
	vis[201][2] = true;
	vis[202][2] = true;
	vis[203][2] = true;
	vis[204][2] = true;
	vis[204][3] = true;
	vis[204][4] = true;
	vis[205][4] = true;
	vis[206][4] = true;
	vis[206][3] = true;
	vis[206][2] = true;
	vis[207][2] = true;
	vis[208][2] = true;
	vis[208][3] = true;
	vis[208][4] = true;
	vis[208][5] = true;
	vis[208][6] = true;
	vis[207][6] = true;
	vis[206][6] = true;
	vis[205][6] = true;
	vis[204][6] = true;
	vis[203][6] = true;
	vis[202][6] = true;
	vis[201][6] = true;
	vis[200][6] = true;
	vis[200][5] = true;
	vis[200][4] = true;

	x = 200, y = 4;
	while (true) {
		char direction;
		int unit;
		bool isSafe = true;
		cin >> direction >> unit;
		if (direction == 'q') {
			break;
		}
		else if (direction == 'r') {
			for (int i = 0; i<unit; ++i) {
				++x;
				if (vis[x][y] == true) {
					isSafe = false;
				}
				vis[x][y] = true;
			}
		}
		else if (direction == 'l') {
			for (int i = 0; i<unit; ++i) {
				--x;
				if (vis[x][y] == true) {
					isSafe = false;
				}
				vis[x][y] = true;
			}
		}
		else if (direction == 'u') {
			for (int i = 0; i<unit; ++i) {
				--y;
				if (vis[x][y] == true) {
					isSafe = false;
				}
				vis[x][y] = true;
			}
		}
		else if (direction == 'd') {
			for (int i = 0; i<unit; ++i) {
				++y;
				if (vis[x][y] == true) {
					isSafe = false;
				}
				vis[x][y] = true;
			}
		}
		if (isSafe) {
			cout << grid[x][y].first << ' ' << grid[x][y].second << ' ' << "safe" << endl;
		}
		else {
			cout << grid[x][y].first << ' ' << grid[x][y].second << ' ' << "DANGER" << endl;
			break;
		}
	}
	return 0;
}
