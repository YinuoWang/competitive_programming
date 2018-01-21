#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

struct coord{
	int x, y, dist;
	coord(int a, int b, int c){
		x = a, y = b, dist = c;
	}
};

int main(){
	int t; 
	int navX[4] = {1,-1,0,0}, navY[4] = {0,0,1,-1};
	cin >> t;
	while (t--){
		char diagram[51][51];
		bool vis[51][51];
		int l, w;
		string line;
		queue<coord> q;

		memset(diagram, 0, sizeof(diagram));
		memset(vis, false, sizeof(vis));

		cin >> l >> w;
		
		for (int i=0; i<w; ++i){
			cin >> line;
			for (int k=0; k<l; ++k){
				diagram[k][i]=line[k];
				if (diagram[k][i]=='C'){
					q.push(coord(k,i,0));
				}
			}
		}
		bool notWorth = true;
		while(!q.empty()){
			int currentX = q.front().x;
			int currentY = q.front().y;
			int currentDist = q.front().dist;
			q.pop();

			if (diagram[currentX][currentY]=='X'){
				continue;
			}
			if (diagram[currentX][currentY]=='W'){
				if (currentDist<60){
					notWorth = false;
					cout << currentDist << endl;
				}
				break;
			}
			for (int i=0; i<4; ++i){
				int cx = currentX + navX[i], cy = currentY + navY[i];
				if (cx < 0 || cx >= l || cy <0 || cy >= w){
					continue;
				}
				if (diagram[cx][cy]=='X' || vis[cx][cy]==true){
					continue;
				}
				q.push(coord(cx,cy, currentDist+1));
				vis[cx][cy]=true;
			}


		}
		if (notWorth){
			cout << "#notworth" << endl;
		}
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}