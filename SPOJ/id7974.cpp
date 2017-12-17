#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    long t1,t2,t3;
    vector <string> types;
    vector <long> answers;
    cin >> t1 >> t2 >> t3;
    while (!(t1==0 && t2==0 && t3==0)){
        if (t2-t1==t3-t2){
            types.push_back("AP");
            answers.push_back(t3+t2-t1);
        }
        else{
            types.push_back("GP");
            answers.push_back(t3*t2/t1);
        }
        cin >> t1 >> t2 >> t3;
    }
    vector<long>::iterator it2=answers.begin();
    for (vector<string>::iterator it=types.begin(); it!=types.end(); ++it){
        cout << *it << " " << *it2 << endl;
        ++it2;
    }
    return 0;
}