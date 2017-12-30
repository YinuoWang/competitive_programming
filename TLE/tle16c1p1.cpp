#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int d, q;
	long double currentInput;
	vector<long double>dimes;
	vector<long double>quarters;
	cin >> d;
	for (int i = 0; i<d; i++) {
		cin >> currentInput;
		dimes.push_back(currentInput);
	}
	cin >> q;
	for (int i = 0; i<q; ++i) {
		cin >> currentInput;
		quarters.push_back(currentInput);
	}
	sort(dimes.begin(), dimes.end());
	sort(quarters.begin(), quarters.end());

	if (10 / (*(dimes.end() - 1))>25/(*quarters.begin())) {
		cout << "Dimes are better" << endl;
	}
	else if (25 / (*(quarters.end() - 1))>10 / (*(dimes.begin()))) {
		cout << "Quarters are better" << endl;
	}
	else {
		cout << "Neither coin is better" << endl;
	}
	return 0;
}