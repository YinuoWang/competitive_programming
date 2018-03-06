#include <iostream>
#include <string>
#include <utility>

using namespace std;

int testCases = 10;
pair<string, char>key[4];

char fillThis(pair<string, char>localKey[4], char left, char right) {
	for (int i = 0; i<4; ++i) {
		if (left == localKey[i].first[0] && right == localKey[i].first[1]) {
			return localKey[i].second;
		}
	}
}

int main() {
	while (testCases--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i<4; ++i) {
			cin >> key[i].first >> key[i].second;
		}
		string currentLine, nextLine;
		cin >> currentLine;
		for (int i = 0; i<m-1; ++i) {
			nextLine = "";
			nextLine += fillThis(key, currentLine[n-1], currentLine[1]);
			for (int k = 1; k<n - 1; ++k) {
				nextLine += fillThis(key, currentLine[k-1], currentLine[k+1]);
			}
			nextLine += fillThis(key, currentLine[n-2], currentLine[0]);
			currentLine = nextLine;
		}
		cout << currentLine << endl;
		char asterisk;
		cin >> asterisk;
	}
}