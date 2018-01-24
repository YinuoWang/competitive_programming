#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> friendGraph[50];

void bfs(int start, int levels[]) {
	for (int i = 0; i < 50; ++i) {
		levels[i] = 0;
	}
	queue<int>q;
	bool vis[50];
	memset(vis, false, sizeof(vis));
	levels[start] = 0;
	vis[start] = true;
	q.push(start);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i<friendGraph[k].size(); ++i) {
			if (vis[friendGraph[k][i]] == false) {
				vis[friendGraph[k][i]] = true;
				q.push(friendGraph[k][i]);
				levels[friendGraph[k][i]] = levels[k] + 1;
			}
		}
	}
}

int main() {
	memset(friendGraph, false, sizeof(friendGraph));
	friendGraph[1] = { 6 };
	friendGraph[2] = { 6 };
	friendGraph[3] = { 6,4,5,15 };
	friendGraph[4] = { 3,5,6 };
	friendGraph[5] = { 4,3,6 };
	friendGraph[6] = { 1,2,3,4,5,7 };
	friendGraph[7] = { 6,8 };
	friendGraph[8] = { 7,9 };
	friendGraph[9] = { 8,10,12 };
	friendGraph[10] = { 9,11 };
	friendGraph[11] = { 10,12 };
	friendGraph[12] = { 9,11,13 };
	friendGraph[13] = { 12,14,15 };
	friendGraph[14] = { 13 };
	friendGraph[15] = { 3,13 };
	friendGraph[16] = { 17,18 };
	friendGraph[17] = { 16,18 };
	friendGraph[18] = { 16,17 };
	while (true) {
		char instruction;
		scanf("%c", &instruction);
		if (instruction == 'q') {
			break;
		}
		else if (instruction == 'i') {
			int x, y;
			scanf("%d%d", &x, &y);
			friendGraph[x].push_back(y);
			friendGraph[y].push_back(x);
		}
		else if (instruction == 'd') {
			int x, y;
			scanf("%d%d", &x, &y);
			friendGraph[x].erase(find(friendGraph[x].begin(), friendGraph[x].end(), y));
			friendGraph[y].erase(find(friendGraph[y].begin(), friendGraph[y].end(), x));
		}
		else if (instruction == 'n') {
			int x;
			scanf("%d", &x);
			printf("%d\n", friendGraph[x].size());
		}
		else if (instruction == 'f') {
			int x, count = 0, lvl[50];
			scanf("%d", &x);
			bfs(x, lvl);
			for (int i = 0; i<50; ++i) {
				if (lvl[i] == 2) {
					count++;
				}
			}
			printf("%d\n", count);
		}
		else if (instruction == 's') {
			int x, y, lvl[50];
			scanf("%d%d", &x, &y);
			bfs(x, lvl);
            if (lvl[y]!=0){
			    printf("%d\n", lvl[y]);
            }
            else{
                printf("Not connected\n");
            }
		}
    }
	return 0;
}