#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int ans=0;
    // void solve(int row,int col,int m,int n){
    //     if(row>=m || col>=n) return;
    //     if(row==m-1 && col==n-1){
    //         ans++;
    //         return;
    //     }
    //     solve(row+1,col,m,n);
    //     solve(row,col+1,m,n);
    // }
    long long uniquePaths(int m, int n) {
        // solve(0,0,m,n);
        // return ans;

        // long long int res = 1;
        // for(int i = 1; i <= n-1; i++){
        //     res = res * ((m+n-2) - i + 1) / i;
        // }
        // return res;

        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(){
    Solution s;
    int m,n;
    cin>>m>>n;
    cout<<s.uniquePaths(m,n);
}