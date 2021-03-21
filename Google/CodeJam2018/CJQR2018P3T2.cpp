#include <iostream>
#include <string.h>

using namespace std;

bool grid[5][100];
int navX[9] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int navY[9] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

bool check(int x, int y, int index){
    if (grid[x+navX[index]][y+navY[index]]==false){
         return false;
    }
    return true;
}

void guess(int x, int y){
    int a, b;
    for (int i=0; i<9; ++i){
        cout << x << ' ' << y << endl;
        cin >> a >> b;
        if (a == 0 && b == 0){
            return;
        }
        grid[a][b] = true;
        if (!check(x,y,i)){
            --i;
        }
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int testCases;
    cin >> testCases;
    for (int t = 0; t<testCases; ++t){
        memset(grid, false, sizeof(grid));
        int a, squaresGuessed = 0;
        cin >> a;
        while(squaresGuessed < a/9 + 1){
            guess(2, 2+3*squaresGuessed);
            squaresGuessed++;
        }
    }
    return 0;
}