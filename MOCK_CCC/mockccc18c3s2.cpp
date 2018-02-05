#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int>finalMedians;
	cin >> n;
	for (int i = 0; i<n; ++i) {
		vector<int>tempMedians;
		for (int k = 0, input; k<n; ++k) {
			cin >> input;
			tempMedians.push_back(input);
		}
		sort(tempMedians.begin(), tempMedians.end());
		finalMedians.push_back(tempMedians[tempMedians.size() / 2]);
	}
	sort(finalMedians.begin(), finalMedians.end());
	cout << finalMedians[finalMedians.size() / 2] << endl;
	return 0;
}