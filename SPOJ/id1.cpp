#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> answers;
	bool ans=true;
	int input;
	while (ans) {
		cin >> input;
		if (input != 42) {
			answers.push_back(input);
		}
		else {
			ans = false;
		}
	}
	for(vector<int>::iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}