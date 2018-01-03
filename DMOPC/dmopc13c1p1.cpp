#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>

using namespace std;


int main() {
	vector<tuple<long long, long long, string>> myVec;
	long long useless, m, creator, share, myNum;
	string title;
	scanf("%lli%lli", &useless, &m);
	for (int i = 0; i<m; ++i) {
		scanf("%lli%lli\n", &creator, &share);
		getline(cin, title);
		myVec.push_back(make_tuple(creator, share, title));
	}
	scanf("%lli", &myNum);
	for (auto it = myVec.begin(); it != myVec.end(); ++it) {
		if (get<1>(*it) == myNum) {
			printf("%s\n", get<2>(*it).c_str());
		}
	}
	return 0;
}