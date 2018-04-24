#include <iostream>
#include <string>

using namespace std;

int boardSize, shipLength, testCases = 10;
char board[100][100];

bool invalidSquare(int x, int y) {
	if (x >= 0 && y >= 0 && x < boardSize && y < boardSize) {
		if (board[x][y] == 'h') {
			return true;
		}
		return false;
	}
	return false;
}

int check(int x, int y) {
	int finalAnswer = 0;
	// going down
	bool flag = true;
	if (y + shipLength <= boardSize) { // if ship will not fit
		if (invalidSquare(x, y - 1) || invalidSquare(x - 1, y - 1) || invalidSquare(x + 1, y - 1) || invalidSquare(x, y + shipLength) || invalidSquare(x - 1, y + shipLength) || invalidSquare(x + 1, y+shipLength)) {
			flag = false; // if top or bottom is bad
		}
		else {
			for (int i = 0; i<shipLength; ++i) {
				if (board[x][y + i] == 'm') { // if miss is on the path
					flag = false;
				}
				if (invalidSquare(x - 1, y + i) || invalidSquare(x + 1, y + i) || invalidSquare(x - 1, y + i - 1) || invalidSquare(x - 1, y + i + 1) || invalidSquare(x + 1, y + i - 1) || invalidSquare(x + 1, y + i + 1)) {
					flag = false; // adjacent to another ship
				}
			}
		}
	}
	else {
		flag = false;
	}
	if (flag) {
		finalAnswer++;
	}
	flag = true;
	if (x + shipLength <= boardSize) { // if ship will not fit
		if (invalidSquare(x - 1, y) || invalidSquare(x - 1, y - 1) || invalidSquare(x - 1, y + 1) || invalidSquare(x+shipLength, y) || invalidSquare(x + shipLength, y + 1) || invalidSquare(x + shipLength, y-1)) {
			flag = false; // if top or bottom is bad
		}
		else {
			for (int i = 0; i<shipLength; ++i) {
				if (board[x+i][y] == 'm') { // if miss is on the path
					flag = false;
				}
				if (invalidSquare(x + i, y - 1) || invalidSquare(x + i, y +  1) || invalidSquare(x + i + 1 , y - 1) || invalidSquare(x + i + 1, y + 1) || invalidSquare(x + i - 1, y - 1) || invalidSquare(x + i - 1, y + 1)) {
					flag = false; // adjacent to another ship
				}
			}
		}
	}
	else {
		flag = false;
	}
	if (flag) {
		finalAnswer++;
	}
	return finalAnswer;
}

int main() {
	while (testCases--) {
		int answer = 0;
		cin >> boardSize >> shipLength;
		for (int i = 0; i<boardSize; ++i) {
			string inputLine;
			cin >> inputLine;
			for (int k = 0; k<boardSize; ++k) {
				board[k][i] = inputLine[k];
			}
		}
		for (int x = 0; x<boardSize; ++x) {
			for (int y = 0; y<boardSize; ++y) {
					answer += check(x, y);
			}
		}
		cout << answer << endl;
	}
	return 0;
}