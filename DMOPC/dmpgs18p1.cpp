#include <iostream>
#include <string>

using namespace std;

string input;
int numInput[100000];

bool validate(int length) {
	int zeroCount = 0, zeroIndex = -1;
	bool flag = false;
	for (int i = 0; i<length; ++i) {
		if (numInput[i] == 0) {
			if (i == 0) {
				break;
			}
			zeroCount++;
			numInput[i] = -1;
			if (zeroIndex==-1){
				zeroIndex = i - 1;
			}
		}
		else if (numInput[i]!=-1){
			if (zeroCount>0) {
				if (zeroCount > numInput[zeroIndex]) {
					break;
				}
				numInput[zeroIndex] -= zeroCount;
				flag = true;
				zeroCount = 0;
				zeroIndex = -1;
			}
		}
	}
	if (zeroCount>0 && numInput[zeroIndex]>= zeroCount) {
		if (numInput[zeroIndex] == 1) {
			while (zeroIndex >= 0 && numInput[zeroIndex] == 1) {
				numInput[zeroIndex] = -1;
				zeroIndex--;
			}
		}
		else {
			numInput[zeroIndex] -= zeroCount;
		}
		flag = true;
	}
	return flag;
}

int main() {
	string output;
	cin >> input;
	for (int i = 0; i < input.length(); ++i) {
		numInput[i] = input[i] - '0';
	}
	while(validate(input.length()));
	if (numInput[0] == 0 || numInput[0]==-1) {
		output = "Valid";
	}
	for (int i = 1; i<input.length(); ++i) {
		if (numInput[i] != -1) {
			output = "Invalid";
		}
	}
	cout << output << endl;
	return 0;
}