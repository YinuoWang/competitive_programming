#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	double h;
	int d, e;
	cin >> h >> d >> e;
	vector<pair<double, double>>defenses;
	for (int i = 0; i<d; ++i) {
		double a, s;
		cin >> a >> s;
		defenses.push_back(make_pair(a, s));
	}
	double attacks[1001], difference[1001];
	memset(attacks, 0, sizeof(attacks));
	memset(difference, 0, sizeof(difference));
	for (int i = 0; i<e; ++i) {
		int t, l;
		double x;
		cin >> t >> l >> x;
		difference[t] += x;
		difference[t + l] -= x;
	}
	for (int i = 0; i<1001; ++i) {
		if (i == 0) {
			attacks[i] = difference[i];
		}
		else {
			attacks[i] = difference[i] + attacks[i - 1];
		}
	}
	for (int i = 0; i<1001; ++i) {
		double minDmg = attacks[i];
		for (auto it = defenses.begin(); it != defenses.end(); ++it) {
			minDmg = min(minDmg, (attacks[i] - (*it).second) * (1 - (*it).first/100));
		}
		if (minDmg>0) {
			h -= minDmg;
		}
	}
	if (h <= 0) {
		cout << "DO A BARREL ROLL!" << endl;
	}
	else {
		cout << setprecision(2) << fixed;
		cout << h << endl;
	}
	return 0;
}