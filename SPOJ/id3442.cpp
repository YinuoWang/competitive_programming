#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int testCases;
	vector<char>output;
	cin >> testCases;
	double num1;
	int num2, answer;
	string sAnswer;
	for (int i = 0; i<testCases; ++i) {
		cin >> num1 >> num2;
		if (num2 == 0) {
			answer = 1;
		}
		else if (num2 % 4 == 0) {
			answer = pow(num1, 4);
		}
		else {
			answer = pow(num1, (num2 % 4));
		}
		sAnswer = to_string(answer);
		output.push_back(sAnswer.at(sAnswer.length() - 1));
	}
	for (vector<char>::iterator it = output.begin(); it != output.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}