#include <iostream>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

long long prefixSum[1000001];
set<int>indices[2002];

bool valid(int x, int y, long long input) {
	if (input < 0) {
		input = -input + 1000;
	}
	auto lowerBoundIt = indices[input].lower_bound(x);
	if (lowerBoundIt != indices[input].end() && *lowerBoundIt <= y) {
		return true;
	}
	return false;
}

int main() {
	int n, q;
	long long k;
	scanf("%d%lli%d", &n, &k, &q);
	prefixSum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int input;
		scanf("%d", &input);
		prefixSum[i] = input + prefixSum[i - 1];
		if (input < 0) {
			indices[-input + 1000].insert(i);
		}
		else {
			indices[input].insert(i);
		}
	}
	for (int i = 0, x, y, a, b; i<q; ++i) {
		scanf("%d%d%d%d", &a, &b, &x, &y);	
		if (prefixSum[y] - prefixSum[x - 1]>k && valid(x, y, a) && valid(x, y, b)) {
			printf("%s\n", "Yes");
		}
		else {
			printf("%s\n", "No");
		}
	}
	return 0;
}