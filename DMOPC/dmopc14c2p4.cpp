#include <iostream>

using namespace std;

int masses[1000001];
long long answers[1000001];

int main(){
    long long N,Q;
    scanf("%lli", &N);
    for (int i=0; i<N; ++i){
        scanf("%i", &masses[i]);
    }
    long long sum=0;
    for (int i=0; i<N; ++i){
        answers[i]=sum;
        sum+=masses[i];
    }
    long long i1,i2;
    scanf("%lli", &Q);
    for (int i=0; i<Q; ++i){
        scanf("%lli %lli", &i1, &i2);
        printf("%lli\n", answers[i2]-answers[i1]+masses[i2]);
    }
    return 0;
}