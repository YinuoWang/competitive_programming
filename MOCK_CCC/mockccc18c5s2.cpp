#include <iostream>
#include <vector>

using namespace std;

int main() {
	int carolCount = 0, n;
	vector<int> nums;
	cin >> n;
	for (int i = 0, input; i<n; ++i) {
		cin >> input;
		nums.push_back(input);
	}
	for (int i = 0; i<n; ++i) {
		for (int k = 0; k<n - i - 1; ++k) {
			if (nums[k]<nums[k + 1]) {
				int temp = nums[k];
				nums[k] = nums[k + 1];
				nums[k + 1] = temp;
				carolCount++;
			}
		}
	}
	cout << carolCount;
	return 0;
}