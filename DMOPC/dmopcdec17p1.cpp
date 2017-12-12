#include <iostream>

using namespace std;

int main(){
    long long N, current, ans=10000000;
    scanf("%lli", &N);
    for (int i=0; i<N; ++i){
        scanf("%lli", &current);
        if (current<ans){
            ans=current;
        }
    }
    cout << ans;
    return 0;
}