#include <iostream>

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n%m == 0) {
		printf("%s %d", "yes", n / m);
	}
	else {
		int x=m+1, increases=1;
		while (n%x != 0) {
			++x;
			++increases;
		}
		printf("%s %d", "no", increases);
	}
	return 0;
}