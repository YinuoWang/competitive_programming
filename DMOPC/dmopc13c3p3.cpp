#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

bool vis[1501][1501];
int grid[1501][1501], navX[4] = { 0,0,1,-1 }, navY[4] = { 1,-1,0,0 }, n, h;

void dfs(int iX, int iY) {
	vis[iX][iY] = true;
	for (int i = 0; i < 4; ++i) {
		int destX = iX + navX[i], destY = iY + navY[i];
		if (destX > 0 && destY > 0 && destX <= n && destY <= n) {
			if (abs(grid[iX][iY] - grid[destX][destY]) <= h && !vis[destX][destY]) {
				dfs(iX + navX[i], iY + navY[i]);
			}
		}
	}
	return;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	memset(vis, false, sizeof(vis));
	cin >> n >> h;
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			cin >> grid[i][k];
		}
	}
	dfs(1, 1);
	if (vis[n][n]) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}