#include <iostream>
#include <string>

using namespace std;

int main(){
    long long n, debt=0, maxDebt=0, day=0;
    cin >> n;
    for (int i=1; i<=n; ++i){
        string input;
        long long amount;
        cin >> input >> amount;
        if (input=="borrow"){
            debt += amount;
        }
        else{
            debt -=amount;
        }
        if (debt>maxDebt){
            maxDebt = debt;
            day = i;
        }
    }
    cout << day << endl;
    return 0;
}