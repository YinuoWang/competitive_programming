#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%i\n", &N);
	string num1, num2;
	bool neg1, neg2;
	for (int i = 0; i < N; ++i) {
		scanf("%s %s\n", &num1, &num2);
		if (num1[0] == '-') {
			neg1 = true;
		}
		else {
			neg1 = false;
		}
		if (num2[0] == '-') {
			neg2 = true;
		}
		else {
			neg2 = false;
		}
		// both numbers are positive
		long long minLength;
		if (neg1 == false && neg2 == false) {
			minLength = min(num1.length(), num2.length());	
		}
		// both numbers are negative
		// one is negative one is positive (subcases)
	}
}