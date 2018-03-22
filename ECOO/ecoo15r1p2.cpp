#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;
	
int testCases = 10;

int main() {
	while (testCases--) {
		int n;
		string line, buffer;
		deque<string>tokens;
		cin >> n;
		cin.ignore();
		getline(cin, line);
		stringstream ss(line);
		while (ss >> buffer) {
			tokens.push_back(buffer);
		}
		int curPos = 0, curLength = 0;
		while (curPos<tokens.size()) {
			if (tokens[curPos].length() <= n) {
				if (curLength + tokens[curPos].length() <= n){
					cout << tokens[curPos];
					curLength += tokens[curPos].length();
					if (curPos != tokens.size() - 1) {
						cout << ' ';
						curLength++;
					}
					curPos++;
				}
				else {
					cout << '\n';
					curLength = 0;
				}
			}
			else {
				if (curPos != 0) {
					cout << '\n';
				}
				curLength = 0;
				for (int i = 0; i<tokens[curPos].length(); ++i) {
					curLength++;
					if (curLength>n) {
						cout << '\n';
						curLength = 1;
					}
					cout << tokens[curPos][i];
				}
				if (curPos != tokens.size() - 1) {
					cout << ' ';
					curLength++;
				}
				curPos++;
			}
		}
		cout << '\n' << "=====" << endl;
	}
	return 0;
}