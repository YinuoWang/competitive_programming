#include <iostream>
#include <string>

using namespace std;

int N;
long sCount=0, tCount=0;

int main(){
    scanf("%i", &N);
    cin.ignore();
    string input1;
    for (int p=0; p<N; ++p){
        getline(cin, input1);
        for (int i=0; i<input1.length(); ++i){
            if (input1.at(i)=='s' || input1[i]=='S'){
                ++sCount;
            }
            else if (input1[i]=='t' || input1[i]=='T'){
                ++tCount;
            }
        }
    }
    if (tCount>sCount){
        cout << "English";
    }
    else {
        cout << "French";
    }
    return 0;
}