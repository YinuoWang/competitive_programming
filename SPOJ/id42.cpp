#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

string reverse(string input);

int main() {
	vector<int> output;
	cin >> N;
	int ans, finalAns;
	string num1, num2, newAns;
	for (int i = 0; i<N; ++i) {
		cin >> num1 >> num2;
		num1 = reverse(num1);
		num2 = reverse(num2);
		ans = stoi(num1) + stoi(num2);
		newAns = to_string(ans);
		newAns = reverse(newAns);
		finalAns = stoi(newAns);
		output.push_back(finalAns);
	}
	for (vector<int>::iterator it = output.begin(); it != output.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}

string reverse(string input) {
	string answer = "";
	for (int i = input.length() - 1; i >= 0; --i) {
		answer += input.at(i);
	}
	return answer;
}