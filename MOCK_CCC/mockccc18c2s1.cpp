#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long n, sumToSecondLast=0;
    vector<long long> myVec;
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        long long input;
        scanf("%lli", &input);
        myVec.push_back(input);
    }
    sort(myVec.begin(), myVec.end());
    for (int i=0; i<n-1; ++i){
        sumToSecondLast+=myVec[i];
    }
    if (sumToSecondLast<myVec[n-1]){
        printf("%lli", sumToSecondLast);
    }
    else{
        printf("%lli", (sumToSecondLast+myVec[n-1])/2);
    }
    return 0;
}