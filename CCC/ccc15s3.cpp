#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int g, p;
    set<int> gates;
    bool flag = true;
    scanf("%d%d", &g, &p);
    for (int i=1; i<=g; ++i){
        gates.insert(-1*i);
    }
    int plane;
    for (int i=0; i<p; ++i){
        scanf("%d", &plane);
        if (gates.lower_bound(-1*plane)==gates.end()){
            printf("%d\n", i);
            flag = false;
            break;
        }
        gates.erase(gates.lower_bound(-1*plane));
    }
    if (flag){
        printf("%d\n", p);
    }
    return 0;
}