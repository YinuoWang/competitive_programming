#include <iostream>
#include <string>

using namespace std;

int testCases = 10, bG, bF, bP, bTotal;
string bestChocoName;

void setNums(int a, int b, int c, int d, string n) {
	bP = a;
	bF = b;
	bG = c;
	bTotal = d;
	bestChocoName = n;
}

int main() {
	while (testCases--) {
		int chocolates;
		bG = 0, bF = 0, bP = 0, bTotal = 0;
		bestChocoName = "";
		cin >> chocolates;
		string name;
		cin >> name;
		for (int i = 0; i<chocolates; ++i) {
			int p = 0, f = 0, g = 0, t = 0;
			string judge;
			cin >> judge;
			while (judge == "J") {
				int x, y, z;
				cin >> x >> y >> z;
				p += x;
				f += y;
				g += z;
				t += x + y + z;
				cin >> judge;
			}
			if (t>bTotal) {
				setNums(p, f, g, t, name);
			}
			else if (t == bTotal) {
				if (g>bG) {
					setNums(p, f, g, t, name);
				}
				else if (g == bG) {
					if (f>bF) {
						setNums(p, f, g, t, name);
					}
					else if (f == bF) {
						if (g>bG) {
							setNums(p, f, g, t, name);
						}
						else if (g == bG) {
							if (bestChocoName == "") {
								bestChocoName = name;
							}
							else {
								bestChocoName += "," + name;
							}
						}
					}
				}
			}
			name = judge;
		}
		cout << bestChocoName << endl;
	}
	return 0;
}