#include <iostream>

using namespace std;

char jerseys[1000001];
long a, j, ans;

int main(){
    scanf("%li%Li", &j, &a);
    char input;
    for (int i=1; i<=j; ++i){
        scanf(" %c",&input);
        switch(input){
            case 'S':
                jerseys[i]=1;
                break;
            case 'M':
                jerseys[i]=2;
                break;
            case 'L':
                jerseys[i]=3;
        }
    }
    char sWant_char;
    long nWant, sWant_long;
    for (int i=0; i<=a; ++i){
        scanf(" %c%li", &sWant_char, &nWant);
        switch(sWant_char){
            case 'S':
                sWant_long=1;
                break;
            case 'M':
                sWant_long=2;
                break;
            case 'L':
                sWant_long=3;
        }
        if (jerseys[nWant]>=sWant_long){
            ans++;
            jerseys[nWant]=0;
        }
    }
    printf("%li\n", ans);
}