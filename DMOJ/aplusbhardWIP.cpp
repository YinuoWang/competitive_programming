#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin.sync_with_stdio(0);
    cin.tie(0);
	cin >> N;
	string num1, num2, longNum, shortNum;
	bool shortNegative, longNegative;
	vector<string> output;
	for (int i = 0; i < N; ++i) {
		cin >> num1 >> num2;
		if (num1.length()<num2.length()) {
			shortNum = num1;
			longNum = num2;
		}
		else {
			shortNum = num2;
			longNum = num1;
		}
		if (shortNum[0] == '-') {
			shortNegative = true;
		}
		else {
			shortNegative = false;
		}
		if (longNum[0] == '-') {
			longNegative = true;
		}
		else {
			longNegative = false;
		}
		// double positive case and double negative case
		string answer = "";
		if ((shortNegative == false && longNegative == false) || (shortNegative == true && longNegative == true)) {
			if (shortNegative == true && longNegative == true) {
				shortNum = shortNum.substr(1, shortNum.length() - 1);
				longNum = longNum.substr(1, longNum.length() - 1);
			}
			int dig1, dig2, carry = 0;
			for (int i = 0; i<shortNum.length(); ++i) {
				dig1 = shortNum[shortNum.length() - i - 1] - '0';
				dig2 = longNum[longNum.length() - i - 1] - '0';
				if (to_string(dig1 + dig2 + carry).length() == 1) {
					answer = to_string(dig1 + dig2 + carry) + answer;
					carry = 0;
				}
				else {
					answer = to_string(dig1 + dig2 + carry)[1] + answer;
					carry = to_string(dig1 + dig2 + carry)[0] - '0';
				}
			}
			for (int i = 0; i<longNum.length() - shortNum.length(); ++i) {
				dig2 = longNum[longNum.length() - shortNum.length() - i - 1] - '0';

				if (to_string(dig2 + carry).length() == 1) {
					answer = to_string(dig2 + carry) + answer;
					carry = 0;
				}
				else {
					answer = to_string(dig2 + carry)[1] + answer;
					carry = to_string(dig2 + carry)[0] - '0';
				}
			}
			if (carry != 0) {
				answer = to_string(carry) + answer;
			}
			if (shortNegative == true && longNegative == true) {
				answer = '-' + answer;
			}
		}
		else {
			if (shortNegative == true) {
				shortNum = shortNum.substr(1, shortNum.length() - 1);
			}
			else {
				longNum = longNum.substr(1, longNum.length() - 1);
			}
			bool negativeAns = true;
			if (shortNum[0] >= longNum[0] && shortNum.length() == longNum.length()) {
				string temp = longNum;
				longNum = shortNum;
				shortNum = temp;
				negativeAns = false;
			}
			else if (shortNegative == true) {
				negativeAns = false;
			}
			int dig1, dig2;
			for (int i = 0; i<shortNum.length(); ++i) {
				if (longNum[longNum.length() - i - 1] == 'n') {
					dig2 = 9;
					if (longNum[longNum.length() - i - 2] == '0') {
						longNum[longNum.length() - i - 2] = 'n';
					}
					else {
						int count = (longNum[longNum.length() - i - 2] - '0') - 1;
						longNum[longNum.length() - i - 2] = '0' + count;
					}
				}
				else {
					dig2 = longNum[longNum.length() - i - 1] - '0';
				}
				dig1 = shortNum[shortNum.length() - i - 1] - '0';
				if (dig2 - dig1<0) {
					answer = to_string(stoi('1' + to_string(dig2)) - dig1) + answer;
					if (longNum[longNum.length() - i - 2] == '0') {
						longNum[longNum.length() - i - 2] = 'n';
					}
					else {
						int count = (longNum[longNum.length() - i - 2] - '0') - 1;
						longNum[longNum.length() - i - 2] = '0' + count;
					}
				}
				else {
					answer = to_string(dig2 - dig1) + answer;
				}
			}
			for (int i = 0; i<longNum.length() - shortNum.length(); ++i) {
				if (longNum[longNum.length() - shortNum.length() - i - 1] == 'n') {
					dig2 = 9;
					if (longNum.length() - shortNum.length() >= 2) {
						if (longNum[longNum.length() - shortNum.length() - i - 2] == '0') {
							longNum[longNum.length() - shortNum.length() - i - 2] = 'n';
						}
						else {
							int count = (longNum[longNum.length() - shortNum.length() - i - 2] - '0') - 1;
							longNum[longNum.length() - shortNum.length() - i - 2] = '0' + count;
						}
					}
				}
				else {
					dig2 = longNum[longNum.length() - shortNum.length() - i - 1] - '0';
				}
				answer = to_string(dig2) + answer;
			}
			if (answer[0] == '0') {
				answer = answer.substr(1, answer.length() - 1);
			}
			if (negativeAns == true && answer[0] != '0') {
				answer = '-' + answer;
			}
			bool check = true;
			for (int i = 0; i<answer.length(); ++i) {
				if (answer[i] != '0') {
					check = false;
					break;
				}
			}
			if (check == true) {
				answer = '0';
			}
		}
		output.push_back(answer);
	}

	for (vector<string>::iterator it = output.begin(); it != output.end(); ++it) {
		cout << *it << '\n';
	}
	return 0;
}