#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long N;
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<long>stamps;
	vector<int> output;
	long needed, friends, input, sum, count;
	for (int i = 0; i<N; ++i) {
		sum = 0;
		count = 0;
		cin >> needed >> friends;
		for (int k = 0; k<friends; ++k) {
			cin >> input;
			stamps.push_back(input);
		}
		sort(stamps.begin(), stamps.end());
		reverse(stamps.begin(), stamps.end());
		for (vector<long>::iterator it = stamps.begin(); it != stamps.end(); it++) {
			sum += *it;
			count++;
			if (sum>=needed) {
				output.push_back(count);
				break;
			}
		}
		if (sum < needed) {
			output.push_back(0);
		}
		stamps.clear();

	}
	for (int i = 0; i<N; ++i) {
		cout << "Scenario #" << i + 1 << ":" << endl;
		if (output[i] == 0) {
			cout << "impossible" << endl;
		}
		else {
			cout << output[i] << endl;
		}
		cout << "" << endl;
	}
	return 0;
}