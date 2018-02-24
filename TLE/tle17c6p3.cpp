#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	long double input, sum = 0;
	int logCount;
	vector<long long> nums;
	cin >> input;
	logCount = floor(log2(input));
	for (int i = 0; i<logCount; ++i) {
		nums.push_back(pow(2, i));
		sum += pow(2, i);
	}
	nums.push_back(input - sum);
	cout << logCount + 1 << endl;
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		cout << *it << ' ';
	}
	return 0;
}