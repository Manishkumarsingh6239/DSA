#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> mp;
        for(auto x : nums){
            if(mp.count(x)) return true;
            mp.insert(x);
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    bool result = sol.containsDuplicate(nums);
    cout << (result ? "Contains duplicates" : "No duplicates") << endl;
    return 0;
}