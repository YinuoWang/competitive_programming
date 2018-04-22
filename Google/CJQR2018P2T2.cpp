#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int testCases;
	cin >> testCases;
	for (int k = 1; k <= testCases; ++k) {
		int n, evenSize;
		cin >> n;
		if (n % 2 == 1) {
			evenSize = n / 2 + 1;
		}
		else {
			evenSize = n / 2;
		}
		vector<long long>oddIndex(n / 2), evenIndex(evenSize);
		long long inputNum;
		for (int i = 0; i<n / 2; ++i) {
			cin >> inputNum;
			evenIndex[i] = inputNum;
			cin >> inputNum;
			oddIndex[i] = inputNum;
		}
		if (n % 2 == 1) {
			cin >> inputNum;
			evenIndex[n / 2] = inputNum;
		}
		sort(oddIndex.begin(), oddIndex.end());
		sort(evenIndex.begin(), evenIndex.end());
		bool ok = true;
		cout << "Case #" << k << ": ";
		if (n % 2 == 1) {
			for (int i = 0; i < (n / 2); ++i) {
				if (evenIndex[i] > oddIndex[i]) {
					cout << 2 * i << endl;
					ok = false;
					break;
				}
				if (oddIndex[i] > evenIndex[i + 1]) {
					cout << 1 + 2 * i << endl;
					ok = false;
					break;
				}
			}
		}
		else {
			bool checkFlag = true;
			for (int i = 0; i < (n / 2) - 1; ++i) {
				if (evenIndex[i] > oddIndex[i]) {
					cout << 2 * i << endl;
					checkFlag = false;
					ok = false;
					break;
				}
				if (oddIndex[i] > evenIndex[i + 1]) {
					cout << 1 + 2 * i << endl;
					checkFlag = false;
					ok = false;
					break;
				}
			}
			if (checkFlag && evenIndex[(n / 2) - 1] > oddIndex[(n / 2) - 1]) {
				ok = false;
				cout << 2 * ((n / 2) - 1) << endl;
			}
		}
		if (ok) {
			cout << "OK" << endl;
		}
	}
	return 0;
}