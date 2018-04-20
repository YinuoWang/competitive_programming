#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int r, c, h, v, testCases;
char grid[10][10];

bool check(int cCut, int rCut) {
	vector<pair<int, int>> corners;
	corners.push_back({ 0,0 });
	corners.push_back({ cCut-1, rCut-1 });
	corners.push_back({ cCut, 0 });
	corners.push_back({ c - 1, rCut - 1 });
	corners.push_back({ 0, rCut });
	corners.push_back({ cCut - 1, r - 1 });
	corners.push_back({ cCut, rCut });
	corners.push_back({ c - 1, r - 1 });
	int chocoCountCheck;
	for (int i = 0; i<8; i += 2) {
		int currentCount = 0;
		for (int x = corners[i].first; x <= corners[i + 1].first; ++x) {
			for (int y = corners[i].second; y <= corners[i + 1].second; ++y) {
				if (grid[x][y] == '@') {
					currentCount++;
				}
			}
		}
		if (i == 0) {
			chocoCountCheck = currentCount;
		}
		else {
			if (currentCount != chocoCountCheck) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		cin >> r >> c >> h >> v;
		for (int i = 0; i < r; ++i) {
			string line;
			cin >> line;
			for (int k = 0; k < c; ++k) {
				grid[k][i] = line[k];
			}
		}
		cout << "Case #" << t << ": ";
		bool flag = false;
		for (int i = 1; i<r; ++i) {
			for (int k = 1; k<c; ++k) {
				if (check(k, i)) {
					cout << "POSSIBLE" << endl;
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}