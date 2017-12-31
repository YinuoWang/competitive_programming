#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	long long r, c, minSide, maxSide;
    long double k;
	cin >> r >> c >> k;
	if (sqrt(k) > r || sqrt(k) > c) {
        minSide = min(r, c);
		maxSide = ceil(k / minSide);
	}
	else {
		if (ceil(sqrt(k))*floor(sqrt(k))>=k){
            maxSide = ceil(sqrt(k));
            minSide = floor(sqrt(k));
        }
        else{
            minSide = ceil(sqrt(k));
            maxSide = minSide;
        }
	}
    cout << 2 * minSide + 2 * maxSide << endl;
	return 0;
}