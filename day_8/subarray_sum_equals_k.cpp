#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); 
        for(int i = 1; i < n; i++)
        {
            arr[i] = arr[i] + arr[i - 1];
        }
        
        unordered_map<int,int> mp; 
        int ans = 0; 
        for(int i = 0; i < n; i++) 
        {
            if(arr[i] == k) 
                ans++;
            
            if(mp.count(arr[i] - k))
            {
                ans += mp[arr[i] - k]; 
            }
            mp[arr[i]]++; 
        }
        
        return ans; 
    }
};

int main(){
    Solution sol;
    
}