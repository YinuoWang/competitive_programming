#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

char square[36][36];
bool vis[36];
const string CONVERSION = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int convertSquare(char input) {
	return CONVERSION.find(input);
}

int main() {
	int n;
	bool latin = true, reduced = true;
	string input;
	cin >> n;
	for (int y = 0; y<n; ++y) {
		cin >> input;
		for (int x = 0; x<n; ++x) {
			square[x][y] = input[x];
		}
	}

	// row check
	for (int y = 0; y<n; ++y) {
		memset(vis, false, sizeof(vis));
		for (int x = 0; x<n; ++x) {
			if (vis[convertSquare(square[x][y])]) {
				latin = false;
			}
			vis[convertSquare(square[x][y])] = true;
		}
	}

	// column check
	for (int x = 0; x<n; ++x) {
		memset(vis, false, sizeof(vis));
		for (int y = 0; y<n; ++y) {
			if (vis[convertSquare(square[x][y])]) {
				latin = false;
			}
			vis[convertSquare(square[x][y])] = true;
		}
	}

	if (latin) {
		vector<char>topRow;
		vector<char>leftColumn;
		for (int i = 0; i<n; ++i) {
			topRow.push_back(square[i][0]);
			leftColumn.push_back(square[0][i]);
		}
		for (int k = 0; k<n; ++k) {
			if (topRow[k] != CONVERSION[k] || leftColumn[k] != CONVERSION[k]) {
				reduced = false;
				break;
			}
		}
	}

	if (reduced && latin) {
		cout << "Reduced" << endl;
	}
	else if (latin) {
		cout << "Latin" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}