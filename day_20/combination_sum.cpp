#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index,vector<int>& candidates, vector<int>& path, int need){
        if(need==0){
            ans.push_back(path);
            return;
        }
        if(need<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            need-=candidates[i];
            path.push_back(candidates[i]);
            solve(i,candidates,path,need);
            need+=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target==1) return {};
        vector<int> path;
        solve(0,candidates,path,target);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = sol.combinationSum(candidates,target);
    for(auto row:ans){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}