#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solver[100001];
vector<int> factorCount[1000001];

int main() {
	for (int i = 1; i <= 100000; ++i) {
		for (int k = i; k <= 100000; k += i) {
			solver[k]++;
		}
	}
	for (int i = 1; i <= 100000; ++i) {
		factorCount[solver[i]].push_back(i);
	}
	int t, a, b, k, output;
	vector<int>::iterator low, up;
	scanf("%i", &t);
	for (int i = 0; i<t; ++i) {
		scanf("%i%i%i", &k, &a, &b);
		low = lower_bound(factorCount[k].begin(), factorCount[k].end(), a);
		up = upper_bound(factorCount[k].begin(), factorCount[k].end(), b);
		output = up - low;
		printf("%i\n", output);
	}
	return 0;
}