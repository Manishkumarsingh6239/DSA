#include<bits/stdc++.h>
using namespace std;


// USING RECURSION

// class Solution {
// public:
//     vector<vector<int>> ans;
//     void solve(int index,vector<int>& subset,vector<int> nums,int n){
//         if(index>=n){
//             ans.push_back(subset);
//             return;
//         }
//         subset.push_back(nums[index]);
//         solve(index+1,subset,nums,n);
//         subset.pop_back();
//         solve(index+1,subset,nums,n);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> subset;
//         solve(0,subset,nums,nums.size());
//         return ans;
//     }
// };


// USING BIT MANIPULATION

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int num=0;num<(pow(2,n));num++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){   //just moving 1 left at a time so that it gives 1 when did AND BITWISE to check which index to choose 1->choose 0->not choose
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = sol.subsets(nums);
    for(auto row:ans){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}