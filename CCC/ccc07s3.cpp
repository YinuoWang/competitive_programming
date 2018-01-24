#include <iostream>
#include <string.h>

using namespace std;

int friendArr[10000], n, cycleStart, counter, separation;
bool vis[10000], isCyclic;

void search(int start, int end){
    if (start==cycleStart){
        isCyclic = true;
    }
    vis[start]=true;
    counter++;
    if(start==end){
        separation = counter;
    }
    if (vis[friendArr[start]]==false){
        search(friendArr[start], end);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; ++i){
        int friend1, friend2;
        scanf("%d%d",&friend1, &friend2);
        friendArr[friend1]=friend2;
    }
    while(true){
        int qStart, qEnd;
        scanf("%d%d", &qStart, &qEnd);
        if (qStart == 0 && qEnd == 0){
            break;
        }
        memset(vis, false, sizeof(vis));
        counter = 0;
        separation = -1;
        isCyclic = false;
        cycleStart = qStart;
        search(qStart, qEnd);
        if (separation != -1 && isCyclic){
            printf("%s%d\n", "Yes ", separation-2);
        }
        else{
            printf("%s\n", "No");
        }
    }
    return 0;
}