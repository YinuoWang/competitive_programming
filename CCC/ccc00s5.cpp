#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main() {
	int n;
	cin >> n;
	vector<pair<double, double>> sheep;
	set<pair<double,double>>eaten;
	for (double i = 0, inputX, inputY; i < n; ++i) {
		cin >> inputX >> inputY;
		sheep.push_back(make_pair(inputX, inputY));
	}
	for (double a = 0; a <= 1000; a+=0.01) {
		double minDist = 100000000;
		vector < pair<double, double>> minPairs;
		for (int b = 0; b < n; ++b) {
			if (dist(sheep[b].first, sheep[b].second, a, 0)<minDist) {
				minDist = dist(sheep[b].first, sheep[b].second, a, 0);
				minPairs.clear();
				minPairs.push_back(sheep[b]);
			}
			else if (dist(sheep[b].first, sheep[b].second, a, 0) == minDist) {
				minPairs.push_back(sheep[b]);
			}
		}
		for (auto it = minPairs.begin(); it != minPairs.end(); ++it) {
			eaten.insert(*it);
		}
	}
	for (auto it = eaten.begin(); it!=eaten.end(); ++it){
		cout << setprecision(2) << fixed;
		cout << "The sheep at (" << (*it).first << ", " << (*it).second << ") might be eaten." << endl;
	}
	return 0;
}