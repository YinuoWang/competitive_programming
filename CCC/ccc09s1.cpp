#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long long a,b;
    cin >> a >> b;
    set<long double> squares;
    for (long double i=1; i<=pow(10.0,4.0); ++i){
        squares.insert(pow(i,2.0));
    }
    set<long double> cubes;
    for (long double i=1; i<465; ++i){
        cubes.insert(pow(i,3.0));
    }
    vector<long double>common;
    for (set<long double>::iterator it=cubes.begin(); it!=cubes.end(); ++it){
        bool is_in = squares.find(*it) !=squares.end();
        if (is_in){
            common.push_back(*it);
        }
    }
    int ans =0;
    for (vector<long double>::iterator it=common.begin(); it!=common.end(); ++it){
        if (*it>=a && *it<=b){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}