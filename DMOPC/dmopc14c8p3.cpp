#include <stdio.h>
#include <set>

using namespace std;

int main() {
	int total, left, right, input;
	set<int> nums;
	scanf("%d%d%d", &total, &left, &right);
	for (int i = 0; i<left; ++i) {
		scanf("%d", &input);
		nums.insert(input);
	}
	for (int i = 0; i<right; ++i) {
		scanf("%d", &input);
		nums.insert(input);
	}
	printf("%d", total - (left + right - nums.size()));
	return 0;
}
