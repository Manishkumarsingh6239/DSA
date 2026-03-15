#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(k!=1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<s.findKthLargest(nums,k);
}