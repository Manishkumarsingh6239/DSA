
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(int p=0;p<4;p++){
                int nr = i + dr[p];
                int nc = j + dc[p];

                if(nr>=0 && nc>=0 && nr<m && nc<n && ans[nr][nc]==-1){
                    ans[nr][nc] = ans[i][j] + 1;
                    q.push({nr,nc});
                }
            }
        }

        return ans;
    }
};
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    Solution sol;
    vector<vector<int>> ans = sol.updateMatrix(mat);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}