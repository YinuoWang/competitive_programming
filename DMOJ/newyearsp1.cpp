#include <iostream>
#include <string>

using namespace std;

int main(){
    long long h,m,s;
    string hAns, mAns, sAns;
    int carryOver = 0;
    cin >> h >> m >> s;
    m+=s/60;
    s=s%60;
    h+=m/60;
    m=m%60;
    h=h%12;
    if (s==0){
        sAns="00"; 
    }
    else if (60-s<10){
        sAns = to_string(60-s);
        sAns = '0' + sAns;
        carryOver = 1;
    }
    else{
        sAns = to_string(60-s);
        carryOver = 1;
    }
    if (m==0 && carryOver ==0){
        mAns = "00";
        carryOver = 0;
    }
    else if (60-m-carryOver<10){
        mAns = to_string(60-m-carryOver);
        mAns = '0' + mAns; 
        carryOver = 1;
    }
    else{
        mAns = to_string(60-m-carryOver);
        carryOver = 1;
    }
    if (h==0 && carryOver ==0){
        hAns = "12";
    }
    else if (12-h-carryOver<10){
        hAns = to_string(12-h-carryOver);
        hAns = '0' + hAns;
    }
    else{
        hAns = to_string(12-h-carryOver);
    }
    cout << hAns << ':' << mAns << ':' << sAns << endl;
    return 0;
}