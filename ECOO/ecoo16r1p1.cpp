#include <iostream>

using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		int weights[4], passes = 0, studentCount;
		for (int i = 0; i<4; ++i) {
			cin >> weights[i];
		}
		cin >> studentCount;
		for (int i = 0; i<studentCount; ++i) {
			int finalMark = 0;
			for (int k = 0; k<4; ++k) {
				int partialMark;
				cin >> partialMark;
				finalMark += partialMark * weights[k];
			}
			if (finalMark >= 5000) {
				passes++;
			}
		}	
		cout << passes << endl;
	}
	return 0;
}