#include <iostream>
#include <string.h>

using namespace std;

bool primes[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	memset(primes, true, sizeof(primes));
	for (long long i = 2; i*i <= 100000; ++i) {
		if (primes[i] == true) {
			for (int k = i * 2; k <= 100000; k += i) {
				primes[k] = false;
			}
		}
	}
	primes[1] = false;
	long long n, count = 0, input;
	cin >> n;
	for (int i = 0; i<n; ++i) {
		cin >> input;
		if (primes[input] == true) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}