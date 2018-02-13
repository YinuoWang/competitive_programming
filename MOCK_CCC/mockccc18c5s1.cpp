#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int nChoosek(int n, int k)
{
	if (k > n) {
		return 0;
	}
	if (k * 2 > n) {
		k = n - k;
	}
	if (k == 0) {
		return 1;
	}
	int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

int main() {
	int n, x, lCount = 0, gCount = 0, xCount = 0, ans;
	vector<int> nums;
	cin >> n >> x;
	for (int i = 0, input; i<n; ++i) {
		cin >> input;
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		if (*it < x) {
			lCount++;
		}
		else if (*it == x) {
			xCount++;
		}
		else {
			gCount++;
		}
	}
	ans = lCount * xCount * gCount + nChoosek(xCount, 2) * (lCount + gCount) + nChoosek(xCount, 3);
	cout << ans << endl;
	return 0;
}