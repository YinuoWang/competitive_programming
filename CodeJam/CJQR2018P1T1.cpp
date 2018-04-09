#include <iostream>
#include <string>

using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	for (int k=1; k<=testCases; ++k) {
		string P;
		long long D, currentDmg = 0, cPos = 31;
		cin >> D >> P;
		int pLength = P.length();
		bool flag = false;
		for (int i = 0; i < pLength; ++i) {
			if (P[i] == 'S') {
				if (flag) {
					currentDmg += 2;
				}
				else {
					currentDmg++;
				}
			}
			else {
				flag = true;
				cPos = i + 1;
			}
		}
		cout << "Case #" << k << ": ";
		if (pLength-cPos < currentDmg-D) {
			if (pLength <= D) {
				cout << 0 << endl;
			}
			else {
				cout << "IMPOSSIBLE" << endl;
			}
		}
		else {
			if (currentDmg - D < 0) {
				cout << 0 << endl;
			}
			else {
				cout << currentDmg - D << endl;
			}
		}
	}
	return 0;
}