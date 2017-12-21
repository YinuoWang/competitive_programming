#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    long N, correctNum;
    string n1, pSign, n2, eSign, n3, answer;
    vector <string> output;
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> n1 >> pSign >> n2 >> eSign >> n3;
        if (n1.find("machula")!=string::npos){
            correctNum = stoi(n3)-stoi(n2);
            answer = to_string(correctNum) + " + " + n2 + " = " + n3;
            output.push_back(answer);
        }
        else if (n2.find("machula")!=string::npos){
            correctNum = stoi(n3)-stoi(n1);
            answer = n1 + " + " + to_string(correctNum) + " = " + n3;
            output.push_back(answer);
        }
        else {
            correctNum = stoi(n2)+stoi(n1);
            answer = n1 + " + " + n2 + " = " + to_string(correctNum);
            output.push_back(answer);
        }
    } 
    for (vector<string>::iterator it = output.begin(); it!=output.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}