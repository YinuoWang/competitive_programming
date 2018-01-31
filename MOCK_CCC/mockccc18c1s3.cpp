#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long long n, k;
	cin >> n;
	double a = -0.5, b = n - 0.5, c = -1* n * (n - 1) / 4;
	k = ceil((-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a));
	if (n == 2) {
		cout << 1 << endl;
	}
	else {
		cout << k << endl;
	}
	return 0;
}