#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited = grid;
        queue<pair<int,int>> q;
        int freshOranges= 0;
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[0].size(); col++){
                if(visited[row][col]==1){
                    freshOranges++;
                }
                if(visited[row][col]==2){
                    q.push({row,col});
                }
            }
        }

        if(freshOranges==0) return 0;
        if(q.size()==0) return -1;

        int deltarow[]={-1,0,1,0};
        int deltacol[]={0,1,0,-1};
        int minutes = -1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row+deltarow[i];
                int ncol = col+deltacol[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && visited[nrow][ncol]==1){
                    visited[nrow][ncol]=2;
                    freshOranges--;
                    q.push({nrow,ncol});
                }
            }
            }
            minutes++;
        }

        if(freshOranges==0){
            return minutes;
        }
        return -1;

    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int result = sol.orangesRotting(grid);
    cout << "Minutes until all oranges are rotten: " << result << endl;
    return 0;
}