#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void bfs(int row,int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int m, int n){
        queue<pair<int,int>> q;
        q.push({row,col});

            int deltarow[]={-1,0,1,0};
            int deltacol[]={0,1,0,-1};
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();


            for(int i=0; i<4; i++){
                    int nrow = row+deltarow[i];
                    int ncol = col+deltacol[i];
                    if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int count=0;

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++;
                    vis[row][col] = 1;
                    bfs(row,col,vis,grid,m,n);
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}