#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int no_of_sb(vector<int> nums, int lt){
        int no_of_subarr = 1, sum=0;
        for(int x:nums){
            if(sum+x<=lt){
                sum+=x;
            }
            else{
                no_of_subarr++;
                sum=x;
            }
        }
        return no_of_subarr;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int r = accumulate(nums.begin(),nums.end(),0);
        int l = *max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid = (l+r)/2;
            if(no_of_sb(nums,mid)>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};
int main(){
    Solution sol;
    vector<int> nums={7,2,5,10,8};
    int k=2;
    cout<<sol.splitArray(nums,k)<<endl;
    return 0;
}