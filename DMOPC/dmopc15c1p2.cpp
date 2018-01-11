#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, l, r, strength, cycle = 1;
	long total = 0;
	vector<int>soldiers;
	cin >> n >> l >> r;
	for (int i = 0; i<n; ++i) {
		cin >> strength;
		soldiers.push_back(strength);
	}
	sort(soldiers.begin(), soldiers.end());
	while (!soldiers.empty()) {
		if (cycle>l) {
			cycle = 1;
		}
		if (cycle == r) {
			total += *(soldiers.end() - 1);
		}
		cycle++;
		soldiers.pop_back();
	}
	cout << total << endl;
	return 0;
}
