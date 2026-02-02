#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        while(low<high){
            if((nums[low]+nums[high])>target) high--;
            else if((nums[low]+nums[high])<target) low++;
            else break;
        }
        return {low+1,high+1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}