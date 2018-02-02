#include <iostream>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        bool flag = false;
        int years, months, days;
        scanf("%d%d%d", &years, &months, &days);
        if (2007-years>18){
            flag = true;
        }
        else if (2007-years==18){
            if (months==1){
                flag = true;
            }
            else if (months == 2){
                if (days<=27){
                    flag = true;
                }
            }
        }
        if (flag){
            printf("%s", "Yes\n");
        }
        else{
            printf("%s", "No\n");
        }
    }
    return 0;
}