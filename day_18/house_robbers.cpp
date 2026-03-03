#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n]; //dpq[i] represents the maximum amount of money that can be robbed from the first i houses
        dp[0]=nums[0];
        if(n==1) return dp[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,1};
    cout<<s.rob(nums)<<endl;
    return 0;
}