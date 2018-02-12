#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long prefixSum[1000001], chocolates[1000001], differenceArray[1000001];

void update(int l, int r, int x) {
	differenceArray[l] += x;
	differenceArray[r + 1] -= x;
}

int main() {
	memset(differenceArray, 0, sizeof(differenceArray));
	int n, t, cups = 0;
	long long l;
	scanf("%d%d", &n, &t);
	for (int i = 0, a, b, c; i<t; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		update(a, b, c);
	}

	for (int i = 1; i<1000001; ++i) {
		chocolates[i] = differenceArray[i] + chocolates[i - 1];
	}
	scanf("%lli", &l);
	prefixSum[0] = 0;
	for (int i = 1; i <= 1000000; ++i) {
		prefixSum[i] = prefixSum[i - 1] + chocolates[i];
	}
	int left = 1;
	for (int right = 1; right <= n;) {
		if (prefixSum[right] - prefixSum[left - 1] <= l) {
			cups = max(cups, right - left + 1);
			right++;
		}
		else {
			if (left == right) {
				right++;
			}
			left++;
		}
	}
	printf("%d", cups);
	return 0;
}