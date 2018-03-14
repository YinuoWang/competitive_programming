#include <iostream>

using namespace std;

int main() {
	double b, p;
	char veg;
	cin >> b >> p >> veg;
	if (b / p >= 5) {
		if (veg == 'Y') {
			cout << 'B';
		}
		else {
			cout << 'A';
		}
	}
	else if (b / p >= 2) {
		if (veg == 'Y') {
			cout << 'D';
		}
		else {
			cout << 'C';
		}
	}
	else {
		cout << "NO PIZZA";
	}
	return 0;
}