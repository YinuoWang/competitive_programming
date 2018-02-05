#include <iostream>
#include <string.h>

bool cats[26][26];
int ways[26][26], r, c;

using namespace std;

int main(){
    cin >> r >> c;
    memset(cats, false, sizeof(cats));
    int k;
    cin >> k;
    for (int i=0, a, b; i<k; ++i){
        cin >> a >> b;
        cats[a][b] = true;
    }
    memset(ways, 0, sizeof(ways));
    ways[1][1] = 1;
    for (int x=1; x<=r; ++x){
        for (int y=1; y<=c; ++y){
            if (!cats[x][y]){
                if (cats[x-1][y]==false && x!=1){
                    ways[x][y]+= ways[x-1][y];
                }
                if (cats[x][y-1]==false && y!=1){
                    ways[x][y]+= ways[x][y-1];
                }
            }
        }
    }
    cout << ways[r][c] << endl;
    return 0;
}