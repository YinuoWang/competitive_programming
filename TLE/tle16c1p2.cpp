#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long frequency[100001];

int main() {
	long long input, finalCount = 0;
	long double mean = 0, median, mode=0, finalMin;
	int n;
	vector<long long>numList;
	cin >> n;
	for (int i = 0; i<n; ++i) {
		cin >> input;
		numList.push_back(input);
		mean += input;
		frequency[input]++;
	}
	// meaan calculation
	mean = mean / n;
	// median calculation
	sort(numList.begin(), numList.end());
	if (numList.size() % 2 == 0) {
		median = (numList[numList.size() / 2] + numList[(numList.size() / 2) - 1]) / 2;
	}
	else {
		median = numList[numList.size() / 2];
	}
	// mode calculation
	vector<long long>mostCommon;
	long long max = 0;
	for (int i = 1; i <= 100000; ++i) {
		if (frequency[i]>max) {
			max = frequency[i];
			mostCommon.clear();
			mostCommon.push_back(i);
		}
		else if (frequency[i] == max) {
			mostCommon.push_back(i);
		}
	}
	if (mostCommon.size() == 1) {
		mode = mostCommon[0];
	}
	else {
		for (int i = 0; i<mostCommon.size(); ++i) {
			mode += mostCommon[i];
		}
	}
	mode = mode / mostCommon.size();
	// finding the smallest between the 3
	if (mean <= mode) {
		if (mean <= median) {
			finalMin = mean;
		}
		else {
			finalMin = median;
		}
	}
	else if (mode <= median){
		finalMin = mode;
	}
    else{
        finalMin =median;
    }
	// finding the number of boxes that must be carried
	for (vector<long long>::iterator it = numList.begin(); it != numList.end(); ++it) {
		if (*it <= finalMin) {
			finalCount++;
		}
		else {
			break;
		}
	}
	cout << finalCount << endl;
	return 0;
}