#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0,zero_count=0,res=INT_MIN;
        while(end<nums.size()){
            if(nums[end++]==0) zero_count++;

            while(zero_count>k){
                if(nums[start++]==0) zero_count--;
            }
            res=max(res,end-start+1);
        }
        return res-1;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<s.longestOnes(nums,k);
}