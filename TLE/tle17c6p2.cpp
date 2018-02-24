#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n;
	string name;
	cin >> n >> name;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		string inputLine, numerator = "", denominator = "", prefix = "";
		char output;
		getline(cin, inputLine);
		int k = 0;
		while (k < inputLine.length() && inputLine[k] != '/') {
			numerator = numerator + inputLine[k];
			k++;
		}
		k++;
		while (k < inputLine.length() && inputLine[k] != ' ') {
			denominator = denominator + inputLine[k];
			k++;
		}
		k++;
		while (k < inputLine.length()) {
			prefix = prefix + inputLine[k];
			k++;
		}
		if (denominator == "") {
			output = 'Y';
		}
		else {
			double numD, denD;
			istringstream(numerator) >> numD;
			istringstream(denominator) >> denD;
			bool overOne, nameValid = true;
			if (numD / denD > 1) {
				overOne = true;
			}
			else {
				overOne = false;
			}
			if (name.length() < prefix.length()){
				nameValid = false;
			}
			else {
				for (int q = 0; q<prefix.length(); ++q) {
					if (prefix[q] != name[q]) {
						nameValid = false;
						break;
					}
				}
			}
			if (overOne && nameValid) {
				output = 'Y';
			}
			else {
				output = 'N';
			}
		}
		cout << output << endl;
	}
	return 0;
}