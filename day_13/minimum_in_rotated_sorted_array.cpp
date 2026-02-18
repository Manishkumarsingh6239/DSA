#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<nums[r]){
             r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return nums[l];
    }
};
int main(){
    Solution sol;
    vector<int> arr = {5,1,2,3,4};
    cout<<(sol.findMin(arr))<<endl;
}