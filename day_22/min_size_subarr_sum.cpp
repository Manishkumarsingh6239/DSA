#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,minLen=INT_MAX,sum=0;
        while(r<nums.size()){
            sum+=nums[r++];
            while(sum>=target){
                sum-=nums[l++];
                minLen=min(minLen,r-l+1);
            }
        }
            return minLen==INT_MAX? 0:minLen;
    }
};

int main(){
    Solution s;
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    cout<<s.minSubArrayLen(target,nums);
}