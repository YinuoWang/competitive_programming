#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const string vowels = "aeiouAEIOU";

string syllable(string line);

int main() {
	int N;
	vector<string> output;
	string poemLine, s1, s2, s3, s4, answer;
	cin >> N;
	cin.ignore();
	for (int i = 0; i<N; ++i) {
		getline(cin, poemLine);
		s1 = syllable(poemLine);
		getline(cin, poemLine);
		s2 = syllable(poemLine);
		getline(cin, poemLine);
		s3 = syllable(poemLine);
		getline(cin, poemLine);
		s4 = syllable(poemLine);
		if (s1 == s2 && s3 == s4 && s1 == s4) {
			answer = "perfect";
		}
		else if (s1 == s2 && s3 == s4) {
			answer = "even";
		}
		else if (s2 == s3 && s1 == s4) {
			answer = "shell";
		}
		else if (s1 == s3 && s2 == s4) {
			answer = "cross";
		}
		else {
			answer = "free";
		}
				
		output.push_back(answer);
	}
	for (vector<string>::iterator it = output.begin(); it != output.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}

string syllable(string line) {
	string finalAns = "";
	for (int i = line.length() - 1; i >= 0; --i) {
		if (line.at(i) == ' ') {
			break;
		}
		size_t found = vowels.find(line.at(i));
		finalAns = line.at(i) + finalAns;
		if (found != string::npos) {
			break;
		}
	}
	transform(finalAns.begin(), finalAns.end(), finalAns.begin(), ::tolower);
	return finalAns;
}
