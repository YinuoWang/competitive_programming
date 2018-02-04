#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double B;
    cin >> B;
    cout << setprecision(2) << fixed;
    cout << "$" << B/2 << " $" << B/2;
    return 0;
}