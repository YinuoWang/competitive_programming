#include <iostream>
#include <vector>

using namespace std;

int main(){
    int squares;
    long answer;
    vector<long> output;
    cin >> squares;
    while(squares!=0){
        answer =0;
        for (int k=squares; k>=1; --k){
            answer+= k*k;
        }
        output.push_back(answer);
        cin >> squares;
    }
    for (vector<long>::iterator it=output.begin(); it!=output.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}