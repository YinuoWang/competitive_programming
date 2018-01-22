#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <climits>
#include <string.h>

using namespace std;

struct coord {
	int x, y, dist;
	coord(int a, int b, int c) {
		x = a, y = b, dist = c;
	}
};

char diagram[1001][1001];
bool vis[1001][1001], teleports[1001][1001];
queue<coord>q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int rows, columns;
	cin >> rows >> columns;
	int startx, starty, endX, endY, endDist, telDist = INT_MAX;
	cin >> starty >> startx;
	q.push(coord(startx, starty, 0));
	cin >> endY >> endX;

	memset(vis, false, sizeof(vis));
	vis[startx][starty] = true;

	for (int i = 0; i<rows; ++i) {
		string line;
		cin >> line;
		for (int k = 0; k<columns; ++k) {
			diagram[k][i] = line[k];
		}
	}

	int telN;
	cin >> telN;
	for (int i = 0; i<telN; ++i) {
		int telx, tely;
		cin >> tely >> telx;
		teleports[telx][tely] = true;
	}

	int navX[4] = { 0,0,1,-1 };
	int navY[4] = { 1,-1,0,0 };

	while (q.empty() == false) {
		int currentX = q.front().x;
		int currentY = q.front().y;
		int currentDist = q.front().dist;
		q.pop();
		if (currentX == endX && currentY == endY) {
			endDist = currentDist;
			break;
		}
		if (teleports[currentX][currentY] == true) {
			telDist = min(telDist, currentDist);
		}
		for (int i = 0; i<4; ++i) {
			int cx = currentX + navX[i], cy = currentY + navY[i];
			if (cx < 0 || cx >= columns || cy <0 || cy >= rows) {
				continue;
			}
			if (diagram[cx][cy] == 'X' || vis[cx][cy] == true) {
				continue;
			}
			q.push(coord(cx, cy, currentDist + 1));
			vis[cx][cy] = true;
		}
	}
	if (telDist >= endDist) {
		cout << 0 << endl;
	}
	else {
		cout << endDist - telDist << endl;
	}
	return 0;
}