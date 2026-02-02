#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int z=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[z++],nums[i]);
            }
        }
        
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    cout << "Array after moving zeroes: ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}