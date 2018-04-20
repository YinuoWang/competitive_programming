#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int potatoesLeft[200001], dArray[200002];

void update(int left, int right) {
	dArray[left - 1] -= 1;
	dArray[right] += 1;
}

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		potatoesLeft[i] = m;
	}

	dArray[0] = potatoesLeft[0], dArray[n] = 0;
	for (int i = 1; i<n; ++i) {
		dArray[i] = potatoesLeft[i] - potatoesLeft[i-1];
	}

	for (int i = 0, l, r; i<m; ++i) {
		cin >> l >> r;
		update(l, r);
	}

	potatoesLeft[0] = dArray[0];
	for (int i = 1; i<n; ++i) {
		potatoesLeft[i] = dArray[i] + potatoesLeft[i - 1];
	}

	int minW = n + 1, leftP = 0, rightP = 0;
	long long currentSum = potatoesLeft[0];
	bool passFlag = false;
	while (leftP<n && rightP<n) {
		if (currentSum >= k) {
			passFlag = true;
			minW = min(minW, rightP - leftP + 1);
			if (leftP == rightP) {
				rightP++;
				if (rightP < n) {
					currentSum += potatoesLeft[rightP];
				}
			}
			else {
				currentSum -= potatoesLeft[leftP];
				leftP++;
			}
		}
		else {
			rightP++;
			if (rightP < n) {
				currentSum += potatoesLeft[rightP];
			}
		}
	}
    
	if (k == 0) {
		cout << 0 << endl;
	}
	else if (!passFlag) {
		cout << -1 << endl;
	}
	else {
		cout << minW << endl;
	}
	return 0;
}