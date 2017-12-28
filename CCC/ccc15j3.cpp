#include <iostream>
#include <string>
#include <cmath>

using namespace std;

char nearVowel(char a);
char nearCons(char a);

const string VOWELS = "aeiou";
const string CONS = "bcdfghjklmnpqrstvwxyz";

int main() {
	string input, answer = "";
	cin >> input;
	for (int i = 0; i<input.length(); ++i) {
		answer = answer + input[i];
		if (VOWELS.find(input[i]) == string::npos) {
			answer = answer + nearVowel(input[i]);
			answer = answer + nearCons(input[i]);
		}
	}
	cout << answer << endl;
	return 0;
}

char nearVowel(char a) {
	int min = int(a) - int('a');
	char ans = 'a';
	for (int i = 1; i<5; ++i) {
		if (abs(int(a) - int(VOWELS[i]))<min) {
			min = abs(int(a) - int(VOWELS[i]));
			ans = VOWELS[i];
		}
	}
	return ans;
}

char nearCons(char a) {
	if (a == 'z') {
		return 'z';
	}
	else {
		size_t found = CONS.find(a);
		return CONS[found + 1];
	}
}