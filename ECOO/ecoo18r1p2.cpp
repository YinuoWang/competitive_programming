#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		deque<int>nums[701];
		int n;
		cin >> n;
		int minDiam = 10000000;
		for (int i = 1, id, r; i <= n; ++i) {
			cin >> id >> r;
			nums[i].push_back(id);
			nums[i].push_back(r);
			for (int count = 0, input; count<r; ++count) {
				cin >> input;
				nums[i].push_back(input);
				minDiam = min(minDiam, input);
			}
		}
		cout << minDiam << " {";
		deque<int>myIds;
		for (int i = 1; i <= n; ++i) {
			for (int count = 2; count<nums[i][1]+2; ++count) {
				if (nums[i][count] == minDiam) {
					myIds.push_back(nums[i][0]);
					break;
				}
			}
		}
		sort(myIds.begin(), myIds.end());
		for (int i = 0; i<myIds.size() - 1; ++i) {
			cout << myIds[i] << ',';
		}
		cout << myIds[myIds.size() - 1] << '}' << endl;
	}
	return 0;
}