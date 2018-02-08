#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool comparePairs(const pair<string, int> &a, const pair<string, int>&b) {
	return a.second>b.second;
}

int main() {
	int n, p;
	cin >> n >> p;
	vector<pair<string, int>> points;
	for (int i = 0; i<n; ++i) {
		string input;
		cin >> input;
		points.push_back(make_pair(input, 0));
	}
	for (int i = 0; i<p; ++i) {
		for (int k = 0; k<n; ++k) {
			int timeSpent;
			cin >> timeSpent;
			points[k].second += timeSpent;
		}
	}
	sort(points.begin(), points.end(), comparePairs);
	for (int i = 3; i<3 + n; ++i) {
		cout << i << ". " << points[i-3].first << endl;
    }
	return 0;
}