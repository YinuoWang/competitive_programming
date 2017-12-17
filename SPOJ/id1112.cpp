#include <iostream>
#include<string>
#include <vector>

using namespace std;

int main(){
    int N, x,y;
    vector<string> output;
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> x;
        cin >> y;
        if (x==y){
            if (x%2==0){
                output.push_back(to_string(2*x));
            }
            else{
                output.push_back(to_string(2*x-1));
            }
        }
        else if (x==(y+2)){
            if (x%2==0){
                output.push_back(to_string(2*x-2));
            }
            else {
                output.push_back(to_string(2*x-3));
            }
        }
        else{
            output.push_back("No Number");
        }
    }
    for (vector<string>::iterator it=output.begin(); it!=output.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}