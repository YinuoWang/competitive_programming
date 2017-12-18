#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N, start = 1;
	cin >> N;
	long count = 0;
	for (int height = 1; height <= sqrt(N); ++height) {
		for (int length = start; length*height <= N; ++length) {
			++count;
		}
		++start;
	}
	cout << count << endl;
	return 0;
}