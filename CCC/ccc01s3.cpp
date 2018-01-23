#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <utility>

using namespace std;

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<int>adj[26];
bool vis[26], flag = false;

void dfs(int src) {
	if (src == 1) {
		flag = true;
	}
	vis[src] = true;
	for (int i = 0; i<adj[src].size(); ++i) {
		if (vis[adj[src][i]] == false) {
			dfs(adj[src][i]);
		}
	}
}

int main() {
	vector<string> inputs;
	while (true) {
		string input;
		cin >> input;
		if (input == "**") {
			break;
		}
		inputs.push_back(input);
		int i1, i2;
		i1 = LETTERS.find(input[0]);
		i2 = LETTERS.find(input[1]);
		adj[i1].push_back(i2);
		adj[i2].push_back(i1);
	}
	int count = 0;
	memset(vis, false, sizeof(vis));
	for (auto it = inputs.begin(); it != inputs.end(); ++it) {
		int n1, n2;
		n1 = LETTERS.find((*it)[0]);
		n2 = LETTERS.find((*it)[1]);
		adj[n1].erase(find(adj[n1].begin(), adj[n1].end(), n2));
		adj[n2].erase(find(adj[n2].begin(), adj[n2].end(), n1));
		dfs(0);
		if (flag == false) {
			cout << *it << endl;
			count++;
		}
		else {
			flag = false;
		}
		memset(vis, false, sizeof(vis));
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}
	cout << "There are " << count << " disconnecting roads." << endl;
	return 0;
}
