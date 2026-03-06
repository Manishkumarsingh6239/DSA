#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,vector<int>& vis,vector<int>& path){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            vis[i]=1;
            path.push_back(nums[i]);
            solve(nums,vis,path);
            vis[i]=0;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        vector<int> path;
        solve(nums,vis,path);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = sol.permute(nums);
    for(auto it:ans){
        for(auto i:it) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}