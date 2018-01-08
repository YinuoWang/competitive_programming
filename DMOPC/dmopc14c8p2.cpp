#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, input, prev;
	string output = "";
	vector<int> nums;
	cin >> n;
	for (int i = 0; i<n; ++i) {
		cin >> input;
		nums.push_back(input);
	}
	auto min = min_element(nums.begin(), nums.end());
	auto max = max_element(nums.begin(), nums.end());
	if (min>max) {
		output = "unknown";
	}
	else {
		prev = *min;
		for (auto it = min + 1; it<max; ++it) {
			if (*it<prev) {
				output = "unknown";
			}
			prev = *it;
		}
	}
	if (output == "") {
		output = to_string(*max - *min);
	}
	cout << output << endl;
	return 0;
}
