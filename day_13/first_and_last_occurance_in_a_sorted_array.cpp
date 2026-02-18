#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st_pos = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int end_pos = upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(st_pos<nums.size() && nums[st_pos]==target){
            return {st_pos,end_pos};
        }
        return {-1,-1};
    }
};

int main(){
    int arr[] =  {1,2,3,4,5,6,8,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int *lb = lower_bound(arr,arr+n,0);
    cout<<lb-arr<<endl;
}