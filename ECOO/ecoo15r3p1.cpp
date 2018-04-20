#include <iostream>
#include <string>
#include <deque>
#include <utility>

using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		deque<string>outputVec;
		string num;
		cin >> num;
		int currentPlace = 0;
		for (int i = num.length() - 1; i >= 0; --i) {
			bool notAdded = true;
			if (i != 0) {
				string twoDigit = "";
				twoDigit = twoDigit + num[i - 1] + num[i];
				if (stoi(twoDigit)<=currentPlace) {
					outputVec.push_front(twoDigit);
					i--;
					notAdded = false;
				}
			}
			if (notAdded) {
				if ((num[i] - '0') > currentPlace) {
					outputVec.push_front("0");
					i++;
				}
				else {
					string putIn(1, num[i]);
					outputVec.push_front(putIn);
				}
			}
			currentPlace++;
		}
		for (auto it = outputVec.begin(); it != outputVec.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	return 0;
}