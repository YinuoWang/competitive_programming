#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

int main() {
	ifstream inputFile("B-small-practice.in");
	ofstream outputFile("B-small-practice.out");
	int testCases;
	inputFile >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		int n, k;
		long long p;
		inputFile >> n >> k >> p;
		vector<int>bitString(n, 0);
		set<int>aLists;
		for (int i = 0; i<k; ++i) {
			int a, b, c;
			inputFile >> a >> b >> c;
			bitString[a - 1] = c;
			aLists.insert(a-1);
		}
		outputFile << "Case #" << t << ": ";
		string restBits = bitset<128>(p - 1).to_string(), finalAns = "";
		int currentLocation = restBits.length() - 1;
		for (int i = n - 1; i >= 0; --i) {
			if (aLists.find(i)==aLists.end()) {
				finalAns = restBits[currentLocation] + finalAns;
				currentLocation--;
			}
			else {
				finalAns = to_string(bitString[i]) + finalAns;
			}
		}
		outputFile << finalAns << '\n';
	}
	outputFile.close();
	return 0;
}