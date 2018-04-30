#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<long long, long long>>numbers;
	for (int i = 0; i<n; ++i) {
		long long m, b;
		cin >> m >> b;
		numbers.push_back(make_pair(m, b));
	}
	sort(numbers.begin(), numbers.end());
	pair<long long, long long> prev = *numbers.begin();
	vector<long long>slopeCounts;
	long long slopeCount = 1;
	for (auto it = numbers.begin()+1; it != numbers.end(); ++it) {
		if ((*it).first == prev.first) {
			if ((*it).second == prev.second) {
				cout << "Infinity" << endl;
				return 0;
			}
			slopeCount++;
		}
		else {
			slopeCounts.push_back(slopeCount);
			slopeCount = 1;
		}
		prev = *it;
	}
	slopeCounts.push_back(slopeCount);
	long long finalAnswer = 0, alreadyCounted = 0;
	for (auto it = slopeCounts.begin(); it != slopeCounts.end(); ++it) {
		finalAnswer += (n - *it - alreadyCounted)*(*it);
		alreadyCounted += *it;
	}
	cout << finalAnswer << endl;
	return 0;
}