#include <iostream>
#include <algorithm>

using namespace std;

int lengths[2001];
int sums[4001];

int main(){
    long long N, input;
    scanf("%lli",&N);
    for (int i=1; i<=N; ++i){
        scanf("%lli", &input);
        lengths[input]++;
    }
    for (int i=1; i<=2000; i++){
        if (lengths[i]!=0){
            for (int k=i; k<=2000; ++k){
                if (lengths[k]!=0){
                    if (i==k){
                        sums[i+k] += lengths[i]/2;
                    }
                    else{
                        sums[i+k] += min(lengths[k],lengths[i]);
                    }
                }
            }
        }
    }
    long fence=0, ways=0;
    for (int i=1; i<4001; ++i){
        if (sums[i]>fence){
            ways = 1;
            fence = sums[i];
        }
        else if (sums[i]==fence){
            ways++;
        }
    }
    printf("%li %li", fence, ways);
    return 0;
}