#include <iostream>
#include <deque>

using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		int n, minCost = 0;
		deque<int>trains;
		scanf("%d", &n);
		for (int i = 0, input; i<n; ++i) {
			scanf("%d", &input);
			trains.push_back(input);
		}
		int findThis = n, skipCount = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (trains[i] == findThis) {
				findThis--;
				skipCount++;
			}
		}
		int skipDiscover = n;
		for (int k = n; k>0; --k) {
			if (k == skipDiscover && skipCount!=0) {
				skipCount--;
				skipDiscover--;
			}
			else {
				for (int i = 0; i<n; ++i) {
					if (k == trains[i]) {
						minCost += i;
						trains.erase(trains.begin() + i);
						trains.push_front(k);
						break;
					}
						
				}
			}
			
		}
		printf("%d\n", minCost);
	}
	return 0;
}