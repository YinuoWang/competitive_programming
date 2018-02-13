#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, k, answer = 0;
	vector<long long> nums;
	scanf("%lli%lli", &n, &k);
	for (long long i = 0, input; i<k; ++i) {
		scanf("%lli", &input);
		nums.push_back(input);
	}
	for (long long i = 0; i<k - 2; ++i) {
		long long remainingNums = n - nums[i + 2] + 1;
		long long backNums;
		if (i == 0) {
			backNums = nums[i];
		}
		else {
			backNums = nums[i] - nums[i - 1];
		}
		answer += remainingNums * backNums;
	}
	cout << answer << endl;
	return 0;
}