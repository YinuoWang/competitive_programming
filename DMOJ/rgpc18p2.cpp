#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

double hits[5];

int main() {
	double notes, longest = 0, currentCombo = 0, prevScore;
	cin >> notes >> prevScore;
	for (int i = 0, input; i<notes; ++i) {
		cin >> input;
		if (abs(input) <= 50) {
			hits[0]++;
		}
		else if (abs(input) <= 100) {
			hits[1]++;
		}
		else if (abs(input) <= 150) {
			hits[2]++;
		}
		else if (abs(input) <= 200) {
			hits[3]++;
		}
		else {
			hits[4]++;
		}
		if (abs(input)>200) {
			longest = max(longest, currentCombo);
			currentCombo = 0;
		}
		else {
			currentCombo++;
		}
	}
	longest = max(currentCombo, longest);
    double newScore = 1.5*hits[0] + hits[1] + hits[2] + 0.5*hits[3] - hits[4] + 0.5*longest;
    cout << setprecision(1) << fixed;
    if (newScore - prevScore > 0){
        cout << newScore - prevScore;
    }
    else{
        cout << 0.0;
    }
    return 0;
}