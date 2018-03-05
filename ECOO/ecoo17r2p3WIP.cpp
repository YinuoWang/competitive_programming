#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int testCases = 10;

bool cmp(pair<long long,int>a, pair<long long,int>b){
    if (a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main(){
    while(testCases-->0){
        long long n, m, k;
        cin >> n >> m >> k;
        vector<pair<long long,int>>ratings(n);
        for (int i=0; i<n; ++i){
            long long currentRating;
            cin >> currentRating;
            ratings[i].first = currentRating;
            ratings[i].second = i+1;
        }
        sort(ratings.begin(), ratings.end(), cmp);
        for (int i=1; i<=n; ++i){

        }
        // change vector such that each one is within one m from each other, subtract that from k
            // think of efficient way to do this
            // need to account for when k reaches 0 inside that loop
        // do k mod n, whatever the result is the restaurant #
    }
    
}