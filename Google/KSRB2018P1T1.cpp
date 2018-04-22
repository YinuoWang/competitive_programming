#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isCorrect(int input) {
	if (input % 9 == 0) {
		return false;
	}
	if (to_string(input).find("9") != string::npos) {
		return false;
	}
	return true;
}

int main() {
	ifstream inputFile("A-small-attempt0.in");
    ofstream outputFile("A-small-attempt0.out");
	int testCases;
	inputFile >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		int first, last, count = 2;
		inputFile >> first >> last;
		for (int k = first + 1; k < last; ++k) {
			if (isCorrect(k)) {
				count++;
			}
		}
		outputFile << "Case #" << t << ": " << count << '\n';
	}
    outputFile.close();
	return 0;
}