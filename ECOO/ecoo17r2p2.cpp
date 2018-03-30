#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

int testCases = 10, xNav[4] = { 0, 0, -1, 1 }, yNav[4] = { 1, -1, 0, 0 };
char diagram[1000][1000];
bool vis[1000][1000];
queue<pair<int, int>>q;
vector<pair<int, int>>doors;

int main() {
	while (testCases--) {
		int n, keyCount = 0, treasureCount = 0;
		memset(vis, false, sizeof(vis));
		memset(diagram, 0, sizeof(diagram));
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string row;
			cin >> row;
			for (int k = 0; k < n; ++k) {
				diagram[i][k] = row[k];
				if (diagram[i][k] == 'S') {
					q.push(make_pair(i, k));
					vis[i][k] = true;
				}
			}
		}
		while (true) {
			while (!q.empty()) {
				int currX = q.front().first, currY = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int tempX = currX + xNav[i], tempY = currY + yNav[i];
					if (tempX < 0 || tempX >= n || tempY < 0 || tempY >= n || diagram[tempX][tempY] == '#') {
						continue;
					}
					else if (vis[tempX][tempY] == false) {
						bool pushQ = true;
						vis[tempX][tempY] = true;
						if (diagram[tempX][tempY] == 'T') {
							treasureCount++;
						}
						else if (diagram[tempX][tempY] == 'K') {
							keyCount++;
						}
						else if (diagram[tempX][tempY] != '.') {
							doors.push_back(make_pair(tempX, tempY));
							pushQ = false;
						}
						if (pushQ) {
							q.push(make_pair(tempX, tempY));
						}
					}
				}
			}
			bool stop = true;
			for (int k = doors.size() - 1; k >= 0; --k) {
				int doorX = doors[k].first, doorY = doors[k].second;
				if (diagram[doorX][doorY] - '0' <= keyCount) {
					diagram[doorX][doorY] = '.';
					q.push(make_pair(doorX, doorY));
					stop = false;
					doors.erase(doors.begin() + k);
				}
			}
			if (stop) {
                doors.clear();
				break;
			}
		}
		cout << treasureCount << endl;
	}
	return 0;
}