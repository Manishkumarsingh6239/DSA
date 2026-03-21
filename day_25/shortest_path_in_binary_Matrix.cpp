#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;

        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n,0));

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        q.push({0,0});
        vis[0][0]++;
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            int step=vis[i][j];

            if(i==n-1 && j==n-1) return step;
            
            for(int p=0;p<8;p++){
                int nr=i+dr[p];
                int nc=j+dc[p];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && vis[nr][nc]==0){
                    vis[nr][nc]=step+1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout<<sol.shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}