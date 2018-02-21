#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int original[100][100], ninetyCW[100][100], ninetyCCW[100][100], oneEighty[100][100];
int n;

bool check(int arr[][100]) {

	for (int i = 0; i < n - 1; ++i) {
		if (arr[0][i] >= arr[0][i + 1] || arr[i][0] >= arr[i + 1][0]) {
			return false;
		}
	}
	return true;
}

void print(int arr[][100]) {
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			cout << arr[i][k] << ' ';
		}
		cout << endl;
	}
}

int main() {
	long long input;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			cin >> input;
			original[i][k] = input;
			ninetyCW[n-k-1][i] = input;
			ninetyCCW[k][n-i-1] = input;
			oneEighty[n - 1 - i][n - 1 - k] = input;
		}
	}
	if (check(original)) {
		print(original);
	}
	else if (check(ninetyCW)) {
		print(ninetyCW);
	}
	else if (check(ninetyCCW)) {
		print(ninetyCCW);
	}
	else {
		print(oneEighty);
	}
	return 0;
}