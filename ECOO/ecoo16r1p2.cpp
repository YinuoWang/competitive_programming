#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int testCases = 10;
bool possible[1000001];

int main() {
	while (testCases--) {
		int N;
		vector<int>spindle;
		memset(possible, false, sizeof(possible));
		scanf("%d", &N);
		for (int i = 0, input; i<N; ++i) {
			scanf("%d", &input);
			spindle.push_back(input);
		}
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				possible[spindle[a] + spindle[b]] = true;
				possible[spindle[a] * spindle[b]] = true;
			}
		}
		for (int i = 0, target; i<5; ++i) {
			scanf("%d", &target);
			bool printThis = false;
			for (int k = 0; k < N; ++k) {
				if ((target - spindle[k] >= 0 && possible[target - spindle[k]]) || (target%spindle[k] == 0 && possible[target / spindle[k]])) {
					printThis = true;
					break;
				}
			}
			if (printThis) {
				printf("%c", 'T');
			}
			else {
				printf("%c", 'F');
			}
		}
		printf("%c", '\n');
	}
	return 0;
}