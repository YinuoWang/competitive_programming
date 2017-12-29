#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int N, input;
    long total=0;
    vector<int> energy;
    vector<int> lengths;
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> input;
        energy.push_back(input);
    }
    for (int i=0; i<N; i++){
        cin >> input;
        lengths.push_back(input);
    }
    sort(energy.begin(), energy.end());
    sort(lengths.begin(), lengths.end(), greater<int>());

    for (int i=0; i<N; i++){
        total+=energy[i]*lengths[i];
    }
    cout << total;
    return 0;
}