#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int testCases = 10;

int main() {
	while (testCases--) {
		double Aw, Ah, Bx, By, Sx, Sy, originalSy;
		cin >> Aw >> Ah >> Bx >> By >> Sx >> originalSy;
		string answer = "";
		for (int i = 0; i<5; ++i) {
			Sy = originalSy;
			double Th, Tx, Ty;
			cin >> Th >> Tx >> Ty;
			double Px = Bx, Py = By;
			bool flag = false;
			while (Px < Aw) {
				if (Sx == 0 && Bx != Tx) { // check for infinite bounce
					break;
				}
				if (Px == Tx && Ty >= Py && Ty - Py <= Th) { // checks if target is hit
					flag = true;
					break;
				}
				Px++;
				// first check to see if it hits a side wall
				double timeLeft;
				if (Py + (Sy / Sx) >= Ah) {
					timeLeft = (1 / Sx) - ((Ah - Py) / Sy);
					Sy *= -1;
					Py = Ah;
				}
				else if (Py + (Sy / Sx) <= 0) {
					timeLeft = (1 / Sx) + (Py / Sy);
					Sy *= -1;
					Py = 0;
				}
				else {
					timeLeft = 0;
					Py += (Sy / Sx);
				}
				// checking until the ball stops bouncing between side walls per x movement of one unit
				while (timeLeft > 0) {
					if (Sy*timeLeft >= Ah) {
						timeLeft -= Ah / Sy;
						Sy *= -1;
						Py = Ah;
					}
					else if (Ah+Sy*timeLeft <= 0) {
						timeLeft += Ah / Sy;
						Sy *= -1;
						Py = 0;
					}
					else {
						Py += timeLeft * Sy;
						timeLeft = 0;
					}
				}
			}
			if (flag) {
				answer += "H";
			}
			else {
				answer += "M";
			}
		}
		cout << answer << endl;
	}
	return 0;
}