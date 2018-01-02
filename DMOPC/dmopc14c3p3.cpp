#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <utility>

using namespace std;

bool myComparison(const tuple<string, int, int> &a, const tuple<string, int, int> &b) {
	if (get<1>(a) == get<1>(b)) {
		return get<2>(a)<get<2>(b);
	}
	return get<1>(a)<get<1>(b);
}

int main() {
	int n, s, q;
	string name;
	vector<tuple<string, int, int>> vetList;
	cin >> n;
	for (int i = 0; i<n; ++i) {
		cin >> name >> s;
		vetList.push_back(make_tuple(name, s, i));
	}
	sort(vetList.begin(), vetList.end(), myComparison);
	cin >> q;
	int sNew, d;
	for (int k = 0; k<q; ++k) {
		cin >> sNew >> d;
		for (auto it = vetList.begin(); it <= vetList.end(); ++it) {
			if (it == vetList.end()) {
				cout << "No suitable teacher!" << endl;
				break;
			}
			if (get<1>(*it) >= sNew && get<1>(*it) <= (sNew + d)) {
				cout << get<0>(*it) << endl;
				break;
			}
		}
	}
	return 0;
}