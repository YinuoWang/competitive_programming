#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		int counts[10], index[10] = { 1,2,5,10,50,100,1000,10000,500000,1000000 }, qCount = 0;;
		memset(counts, 0, sizeof(counts));
		string input;
		for (int i = 0; i<9; ++i) {
			cin >> input;
			if (input == "?") {
				qCount++;
				continue;
			}
			int value = stoi(input.substr(1, input.length() - 1));
			for (int k = 0; k<10; ++k) {
				if (index[k] == value) {
					counts[k]++;
					break;
				}
			}
		}
		bool alreadyDone = false;
		for (int i = 0; i < 10; ++i) {
			if (counts[i] == 3) {
				cout << '$' << index[i];
				alreadyDone = true;
			}
		}
		if (!alreadyDone) {
			bool flag = true;
			for (int i = 0; i < 10; ++i) {
				if (counts[i] + qCount >= 3) {
					cout << '$' << index[i] << ' ';
					flag = false;
				}
			}
			if (flag) {
				cout << "No Prizes Possible";
			}
		}
		cout << endl;
	}
	return 0;
}