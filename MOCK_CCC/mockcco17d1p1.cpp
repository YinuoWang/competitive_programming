#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n, level = 0, prevLevel = 0, maxCard = 0, cardCount = 0;
priority_queue< int, vector<int>, greater<int> >pq;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	vector<int>nums(n);
	for (int i = 0, input; i<n; ++i) {
		cin >> input;
		nums[i] = input;
	}
	pq.push(nums[0]);
	while (level<n) {
		prevLevel = level;
		while (!pq.empty()) {
			if (maxCard >= pq.top()) {
				pq.pop();
				continue;
			}
			maxCard = pq.top();
			level += maxCard;
			pq.pop();
			cardCount++;
            break;
		}
		if (pq.empty() && level == prevLevel) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = prevLevel + 1; i <= level && i<n; ++i) {
			pq.push(nums[i]);
		}   
	}
	cout << cardCount << endl;
	return 0;
}