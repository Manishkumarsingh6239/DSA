#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
       if(nums.size()==1) return 0;
       int l=0,r=0,jumps=0;
       while(r<nums.size()-1){
        int farthest=0;
        for(int i=l;i<=r;i++){
            farthest=max(farthest,i+nums[i]);
        }
        l=r+1;
        r=farthest;
        jumps++;
       }
       return jumps;
    }
};

int main(){
    Solution s;
    vector<int> nums={2,3,1,1,4};
    cout<<s.jump(nums)<<endl;
    return 0;
}