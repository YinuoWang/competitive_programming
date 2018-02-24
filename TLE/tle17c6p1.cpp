#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int table[26];

int main(){
    int length, maxCount = -1;
    string molecules;
    cin >> length >> molecules;
    for (int i=0; i<length; ++i){
        int c = molecules[i] - 97;
        table[c]++;
    }
    for (int i=0; i<26; ++i){
        maxCount = max(maxCount, table[i]);
    }
    if (length<2*maxCount || length%2 ==1 ){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;
}