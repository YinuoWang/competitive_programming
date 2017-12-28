#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;
	int answer = 1;
	for (int i = 0; i<input.length(); ++i) {
		int count = 1;
		bool check = true;
		int tempAns = 0;
		while (check) {
			string temp1 = input.substr(i, count);
			string temp2 = temp1;
			reverse(temp1.begin(), temp1.end());
			if (temp1 == temp2) {
				tempAns = count;
			}
			count++;
			if (count > input.length() - i) {
				break;
			}
		}
		if (tempAns>answer) {
			answer = tempAns;
		}
	}
	cout << answer << endl;
	return 0;
}