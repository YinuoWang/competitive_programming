#include <iostream>
#include <vector>

using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	for (int k=1; k<=testCases; ++k) {
		int n;
		cin >> n;
		vector<long long>listNums;
		for (int i = 0; i < n; ++i) {
			long long inputNum;
			cin >> inputNum;
			listNums.push_back(inputNum);
		}
		bool flag = false;
		while (!flag) {
			flag = true;
			for (int i = 0; i < n - 2; ++i) {
				if (listNums[i] > listNums[i + 2]) {
					flag = false;
					long long temp = listNums[i];
					listNums[i] = listNums[i + 2];
					listNums[i + 2] = temp;
				}
			}
		}
		bool ok = true;
		cout << "Case #" << k << ": ";
		for (int i = 0; i < n-1; ++i) {
			if (listNums[i] > listNums[i + 1]) {
				cout << i << endl;
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "OK" << endl;
		}
	}
	return 0;
}