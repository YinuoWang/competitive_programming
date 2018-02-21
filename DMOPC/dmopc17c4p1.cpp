#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int n, q, count = 0;
	vector<pair<int, int>> ranges, finalRanges;
	scanf("%d%d", &n, &q);
	for (int i = 0, x, y; i<q; ++i) {
		scanf("%d%d", &x, &y);
		ranges.push_back(make_pair(x, y));
	}
	sort(ranges.begin(), ranges.end());
	int start = (*ranges.begin()).first, end = (*ranges.begin()).second;
	for (auto it = ranges.begin()+1; it != ranges.end(); ++it) {
		if ((*it).first>end) {
			finalRanges.push_back(make_pair(start, end));
			start = (*it).first;
			end = (*it).second;
		}
		else {
			end = max(end, (*it).second);
		}
	}
	finalRanges.push_back(make_pair(start, end));
	for (auto it = finalRanges.begin(); it != finalRanges.end(); ++it) {
		count += (*it).second - (*it).first;
	}
	cout << n - count << ' ' << count << endl;
	return 0;
}