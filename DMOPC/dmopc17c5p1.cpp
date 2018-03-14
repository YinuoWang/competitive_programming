#include <iostream>
#include <string>

using namespace std;

string NUMS = "01345689", CONVERSION = "OlEASGBg";

int main() {
	string input;
	cin >> input;
	for (int i = 0; i<input.length(); ++i) {
		int foundLocation = NUMS.find(input[i]);
		if (foundLocation != string::npos) {
			input[i] = CONVERSION[foundLocation];
		}
	}
	cout << input;
	return 0;
}