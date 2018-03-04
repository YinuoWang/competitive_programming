#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int main() {
	for (int testCases = 0; testCases<10; ++testCases) {
		int N;
		vector<string>names;
		cin >> N;
		for (int i = 0; i<N; ++i) {
			string inputName;
			cin >> inputName;
			names.push_back(inputName);
		}
		int finalAns = INT_MAX;
		for (auto it = names.begin(); it!=names.end(); ++it) {
			string hold = *it;
			*it = "";
			pair<string, int> arrPos[1001];
			bool flag = true;
			for (int i = 0; i < N; i++) {
				if (names[i] == "") {
					flag = false;
					continue;
				}
				if (flag) {
					arrPos[i].first = names[i];
					arrPos[i].second = i;
				}
				else {
					arrPos[i-1].first = names[i];
					arrPos[i-1].second = i-1;
				}
			}
			sort(arrPos, arrPos + N-1);
			vector<bool> vis(N-1, false);
			int ans = 0;
			for (int i = 0; i < N-1; i++) {
				if (vis[i] || arrPos[i].second == i) {
					continue;
				}
				int cycle_size = 0;
				int j = i;
				while (!vis[j]) {
					vis[j] = true;
					j = arrPos[j].second;
					cycle_size++;
				}
				ans += (cycle_size - 1);
			}
			*it = hold;
			finalAns = min(ans, finalAns);
		}
		cout << finalAns << endl;
	}
	return 0;
}