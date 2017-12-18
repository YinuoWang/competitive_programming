#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int columns;
    string message, answer, currentChunk;
    vector<string>output;
    vector<string>chunks;
    cin >> columns;
    int position;
    while (columns!=0){
        cin >> message;
        currentChunk = "";
        answer = "";
        position=0;
        for (int i=0; i<(message.length()/columns); ++i){
            for (int k=position; k<(position+columns); ++k){
                currentChunk = currentChunk + message.at(k);
            }
            chunks.push_back(currentChunk);
            currentChunk = "";
            position += columns;
        }
        for (int i=0; i<chunks.size(); ++i){
            if (i%2!=0){
                reverse(chunks[i].begin(), chunks[i].end());
            }
        }
        for (int i=0; i<columns; ++i){
            for (int k=0; k<chunks.size(); ++k){
                answer += chunks[k].at(i);
            }
        }
        chunks.clear();
        output.push_back(answer);
        cin >> columns;
    }
    for (vector<string>::iterator it=output.begin(); it!=output.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}