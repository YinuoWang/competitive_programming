#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    char output[testCases];
    for (int i=0; i<testCases; i++){
        long N, input, count=1;
        cin >> N;
        deque<long> mountain;
        deque<long> branch;
        for (int i=0; i<N; i++){
            scanf("%li",&input);
            mountain.push_front(input);
        }
        for (deque<long>::iterator it=mountain.begin(); it!=mountain.end(); ++it){
            if (*it==count){
                count++;
            }
            else if (branch.empty()==true){
                branch.push_front(*it);
            }
            else if (*branch.begin()==count){
                branch.pop_front();
                count++;
                --it;
            }
            else{
                branch.push_front(*it);
            }
        }
        for (deque<long>::iterator itr=branch.begin(); itr!=branch.end(); ++itr){
            if (*itr==count){
                count++;
                branch.pop_front();
            }
            else{
                break;
            }
        }
        if (branch.empty()==true){
            output[i]='Y';
        }
        else {
            output[i]='N';
        }
    }
    for (int i=0; i<testCases; i++){
        cout << output[i] << endl;
    }
    return 0;
}