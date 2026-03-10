#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxReach) return false;
            maxReach = max(maxReach,i+nums[i]);
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums={2,3,1,1,4};
    cout<<s.canJump(nums);
}