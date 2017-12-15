#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, value;

int main() {
	vector<long long> ans;
	ios::sync_with_stdio(false);
	long long current_value;
	cin >> value;
	for (int i = 0; i<value; ++i) {
		cin >> N;
		current_value = 0;
		for (int k = 1; k <= 12; ++k) {
			current_value += N / pow(5.0, k);
		}
		ans.push_back(current_value);
	}
	for (vector<long long>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}