#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int letterCount[26];

int main(){
    memset(letterCount, 0, sizeof(letterCount));
    string input;
    cin >> input;
    for (int i=0; i<input.length(); ++i){
        letterCount[ALPHABET.find(input[i])]++;
    }
    int sum = 0, big1 = -1, big2=-1;
    for (int i=0; i<26; ++i){
        if (letterCount[i]>big1){
            big2 = big1;
            big1 = letterCount[i];
        }
        else if (letterCount[i]>big2){
            big2 = letterCount[i];
        }
        sum+=letterCount[i];
    }
    cout << sum-big1-big2 << endl;
    return 0;
}