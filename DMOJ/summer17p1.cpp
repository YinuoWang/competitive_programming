#include <iostream>
#include <string>

using namespace std;

int main(){
    int N,count=0;
    string input;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> input;
        if (input.length()<=10){
            count++;
        }
    }
    cout << count;
    return 0;
}