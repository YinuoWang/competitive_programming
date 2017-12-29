#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long n;
	vector<long long>output;
	for (int k = 0; k <10; ++k) {
		cin >> n;
		long double index[10001], heights[10001];
		fill_n(index, 10001, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> heights[i];
		}
		long double currentSlope, greatestSlope;
		for (long a = 1; a<=n; ++a) {
			greatestSlope = -10000000000;
				for (long b = a; b<=n; ++b) {
					currentSlope = (heights[a] - heights[b]) / (a - b);
					if (currentSlope > greatestSlope) {
						index[a]++;
						index[b]++;
						greatestSlope = currentSlope;
					}
				}
		}
		vector<long long>maxIndex;
		long long maxCount = 0;
		for (int i = 1; i <= n; ++i) {
			if (index[i] > maxCount) {
				maxIndex.clear();
				maxIndex.push_back(i);
				maxCount = index[i];
			}
			else if (index[i] != 0 && index[i] == maxCount) {
				maxIndex.push_back(i);
			}
		}
		sort(maxIndex.begin(), maxIndex.end());
		output.push_back(maxIndex[0]);
		maxIndex.clear();
	}
	for (vector<long long>::iterator it = output.begin(); it != output.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}