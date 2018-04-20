#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		string type, line, buf;
		cin >> type;
		cin.ignore();
		getline(cin, line);
		stringstream ss(line);
		vector<string> tokens;
		while (ss >> buf) {
			tokens.push_back(buf);
		}
		if (type == "encode") {
			string answer = "";
			int maxSize = 0;
			for (auto it = tokens.begin(); it != tokens.end(); ++it) {
				int l = (*it).length();
				maxSize = max(maxSize, l);
			}
			int currentLocation = 0;
			for (int i = 0; i < maxSize; ++i) {
				for (auto it = tokens.begin(); it != tokens.end(); ++it) {
					if ((*it).length()<=i) {
						continue;
					}
					if (line[currentLocation] == ' ') {
						answer += ' ';
						currentLocation++;
					}
					answer += (*it)[i];
					currentLocation++;
					
				}
			}
			cout << answer << endl;
		}
		else {
			vector<string>words(tokens.size());
			int location = 0;
			for (int i = 0; i<line.length(); ++i) {
				if (line[i] != ' ') {
					if (words[location].length()<tokens[location].length()) {
						words[location] += line[i];
					}
					else {
						i--;
					}
					location++;
					if (location == tokens.size()) {
						location = 0;
					}
				}
			}
			for (auto it = words.begin(); it != words.end(); ++it) {
				cout << *it << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}