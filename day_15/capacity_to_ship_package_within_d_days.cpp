#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int req_days(vector<int> weights,int capc){
        int day=1,load=0;
        for(auto weight:weights){
            if(load+weight <= capc){
                load+=weight;
            }
            else{
                load=weight;
                day++;
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);

        while(l<=r){
            int mid=(l+r)/2;
            if(req_days(weights,mid)>days){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};

int main(){
    Solution sol;
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    cout<<sol.shipWithinDays(weights,days)<<endl;
    return 0;
}