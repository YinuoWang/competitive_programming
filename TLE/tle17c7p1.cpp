#include <iostream>
#include <utility>
#include <string.h>

using namespace std;

bool planetMap[2001][2001];
pair<int, int> planetCoords[1001];
int counter = 1, n;

int main() {
	memset(planetMap, false, sizeof(planetMap));
	planetMap[1000][1000] = true;
	planetCoords[1] = make_pair(1000, 1000);
	cin >> n;
	for (int i = 2, p, x, y; i <= n; ++i) {
		cin >> p >> x >> y;
		int xCoord = x + planetCoords[p].first, yCoord = y + planetCoords[p].second;
		if (planetMap[xCoord][yCoord] == false) {
			planetMap[xCoord][yCoord] = true;
			counter++;
		}
		planetCoords[i] = make_pair(xCoord, yCoord);
	}
	cout << counter << endl;
	return 0;
}