#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> s;
        unordered_map <int,int> next;
        for(int i=n2-1;i>=0;--i){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            next[nums2[i]]=s.empty() ? -1: s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int num: nums1){
            ans.push_back(next[num]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {6,5,4,3,2,1,7};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for(int val : result){
        cout << val << " ";
    }
    cout <<endl;
    return 0;
}