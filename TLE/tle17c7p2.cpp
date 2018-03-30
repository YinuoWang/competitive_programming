#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

vector<pair<int, int>> schedule[100001];
int n, m, timeCount = 0, dayCount = 0;

void bestFlight(vector<pair<int, int>> flights) {
	int bestTime = INT_MAX;
	for (auto it = flights.begin(); it != flights.end(); ++it) {
		if (20 + timeCount <= (*it).first) {
			if (bestTime > (*it).first - timeCount + (*it).second + 20) {
				bestTime = (*it).first - timeCount + (*it).second + 20;
			}
		}
		else if (20 + timeCount <= 60 * 24 + (*it).first) {
			if (bestTime > 60 * 24 - timeCount + (*it).first + (*it).second + 20) {
				bestTime = 60 * 24 - timeCount + (*it).first + (*it).second + 20;
			}
		}
		else{
			if (bestTime > 60 * 24 + 60 * 24 - timeCount + (*it).first) {
				bestTime = 60 * 24 + 60 * 24 - timeCount + (*it).first;
			}
		}
	}
	timeCount += bestTime;
	if (timeCount >= 60 * 24) {
		dayCount+= timeCount / (60*24) ;
		timeCount = timeCount % (60 * 24);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; ++i) {
		cin >> a >> b >> c;
		schedule[a].push_back(make_pair(b * 60, c * 60));
	}
	for (int i = 1; i < n; ++i) {
		bestFlight(schedule[i]);
	}
	cout << "Day " << dayCount << " Hour " << ceil(timeCount / 60.0) << endl;
	return 0;
}