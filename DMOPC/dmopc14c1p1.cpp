#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	vector<int> marks;
	int count, current;
	scanf("%i", &count);
	for (int i = 0; i<count; ++i) {
		scanf("%i", &current);
		marks.push_back(current);
	}
	sort(marks.begin(), marks.end());
	if (marks.size() % 2 != 0) {
		printf("%i\n", marks[marks.size() / 2]);
	}
	else {
		double ans = (marks[marks.size() / 2] + marks[(marks.size() / 2) - 1]) / 2.0;
		ans = round(ans);
		printf("%g\n", ans);
	}
	return 0;
}