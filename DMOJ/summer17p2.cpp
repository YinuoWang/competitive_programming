#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N, sum=0;
    string input;
    int arrayx[6] = {0,0,0,0,0,0};
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> input;
        if (input=="red"){
            arrayx[0]++;
        }
        else if (input=="orange"){
            arrayx[1]++;
        }
        else if (input=="yellow"){
            arrayx[2]++;
        }
        else if (input=="green"){
            arrayx[3]++;
        }
        else if (input=="blue"){
            arrayx[4]++;
        }
        else if (input=="black"){
            arrayx[5]++;
        }
    }
    sort(arrayx, arrayx+6);

    for (int i=0; i<5; i++){
        sum+=arrayx[i];
    }
    if (sum>=arrayx[5]){
        cout << sum+arrayx[5];
    }
    else {
        cout << sum*2+1;
    }
}