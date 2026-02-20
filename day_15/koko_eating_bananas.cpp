#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long timetaken(vector<int>& piles, int s){
        long long ans=0;
        for(int x:piles){
            ans+=ceil(double(x)/double(s));
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(),piles.end());
        int l=1,mid=0;
        while(l<=max){
            mid = (l+max)/2;
            long long time = timetaken(piles,mid);
            if(time>h){
                l=mid+1;
            }
            else{
                max=mid-1;
            }
        }
        return l;
    }
};
int main(){
    Solution s;
    vector<int> piles = {3,6,7,11};
    int h=8;
    cout<<s.minEatingSpeed(piles,h)<<endl;
}