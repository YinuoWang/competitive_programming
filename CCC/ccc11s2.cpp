#include <iostream>

using namespace std;

char answerKey[10001];

int main(){
    int N, ans=0;
    char answer;
    scanf("%i", &N);
    for (int i=0; i<N; ++i){
        scanf(" %c",&answerKey[i]);
    }
    for (int i=0; i<N; ++i){
        scanf(" %c",&answer);
        if (answerKey[i]==answer){
            ++ans;
        }
    }
    printf("%i\n", ans);
}