#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    double ratio = 1000001;
    string answer = "yes";
    cin >> n;
    for (int i=0; i<n; ++i){
        double x, tx;
        cin >> x >> tx;
        if (x==0){
            if (tx==0){
                continue;
            }
            else{
                answer = "no";
                break;
            }   
        }
        if (ratio == 1000001){
            ratio = tx/x;
        }
        else if (tx/x != ratio){
            answer = "no";
            break;
        }
    }
    cout << answer << endl;
    return 0;
}