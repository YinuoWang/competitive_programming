#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int>temps;
int diff[21];

int main() {
	while (true) {
		temps.clear();
		memset(diff, 0, sizeof(diff));
		int numOfTemps;
		cin >> numOfTemps;
		if (numOfTemps == 0) {
			break;
		}
		else {
			for (int i = 0; i<numOfTemps; ++i) {
				int input;
				cin >> input;
				temps.push_back(input);
			}
			if (numOfTemps == 1) {
				cout << 0 << endl;
				continue;
			}
			for (int i = 0; i<numOfTemps - 1; ++i) {
				diff[i] = temps[i + 1] - temps[i];
			}
			for (int i = 1; i<numOfTemps; ++i) {
				bool flag = true;
				for (int k = 0; k<numOfTemps - 1; ++k) {
					if (diff[k] != diff[k%i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}