#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int distanceSquared(int x1, int x2, int y1, int y2){
    return pow(x1-x2,2) + pow(y1-y2,2);
}

int main(){
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << min(distanceSquared(x3,x2,y3,y2),min(distanceSquared(x1,x2,y1,y2), distanceSquared(x1,x3,y1,y3)));
    return 0;
}