#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int need = target - nums[i];
            if (mp.count(need))
                return {i, mp[need]};

            mp[nums[i]] = i;
        }
        return {1, 1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}