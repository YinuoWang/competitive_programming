#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>


using namespace std;

int dp[6][3001];
vector<pair<int, int>> comp[6];

int main() {
	int t, n;
	cin >> t >> n;
	for (int i = 0, a, b, c; i<n; ++i) {
		cin >> a >> b >> c;
		comp[c].push_back(make_pair(a, b));
	}
	for (int i = 1; i <= t; ++i) {
		sort(comp[i].begin(), comp[i].end());
	}
	int budget;
	cin >> budget;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= budget; j++) {
			dp[i][j] = dp[i][j - 1];
			for (int k = 0; k < comp[i].size(); k++) {
				if (comp[i][k].first <= j) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - comp[i][k].first] + comp[i][k].second);
				}
			}
		}
	}
	if (dp[t][budget] != 0) {
		cout << dp[t][budget] << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}