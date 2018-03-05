#include <iostream>
#include <string>
#include <utility>

using namespace std;

int testCases = 10;
pair<string, char>key[4];

char fillThis(pair<string, char>localKey[4], string inputLR) {
	for (int i = 0; i<4; ++i) {
		if (inputLR == localKey[i].first) {
			return localKey[i].second;
		}
	}
}

int main() {
	while (testCases != 0) {
		--testCases;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i<4; ++i) {
			cin >> key[i].first >> key[i].second;
		}
		string currentLine, nextLine = "";
		cin >> currentLine;
		for (int i = 0; i<m-1; ++i) {
			string appendThis = "";
			appendThis += currentLine[n-1];
			appendThis += currentLine[1];
			nextLine += fillThis(key, appendThis);
			for (int k = 1; k<n - 1; ++k) {
				appendThis = "";
				appendThis += currentLine[k-1];
				appendThis += currentLine[k+1];
				nextLine += fillThis(key, appendThis);
			}
			appendThis = "";
			appendThis += currentLine[n-2];
			appendThis += currentLine[0];
			nextLine += fillThis(key, appendThis);
			currentLine = nextLine;
			nextLine = "";
		}
		cout << currentLine << endl;
		char asterisk;
		cin >> asterisk;
	}
}