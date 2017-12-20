#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
	
using namespace std;

long long N, biggest=1, bigger=1;
long acid_levels[1002];
int ans1, ans2;

int main() {
	scanf("%lli", &N);
	int input;
	for (int i = 0; i < N; ++i) {
		scanf("%i", &input);
		++acid_levels[input];
	}
	vector<long> biggest_vector;
	vector<long> bigger_vector;
	for (int i = 1; i <= 1000; ++i) {
		if (acid_levels[i] > biggest) {
			if (biggest > bigger) {
				bigger = biggest;
				bigger_vector.clear();
				for (vector<long>::iterator it = biggest_vector.begin(); it != biggest_vector.end(); ++it) {
					bigger_vector.push_back(*it);
				}
			}
			else if (biggest == bigger) {
				for (vector<long>::iterator it = biggest_vector.begin(); it != biggest_vector.end(); ++it) {
					bigger_vector.push_back(*it);
				}
			}
			biggest_vector.clear();
			biggest_vector.push_back(i);
			biggest = acid_levels[i];
		}
		else if (acid_levels[i] == biggest) {
			biggest_vector.push_back(i);
		}
		else if (acid_levels[i] > bigger) {
			bigger_vector.clear();
			bigger_vector.push_back(i);
			bigger = acid_levels[i];
		}
		else if (acid_levels[i] == bigger && bigger!=0) {
			bigger_vector.push_back(i);
		}
	}
	if (bigger_vector.empty() == true) {
		sort(biggest_vector.begin(), biggest_vector.end());
		cout << abs(*biggest_vector.begin() - *(biggest_vector.end() - 1)) << endl;
	}
	else if (bigger_vector.size() == 1 && biggest_vector.size() == 1) {
		cout << abs(*bigger_vector.begin() - *biggest_vector.begin()) << endl;
	}
	else if (biggest_vector.size() > 1) {
		sort(biggest_vector.begin(), biggest_vector.end());
		cout << abs(*biggest_vector.begin() - *(biggest_vector.end() - 1)) << endl;
	}
	else {
		sort(bigger_vector.begin(), bigger_vector.end());
		ans1 = abs(*biggest_vector.begin() - *bigger_vector.begin());
		ans2 = abs(*biggest_vector.begin() - *(bigger_vector.end() - 1));
		cout << max(ans1, ans2) << endl;
	}	
	return 0;
}