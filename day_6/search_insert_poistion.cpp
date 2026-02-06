#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high = nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){
    vector <int> arr = {-1,0,3,6,7,10};
    Solution sol;
    int target = 8;
    int index = sol.search(arr,target);
    cout<<target<<" is/should be at index "<<index<<endl;
}