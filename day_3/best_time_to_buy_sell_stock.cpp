#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy=prices[0],best = INT_MIN;
        for(int i=1;i<n;i++){
            if(buy>prices[i]) buy=prices[i];
            best = max(best,prices[i]-buy);
        }
        if(best<=0)return 0;
        return best;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl; // Output: 5
    return 0;
}