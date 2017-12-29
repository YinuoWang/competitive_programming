#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long long n, input, trips = 0;
	vector<long long> microwaves;
	vector<long long> trucks;
	cin >> n;
	for (int i = 0; i<3; ++i) {
		cin >> input;
		microwaves.push_back(input);
	}
	for (int i = 0; i<3; ++i) {
		cin >> input;
		trucks.push_back(input);
	}
	sort(microwaves.begin(), microwaves.end());
	sort(trucks.begin(), trucks.end());
	for (int i = 0; i<3; ++i) {
		if (microwaves[i]>trucks[i]) {
			cout << "SCAMMED" << endl;
			return 0;
		}
	}
	vector<long long> products;
	products.push_back((trucks[0] / microwaves[0])*(trucks[1] / microwaves[1])*(trucks[2] / microwaves[2]));
	products.push_back((trucks[0] / microwaves[0])*(trucks[2] / microwaves[1])*(trucks[1] / microwaves[2]));
	products.push_back((trucks[1] / microwaves[0])*(trucks[0] / microwaves[1])*(trucks[2] / microwaves[2]));
	products.push_back((trucks[1] / microwaves[0])*(trucks[2] / microwaves[1])*(trucks[0] / microwaves[2]));
	products.push_back((trucks[2] / microwaves[0])*(trucks[0] / microwaves[1])*(trucks[1] / microwaves[2]));
	products.push_back((trucks[2] / microwaves[0])*(trucks[1] / microwaves[1])*(trucks[0] / microwaves[2]));
	sort(products.begin(), products.end());
	while (n>0) {		
		n -= products[5];
		trips++;
	}
	cout << trips << endl;
	return 0;
}