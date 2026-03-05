#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp = grid;
        for(int i=1;i<col;i++){
            dp[0][i]+=dp[0][i-1];
        }
        for(int i=1;i<row;i++){
            dp[i][0]+=dp[i-1][0];
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};

int main(){
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<s.minPathSum(grid);
}