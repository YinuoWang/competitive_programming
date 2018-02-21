#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

int xnav[4] = { 0, 0, -1, 1 };
int ynav[4] = { 1, -1, 0, 0 };
int n, m;
char diagram[101][101];
int distances[101][101];
bool vis[101][101], noStart = false;
vector<pair<int, int>> infin;

queue<pair<int, int>>q;

pair<int, int> traverse(int x, int y) {
	if (diagram[x][y] == 'W' || diagram[x][y] == 'B' || diagram[x][y] == 'C') {
		return make_pair(-1, -1);
	}
	else if (diagram[x][y] == '.') {
		return make_pair(x, y);
	}
	else if (diagram[x][y] == 'L'&& vis[x][y] != true) {
		vis[x][y] = true;
		infin.push_back(make_pair(x, y));
		return traverse(x, y - 1);
	}
	else if (diagram[x][y] == 'R'&& vis[x][y] != true) {
		vis[x][y] = true;
		infin.push_back(make_pair(x, y));
		return traverse(x, y + 1);
	}
	else if (diagram[x][y] == 'U'&& vis[x][y] != true) {
		vis[x][y] = true;
		infin.push_back(make_pair(x, y));
		return traverse(x - 1, y);
	}
	else if (diagram[x][y] == 'D' && vis[x][y]!=true) {
		vis[x][y] = true;
		infin.push_back(make_pair(x, y));
		return traverse(x + 1, y);
	}
	else {
		return make_pair(-1, -1);
	}
}

int main() {
	memset(vis, false, sizeof(vis));
	memset(distances, -1, sizeof(distances));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string input;
		cin >> input;
		for (int k = 0; k < m; ++k) {
			diagram[i][k] = input[k];
			if (diagram[i][k] == 'S') {
				q.push(make_pair(i, k));
				distances[i][k] = 0;
				vis[i][k] = true;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < m; ++k) {
			if (diagram[i][k] == 'C') {
				for (int x = i+1; x < n-1; ++x) {
					if (diagram[x][k] == 'W') {
						break;
					}
					else if (diagram[x][k] == '.') {
						diagram[x][k] = 'B';
					}
					else if (diagram[x][k] == 'S'){
						noStart = true;
					}
				}
				for (int x = i-1; x > 0; --x) {
					if (diagram[x][k] == 'W') {
						break;
					}
					else if (diagram[x][k] == '.') {
						diagram[x][k] = 'B';
					}
					else if (diagram[x][k] == 'S') {
						noStart = true;
					}
				}
				for (int y = k+1; y < m-1; ++y) {
					if (diagram[i][y] == 'W') {
						break;
					}
					else if (diagram[i][y] == '.') {
						diagram[i][y] = 'B';
					}
					else if (diagram[i][y] == 'S') {
						noStart = true;
					}
				}
				for (int y = k-1; y > 0; --y) {
					if (diagram[i][y] == 'W') {
						break;
					}
					else if (diagram[i][y] == '.') {
						diagram[i][y] = 'B';
					}
					else if (diagram[i][y] == 'S') {
						noStart = true;
					}
				}
			}
		}
	}

	if (noStart){
		q.pop();
	}

	while (!q.empty()) {
		int currX = q.front().first, currY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int tempx = currX + xnav[i], tempy = currY + ynav[i];
			if (diagram[tempx][tempy] == 'W' || diagram[tempx][tempy] == 'B' || diagram[tempx][tempy]=='C') {
				continue;
			}
			else if (diagram[tempx][tempy] == '.') {
				if (vis[tempx][tempy] == false) {
					distances[tempx][tempy] = distances[currX][currY] + 1;
					vis[tempx][tempy] = true;
					q.push(make_pair(tempx, tempy));
				}
			}
			else if (diagram[tempx][tempy] != 'S') {
				pair<int, int> dest = traverse(tempx, tempy);
				for (vector<pair<int,int> >::iterator it = infin.begin(); it != infin.end(); ++it) {
					vis[(*it).first][(*it).second] = false;
				}
				infin.clear();
				if (dest.first == -1) {
					continue;
				}
				else if (vis[dest.first][dest.second] == true) {
					continue;
				}
				distances[dest.first][dest.second] = distances[currX][currY] + 1;
				vis[dest.first][dest.second] = true;
				q.push(make_pair(dest.first, dest.second));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < m; ++k) {
			if (diagram[i][k] == '.' || diagram[i][k] == 'B') {
				cout << distances[i][k] << endl;
			}
		}
	}
	return 0;
}