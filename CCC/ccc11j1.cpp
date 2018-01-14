#include <stdio.h>

using namespace std;

int main(){
    int a, e;
    scanf("%d%d",&a,&e);
    if (a>=3 && e<=4){
        printf("%s\n", "TroyMartian");
    }
    if (a<=6 && e>=2){
        printf("%s\n", "VladSaturnian");
    }
    if (a<=2 && e<=3){
        printf("%s\n", "GraemeMercurian");
    }
    return 0;
}