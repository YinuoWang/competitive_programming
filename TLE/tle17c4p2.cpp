#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isGood(string input);
long long secondsConversion(string input);

string buttons;

int main() {
	string desired, answer = "";
	cin >> desired >> buttons;

	long long desiredTime = secondsConversion(desired);

	string check = "", best = "";
	long minDiff = 100000000000000;

	for (int hh = 0; hh <= 99; ++hh) {
		for (int mm = 0; mm <= 99; ++mm) {
			for (int ss = 0; ss <= 99; ++ss) {
				check = "";
				if (to_string(hh).length() == 1) {
					check = '0';
				}
				check += to_string(hh) + ':';

				if (to_string(mm).length() == 1) {
					check += '0';
				}
				check += to_string(mm) + ':';
				if (to_string(ss).length() == 1) {
					check += '0';
				}
				check += to_string(ss);
				if (isGood(check) == true) {
					if (abs(secondsConversion(check) - desiredTime)<minDiff) {
						minDiff = abs(secondsConversion(check) - desiredTime);
						best = check;
					}
				}
			}
		}
	}
	cout << best << endl;
	return 0;
}

bool isGood(string input) {
	for (int i = 0; i<input.length(); ++i) {
		if (input.at(i) != ':') {
			size_t found = buttons.find(input.at(i));
			if (found == string::npos) {
				return false;
			}
		}
	}
	return true;
}

long long secondsConversion(string input) {
	return stoi(input.substr(0, 2)) * 3600 + stoi(input.substr(3, 2)) * 60 + stoi(input.substr(6, 2));
}
