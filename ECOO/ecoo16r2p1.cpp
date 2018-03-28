#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int testCases = 10, wLength;
string word;

bool isPalindrome(int sLength, bool startOrEnd) { // true is start, false is end
	if (startOrEnd) {
		for (int i = 0; i < sLength / 2; ++i) {
			if (word[i] != word[sLength - 1 - i]) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < sLength / 2; ++i) {
			if (word[wLength - sLength + i] != word[wLength - 1 - i]) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	while (testCases--) {
		cin >> word;
		wLength = word.length();
		for (int ssLength = wLength; ssLength>0; --ssLength){
			if (isPalindrome(ssLength,true) || isPalindrome(ssLength, false)) {
				cout << wLength - ssLength << endl;
				break;
			}
		}
	}
	return 0;
}