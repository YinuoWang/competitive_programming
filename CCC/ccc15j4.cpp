#include <iostream>

using namespace std;

int receiveTime[101];
int answer[101];
int needReply[101];

int main() {
	fill_n(receiveTime, 101, -1);
	fill_n(answer, 101, 0);
	fill_n(answer, 100, 0);
	int N;
	cin >> N;
	int currentTime = 0;
	for (int i = 0; i<N; ++i) {
		char type;
		cin >> type;
		int friendNum;
		if (type == 'R') {
			cin >> friendNum;
			if (receiveTime[friendNum] != -1) {
				needReply[friendNum] = 1;
			}
			receiveTime[friendNum] = currentTime;
			currentTime++;
		}
		else if (type == 'S') {
			cin >> friendNum;
			answer[friendNum] += currentTime - receiveTime[friendNum];
			needReply[friendNum] = 0;
			currentTime++;
		}
		else {
			int waitTime;
			cin >> waitTime;
			currentTime += waitTime - 1;
		}
	}
	for (int i = 0; i<101; ++i) {
		if (receiveTime[i] != -1) {
			if (answer[i] != 0 && needReply[i] != 1) {
				cout << i << ' ' << answer[i] << endl;
			}
			else {
				cout << i << ' ' << -1 << endl;
			}
		}
	}
	return 0;
}