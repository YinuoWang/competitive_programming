#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int>zeroes, ones;
int zeroCount = 0, oneCount = 0, q;

int main() {
	string input;
	cin >> input;
	for (int i = 0; i<input.length(); ++i) {
		if (input[i] == '0') {
			zeroCount++;
		}
		else {
			oneCount++;
		}
		zeroes.push_back(zeroCount);
		ones.push_back(oneCount);
	}
	cin >> q;
	for (int i = 0, x, y, z; i<q; ++i) {
		cin >> x >> y >> z;
		x--;
		if (z == 0) {
			vector<int>::iterator it;
			if (x != 0) {
				 it = lower_bound(zeroes.begin(), zeroes.end(), zeroes[x - 1] + y);
			}
			else {
				it = lower_bound(zeroes.begin(), zeroes.end(), y);
			}
			if (it != zeroes.end()) {
				printf("%d\n", it - zeroes.begin() + 1);
			}
			else {
				printf("%d\n", -1);
			}
		}
		else {
			vector<int>::iterator it;
			if (x != 0) {
				 it = lower_bound(ones.begin(), ones.end(), ones[x - 1] + y);
			}
			else {
				it = lower_bound(ones.begin(), ones.end(), y);
			}
			if (it != ones.end()) {
				printf("%d\n", it - ones.begin() + 1);
			}
			else {
				printf("%d\n", -1);
			}
		}
	}
	return 0;
}