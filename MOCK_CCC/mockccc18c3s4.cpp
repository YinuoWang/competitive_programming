#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<long long>nums;
	cin >> n;
	for (int i = 0, input; i<n; ++i) {
		cin >> input;
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());
	long long sum=0, max=nums[nums.size()-1];
	for (int i = 0; i < nums.size() - 1; ++i) {
		sum += nums[i];
	}
	if ((sum+nums[n-1]) %2 == 0 && max<=sum) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}