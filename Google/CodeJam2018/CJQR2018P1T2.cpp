#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long calcDmg(string s){
    long long total=0, counter=1;
    for (int i=0; i<s.length(); ++i){
        if (s[i]=='S'){
            total+=counter;
        }
        else{
            counter*=2;
        }
    }
    return total;
}

int main() {
	int testCases;  
	cin >> testCases;
	for (int k=1; k<=testCases; ++k) {
		string P;
		long long D, swaps = 0;
		cin >> D >> P;
        bool flag = true;
        cout << "Case #" << k << ": ";
        while(flag){
            bool noChain = true, noSol = true;
            for (int i=P.length()-1; i>0; --i){
                if (P[i]=='C'){
                    if (!noChain){
                        P[i+1] = 'C';
                        P[i] = 'S';
                        swaps++;
                        noSol = false;
                        break;
                    }
                }
                else{
                    noChain = false;
                }
            }
            if (noSol && calcDmg(P) > D){
                cout << "IMPOSSIBLE" << endl;
                break;
            }
            else if (calcDmg(P)<=D){
                cout << swaps << endl;
                break;
            }
        }
	}
	return 0;
}