#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector <double> villages;
	double input;
	double answer = 1000000000000;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		villages.push_back(input);
	}
	sort(villages.begin(), villages.end());
	for (int i = 1; i < n - 1; ++i) {
		double size = abs(villages[i] - villages[i - 1])/2 + abs(villages[i] - villages[i + 1])/2;
		answer = min(size, answer);
	}
	cout << setprecision(1) << fixed;
	cout << answer << endl;
	return 0;
}