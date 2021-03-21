#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int cur_case = 1; cur_case <= cases; ++cur_case){
        int r,c;
        cin >> r >> c;
        vector<vector<int>> up(r+1, vector<int>(c+1, 0));
        vector<vector<int>> down(r+1, vector<int>(c+1, 0));
        vector<vector<int>> left(r+1, vector<int>(c+1, 0));
        vector<vector<int>> right(r+1, vector<int>(c+1, 0));
        vector<vector<int>> grid(r+1, vector<int>(c+1));

        for (int rc = 0; rc < r; ++rc){
            for (int cc = 0; cc < c; ++cc){
               cin >> grid[rc][cc]; 
            }
        }

        // compute across
        for (int row = 0; row < r; ++row){
            int count = 0;
            int index = 0;
            while (index <= c){
                if (index == c || grid[row][index] == 0){
                    int temp_index = index - count;
                    int start = 1;
                    while (temp_index < index) {
                        right[row][temp_index] = count;
                        left[row][temp_index] = start;
                        count -= 1;
                        temp_index += 1;
                        start += 1;
                    }
                    count = 0;
                }
                else {
                    count++;
                }
                index++;
            }
        }

        for (int col = 0; col < c; ++col){
            int count = 0;
            int index = 0;
            while (index <= r){
                if (index == r || grid[index][col] == 0){
                    int temp_index = index - count;
                    int start = 1;
                    while (temp_index < index) {
                        down[temp_index][col] = count;
                        up[temp_index][col] = start;
                        count -= 1;
                        temp_index += 1;
                        start += 1;
                    }
                    count = 0;
                }
                else {
                    count++;
                }
                index++;
            }
        }
        int ans = 0;
        for (int rc = 0; rc < r; ++rc){
            for (int cc = 0; cc < c; ++cc){
                if (grid[rc][cc] == 0){
                    continue;
                }
                ans += min(max(0, up[rc][cc]/2 - 1), left[rc][cc]-1);
                ans += min(max(0, left[rc][cc]/2 - 1), up[rc][cc]-1);

                ans += min(max(0, up[rc][cc]/2 - 1), right[rc][cc]-1);
                ans += min(max(0, right[rc][cc]/2 - 1), up[rc][cc]-1);

                ans += min(max(0, down[rc][cc]/2 - 1), left[rc][cc]-1);
                ans += min(max(0, left[rc][cc]/2 - 1), down[rc][cc]-1);

                ans += min(max(0, down[rc][cc]/2 - 1), right[rc][cc]-1);
                ans += min(max(0, right[rc][cc]/2 - 1), down[rc][cc]-1);
            }
        }
        cout << "Case #" << cur_case << ": " << ans << endl;
    }
    return 0;
}