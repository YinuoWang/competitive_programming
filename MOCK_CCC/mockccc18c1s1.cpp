#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double k, p, x, m = 1, current, output, previous = 10000000000000;
	bool flag = true;
	cin >> k >> p >> x;
	while (flag) {
		current = m * x + k * p / m;
		if (current <= previous) {
			previous = current;
			m++;
		}
		else {
			flag = false;
			output = previous;
		}
	}
	cout << setprecision(3) << fixed;
	cout << output << endl;
	return 0;
}