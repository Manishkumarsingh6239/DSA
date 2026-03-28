#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> t;
    int solve(int idx, vector<int>& coins,int target){
        if(idx==0){
            if(target%coins[idx] == 0){
                return target/coins[0];
            }
            return 1e9;
        }
        if(t[idx][target]!=-1) return t[idx][target];
        int not_take = 0+solve(idx-1,coins,target);
        int take =1e9;
        if (coins[idx]<=target) take = 1+solve(idx,coins,target-coins[idx]);
        return t[idx][target]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        t = vector(n,vector<int>(amount+1, -1));
        int ans = solve(n-1,coins,amount);
        if(ans>=1e9) return -1;
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<s.coinChange(coins,amount)<<endl;
}