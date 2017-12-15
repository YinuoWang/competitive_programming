#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

bool isPrime(long long input);

int main(){
    cin >> N;
    long long num1, num2;
    vector<long long> output;
    for (int i=0; i<N; ++i){
        cin >> num1 >> num2;
        for (int k=num1; k<=num2; ++k){
            if(isPrime(k)){
                output.push_back(k);
            }
        }
        output.push_back(0);
    }
    output.pop_back();
    for (vector<long long>::iterator it=output.begin(); it!=output.end(); ++it){
        if (*it!=0 && *it!=1){
            cout << *it << endl;
        }
        else if (*it==0){
            cout << endl;
        }
    }
    return 0;
}

bool isPrime(long long input){
    bool output = true;
    for (int i=2; i<=sqrt(input); ++i){
        if (input%i==0){
            return false;
        }
    }
    return output;
}