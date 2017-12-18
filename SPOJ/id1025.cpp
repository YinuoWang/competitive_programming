#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(){
    int cases, N,input;
    long total;
    vector<long>answers;
    vector<int>men;
    vector<int>women;
    cin >> cases;
    for (int i=0; i<cases; ++i){
        cin >> N;
        for (int k=0; k<N; ++k){
            cin >> input;
            men.push_back(input);
        }
        for (int k=0; k<N; ++k){
            cin >> input;
            women.push_back(input);
        }
        sort(men.begin(), men.end());
        sort(women.begin(), women.end());
        vector<int>::iterator it1 = men.begin();
        total = 0;
        for (vector<int>::iterator it2 = women.begin(); it2!=women.end(); ++it2){
            total += (*it1)*(*it2);
            ++it1;
        }
        answers.push_back(total);
        men.clear();
        women.clear();
    }
    for (vector<long>::iterator it=answers.begin(); it!=answers.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}