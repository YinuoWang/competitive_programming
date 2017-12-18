#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    long N,input,sum,movement;
    double average;
    cin >> N;
    vector<long>check;
    vector<long>answers;
    while (N!=-1){
        sum=0;
        average=0;
        for (int i=0; i<N; ++i){
            cin >> input;
            sum+=input;
            check.push_back(input);
        }
        if (sum%N==0){
            movement = 0;
            average = sum / N;
            for (vector<long>::iterator it=check.begin(); it!= check.end(); ++it){
                movement+= abs(*it-average);
            }
            answers.push_back(movement/2);
        }
        else{
            answers.push_back(-1);
        }
        check.clear();
        cin >> N;
    }
    for (vector<long>::iterator it=answers.begin(); it!=answers.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}