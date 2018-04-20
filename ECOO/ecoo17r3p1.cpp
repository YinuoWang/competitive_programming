#include <iostream>
#include <string.h>

using namespace std;

int testCases = 10, days[4726], franchises[131];

int main(){
    while(testCases--){
        memset(days, 0, sizeof(days));
        memset(franchises, 0, sizeof(franchises));
        int dozens = 0, f, d;
        cin >> f >> d;
        for (int i=1; i<=d; ++i){
            int currentDay = 0;
            for (int k=1; k<=f; ++k){
                int input;
                cin >> input;
                franchises[k]+=input;
                currentDay+=input;
            }
            days[i] = currentDay;
        }
        for (int i=1; i<=d; ++i){
            if (days[i]%13==0){
                dozens+=days[i]/13;
            }
        }
        for (int i=1; i<=f; ++i){
            if (franchises[i]%13==0){
                dozens+=franchises[i]/13;
            }
        }
        cout << dozens << endl;
    }
    return 0;
}