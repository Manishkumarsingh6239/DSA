#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int cur = nums[0], best = nums[0];
        int n = nums.size();
        for(int i=1;i<n; i++){
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}