#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int apartmentCount[1000001];

int main() {
	int n, k, count = 0;
	vector<int>unlucky;
	scanf("%d", &k);
	for (int i = 0, input; i<k; ++i) {
		scanf("%d", &input);
		unlucky.push_back(input);
	}
	sort(unlucky.begin(), unlucky.end());
	scanf("%d", &n);
	for (int i = 1; i <= 1000000; ++i) {
		if (unlucky[count] == i) {
			++count;
		}
		apartmentCount[i] = i - count;
	}
	for (int i = 0, input; i<n; ++i) {
		scanf("%d", &input);
		printf("%d\n", apartmentCount[input]);
	}
	return 0;
}