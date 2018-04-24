#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long nums[200001], prefixSum[200001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> nums[i];
	}
	prefixSum[1] = nums[1];
	for (int i = 2; i <= n; ++i) {
		prefixSum[i] = nums[i] + prefixSum[i - 1];
	}
	long long currentTotal = prefixSum[n];
	for (int i = 1; i <= n; ++i) {
		cout << currentTotal << endl;
		currentTotal += (prefixSum[n-i] - prefixSum[i]);
	}
	return 0;
}