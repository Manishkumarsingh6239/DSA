#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(begin(gas),end(gas),0);
        int totalCost = accumulate(cost.begin(),cost.end(),0);

        if(totalGas<totalCost) return -1;

        int total=0;
        int result=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                result=i+1;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    cout<<s.canCompleteCircuit(gas,cost)<<endl;
}