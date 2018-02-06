#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int dp[5281];
vector<int> clubs;

int main() {
	int dist, clubCount;
	cin >> dist >> clubCount;
	for (int i = 0; i <= 5280; ++i) {
		dp[i] = INT_MAX;
	}
	for (int i = 0, input; i < clubCount; ++i) {
		cin >> input;
		dp[input] = 1;
		clubs.push_back(input);
	}
	sort(clubs.begin(), clubs.end());
	for (int i = 1; i <= dist; ++i) {
		for (int k = 0; k < clubCount && clubs[k]<i ; ++k) {
			if (dp[i - clubs[k]] != INT_MAX) {
				dp[i] = min(dp[i], dp[i - clubs[k]] + 1);
			}
		}
	}
	if (dp[dist] == INT_MAX) {
		cout << "Roberta acknowledges defeat." << endl;
	}
	else {
		cout << "Roberta wins in " << dp[dist] << " strokes." << endl;
	}
	return 0;
}
